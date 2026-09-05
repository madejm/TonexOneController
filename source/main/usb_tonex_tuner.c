/*
 Copyright (C) 2026  Greg Smith

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_log.h"
#include "esp_heap_caps.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/stream_buffer.h"
#include "freertos/task.h"
#include "usb/usb_helpers.h"
#include "usb/usb_host.h"

#include "display.h"
#include "task_priorities.h"
#include "tonex_params.h"
#include "usb_tonex_tuner.h"

#define TAG                             "tonex_tuner"

#define AUDIO_SAMPLE_RATE               44100U
#define TUNER_DECIMATION                4U
#define AUDIO_CHANNELS                  2U
#define TUNER_INPUT_CHANNEL             0U

#define USB_TRANSFER_COUNT              4U
#define USB_PACKETS_PER_TRANSFER        4U
#define USB_MIN_TRANSFER_COUNT          2U
#define AUDIO_STREAM_BUFFER_BYTES       (12U * 1024U)
#define AUDIO_CALLBACK_MAX_FRAMES       128U
#define AUDIO_CAPTURE_SECONDS           2U
#define AUDIO_CAPTURE_BYTES             \
    (AUDIO_SAMPLE_RATE * AUDIO_CHANNELS * 4U * AUDIO_CAPTURE_SECONDS)
#define AUDIO_CAPTURE_TRACE_RECORD_BYTES 8U
#define AUDIO_CAPTURE_TRACE_RECORDS     4096U
#define AUDIO_CAPTURE_TRACE_BYTES       \
    (AUDIO_CAPTURE_TRACE_RECORD_BYTES * AUDIO_CAPTURE_TRACE_RECORDS)

#define TUNER_WINDOW_SIZE               2048U
#define TUNER_HOP_SIZE                  512U
#define TUNER_MIN_FREQUENCY             25.0f
#define TUNER_MAX_FREQUENCY             1500.0f
#define TUNER_YIN_THRESHOLD             0.15f
#define TUNER_MIN_CONFIDENCE            0.72f
#define TUNER_YIN_MINIMUM_TOLERANCE     0.05f
#define TUNER_MIN_LEVEL_DB              -48.0f
#define TUNER_TASK_STACK_SIZE           (7U * 1024U)
#define TUNER_TASK_PRIORITY             (tskIDLE_PRIORITY + 3)

#define USB_SUBCLASS_AUDIOSTREAMING     0x02U
#define USB_SUBCLASS_AUDIOCONTROL       0x01U
#define USB_PROTOCOL_UAC2               0x20U
#define USB_PROTOCOL_UAC1               0x00U
#define USB_CS_INTERFACE                0x24U
#define UAC_AS_GENERAL                  0x01U
#define UAC_FORMAT_TYPE                 0x02U
#define UAC_FORMAT_TYPE_I               0x01U
#define UAC_CLOCK_SOURCE                0x0AU
#define UAC_REQUEST_CUR                 0x01U
#define UAC_CLOCK_FREQUENCY_CONTROL     0x01U

typedef struct {
    float b0;
    float b1;
    float b2;
    float a1;
    float a2;
    float z1;
    float z2;
} biquad_t;

typedef struct {
    usb_host_client_handle_t client_hdl;
    usb_device_handle_t dev_hdl;
    uint8_t interface_number;
    uint8_t alternate_setting;
    uint8_t endpoint_address;
    uint16_t endpoint_mps;
    uint8_t endpoint_interval;
    uint8_t audio_channels;
    uint8_t audio_subslot_size;
    uint8_t audio_bit_resolution;
    uint8_t audio_protocol;
    uint32_t audio_sample_rate;
    uint8_t audio_control_interface;
    uint8_t clock_source_id;
    bool clock_frequency_writable;
    bool interface_claimed;
    volatile bool active;
    volatile uint32_t transfers_in_flight;
    usb_transfer_t *transfers[USB_TRANSFER_COUNT];
    StreamBufferHandle_t audio_stream;
    uint8_t *audio_stream_storage;
    TaskHandle_t tuner_task;
    uint32_t packet_count;
    uint32_t frame_count;
    uint32_t packet_errors;
    uint32_t stream_overruns;
    volatile uint32_t total_frame_count;
    float input_sample_rate;
    bool sample_rate_measured;
    uint8_t selected_channel;
    volatile usb_transfer_status_t last_error_status;
    volatile bool submit_failed;
    uint8_t qualifier_status;
    uint8_t qualifier_length;
    uint8_t other_speed_status;
    uint8_t other_speed_length;
} tuner_context_t;

typedef enum {
    TUNER_DISPLAY_UNKNOWN,
    TUNER_DISPLAY_VALID,
    TUNER_DISPLAY_NO_USB_SAMPLES,
    TUNER_DISPLAY_USB_ERROR,
    TUNER_DISPLAY_SILENT,
    TUNER_DISPLAY_SEARCHING,
} tuner_display_state_t;

typedef struct {
    volatile bool complete;
    usb_transfer_status_t status;
} control_transfer_wait_t;

static tuner_context_t s_tuner;
static StaticStreamBuffer_t s_audio_stream_control;
static tuner_display_state_t s_display_state;
static float s_tuner_window[TUNER_WINDOW_SIZE];
static float s_yin[TUNER_WINDOW_SIZE / 2U];

typedef enum {
    AUDIO_CAPTURE_DISABLED,
    AUDIO_CAPTURE_RECORDING,
    AUDIO_CAPTURE_READY,
} audio_capture_state_t;

/* Keep a completed diagnostic capture available after USB disconnect. */
static uint8_t *s_capture_data;
static size_t s_capture_length;
static uint8_t *s_capture_packet_trace;
static size_t s_capture_packet_trace_length;
static volatile audio_capture_state_t s_capture_state;
static volatile uint32_t s_capture_readers;
static TickType_t s_capture_start_tick;
static int64_t s_capture_start_us;
static uint32_t s_capture_wall_ms;
static bool s_capture_started;
static uint32_t s_capture_packets_40;
static uint32_t s_capture_packets_48;
static uint32_t s_capture_packets_56;
static uint32_t s_capture_packets_96;
static uint32_t s_capture_packets_352;
static uint32_t s_capture_packets_360;
static uint32_t s_capture_packets_other;
static uint32_t s_capture_packets_completed;
static uint32_t s_capture_packets_skipped;
static uint32_t s_capture_packets_failed;
static portMUX_TYPE s_capture_lock = portMUX_INITIALIZER_UNLOCKED;
static bool s_capture_ready_announced;

static bool capture_prepare(void)
{
    portENTER_CRITICAL(&s_capture_lock);
    const bool busy = s_capture_readers != 0U;
    portEXIT_CRITICAL(&s_capture_lock);
    if (busy) {
        return false;
    }

    if (s_capture_data == NULL) {
        s_capture_data = heap_caps_malloc(
            AUDIO_CAPTURE_BYTES, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
        if (s_capture_data == NULL) {
            return false;
        }
    }
    if (s_capture_packet_trace == NULL) {
        s_capture_packet_trace = heap_caps_malloc(
            AUDIO_CAPTURE_TRACE_BYTES, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
        if (s_capture_packet_trace == NULL) {
            return false;
        }
    }

    s_capture_length = 0U;
    s_capture_packet_trace_length = 0U;
    s_capture_start_tick = 0;
    s_capture_start_us = 0;
    s_capture_wall_ms = 0U;
    s_capture_started = false;
    s_capture_packets_40 = 0U;
    s_capture_packets_48 = 0U;
    s_capture_packets_56 = 0U;
    s_capture_packets_96 = 0U;
    s_capture_packets_352 = 0U;
    s_capture_packets_360 = 0U;
    s_capture_packets_other = 0U;
    s_capture_packets_completed = 0U;
    s_capture_packets_skipped = 0U;
    s_capture_packets_failed = 0U;
    s_capture_ready_announced = false;
    portENTER_CRITICAL(&s_capture_lock);
    s_capture_state = AUDIO_CAPTURE_RECORDING;
    portEXIT_CRITICAL(&s_capture_lock);
    return true;
}

static bool capture_owns_tuner_ui(void)
{
    return s_capture_state == AUDIO_CAPTURE_RECORDING ||
           s_capture_state == AUDIO_CAPTURE_READY;
}

static void control_transfer_complete(usb_transfer_t *transfer)
{
    control_transfer_wait_t *wait = (control_transfer_wait_t *)transfer->context;
    wait->status = transfer->status;
    wait->complete = true;
}

static esp_err_t read_standard_descriptor(uint8_t descriptor_type,
                                          uint8_t *destination,
                                          size_t requested_length,
                                          uint8_t *transfer_status,
                                          uint8_t *actual_length)
{
    usb_transfer_t *transfer = NULL;
    control_transfer_wait_t wait = {0};
    esp_err_t result = usb_host_transfer_alloc(
        sizeof(usb_setup_packet_t) + requested_length, 0, &transfer);
    if (result != ESP_OK) {
        *transfer_status = UINT8_MAX;
        *actual_length = 0U;
        return result;
    }

    usb_setup_packet_t *setup = (usb_setup_packet_t *)transfer->data_buffer;
    setup->bmRequestType = USB_BM_REQUEST_TYPE_DIR_IN |
                           USB_BM_REQUEST_TYPE_TYPE_STANDARD |
                           USB_BM_REQUEST_TYPE_RECIP_DEVICE;
    setup->bRequest = USB_B_REQUEST_GET_DESCRIPTOR;
    setup->wValue = (uint16_t)descriptor_type << 8;
    setup->wIndex = 0U;
    setup->wLength = (uint16_t)requested_length;
    transfer->device_handle = s_tuner.dev_hdl;
    transfer->bEndpointAddress = 0x80U;
    transfer->callback = control_transfer_complete;
    transfer->context = &wait;
    transfer->num_bytes = sizeof(usb_setup_packet_t) + requested_length;

    result = usb_host_transfer_submit_control(s_tuner.client_hdl, transfer);
    while (result == ESP_OK && !wait.complete) {
        result = usb_host_client_handle_events(s_tuner.client_hdl, pdMS_TO_TICKS(20));
        if (result == ESP_ERR_TIMEOUT) {
            result = ESP_OK;
        }
    }

    if (result == ESP_OK) {
        *transfer_status = (uint8_t)wait.status;
        size_t received = transfer->actual_num_bytes > (int)sizeof(usb_setup_packet_t)
                        ? (size_t)transfer->actual_num_bytes - sizeof(usb_setup_packet_t)
                        : 0U;
        if (received > requested_length) {
            received = requested_length;
        }
        *actual_length = (uint8_t)received;
        if (received > 0U) {
            memcpy(destination, transfer->data_buffer + sizeof(usb_setup_packet_t), received);
        }
        if (wait.status != USB_TRANSFER_STATUS_COMPLETED) {
            result = ESP_FAIL;
        }
    } else {
        *transfer_status = UINT8_MAX;
        *actual_length = 0U;
    }

    usb_host_transfer_free(transfer);
    return result;
}

static void probe_speed_descriptors(void)
{
    uint8_t descriptor[10] = {0};

    esp_err_t result = read_standard_descriptor(
        USB_B_DESCRIPTOR_TYPE_DEVICE_QUALIFIER, descriptor, sizeof(descriptor),
        &s_tuner.qualifier_status, &s_tuner.qualifier_length);
    ESP_LOGI(TAG, "Device qualifier: result=%s status=%u length=%u",
             esp_err_to_name(result), s_tuner.qualifier_status,
             s_tuner.qualifier_length);
    if (s_tuner.qualifier_length > 0U) {
        ESP_LOG_BUFFER_HEX_LEVEL(TAG, descriptor, s_tuner.qualifier_length, ESP_LOG_INFO);
    }

    memset(descriptor, 0, sizeof(descriptor));
    result = read_standard_descriptor(
        USB_B_DESCRIPTOR_TYPE_OTHER_SPEED_CONFIGURATION, descriptor, 9U,
        &s_tuner.other_speed_status, &s_tuner.other_speed_length);
    ESP_LOGI(TAG, "Other-speed configuration: result=%s status=%u length=%u",
             esp_err_to_name(result), s_tuner.other_speed_status,
             s_tuner.other_speed_length);
    if (s_tuner.other_speed_length > 0U) {
        ESP_LOG_BUFFER_HEX_LEVEL(TAG, descriptor, s_tuner.other_speed_length, ESP_LOG_INFO);
    }
}

static esp_err_t set_streaming_alternate_setting(void)
{
    usb_transfer_t *transfer = NULL;
    control_transfer_wait_t wait = {0};
    esp_err_t result = usb_host_transfer_alloc(sizeof(usb_setup_packet_t), 0, &transfer);
    if (result != ESP_OK) {
        return result;
    }

    USB_SETUP_PACKET_INIT_SET_INTERFACE(
        (usb_setup_packet_t *)transfer->data_buffer,
        s_tuner.interface_number, s_tuner.alternate_setting);
    transfer->device_handle = s_tuner.dev_hdl;
    transfer->bEndpointAddress = 0x00;
    transfer->callback = control_transfer_complete;
    transfer->context = &wait;
    transfer->num_bytes = sizeof(usb_setup_packet_t);

    result = usb_host_transfer_submit_control(s_tuner.client_hdl, transfer);
    while (result == ESP_OK && !wait.complete) {
        result = usb_host_client_handle_events(s_tuner.client_hdl, pdMS_TO_TICKS(20));
        if (result == ESP_ERR_TIMEOUT) {
            result = ESP_OK;
        }
    }

    if (result == ESP_OK && wait.status != USB_TRANSFER_STATUS_COMPLETED) {
        result = ESP_FAIL;
    }
    usb_host_transfer_free(transfer);
    return result;
}

static esp_err_t set_audio_clock_frequency(void)
{
    if (!s_tuner.clock_frequency_writable || s_tuner.clock_source_id == 0U) {
        return ESP_OK;
    }

    usb_transfer_t *transfer = NULL;
    control_transfer_wait_t wait = {0};
    esp_err_t result = usb_host_transfer_alloc(
        sizeof(usb_setup_packet_t) + sizeof(uint32_t), 0, &transfer);
    if (result != ESP_OK) {
        return result;
    }

    usb_setup_packet_t *setup = (usb_setup_packet_t *)transfer->data_buffer;
    setup->bmRequestType = USB_BM_REQUEST_TYPE_DIR_OUT |
                           USB_BM_REQUEST_TYPE_TYPE_CLASS |
                           USB_BM_REQUEST_TYPE_RECIP_INTERFACE;
    setup->bRequest = UAC_REQUEST_CUR;
    setup->wValue = UAC_CLOCK_FREQUENCY_CONTROL << 8;
    setup->wIndex = ((uint16_t)s_tuner.clock_source_id << 8) |
                    s_tuner.audio_control_interface;
    setup->wLength = sizeof(uint32_t);

    const uint32_t sample_rate = AUDIO_SAMPLE_RATE;
    memcpy(transfer->data_buffer + sizeof(usb_setup_packet_t),
           &sample_rate, sizeof(sample_rate));
    transfer->device_handle = s_tuner.dev_hdl;
    transfer->bEndpointAddress = 0x00;
    transfer->callback = control_transfer_complete;
    transfer->context = &wait;
    transfer->num_bytes = sizeof(usb_setup_packet_t) + sizeof(sample_rate);

    result = usb_host_transfer_submit_control(s_tuner.client_hdl, transfer);
    while (result == ESP_OK && !wait.complete) {
        result = usb_host_client_handle_events(s_tuner.client_hdl, pdMS_TO_TICKS(20));
        if (result == ESP_ERR_TIMEOUT) {
            result = ESP_OK;
        }
    }
    if (result == ESP_OK && wait.status != USB_TRANSFER_STATUS_COMPLETED) {
        result = ESP_FAIL;
    }
    usb_host_transfer_free(transfer);
    return result;
}

static size_t audio_frame_bytes(void)
{
    return (size_t)s_tuner.audio_channels * s_tuner.audio_subslot_size;
}

static inline int16_t unpack_audio_sample(const uint8_t *data)
{
    if (s_tuner.audio_subslot_size == 4U) {
        const uint32_t packed = (uint32_t)data[0]
                              | ((uint32_t)data[1] << 8)
                              | ((uint32_t)data[2] << 16)
                              | ((uint32_t)data[3] << 24);
        /* UAC2 PCM is left-aligned inside its audio subslot. */
        const int32_t sample = (int32_t)packed;
        return (int16_t)(sample >> 16);
    }

    if (s_tuner.audio_subslot_size == 3U) {
        const uint32_t packed = (uint32_t)data[0]
                          | ((uint32_t)data[1] << 8)
                          | ((uint32_t)data[2] << 16);
        int32_t sample = (int32_t)(packed << 8) >> 8;
        return (int16_t)(sample >> 8);
    }

    return (int16_t)((uint16_t)data[0] | ((uint16_t)data[1] << 8));
}

static inline float biquad_process(biquad_t *filter, float input)
{
    const float output = filter->b0 * input + filter->z1;
    filter->z1 = filter->b1 * input - filter->a1 * output + filter->z2;
    filter->z2 = filter->b2 * input - filter->a2 * output;
    return output;
}

static void biquad_init_lowpass(biquad_t *filter, float cutoff, float sample_rate)
{
    const float pi = 3.14159265358979323846f;
    const float omega = 2.0f * pi * cutoff / sample_rate;
    const float cosine = cosf(omega);
    const float sine = sinf(omega);
    const float alpha = sine / (2.0f * 0.70710678f);
    const float a0 = 1.0f + alpha;

    memset(filter, 0, sizeof(*filter));
    filter->b0 = ((1.0f - cosine) * 0.5f) / a0;
    filter->b1 = (1.0f - cosine) / a0;
    filter->b2 = filter->b0;
    filter->a1 = (-2.0f * cosine) / a0;
    filter->a2 = (1.0f - alpha) / a0;
}

static float tuner_reference_frequency(void)
{
    float reference = 440.0f;
    tModellerParameter *parameters = NULL;

    if (tonex_params_get_locked_access(&parameters) == ESP_OK) {
        reference = parameters[TONEX_GLOBAL_TUNING_REFERENCE].Value;
        tonex_params_release_locked_access();
    }

    if (reference < 400.0f || reference > 480.0f) {
        reference = 440.0f;
    }
    return reference;
}

static void tuner_publish_status(tuner_display_state_t state, const char *text)
{
    if (capture_owns_tuner_ui()) {
        return;
    }
    if (s_display_state == state) {
        return;
    }
    s_display_state = state;
    UI_SetTunerStatus(text, false);
}

static const char *usb_error_status_text(void)
{
    if (s_tuner.submit_failed) {
        return "USB RESUBMIT FAIL";
    }

    switch (s_tuner.last_error_status) {
        case USB_TRANSFER_STATUS_TIMED_OUT:
            return "USB TIMEOUT";
        case USB_TRANSFER_STATUS_STALL:
            return "USB STALL";
        case USB_TRANSFER_STATUS_OVERFLOW:
            return "USB OVERFLOW";
        case USB_TRANSFER_STATUS_SKIPPED:
            return "USB SCHEDULING";
        case USB_TRANSFER_STATUS_NO_DEVICE:
            return "USB DISCONNECTED";
        case USB_TRANSFER_STATUS_CANCELED:
            return "USB CANCELED";
        case USB_TRANSFER_STATUS_ERROR:
        default:
            return "USB TRANSFER ERROR";
    }
}

static bool tuner_detect_pitch(const float *samples, float *frequency, float *confidence, float *level_db)
{
    const float tuner_sample_rate = s_tuner.input_sample_rate / (float)TUNER_DECIMATION;
    const uint32_t tau_min = (uint32_t)(tuner_sample_rate / TUNER_MAX_FREQUENCY);
    const uint32_t tau_max = (uint32_t)(tuner_sample_rate / TUNER_MIN_FREQUENCY);
    float energy = 0.0f;

    for (uint32_t i = 0; i < TUNER_WINDOW_SIZE; ++i) {
        energy += samples[i] * samples[i];
    }

    const float rms = sqrtf(energy / (float)TUNER_WINDOW_SIZE);
    *level_db = 20.0f * log10f(rms + 1.0e-9f);
    if (*level_db < TUNER_MIN_LEVEL_DB) {
        return false;
    }

    memset(s_yin, 0, sizeof(s_yin));
    /* YIN requires the same comparison window for every candidate lag.
       Varying it with tau biases the difference curve and its minima. */
    const uint32_t difference_window = TUNER_WINDOW_SIZE - tau_max;
    for (uint32_t tau = 1; tau <= tau_max; ++tau) {
        float difference = 0.0f;
        for (uint32_t i = 0; i < difference_window; ++i) {
            const float delta = samples[i] - samples[i + tau];
            difference += delta * delta;
        }
        s_yin[tau] = difference;
    }

    s_yin[0] = 1.0f;
    float running_sum = 0.0f;
    for (uint32_t tau = 1; tau <= tau_max; ++tau) {
        running_sum += s_yin[tau];
        s_yin[tau] = (running_sum > 0.0f)
                   ? s_yin[tau] * (float)tau / running_sum
                   : 1.0f;
    }

    uint32_t global_tau = tau_min;
    float global_value = s_yin[global_tau];
    for (uint32_t tau = tau_min + 1U; tau < tau_max; ++tau) {
        if (s_yin[tau] < global_value) {
            global_value = s_yin[tau];
            global_tau = tau;
        }
    }

    /* Prefer the first strong local minimum, but only when it is close to the
       global minimum. This rejects shallow harmonic minima on guitar signals. */
    float acceptance = global_value + TUNER_YIN_MINIMUM_TOLERANCE;
    if (acceptance > TUNER_YIN_THRESHOLD) {
        acceptance = TUNER_YIN_THRESHOLD;
    }
    uint32_t best_tau = global_tau;
    for (uint32_t tau = tau_min + 1U; tau < tau_max; ++tau) {
        if (s_yin[tau] <= acceptance &&
            s_yin[tau] <= s_yin[tau - 1U] &&
            s_yin[tau] < s_yin[tau + 1U]) {
            best_tau = tau;
            break;
        }
    }

    if (best_tau <= tau_min || best_tau >= tau_max) {
        return false;
    }

    *confidence = 1.0f - s_yin[best_tau];
    if (*confidence < TUNER_MIN_CONFIDENCE) {
        return false;
    }

    const float left = s_yin[best_tau - 1U];
    const float center = s_yin[best_tau];
    const float right = s_yin[best_tau + 1U];
    const float denominator = left - 2.0f * center + right;
    float refined_tau = (float)best_tau;
    if (fabsf(denominator) > 1.0e-9f) {
        refined_tau += 0.5f * (left - right) / denominator;
    }

    *frequency = tuner_sample_rate / refined_tau;
    return *frequency >= TUNER_MIN_FREQUENCY && *frequency <= TUNER_MAX_FREQUENCY;
}

static void tuner_publish_result(float frequency, float confidence, bool valid)
{
    static const char *note_names[12] = {
        "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
    };
    static float displayed_cents = 0.0f;
    static int previous_midi_note = -1;

    if (!valid || capture_owns_tuner_ui()) {
        displayed_cents = 0.0f;
        previous_midi_note = -1;
        return;
    }

    const float reference = tuner_reference_frequency();
    const float fractional_note = 69.0f + 12.0f * log2f(frequency / reference);
    const int midi_note = (int)lroundf(fractional_note);
    const int octave = midi_note / 12 - 1;
    const float measured_cents = 100.0f * (fractional_note - (float)midi_note);
    /* Large enough for a two-character note name and any formatted int octave. */
    char note[24];

    if (midi_note != previous_midi_note) {
        displayed_cents = measured_cents;
        previous_midi_note = midi_note;
    } else {
        displayed_cents += 0.30f * (measured_cents - displayed_cents);
    }
    snprintf(note, sizeof(note), "%s%d", note_names[(midi_note % 12 + 12) % 12], octave);
    s_display_state = TUNER_DISPLAY_VALID;
    UI_SetTunerResult(note, displayed_cents, confidence >= TUNER_MIN_CONFIDENCE,
                      (uint32_t)lroundf(frequency * 10.0f),
                      s_tuner.selected_channel);
}

static void tuner_task(void *arg)
{
    (void)arg;
    int16_t input[256];
    biquad_t lowpass;
    float previous_input = 0.0f;
    float previous_highpass = 0.0f;
    uint32_t decimation_phase = 0;
    uint32_t window_count = 0;
    TickType_t stats_tick = xTaskGetTickCount();
    uint32_t previous_total_frames = s_tuner.total_frame_count;

    biquad_init_lowpass(&lowpass, 2000.0f, (float)s_tuner.audio_sample_rate);
    if (!capture_owns_tuner_ui()) {
        UI_SetTunerResult("--", 0.0f, false, 0U, 0U);
    }

    while (s_tuner.active) {
        if (s_capture_state == AUDIO_CAPTURE_READY && !s_capture_ready_announced) {
            s_capture_ready_announced = true;
            char capture_status[64];
            const uint32_t captured_frames = (uint32_t)(
                s_capture_length / audio_frame_bytes());
            const uint32_t received_rate = s_capture_wall_ms > 0U
                ? captured_frames * 1000U / s_capture_wall_ms : 0U;
            snprintf(capture_status, sizeof(capture_status),
                     "FILE READY %lusps: /tonex-capture.wav",
                     (unsigned long)received_rate);
            UI_SetTunerStatus(capture_status, false);
        }

        const size_t received = xStreamBufferReceive(
            s_tuner.audio_stream, input, sizeof(input), pdMS_TO_TICKS(100));

        const size_t sample_count = received / sizeof(input[0]);
        for (size_t i = 0; i < sample_count; ++i) {
            const float current = (float)input[i] / 32768.0f;
            const float highpass = current - previous_input + 0.9985f * previous_highpass;
            previous_input = current;
            previous_highpass = highpass;

            const float filtered = biquad_process(&lowpass, highpass);
            if (++decimation_phase < TUNER_DECIMATION) {
                continue;
            }
            decimation_phase = 0;
            s_tuner_window[window_count++] = filtered;

            if (window_count == TUNER_WINDOW_SIZE) {
                float frequency = 0.0f;
                float confidence = 0.0f;
                float level_db = 0.0f;
                const bool valid = tuner_detect_pitch(
                    s_tuner_window, &frequency, &confidence, &level_db);
                if (valid) {
                    tuner_publish_result(frequency, confidence, true);
                } else if (level_db < TUNER_MIN_LEVEL_DB) {
                    tuner_publish_status(TUNER_DISPLAY_SILENT, "INPUT SILENT");
                } else {
                    tuner_publish_status(TUNER_DISPLAY_SEARCHING, "SEARCHING");
                }

                memmove(s_tuner_window,
                        &s_tuner_window[TUNER_HOP_SIZE],
                        sizeof(float) * (TUNER_WINDOW_SIZE - TUNER_HOP_SIZE));
                window_count = TUNER_WINDOW_SIZE - TUNER_HOP_SIZE;
            }
        }

        if ((xTaskGetTickCount() - stats_tick) >= pdMS_TO_TICKS(1000)) {
            const TickType_t now = xTaskGetTickCount();
            const TickType_t elapsed_ticks = now - stats_tick;
            const uint32_t total_frames = s_tuner.total_frame_count;
            const uint32_t elapsed_frames = total_frames - previous_total_frames;
            if (elapsed_frames > 30000U && elapsed_frames < 60000U && elapsed_ticks > 0U) {
                const float measured_rate =
                    (float)elapsed_frames * (float)configTICK_RATE_HZ / (float)elapsed_ticks;
                if (!s_tuner.sample_rate_measured) {
                    s_tuner.input_sample_rate = measured_rate;
                    s_tuner.sample_rate_measured = true;
                } else {
                    s_tuner.input_sample_rate +=
                        0.25f * (measured_rate - s_tuner.input_sample_rate);
                }
            }
            previous_total_frames = total_frames;
            if (s_tuner.frame_count == 0U) {
                if (s_tuner.packet_errors > 0U) {
                    tuner_publish_status(TUNER_DISPLAY_USB_ERROR, usb_error_status_text());
                } else {
                    tuner_publish_status(TUNER_DISPLAY_NO_USB_SAMPLES, "NO USB SAMPLES");
                }
            }
            ESP_LOGI(TAG, "frames=%lu packets=%lu errors=%lu overruns=%lu",
                     (unsigned long)s_tuner.frame_count,
                     (unsigned long)s_tuner.packet_count,
                     (unsigned long)s_tuner.packet_errors,
                     (unsigned long)s_tuner.stream_overruns);
            s_tuner.frame_count = 0;
            s_tuner.packet_count = 0;
            stats_tick = now;
        }
    }

    s_tuner.tuner_task = NULL;
    vTaskDelete(NULL);
}

static void audio_capture_complete(usb_transfer_t *transfer)
{
    if (s_tuner.transfers_in_flight > 0U) {
        --s_tuner.transfers_in_flight;
    }

    if (!s_tuner.active) {
        return;
    }

    if (transfer->status == USB_TRANSFER_STATUS_COMPLETED) {
        const int64_t callback_us = esp_timer_get_time();
        size_t offset = 0;
        for (int packet_index = 0; packet_index < transfer->num_isoc_packets; ++packet_index) {
            usb_isoc_packet_desc_t *packet = &transfer->isoc_packet_desc[packet_index];
            if (s_capture_state == AUDIO_CAPTURE_RECORDING) {
                if (!s_capture_started) {
                    s_capture_start_tick = xTaskGetTickCount();
                    s_capture_start_us = callback_us;
                    s_capture_started = true;
                }
                if (s_capture_packet_trace_length + AUDIO_CAPTURE_TRACE_RECORD_BYTES <=
                    AUDIO_CAPTURE_TRACE_BYTES) {
                    uint8_t *record = s_capture_packet_trace + s_capture_packet_trace_length;
                    const uint32_t elapsed_us = (uint32_t)(callback_us - s_capture_start_us);
                    record[0] = (uint8_t)elapsed_us;
                    record[1] = (uint8_t)(elapsed_us >> 8);
                    record[2] = (uint8_t)(elapsed_us >> 16);
                    record[3] = (uint8_t)(elapsed_us >> 24);
                    record[4] = (uint8_t)packet->actual_num_bytes;
                    record[5] = (uint8_t)((uint32_t)packet->actual_num_bytes >> 8);
                    record[6] = (uint8_t)packet->status;
                    record[7] = (uint8_t)packet_index;
                    s_capture_packet_trace_length += AUDIO_CAPTURE_TRACE_RECORD_BYTES;
                }
                if (packet->status == USB_TRANSFER_STATUS_COMPLETED) {
                    ++s_capture_packets_completed;
                } else if (packet->status == USB_TRANSFER_STATUS_SKIPPED) {
                    ++s_capture_packets_skipped;
                } else {
                    ++s_capture_packets_failed;
                }
            }
            if (packet->status == USB_TRANSFER_STATUS_COMPLETED &&
                packet->actual_num_bytes >= audio_frame_bytes()) {
                const uint8_t *packet_data = transfer->data_buffer + offset;
                const size_t frame_bytes = audio_frame_bytes();
                size_t frames = (size_t)packet->actual_num_bytes / frame_bytes;
                int16_t mono[AUDIO_CALLBACK_MAX_FRAMES];

                if (s_capture_state == AUDIO_CAPTURE_RECORDING) {
                    const TickType_t now = xTaskGetTickCount();
                    const size_t remaining = AUDIO_CAPTURE_BYTES - s_capture_length;
                    const size_t packet_size = (size_t)packet->actual_num_bytes;
                    const size_t copy_size = packet_size < remaining ? packet_size : remaining;
                    memcpy(s_capture_data + s_capture_length, packet_data, copy_size);
                    s_capture_length += copy_size;
                    if (packet->actual_num_bytes == 40) {
                        ++s_capture_packets_40;
                    } else if (packet->actual_num_bytes == 48) {
                        ++s_capture_packets_48;
                    } else if (packet->actual_num_bytes == 56) {
                        ++s_capture_packets_56;
                    } else if (packet->actual_num_bytes == 96) {
                        ++s_capture_packets_96;
                    } else if (packet->actual_num_bytes == 352) {
                        ++s_capture_packets_352;
                    } else if (packet->actual_num_bytes == 360) {
                        ++s_capture_packets_360;
                    } else {
                        ++s_capture_packets_other;
                    }

                    const TickType_t elapsed_ticks = now - s_capture_start_tick;
                    if (elapsed_ticks >= pdMS_TO_TICKS(AUDIO_CAPTURE_SECONDS * 1000U) ||
                        s_capture_length == AUDIO_CAPTURE_BYTES) {
                        s_capture_wall_ms = (uint32_t)(
                            (uint64_t)elapsed_ticks * 1000U / configTICK_RATE_HZ);
                        portENTER_CRITICAL(&s_capture_lock);
                        s_capture_state = AUDIO_CAPTURE_READY;
                        portEXIT_CRITICAL(&s_capture_lock);
                    }
                }

                if (frames > AUDIO_CALLBACK_MAX_FRAMES) {
                    frames = AUDIO_CALLBACK_MAX_FRAMES;
                }

                /* Diagnostic POC: keep one continuous channel. Switching between
                   phase-shifted stereo channels corrupts period detection. */
                s_tuner.selected_channel = TUNER_INPUT_CHANNEL;
                const size_t selected_channel = s_tuner.selected_channel;
                for (size_t frame = 0; frame < frames; ++frame) {
                    mono[frame] = unpack_audio_sample(
                        packet_data + frame * frame_bytes +
                        selected_channel * s_tuner.audio_subslot_size);
                }

                const size_t bytes = frames * sizeof(mono[0]);
                if (xStreamBufferSpacesAvailable(s_tuner.audio_stream) < bytes) {
                    ++s_tuner.stream_overruns;
                } else {
                    xStreamBufferSend(s_tuner.audio_stream, mono, bytes, 0);
                }
                ++s_tuner.packet_count;
                s_tuner.frame_count += frames;
                s_tuner.total_frame_count += frames;
            } else if (packet->status != USB_TRANSFER_STATUS_SKIPPED) {
                s_tuner.last_error_status = packet->status;
                ++s_tuner.packet_errors;
            }
            offset += (size_t)packet->num_bytes;
        }
    } else if (transfer->status != USB_TRANSFER_STATUS_CANCELED &&
               transfer->status != USB_TRANSFER_STATUS_NO_DEVICE) {
        if (s_capture_state == AUDIO_CAPTURE_RECORDING) {
            s_capture_packets_failed += (uint32_t)transfer->num_isoc_packets;
        }
        s_tuner.last_error_status = transfer->status;
        ++s_tuner.packet_errors;
    }

    if (s_tuner.active) {
        if (usb_host_transfer_submit(transfer) == ESP_OK) {
            ++s_tuner.transfers_in_flight;
        } else {
            s_tuner.submit_failed = true;
            ++s_tuner.packet_errors;
        }
    }
}

static bool find_capture_endpoint(const usb_config_desc_t *config,
                                  tuner_context_t *target)
{
    const usb_standard_desc_t *descriptor = (const usb_standard_desc_t *)config;
    const usb_intf_desc_t *interface = NULL;
    uint16_t offset = 0;
    uint8_t channels = 0;
    uint8_t subslot_size = 0;
    uint8_t bit_resolution = 0;
    uint32_t sample_rate = 0;
    bool found = false;

    while (descriptor != NULL && offset < config->wTotalLength) {
        if (descriptor->bDescriptorType == USB_B_DESCRIPTOR_TYPE_INTERFACE) {
            interface = (const usb_intf_desc_t *)descriptor;
            channels = 0;
            subslot_size = 0;
            bit_resolution = 0;
            sample_rate = 0;
        } else if (descriptor->bDescriptorType == USB_CS_INTERFACE && interface != NULL &&
                   interface->bInterfaceClass == USB_CLASS_AUDIO &&
                   interface->bInterfaceSubClass == USB_SUBCLASS_AUDIOSTREAMING) {
            const uint8_t *raw = (const uint8_t *)descriptor;
            if (interface->bInterfaceProtocol == USB_PROTOCOL_UAC2 &&
                descriptor->bLength >= 11U && raw[2] == UAC_AS_GENERAL) {
                channels = raw[10];
            } else if (interface->bInterfaceProtocol == USB_PROTOCOL_UAC2 &&
                       descriptor->bLength >= 6U && raw[2] == UAC_FORMAT_TYPE &&
                       raw[3] == UAC_FORMAT_TYPE_I) {
                subslot_size = raw[4];
                bit_resolution = raw[5];
            } else if (interface->bInterfaceProtocol == USB_PROTOCOL_UAC1 &&
                       descriptor->bLength >= 11U && raw[2] == UAC_FORMAT_TYPE &&
                       raw[3] == UAC_FORMAT_TYPE_I) {
                channels = raw[4];
                subslot_size = raw[5];
                bit_resolution = raw[6];
                if (raw[7] > 0U) {
                    sample_rate = (uint32_t)raw[8]
                                | ((uint32_t)raw[9] << 8)
                                | ((uint32_t)raw[10] << 16);
                }
            }
        } else if (descriptor->bDescriptorType == USB_B_DESCRIPTOR_TYPE_ENDPOINT &&
                   interface != NULL &&
                   interface->bInterfaceClass == USB_CLASS_AUDIO &&
                   interface->bInterfaceSubClass == USB_SUBCLASS_AUDIOSTREAMING &&
                   (interface->bInterfaceProtocol == USB_PROTOCOL_UAC2 ||
                    interface->bInterfaceProtocol == USB_PROTOCOL_UAC1) &&
                   interface->bAlternateSetting != 0U) {
            const usb_ep_desc_t *endpoint = (const usb_ep_desc_t *)descriptor;
            const bool is_input = (endpoint->bEndpointAddress & USB_B_ENDPOINT_ADDRESS_EP_DIR_MASK) != 0U;
            const bool is_isochronous = USB_EP_DESC_GET_XFERTYPE(endpoint) == USB_TRANSFER_TYPE_ISOCHRONOUS;
            const bool is_audio_data = USB_EP_DESC_GET_USAGETYPE(endpoint) == 0U;
            const uint16_t mps = USB_EP_DESC_GET_MPS(endpoint);

            if (is_input && is_isochronous && is_audio_data && channels > 0U &&
                subslot_size >= 2U && subslot_size <= 4U && mps >= channels * subslot_size) {
                const bool exact_format =
                    (interface->bInterfaceProtocol == USB_PROTOCOL_UAC2 &&
                     channels == AUDIO_CHANNELS &&
                     (subslot_size == 3U || subslot_size == 4U) &&
                     bit_resolution == 24U) ||
                    (interface->bInterfaceProtocol == USB_PROTOCOL_UAC1 &&
                     channels == 1U && subslot_size == 2U &&
                     bit_resolution == 16U && sample_rate == 48000U);
                if (!found || exact_format || mps < target->endpoint_mps) {
                    target->interface_number = interface->bInterfaceNumber;
                    target->alternate_setting = interface->bAlternateSetting;
                    target->endpoint_address = endpoint->bEndpointAddress;
                    target->endpoint_mps = mps;
                    target->endpoint_interval = endpoint->bInterval;
                    target->audio_channels = channels;
                    target->audio_subslot_size = subslot_size;
                    target->audio_bit_resolution = bit_resolution;
                    target->audio_protocol = interface->bInterfaceProtocol;
                    target->audio_sample_rate = sample_rate != 0U
                                              ? sample_rate : AUDIO_SAMPLE_RATE;
                    found = true;
                    if (exact_format) {
                        break;
                    }
                }
            }
        }

        int next_offset = offset;
        descriptor = usb_parse_next_descriptor(descriptor, config->wTotalLength, &next_offset);
        if (descriptor == NULL || next_offset <= offset) {
            break;
        }
        offset = (uint16_t)next_offset;
    }

    return found;
}

static void find_audio_clock_source(const usb_config_desc_t *config)
{
    const usb_standard_desc_t *descriptor = (const usb_standard_desc_t *)config;
    const usb_intf_desc_t *interface = NULL;
    uint16_t offset = 0;

    while (descriptor != NULL && offset < config->wTotalLength) {
        if (descriptor->bDescriptorType == USB_B_DESCRIPTOR_TYPE_INTERFACE) {
            interface = (const usb_intf_desc_t *)descriptor;
        } else if (descriptor->bDescriptorType == USB_CS_INTERFACE &&
                   interface != NULL &&
                   interface->bInterfaceClass == USB_CLASS_AUDIO &&
                   interface->bInterfaceSubClass == USB_SUBCLASS_AUDIOCONTROL &&
                   interface->bInterfaceProtocol == USB_PROTOCOL_UAC2 &&
                   descriptor->bLength >= 6U) {
            const uint8_t *raw = (const uint8_t *)descriptor;
            if (raw[2] == UAC_CLOCK_SOURCE) {
                s_tuner.audio_control_interface = interface->bInterfaceNumber;
                s_tuner.clock_source_id = raw[3];
                s_tuner.clock_frequency_writable = (raw[5] & 0x03U) == 0x03U;
                return;
            }
        }

        int next_offset = offset;
        descriptor = usb_parse_next_descriptor(descriptor, config->wTotalLength, &next_offset);
        if (descriptor == NULL || next_offset <= offset) {
            return;
        }
        offset = (uint16_t)next_offset;
    }
}

static esp_err_t allocate_and_submit_transfers(void)
{
    const size_t transfer_size = (size_t)s_tuner.endpoint_mps * USB_PACKETS_PER_TRANSFER;
    uint32_t allocated_transfers = 0U;

    for (uint32_t transfer_index = 0; transfer_index < USB_TRANSFER_COUNT; ++transfer_index) {
        usb_transfer_t *transfer = NULL;
        esp_err_t result = usb_host_transfer_alloc(
            transfer_size, USB_PACKETS_PER_TRANSFER, &transfer);
        if (result != ESP_OK) {
            if (allocated_transfers < USB_MIN_TRANSFER_COUNT) {
                return result;
            }
            ESP_LOGW(TAG, "USB DMA limited queue to %lu transfers",
                     (unsigned long)allocated_transfers);
            break;
        }

        transfer->device_handle = s_tuner.dev_hdl;
        transfer->bEndpointAddress = s_tuner.endpoint_address;
        transfer->callback = audio_capture_complete;
        transfer->context = NULL;
        transfer->num_bytes = (int)transfer_size;
        for (uint32_t packet = 0; packet < USB_PACKETS_PER_TRANSFER; ++packet) {
            transfer->isoc_packet_desc[packet].num_bytes = s_tuner.endpoint_mps;
        }
        s_tuner.transfers[transfer_index] = transfer;
        ++allocated_transfers;
    }

    s_tuner.active = true;
    for (uint32_t transfer_index = 0; transfer_index < allocated_transfers; ++transfer_index) {
        esp_err_t result = usb_host_transfer_submit(s_tuner.transfers[transfer_index]);
        if (result != ESP_OK) {
            s_tuner.active = false;
            return result;
        }
        ++s_tuner.transfers_in_flight;
    }
    return ESP_OK;
}

esp_err_t usb_tonex_tuner_init(class_driver_t *driver_obj)
{
    const usb_config_desc_t *config = NULL;
    usb_device_info_t device_info;
    esp_err_t result;

    if (driver_obj == NULL || driver_obj->client_hdl == NULL || driver_obj->dev_hdl == NULL) {
        return ESP_ERR_INVALID_ARG;
    }
    if (s_tuner.active || s_tuner.interface_claimed) {
        return ESP_ERR_INVALID_STATE;
    }

    memset(&s_tuner, 0, sizeof(s_tuner));
    s_display_state = TUNER_DISPLAY_UNKNOWN;
    s_tuner.input_sample_rate = (float)AUDIO_SAMPLE_RATE;
    s_tuner.client_hdl = driver_obj->client_hdl;
    s_tuner.dev_hdl = driver_obj->dev_hdl;

    result = usb_host_get_active_config_descriptor(s_tuner.dev_hdl, &config);
    if (result != ESP_OK) {
        UI_SetTunerStatus("NO USB DESCRIPTOR", true);
        return result;
    }
    if (!find_capture_endpoint(config, &s_tuner)) {
        ESP_LOGE(TAG, "No supported USB audio capture endpoint found");
        usb_print_config_descriptor(config, NULL);
        UI_SetTunerStatus("NO USB AUDIO INPUT", true);
        return ESP_ERR_NOT_FOUND;
    }
    if (s_tuner.audio_channels == 0U || s_tuner.audio_subslot_size < 2U ||
        s_tuner.audio_subslot_size > 4U || s_tuner.audio_sample_rate == 0U) {
        UI_SetTunerStatus("UNSUPPORTED FORMAT", true);
        return ESP_ERR_NOT_SUPPORTED;
    }
    s_tuner.input_sample_rate = (float)s_tuner.audio_sample_rate;
    find_audio_clock_source(config);

    result = usb_host_device_info(s_tuner.dev_hdl, &device_info);
    if (result != ESP_OK) {
        UI_SetTunerStatus("NO USB DEVICE INFO", true);
        return result;
    }
    if (device_info.speed == USB_SPEED_FULL) {
        probe_speed_descriptors();
        /* Keep the endpoint exactly as advertised. Enlarging the cached MPS
           cannot make the device repacketize its stream and changes the HCD's
           scheduling and DMA allocation without changing anything on-wire. */
    }

    ESP_LOGI(TAG, "Capture UAC%u interface=%u alt=%u endpoint=0x%02x mps=%u interval=%u format=%uch/%ubyte/%ubit/%luHz",
             s_tuner.audio_protocol == USB_PROTOCOL_UAC2 ? 2U : 1U,
             s_tuner.interface_number, s_tuner.alternate_setting,
             s_tuner.endpoint_address, s_tuner.endpoint_mps, s_tuner.endpoint_interval,
             s_tuner.audio_channels, s_tuner.audio_subslot_size,
             s_tuner.audio_bit_resolution, (unsigned long)s_tuner.audio_sample_rate);

    /* Audio samples are consumed by the CPU and are not USB DMA buffers, so keep
       their relatively large FIFO in PSRAM and preserve internal RAM for USB. */
    s_tuner.audio_stream_storage = heap_caps_malloc(
        AUDIO_STREAM_BUFFER_BYTES + 1U, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (s_tuner.audio_stream_storage == NULL) {
        UI_SetTunerStatus("AUDIO BUFFER FAILED", true);
        return ESP_ERR_NO_MEM;
    }
    s_tuner.audio_stream = xStreamBufferCreateStatic(
        AUDIO_STREAM_BUFFER_BYTES + 1U, sizeof(int16_t),
        s_tuner.audio_stream_storage, &s_audio_stream_control);
    if (s_tuner.audio_stream == NULL) {
        heap_caps_free(s_tuner.audio_stream_storage);
        s_tuner.audio_stream_storage = NULL;
        UI_SetTunerStatus("AUDIO BUFFER FAILED", true);
        return ESP_ERR_NO_MEM;
    }

    result = usb_host_interface_claim(s_tuner.client_hdl, s_tuner.dev_hdl,
                                      s_tuner.interface_number, s_tuner.alternate_setting);
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "Could not claim capture interface: %s", esp_err_to_name(result));
        vStreamBufferDelete(s_tuner.audio_stream);
        s_tuner.audio_stream = NULL;
        heap_caps_free(s_tuner.audio_stream_storage);
        s_tuner.audio_stream_storage = NULL;
        UI_SetTunerStatus("AUDIO CLAIM FAILED", true);
        return result;
    }
    s_tuner.interface_claimed = true;

    result = set_audio_clock_frequency();
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "Could not set UAC2 clock to 44.1 kHz: %s",
                 esp_err_to_name(result));
        usb_tonex_tuner_deinit();
        UI_SetTunerStatus("CLOCK SET FAILED", true);
        return result;
    }

    result = set_streaming_alternate_setting();
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "Could not enable capture alternate setting: %s",
                 esp_err_to_name(result));
        usb_tonex_tuner_deinit();
        UI_SetTunerStatus("ALT SETTING FAILED", true);
        return result;
    }

    if (!capture_prepare()) {
        usb_tonex_tuner_deinit();
        UI_SetTunerStatus("CAPTURE BUFFER FAILED", true);
        return ESP_ERR_NO_MEM;
    }

    result = allocate_and_submit_transfers();
    if (result != ESP_OK) {
        ESP_LOGE(TAG, "Could not start capture transfers: %s", esp_err_to_name(result));
        usb_tonex_tuner_deinit();
        UI_SetTunerStatus(result == ESP_ERR_NO_MEM
                          ? "USB DMA MEM FAILED"
                          : "AUDIO SUBMIT FAILED", true);
        return result;
    }

    UI_SetTunerStatus("RECORDING USB AUDIO (2S)", false);

    if (xTaskCreatePinnedToCore(tuner_task, "TUNER", TUNER_TASK_STACK_SIZE, NULL,
                                TUNER_TASK_PRIORITY, &s_tuner.tuner_task, 1) != pdPASS) {
        usb_tonex_tuner_deinit();
        UI_SetTunerStatus("TUNER TASK FAILED", true);
        return ESP_ERR_NO_MEM;
    }

    ESP_LOGI(TAG, "UAC2 tuner capture active");
    return ESP_OK;
}

void usb_tonex_tuner_deinit(void)
{
    s_tuner.active = false;

    if (s_capture_state == AUDIO_CAPTURE_RECORDING) {
        portENTER_CRITICAL(&s_capture_lock);
        s_capture_state = AUDIO_CAPTURE_DISABLED;
        portEXIT_CRITICAL(&s_capture_lock);
    }

    if (s_tuner.endpoint_address != 0U && s_tuner.dev_hdl != NULL) {
        usb_host_endpoint_halt(s_tuner.dev_hdl, s_tuner.endpoint_address);
        usb_host_endpoint_flush(s_tuner.dev_hdl, s_tuner.endpoint_address);
    }

    /* Flush completion callbacks are delivered by the owning client's event loop. */
    for (uint32_t wait = 0; wait < 100U && s_tuner.transfers_in_flight > 0U; ++wait) {
        if (s_tuner.client_hdl == NULL) {
            break;
        }
        usb_host_client_handle_events(s_tuner.client_hdl, pdMS_TO_TICKS(1));
    }

    if (s_tuner.tuner_task != NULL) {
        vTaskDelete(s_tuner.tuner_task);
        s_tuner.tuner_task = NULL;
    }

    if (s_tuner.interface_claimed && s_tuner.dev_hdl != NULL) {
        usb_host_interface_release(s_tuner.client_hdl, s_tuner.dev_hdl, s_tuner.interface_number);
        s_tuner.interface_claimed = false;
    }

    /* Transfers are normally returned by endpoint flush or device removal. */
    for (uint32_t i = 0; i < USB_TRANSFER_COUNT; ++i) {
        if (s_tuner.transfers[i] != NULL && s_tuner.transfers_in_flight == 0U) {
            usb_host_transfer_free(s_tuner.transfers[i]);
            s_tuner.transfers[i] = NULL;
        }
    }

    if (s_tuner.transfers_in_flight > 0U) {
        ESP_LOGW(TAG, "%lu capture transfers did not return during shutdown",
                 (unsigned long)s_tuner.transfers_in_flight);
    }

    if (s_tuner.audio_stream != NULL) {
        vStreamBufferDelete(s_tuner.audio_stream);
        s_tuner.audio_stream = NULL;
    }
    if (s_tuner.audio_stream_storage != NULL) {
        heap_caps_free(s_tuner.audio_stream_storage);
        s_tuner.audio_stream_storage = NULL;
    }
    if (s_capture_state != AUDIO_CAPTURE_READY) {
        UI_SetTunerResult("--", 0.0f, false, 0U, 0U);
    }
}

bool usb_tonex_tuner_is_active(void)
{
    return s_tuner.active;
}

bool usb_tonex_tuner_is_uac1_capture_device(class_driver_t *driver_obj)
{
    if (driver_obj == NULL || driver_obj->dev_hdl == NULL) {
        return false;
    }

    const usb_config_desc_t *config = NULL;
    tuner_context_t candidate = {0};
    if (usb_host_get_active_config_descriptor(driver_obj->dev_hdl, &config) != ESP_OK ||
        !find_capture_endpoint(config, &candidate)) {
        return false;
    }

    return candidate.audio_protocol == USB_PROTOCOL_UAC1 &&
           candidate.audio_channels == 1U &&
           candidate.audio_subslot_size == 2U &&
           candidate.audio_bit_resolution == 16U &&
           candidate.audio_sample_rate == 48000U;
}

bool usb_tonex_tuner_capture_acquire(usb_tonex_capture_view_t *view)
{
    if (view == NULL) {
        return false;
    }

    portENTER_CRITICAL(&s_capture_lock);
    if (s_capture_state != AUDIO_CAPTURE_READY || s_capture_data == NULL) {
        portEXIT_CRITICAL(&s_capture_lock);
        return false;
    }
    ++s_capture_readers;
    view->data = s_capture_data;
    view->data_size = s_capture_length;
    view->packet_trace = s_capture_packet_trace;
    view->packet_trace_size = s_capture_packet_trace_length;
    view->packet_trace_record_size = AUDIO_CAPTURE_TRACE_RECORD_BYTES;
    view->sample_rate = s_tuner.audio_sample_rate;
    view->channels = s_tuner.audio_channels;
    view->subslot_size = s_tuner.audio_subslot_size;
    view->valid_bits = s_tuner.audio_bit_resolution;
    view->capture_wall_ms = s_capture_wall_ms;
    view->packets_40 = s_capture_packets_40;
    view->packets_48 = s_capture_packets_48;
    view->packets_56 = s_capture_packets_56;
    view->packets_96 = s_capture_packets_96;
    view->packets_352 = s_capture_packets_352;
    view->packets_360 = s_capture_packets_360;
    view->packets_other = s_capture_packets_other;
    view->packets_completed = s_capture_packets_completed;
    view->packets_skipped = s_capture_packets_skipped;
    view->packets_failed = s_capture_packets_failed;
    view->qualifier_status = s_tuner.qualifier_status;
    view->qualifier_length = s_tuner.qualifier_length;
    view->other_speed_status = s_tuner.other_speed_status;
    view->other_speed_length = s_tuner.other_speed_length;
    portEXIT_CRITICAL(&s_capture_lock);
    return true;
}

void usb_tonex_tuner_capture_release(void)
{
    portENTER_CRITICAL(&s_capture_lock);
    if (s_capture_readers > 0U) {
        --s_capture_readers;
    }
    portEXIT_CRITICAL(&s_capture_lock);
}
