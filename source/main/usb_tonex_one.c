/*
 Copyright (C) 2025  Greg Smith

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

//***** Tonex One device *****
//-----------------------------
//idVendor = 0x1963
//idProduct = 0x00D1

//Index  LANGID  String
//0x00   0x0000  0x0409 
//0x01   0x0409  "IK Multimedia"
//0x02   0x0409  "ToneX One"
//0x04   0x0409  "ToneX One Record"
//0x05   0x0409  "ToneX One Playback"
//0x06   0x0409  "ToneX Control VCOM"
//0x09   0x0409  "ToneX One USB Input"
//0x0A   0x0409  "ToneX One USB Output"
//0x0B   0x0409  "ToneX One Internal Clock"
//0x0C   0x0409  "ToneX One In 1"
//0x0D   0x0409  "ToneX One In 2"
//0x10   0x0409  "ToneX One Out 1"
//0x11   0x0409  "ToneX One Out 2"
//0x12   0x0409  "xxxxxxxxxxxxxxxxxxxx"     // Serial Number

//Composite Device.
//- 5 interfaces total
//- Communications Device Class "Tonex Control VCOM"
//- Audio Device Class "Audio Protocol IP version 2.00"

//----------------------------------------------------
//Endpoint 7 is the Control endpoint, using CDC protocol.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/ringbuf.h"
#include "esp_heap_caps.h"
#include "esp_log.h"
#include "usb/usb_host.h"
#include "usb/cdc_acm_host.h"
#include "driver/i2c_master.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "control.h"
#include "display.h"
#include "wifi_config.h"
#include "tonex_params.h"
#include "scenes.h"
#include "nvs.h"

static const char *TAG = "app_TonexOne";

// preset name is proceeded by this byte sequence:
static const uint8_t ToneOnePresetByteMarker[] = {0xB9, 0x04, 0xB9, 0x02, 0xBC, 0x21};

// lengths of preset name and drive character
#define TONEX_ONE_RESP_OFFSET_PRESET_NAME_LEN       32
#define TONEX_ONE_CDC_INTERFACE_INDEX               0

#define MAX_INPUT_BUFFERS                           3

#define MAX_STATE_DATA                              512
#define TONEX_ONE_CDC_RX_TRANSFER_SIZE              4096

#define PROGRESS_SYNC_INIT  "Synchronizing presets"
#define PROGRESS_SYNC_SCENE "Uploading scene presets to Tonex"

#define NVS_FX_DEFAULTS_NAMESPACE "fx_defaults"

// credit to https://github.com/vit3k/tonex_controller for some of the below details and implementation
enum CommsState
{
    COMMS_STATE_IDLE,
    COMMS_STATE_HELLO,
    COMMS_STATE_READY,
    COMMS_STATE_GET_STATE
};

typedef enum Type 
{
    TYPE_UNKNOWN,
    TYPE_STATE_UPDATE,
    TYPE_HELLO,
    TYPE_STATE_PRESET_DETAILS,
    TYPE_STATE_PRESET_DETAILS_FULL,
    TYPE_PARAM_CHANGED
} Type;

typedef enum Slot
{
    A = 0,
    B = 1,
    C = 2
} Slot;


#define TONEX_STATE_OFFSET_START_INPUT_TRIM     15          // 0x000070c1 (-15.0) -> 0x000058c1 (0) -> 0x00007041 (15.0) 
#define TONEX_STATE_OFFSET_START_STOMP_MODE     19          // 0x00 - off, 0x01 - on
#define TONEX_STATE_OFFSET_START_CAB_BYPASS     20          // 0x00 - off, 0x01 - on
#define TONEX_STATE_OFFSET_START_TUNING_MODE    21          // 0x00 - mute, 0x01 - through
#define TONEX_STATE_OFFSET_START_COLORS         22

#define TONEX_STATE_OFFSET_END_BPM              4          
#define TONEX_STATE_OFFSET_END_TEMPO_SOURCE     6           // 00 - GLOBAL, 01 - PRESET 
#define TONEX_STATE_OFFSET_END_DIRECT_MONITOR   7           // 0x00 - off, 0x01 - on 
#define TONEX_STATE_OFFSET_END_TUNING_REF       9           
#define TONEX_STATE_OFFSET_END_CURRENT_SLOT     11           
#define TONEX_STATE_OFFSET_END_BYPASS_MODE      12
#define TONEX_STATE_OFFSET_END_SLOT_C_PRESET    14
#define TONEX_STATE_OFFSET_END_SLOT_B_PRESET    16
#define TONEX_STATE_OFFSET_END_SLOT_A_PRESET    18


typedef struct __attribute__ ((packed)) 
{
    Type type;
    uint16_t size;
    uint16_t unknown;
} tHeader;

typedef struct __attribute__ ((packed)) 
{
    // storage for current pedal state data
    uint8_t StateData[MAX_STATE_DATA]; 
    uint16_t StateDataLength;

    // storage for current preset details data (short version)
    uint8_t PresetData[TONEX_MAX_SHORT_PRESET_DATA];
    uint16_t PresetDataLength;

    // storage for current preset details data (full version)
    uint8_t FullPresetData[TONEX_MAX_FULL_PRESET_DATA];
    uint16_t FullPresetDataLength;
} tPedalData;

typedef struct __attribute__ ((packed)) 
{
    tHeader Header;
    uint8_t SlotAPreset;
    uint8_t SlotBPreset;
    uint8_t SlotCPreset;
    Slot CurrentSlot;
    tPedalData PedalData;
} tTonexMessage;

typedef struct __attribute__ ((packed)) 
{
    tTonexMessage Message;
    uint8_t TonexState;
} tTonexData;

typedef struct
{
    uint8_t Data[TONEX_RX_TEMP_BUFFER_SIZE];
    uint16_t Length;
    uint8_t ReadyToRead : 1;
    uint8_t ReadyToWrite : 1;
} tInputBufferEntry;



/*
** Static vars
*/
static cdc_acm_dev_hdl_t cdc_dev;
static tTonexData* TonexData;
static char preset_name[TONEX_ONE_RESP_OFFSET_PRESET_NAME_LEN + 1];
static uint8_t* TxBuffer;
static uint8_t* FramedBuffer;
static QueueHandle_t input_queue;
static uint8_t boot_init_needed = 0;
static uint8_t boot_global_request = 0;
static uint8_t boot_preset_request = 0;
static uint8_t scene_sync_preset_request = 0;
static bool scene_sync_in_progress = false;
static uint8_t scene_save_preset_request = 0;
static bool scene_save_preset_in_progress = false;
static volatile tInputBufferEntry* InputBuffers;
static float* PresetParamsBuffer;

// One owned upload at a time. HTTP only publishes a buffer; USB alone sends it.
static portMUX_TYPE import_lock = portMUX_INITIALIZER_UNLOCKED;
static uint8_t *import_body;
static size_t import_length;
static uint8_t import_slot;
static bool import_keep_parameters;
static uint32_t import_id;
static TickType_t import_queued_at;
static bool import_ready;
static usb_tonex_one_import_state_t import_state = TONEX_IMPORT_NONE;
static uint8_t *export_body;
static size_t export_length;
static uint8_t export_slot;
static uint32_t export_id;
static TickType_t export_queued_at;
static usb_tonex_one_export_state_t export_state = TONEX_EXPORT_NONE;

typedef struct
{
    const uint8_t *data;
    size_t length;
    size_t offset;
} tPresetImportReader;

static bool import_expect(tPresetImportReader *reader, uint8_t value)
{
    if (reader->offset >= reader->length || reader->data[reader->offset] != value)
        return false;
    reader->offset++;
    return true;
}

static bool import_list(tPresetImportReader *reader, uint8_t tag, uint8_t count)
{
    return import_expect(reader, tag) && import_expect(reader, count);
}

static bool import_blob(tPresetImportReader *reader, size_t count)
{
    if (!import_expect(reader, 0xBC)) return false;
    if (count < 128)
    {
        if (!import_expect(reader, count)) return false;
    }
    else if (!import_expect(reader, 0x81) || !import_expect(reader, count & 255) ||
             !import_expect(reader, count >> 8)) return false;
    if (count > reader->length - reader->offset) return false;
    reader->offset += count;
    return true;
}

static bool import_detail(tPresetImportReader *reader, size_t capacity, bool opaque)
{
    if (!import_list(reader, 0xB9, 2) || !import_blob(reader, capacity)) return false;
    size_t start = reader->offset - capacity;
    if (reader->offset >= reader->length) return false;
    uint8_t length = reader->data[reader->offset++];
    if (length >= capacity) return false;
    // One editor metadata field deliberately has length zero with opaque bytes.
    return opaque ? length == 0 :
        (reader->data[start + length] == 0 && memchr(reader->data + start, 0, length) == NULL);
}

static bool import_floats(tPresetImportReader *reader, uint8_t count)
{
    if (!import_list(reader, 0xBA, count)) return false;
    for (uint8_t i = 0; i < count; i++)
    {
        if (!import_expect(reader, 0x88) || reader->length - reader->offset < sizeof(float)) return false;
        float value;
        memcpy(&value, reader->data + reader->offset, sizeof(value));
        if (!isfinite(value)) return false;
        reader->offset += sizeof(value);
    }
    return true;
}

static bool import_boolean(tPresetImportReader *reader)
{
    if (reader->offset >= reader->length || reader->data[reader->offset] > 1) return false;
    reader->offset++;
    return true;
}

static bool import_asset(tPresetImportReader *reader, bool empty)
{
    if (!import_list(reader, 0xB9, 5) || !import_blob(reader, 16) ||
        !import_detail(reader, 33, false) || reader->offset >= reader->length) return false;
    uint8_t type = reader->data[reader->offset++];
    if (empty ? type != 0 : (type < 1 || type > 4)) return false;
    if (!import_blob(reader, 13768) || !import_list(reader, 0xB9, 9)) return false;
    for (int i = 0; i < 3; i++) if (!import_boolean(reader)) return false;
    return import_detail(reader, 17, false) && import_detail(reader, 17, false) &&
           import_detail(reader, 11, false) && import_detail(reader, 33, true) &&
           import_detail(reader, 65, false) && import_detail(reader, 65, false);
}

static bool import_validate(const uint8_t *data, size_t length)
{
    tPresetImportReader reader = {.data = data, .length = length, .offset = 0};
    if (!import_list(&reader, 0xB9, 3) || !import_expect(&reader, 1) ||
        reader.offset >= length || data[reader.offset++] >= MAX_PRESETS_TONEX_ONE ||
        !import_list(&reader, 0xB9, 4) || !import_list(&reader, 0xB9, 4) ||
        !import_detail(&reader, 33, false) || !import_floats(&reader, 2) ||
        !import_list(&reader, 0xBA, 3)) return false;
    for (int i = 0; i < 3; i++) if (!import_floats(&reader, 109)) return false;
    if (!import_list(&reader, 0xB9, 13) || !import_detail(&reader, 33, false) ||
        !import_detail(&reader, 11, false)) return false;
    for (int i = 0; i < 10; i++) if (!import_detail(&reader, 33, false)) return false;
    if (!import_detail(&reader, 65, false) || !import_asset(&reader, false) ||
        reader.offset >= length) return false;
    uint8_t separate = data[reader.offset];
    return import_boolean(&reader) && import_asset(&reader, separate == 0) && reader.offset == length;
}

static bool usb_tonex_one_supports_txp_transfer(void)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:
            return true;

        default:
            ESP_LOGE(TAG, "TXP transfer requested for unsupported modeller %u",
                     usb_get_connected_modeller_type());
            return false;
    }
}

esp_err_t usb_tonex_one_import_preset(uint8_t *body, size_t length, uint8_t slot,
                                      bool keep_parameters, uint32_t *id)
{
    if (!usb_tonex_one_supports_txp_transfer()) return ESP_ERR_NOT_SUPPORTED;
    if (body == NULL || id == NULL || slot >= MAX_PRESETS_TONEX_ONE ||
        length > TONEX_MAX_FULL_PRESET_DATA - 11 || !import_validate(body, length))
        return ESP_ERR_INVALID_ARG;

    // The HTTP destination is authoritative, never the uploaded body index.
    body[3] = slot;
    TickType_t queued_at = xTaskGetTickCount();
    portENTER_CRITICAL(&import_lock);
    if (!import_ready || import_state == TONEX_IMPORT_QUEUED ||
        import_state == TONEX_IMPORT_WAITING_FOR_PARAMETERS || import_state == TONEX_IMPORT_SENDING ||
        export_state == TONEX_EXPORT_QUEUED || export_state == TONEX_EXPORT_WAITING_FOR_PRESET)
    {
        portEXIT_CRITICAL(&import_lock);
        return ESP_ERR_INVALID_STATE;
    }
    import_body = body;
    import_length = length;
    import_slot = slot;
    import_keep_parameters = keep_parameters;
    if (++import_id == 0) ++import_id;
    *id = import_id;
    import_queued_at = queued_at;
    import_state = TONEX_IMPORT_QUEUED;
    portEXIT_CRITICAL(&import_lock);
    return ESP_OK;
}

usb_tonex_one_import_state_t usb_tonex_one_import_status(uint32_t id)
{
    portENTER_CRITICAL(&import_lock);
    usb_tonex_one_import_state_t state = (id != 0 && id == import_id) ? import_state : TONEX_IMPORT_NONE;
    portEXIT_CRITICAL(&import_lock);
    return state;
}

esp_err_t usb_tonex_one_export_preset(uint8_t slot, uint32_t *id)
{
    if (!usb_tonex_one_supports_txp_transfer()) return ESP_ERR_NOT_SUPPORTED;
    if (id == NULL || slot >= MAX_PRESETS_TONEX_ONE) return ESP_ERR_INVALID_ARG;
    portENTER_CRITICAL(&import_lock);
    if (export_state == TONEX_EXPORT_FAILED) export_state = TONEX_EXPORT_NONE;
    if (!import_ready || export_state != TONEX_EXPORT_NONE ||
        import_state == TONEX_IMPORT_QUEUED || import_state == TONEX_IMPORT_WAITING_FOR_PARAMETERS ||
        import_state == TONEX_IMPORT_SENDING)
    {
        portEXIT_CRITICAL(&import_lock);
        return ESP_ERR_INVALID_STATE;
    }
    export_slot = slot;
    if (++export_id == 0) ++export_id;
    *id = export_id;
    export_queued_at = xTaskGetTickCount();
    export_state = TONEX_EXPORT_QUEUED;
    portEXIT_CRITICAL(&import_lock);
    return ESP_OK;
}

usb_tonex_one_export_state_t usb_tonex_one_export_status(uint32_t id)
{
    portENTER_CRITICAL(&import_lock);
    usb_tonex_one_export_state_t state = (id != 0 && id == export_id) ? export_state : TONEX_EXPORT_NONE;
    portEXIT_CRITICAL(&import_lock);
    return state;
}

esp_err_t usb_tonex_one_export_take(uint32_t id, uint8_t **body, size_t *length)
{
    if (body == NULL || length == NULL) return ESP_ERR_INVALID_ARG;
    portENTER_CRITICAL(&import_lock);
    if (id == 0 || id != export_id || export_state != TONEX_EXPORT_READY)
    {
        portEXIT_CRITICAL(&import_lock);
        return ESP_ERR_INVALID_STATE;
    }
    *body = export_body;
    *length = export_length;
    export_body = NULL;
    export_length = 0;
    export_state = TONEX_EXPORT_NONE;
    portEXIT_CRITICAL(&import_lock);
    return ESP_OK;
}

static void __attribute__((noreturn)) usb_tonex_one_debug_halt(const char *reason, size_t requested_size)
{
    size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);
    size_t largest_block = heap_caps_get_largest_free_block(MALLOC_CAP_SPIRAM);
    size_t free_dma = heap_caps_get_free_size(MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);
    size_t largest_dma_block = heap_caps_get_largest_free_block(MALLOC_CAP_DMA | MALLOC_CAP_INTERNAL);

    ESP_LOGE(TAG, "Diagnostic halt: %s, requested=%u, PSRAM free=%u largest=%u, DMA free=%u largest=%u",
             reason, (unsigned)requested_size, (unsigned)free_psram, (unsigned)largest_block,
             (unsigned)free_dma, (unsigned)largest_dma_block);
    wifi_log_msg("TONEX HALT %s req=%u psram=%u/%u dma=%u/%u",
                 reason, (unsigned)requested_size, (unsigned)free_psram, (unsigned)largest_block,
                 (unsigned)free_dma, (unsigned)largest_dma_block);

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void usb_tonex_one_debug_check(esp_err_t result, const char *operation)
{
    if (result != ESP_OK)
    {
        wifi_log_msg("TONEX init failed: %s: %s", operation, esp_err_to_name(result));
        usb_tonex_one_debug_halt(operation, 0);
    }
}

typedef struct
{
    Clipboard_t type;
    float param1;
    float param2;
    float param3;
    float param4;
    float param5;
    float param6;
    float param7;
    float param8;
    float param9;
} tSettingsClipboard;

static tSettingsClipboard settingsClipboard = {
    .type = CLIPBOARD_NONE
};

/*
** Static function prototypes
*/
static TonexStatus usb_tonex_one_parse(uint8_t* message, uint16_t inlength);
static esp_err_t usb_tonex_one_set_active_slot(Slot newSlot);
static esp_err_t usb_tonex_one_set_preset_in_slot(uint16_t preset, Slot newSlot, uint8_t selectSlot);
static esp_err_t usb_tonex_one_set_ab_slots(uint16_t preset_a, uint16_t preset_b);
static uint16_t usb_tonex_one_get_current_active_preset(void);
static void usb_tonex_one_mark_current_scene_preset_modified(void);
static esp_err_t usb_tonex_one_send_single_parameter(uint16_t index, float value);

static esp_err_t settings_copy(Clipboard_t type, tSettingsClipboard *settings)
{
    tModellerParameter* param_ptr = NULL;

    if (tonex_params_get_locked_access(&param_ptr) != ESP_OK) {
        return ESP_FAIL;
    }

    settings->type = type;

    switch (type) {
        case CLIPBOARD_NONE: {
        } break;

        case CLIPBOARD_GATE: {
            settings->param1 = param_ptr[TONEX_PARAM_NOISE_GATE_THRESHOLD].Value;
            settings->param2 = param_ptr[TONEX_PARAM_NOISE_GATE_RELEASE].Value;
            settings->param3 = param_ptr[TONEX_PARAM_NOISE_GATE_DEPTH].Value;
        } break;

        case CLIPBOARD_COMPRESSOR: {
            settings->param1 = param_ptr[TONEX_PARAM_COMP_THRESHOLD].Value;
            settings->param2 = param_ptr[TONEX_PARAM_COMP_MAKE_UP].Value;
            settings->param3 = param_ptr[TONEX_PARAM_COMP_ATTACK].Value;
        } break;

        case CLIPBOARD_AMP: {
            settings->param1 = param_ptr[TONEX_PARAM_MODEL_GAIN].Value;
            settings->param2 = param_ptr[TONEX_PARAM_MODEL_VOLUME].Value;
            settings->param3 = param_ptr[TONEX_PARAM_MODEX_MIX].Value;
            settings->param4 = param_ptr[TONEX_PARAM_VIR_CABINET_MODEL].Value;
        } break;

        case CLIPBOARD_CAB: {
            settings->param1 = param_ptr[TONEX_PARAM_VIR_CABINET_MODEL].Value;
            settings->param2 = param_ptr[TONEX_PARAM_VIR_RESO].Value;
            settings->param3 = param_ptr[TONEX_PARAM_VIR_MIC_1].Value;
            settings->param4 = param_ptr[TONEX_PARAM_VIR_MIC_1_X].Value;
            settings->param5 = param_ptr[TONEX_PARAM_VIR_MIC_1_Z].Value;
            settings->param6 = param_ptr[TONEX_PARAM_VIR_MIC_2].Value;
            settings->param7 = param_ptr[TONEX_PARAM_VIR_MIC_2_X].Value;
            settings->param8 = param_ptr[TONEX_PARAM_VIR_MIC_2_Z].Value;
            settings->param9 = param_ptr[TONEX_PARAM_VIR_BLEND].Value;
        } break;

        case CLIPBOARD_EQ: {
            settings->param1 = param_ptr[TONEX_PARAM_EQ_BASS].Value;
            settings->param2 = param_ptr[TONEX_PARAM_EQ_BASS_FREQ].Value;
            settings->param3 = param_ptr[TONEX_PARAM_EQ_MID].Value;
            settings->param4 = param_ptr[TONEX_PARAM_EQ_MIDQ].Value;
            settings->param5 = param_ptr[TONEX_PARAM_EQ_MID_FREQ].Value;
            settings->param6 = param_ptr[TONEX_PARAM_EQ_TREBLE].Value;
            settings->param7 = param_ptr[TONEX_PARAM_EQ_TREBLE_FREQ].Value;
            settings->param8 = param_ptr[TONEX_PARAM_MODEL_PRESENCE].Value;
            settings->param9 = param_ptr[TONEX_PARAM_MODEL_DEPTH].Value;
        } break;

        case CLIPBOARD_DELAY: {
            switch ((int)param_ptr[TONEX_PARAM_DELAY_MODEL].Value)
            {
                case TONEX_DELAY_DIGITAL:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_SYNC].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_TS].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_TIME].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_FEEDBACK].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_MODE].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_DELAY_DIGITAL_MIX].Value;
                } break;

                case TONEX_DELAY_TAPE:
                default:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_DELAY_TAPE_SYNC].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_DELAY_TAPE_TS].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_DELAY_TAPE_TIME].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_DELAY_TAPE_FEEDBACK].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_DELAY_TAPE_MODE].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_DELAY_TAPE_MIX].Value;
                } break;
            }
        } break;

        case CLIPBOARD_REVERB: {
            switch ((int)param_ptr[TONEX_PARAM_REVERB_MODEL].Value)
            {
                case TONEX_REVERB_SPRING_1:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_SPRING1_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_SPRING1_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_SPRING1_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_SPRING1_MIX].Value;
                } break;

                case TONEX_REVERB_SPRING_2:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_SPRING2_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_SPRING2_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_SPRING2_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_SPRING2_MIX].Value;
                } break;

                case TONEX_REVERB_SPRING_3:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_SPRING3_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_SPRING3_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_SPRING3_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_SPRING3_MIX].Value;
                } break;

                case TONEX_REVERB_SPRING_4:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_SPRING4_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_SPRING4_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_SPRING4_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_SPRING4_MIX].Value;
                } break;

                case TONEX_REVERB_ROOM:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_ROOM_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_ROOM_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_ROOM_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_ROOM_MIX].Value;
                } break;

                case TONEX_REVERB_PLATE:
                {
                    settings->param1 = param_ptr[TONEX_PARAM_REVERB_PLATE_TIME].Value;
                    settings->param2 = param_ptr[TONEX_PARAM_REVERB_PLATE_PREDELAY].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_REVERB_PLATE_COLOR].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_REVERB_PLATE_MIX].Value;
                } break;
            }
        } break;

        case CLIPBOARD_MODULATION: {
            float model = param_ptr[TONEX_PARAM_MODULATION_MODEL].Value;
            settings->param1 = model;

            switch ((int)model)
            {
                case TONEX_MODULATION_CHORUS: {
                    settings->param2 = param_ptr[TONEX_PARAM_MODULATION_CHORUS_SYNC].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_MODULATION_CHORUS_TS].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_MODULATION_CHORUS_RATE].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_MODULATION_CHORUS_DEPTH].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_MODULATION_CHORUS_LEVEL].Value;
                } break;
                
                case TONEX_MODULATION_TREMOLO: {
                    settings->param2 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_SYNC].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_TS].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_RATE].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_SHAPE].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_SPREAD].Value;
                    settings->param7 = param_ptr[TONEX_PARAM_MODULATION_TREMOLO_LEVEL].Value;
                } break;
                
                case TONEX_MODULATION_PHASER: {
                    settings->param2 = param_ptr[TONEX_PARAM_MODULATION_PHASER_SYNC].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_MODULATION_PHASER_TS].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_MODULATION_PHASER_RATE].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_MODULATION_PHASER_DEPTH].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_MODULATION_PHASER_LEVEL].Value;
                } break;
                
                case TONEX_MODULATION_FLANGER: {
                    settings->param2 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_SYNC].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_TS].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_RATE].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_DEPTH].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_FEEDBACK].Value;
                    settings->param7 = param_ptr[TONEX_PARAM_MODULATION_FLANGER_LEVEL].Value;
                } break;
                
                case TONEX_MODULATION_ROTARY: {
                    settings->param2 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_SYNC].Value;
                    settings->param3 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_TS].Value;
                    settings->param4 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_SPEED].Value;
                    settings->param5 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_RADIUS].Value;
                    settings->param6 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_SPREAD].Value;
                    settings->param7 = param_ptr[TONEX_PARAM_MODULATION_ROTARY_LEVEL].Value;
                } break;
            }
        } break;
    }

    tonex_params_release_locked_access();


    return ESP_OK;
}

static esp_err_t clipboard_paste_param(TonexParameter_t index, float value)
{
    if (tonex_common_modify_parameter(index, value) != ESP_OK)
    {
        return ESP_FAIL;
    }
    if (usb_tonex_one_send_single_parameter(index, value) != ESP_OK)
    {
        return ESP_FAIL;
    }
    return ESP_OK;
}

static esp_err_t settings_paste(const tSettingsClipboard *settings)
{
    if (settings->type == CLIPBOARD_NONE) {
        return ESP_FAIL;
    }

    esp_err_t res = ESP_OK;


    switch (settings->type) {
        case CLIPBOARD_NONE: {
        } break;

        case CLIPBOARD_GATE: {
            res |= clipboard_paste_param(TONEX_PARAM_NOISE_GATE_THRESHOLD, settings->param1);
            res |= clipboard_paste_param(TONEX_PARAM_NOISE_GATE_RELEASE, settings->param2);
            res |= clipboard_paste_param(TONEX_PARAM_NOISE_GATE_DEPTH, settings->param3);
        } break;

        case CLIPBOARD_COMPRESSOR: {
            res |= clipboard_paste_param(TONEX_PARAM_COMP_THRESHOLD, settings->param1);
            res |= clipboard_paste_param(TONEX_PARAM_COMP_MAKE_UP, settings->param2);
            res |= clipboard_paste_param(TONEX_PARAM_COMP_ATTACK, settings->param3);
        } break;

        case CLIPBOARD_AMP: {
            res |= clipboard_paste_param(TONEX_PARAM_MODEL_GAIN, settings->param1);
            res |= clipboard_paste_param(TONEX_PARAM_MODEL_VOLUME, settings->param2);
            res |= clipboard_paste_param(TONEX_PARAM_MODEX_MIX, settings->param3);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_CABINET_MODEL, settings->param4);
        } break;

        case CLIPBOARD_CAB: {
            res |= clipboard_paste_param(TONEX_PARAM_VIR_CABINET_MODEL, settings->param1);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_RESO, settings->param2);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_1, settings->param3);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_1_X, settings->param4);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_1_Z, settings->param5);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_2, settings->param6);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_2_X, settings->param7);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_MIC_2_Z, settings->param8);
            res |= clipboard_paste_param(TONEX_PARAM_VIR_BLEND, settings->param9);
        } break;

        case CLIPBOARD_EQ: {
            res |= clipboard_paste_param(TONEX_PARAM_EQ_BASS, settings->param1);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_BASS_FREQ, settings->param2);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_MID, settings->param3);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_MIDQ, settings->param4);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_MID_FREQ, settings->param5);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_TREBLE, settings->param6);
            res |= clipboard_paste_param(TONEX_PARAM_EQ_TREBLE_FREQ, settings->param7);
            res |= clipboard_paste_param(TONEX_PARAM_MODEL_PRESENCE, settings->param8);
            res |= clipboard_paste_param(TONEX_PARAM_MODEL_DEPTH, settings->param9);
        } break;

        case CLIPBOARD_DELAY: {
            tModellerParameter* param_ptr = NULL;
            if (tonex_params_get_locked_access(&param_ptr) != ESP_OK) {
                return ESP_FAIL;
            }
            int model = (int)param_ptr[TONEX_PARAM_DELAY_MODEL].Value;
            tonex_params_release_locked_access();

            switch (model)
            {
                case TONEX_DELAY_DIGITAL:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_SYNC, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_TS, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_TIME, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_FEEDBACK, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_MODE, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_DIGITAL_MIX, settings->param6);
                } break;

                case TONEX_DELAY_TAPE:
                default:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_SYNC, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_TS, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_TIME, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_FEEDBACK, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_MODE, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_DELAY_TAPE_MIX, settings->param6);
                } break;
            }
        } break;

        case CLIPBOARD_REVERB: {
            tModellerParameter* param_ptr = NULL;
            if (tonex_params_get_locked_access(&param_ptr) != ESP_OK) {
                return ESP_FAIL;
            }
            int model = (int)param_ptr[TONEX_PARAM_REVERB_MODEL].Value;
            tonex_params_release_locked_access();

            switch (model)
            {
                case TONEX_REVERB_SPRING_1:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING1_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING1_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING1_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING1_MIX, settings->param4);
                } break;

                case TONEX_REVERB_SPRING_2:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING2_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING2_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING2_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING2_MIX, settings->param4);
                } break;

                case TONEX_REVERB_SPRING_3:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING3_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING3_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING3_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING3_MIX, settings->param4);
                } break;

                case TONEX_REVERB_SPRING_4:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING4_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING4_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING4_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_SPRING4_MIX, settings->param4);
                } break;

                case TONEX_REVERB_ROOM:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_ROOM_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_ROOM_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_ROOM_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_ROOM_MIX, settings->param4);
                } break;

                case TONEX_REVERB_PLATE:
                default:
                {
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_PLATE_TIME, settings->param1);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_PLATE_PREDELAY, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_PLATE_COLOR, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_REVERB_PLATE_MIX, settings->param4);
                } break;
            }
        } break;

        case CLIPBOARD_MODULATION: {
            res |= clipboard_paste_param(TONEX_PARAM_MODULATION_MODEL, settings->param1);

            switch ((int)settings->param1)
            {
                case TONEX_MODULATION_CHORUS: {
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_CHORUS_SYNC, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_CHORUS_TS, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_CHORUS_RATE, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_CHORUS_DEPTH, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_CHORUS_LEVEL, settings->param6);
                } break;
                
                case TONEX_MODULATION_TREMOLO: {
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_SYNC, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_TS, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_RATE, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_SHAPE, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_SPREAD, settings->param6);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_TREMOLO_LEVEL, settings->param7);
                } break;
                
                case TONEX_MODULATION_PHASER: {
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_PHASER_SYNC, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_PHASER_TS, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_PHASER_RATE, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_PHASER_DEPTH, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_PHASER_LEVEL, settings->param6);
                } break;
                
                case TONEX_MODULATION_FLANGER: {
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_SYNC, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_TS, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_RATE, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_DEPTH, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_FEEDBACK, settings->param6);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_FLANGER_LEVEL, settings->param7);
                } break;
                
                case TONEX_MODULATION_ROTARY: {
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_SYNC, settings->param2);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_TS, settings->param3);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_SPEED, settings->param4);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_RADIUS, settings->param5);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_SPREAD, settings->param6);
                    res |= clipboard_paste_param(TONEX_PARAM_MODULATION_ROTARY_LEVEL, settings->param7);
                } break;
            }
        } break;
    }
    
    return res;
}

// Versioned records are isolated from the scene catalog in the same NVS partition.
static esp_err_t settings_default_key(Clipboard_t type, char *key, size_t size)
{
    if (type <= CLIPBOARD_NONE || type > CLIPBOARD_REVERB)
    {
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t model = 0;
    if (type == CLIPBOARD_DELAY || type == CLIPBOARD_REVERB || type == CLIPBOARD_MODULATION)
    {
        tModellerParameter *params = NULL;
        esp_err_t err = tonex_params_get_locked_access(&params);
        if (err != ESP_OK)
        {
            return err;
        }
        TonexParameter_t index;
        switch (type) {
            case CLIPBOARD_DELAY:  index = TONEX_PARAM_DELAY_MODEL; break;
            case CLIPBOARD_REVERB: index = TONEX_PARAM_REVERB_MODEL; break;
            default:               index = TONEX_PARAM_MODULATION_MODEL; break;
        }
        float value = params[index].Value;
        tonex_params_release_locked_access();

        uint8_t last;
        switch (type) {
            case CLIPBOARD_DELAY:  last = TONEX_DELAY_TAPE; break;
            case CLIPBOARD_REVERB: last = TONEX_REVERB_PLATE; break;
            default:               last = TONEX_MODULATION_ROTARY; break;
        }

        if (!isfinite(value) || value < 0 || value > last || value != floorf(value))
        {
            return ESP_ERR_INVALID_STATE;
        }
        model = (uint8_t)value;
    }
    snprintf(key, size, "set_%u_%u", (uint8_t)type, model);
    return ESP_OK;
}

static esp_err_t settings_default_read(Clipboard_t type, tSettingsClipboard *settings)
{
    char key[16];
    esp_err_t err = settings_default_key(type, key, sizeof(key));
    if (err != ESP_OK)
    {
        return err;
    }
    nvs_handle_t handle;
    err = nvs_open_from_partition(NVS_SCENES_PARTITION, NVS_FX_DEFAULTS_NAMESPACE, NVS_READONLY, &handle);
    if (err != ESP_OK)
    {
        return err;
    }
    size_t size = sizeof(*settings);
    err = nvs_get_blob(handle, key, settings, &size);
    nvs_close(handle);
    if (err == ESP_OK && (size != sizeof(*settings) || settings->type != type))
    {
        err = ESP_ERR_INVALID_SIZE;
    }
    return err;
}

bool usb_tonex_one_has_settings_default(Clipboard_t type)
{
    char key[16];
    esp_err_t err = settings_default_key(type, key, sizeof(key));
    if (err != ESP_OK)
    {
        return false;
    }
    nvs_handle_t handle;
    err = nvs_open_from_partition(NVS_SCENES_PARTITION, NVS_FX_DEFAULTS_NAMESPACE, NVS_READONLY, &handle);
    if (err != ESP_OK)
    {
        return false;
    }
    size_t size = 0;
    err = nvs_get_blob(handle, key, NULL, &size);
    nvs_close(handle);
    return err == ESP_OK && size == sizeof(tSettingsClipboard);
}

static esp_err_t settings_default_save(Clipboard_t type)
{
    char key[16];
    esp_err_t err = settings_default_key(type, key, sizeof(key));
    if (err != ESP_OK)
    {
        return err;
    }
    tSettingsClipboard settings = {0};
    err = settings_copy(type, &settings);
    if (err != ESP_OK)
    {
        return err;
    }
    nvs_handle_t handle;
    err = nvs_open_from_partition(NVS_SCENES_PARTITION, NVS_FX_DEFAULTS_NAMESPACE, NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        return err;
    }
    err = nvs_set_blob(handle, key, &settings, sizeof(settings));
    if (err == ESP_OK)
    {
        err = nvs_commit(handle);
    }
    nvs_close(handle);
    if (err == ESP_OK)
    {
        UI_SettingsCopied(settingsClipboard.type);
    }
    return err;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_hello(void)
{
    uint16_t outlength;
    
    ESP_LOGI(TAG, "Sending Hello");

    uint8_t request[] = {0xb9, 0x03, 0x00, 0x82, 0x04, 0x00, 0x80, 0x0b, 0x01, 0xb9, 0x02, 0x02, 0x0b};

    // add framing
    outlength = tonex_common_add_framing(request, sizeof(request), FramedBuffer);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, outlength, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_request_state(void)
{
    uint16_t outlength;

    uint8_t request[] = {0xb9, 0x03, 0x00, 0x82, 0x06, 0x00, 0x80, 0x0b, 0x03, 0xb9, 0x02, 0x81, 0x06, 0x03, 0x0b};

    // add framing
    outlength = tonex_common_add_framing(request, sizeof(request), FramedBuffer);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, outlength, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t __attribute__((unused)) usb_tonex_one_request_preset_details(uint8_t preset_index, uint8_t full_details)
{
    uint16_t outlength;

    ESP_LOGI(TAG, "Requesting full preset details for %d", (int)preset_index);

    uint8_t request[] = {0xb9, 0x03, 0x81, 0x00, 0x03, 0x82, 0x06, 0x00, 0x80, 0x0b, 0x03, 0xb9, 0x04, 0x0b, 0x01, 0x00,  0x00};  

    request[15] = preset_index;
    request[16] = full_details;     // 0x00 = approx 2k byte summary. 0x01 = approx 30k byte full preset details

    // add framing
    outlength = tonex_common_add_framing(request, sizeof(request), FramedBuffer);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, outlength, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_send_full_preset_data(void)
{
    // Build message, length to 0 for now                                 len LSB  len MSB
    static const uint8_t message[] = {0xb9, 0x03, 0x81, 0x03, 0x03, 0x82, 0,       0,       0x80, 0x0B, 0x03};
    const uint16_t preset_data_length = TonexData->Message.PedalData.FullPresetDataLength;
    const size_t message_length = sizeof(message) + preset_data_length;
    size_t framed_length = 1; // opening frame marker

    if (message_length > TONEX_RX_TEMP_BUFFER_SIZE)
    {
        wifi_log_msg("Full preset message too large: %u", (unsigned)message_length);
        ESP_LOGE(TAG, "Full preset message too large: %u", (unsigned)message_length);
        return ESP_ERR_INVALID_SIZE;
    }

    memcpy(TxBuffer, message, sizeof(message));
    TxBuffer[6] = preset_data_length & 0xFF;
    TxBuffer[7] = (preset_data_length >> 8) & 0xFF;
    memcpy(&TxBuffer[sizeof(message)], TonexData->Message.PedalData.FullPresetData, preset_data_length);

    for (size_t index = 0; index < message_length; index++)
    {
        framed_length += (TxBuffer[index] == 0x7E || TxBuffer[index] == 0x7D) ? 2 : 1;
    }

    uint16_t crc = tonex_common_calculate_CRC(TxBuffer, message_length);
    framed_length += ((crc & 0xFF) == 0x7E || (crc & 0xFF) == 0x7D) ? 2 : 1;
    framed_length += ((crc >> 8) == 0x7E || (crc >> 8) == 0x7D) ? 2 : 1;
    framed_length++; // closing frame marker

    if (framed_length > TONEX_RX_TEMP_BUFFER_SIZE)
    {
        wifi_log_msg("Framed full preset message too large: %u", (unsigned)framed_length);
        ESP_LOGE(TAG, "Framed full preset message too large: %u", (unsigned)framed_length);
        return ESP_ERR_INVALID_SIZE;
    }

    return tonex_common_transmit(cdc_dev, FramedBuffer,
                                 tonex_common_add_framing(TxBuffer, message_length, FramedBuffer),
                                 TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
static bool usb_tonex_one_replace_full_preset_parameters(const float preset_params[TONEX_PARAM_LAST])
{
    static const uint8_t param_start_marker[] = {0xBA, 0x03, 0xBA, 0x6D};
    uint8_t *data = TonexData->Message.PedalData.FullPresetData;
    const uint16_t length = TonexData->Message.PedalData.FullPresetDataLength;
    uint8_t *parameter = memmem(data, length, param_start_marker, sizeof(param_start_marker));

    if (parameter == NULL)
    {
        wifi_log_msg("Full preset parameters marker not found");
        ESP_LOGE(TAG, "Full preset parameters marker not found");
        return false;
    }

    parameter += sizeof(param_start_marker);
    for (uint16_t index = 0; index < TONEX_PARAM_LAST; index++)
    {
        if ((parameter + 1 + sizeof(float)) > (data + length) || *parameter != 0x88)
        {
            wifi_log_msg("Invalid full preset parameter %u", index);
            ESP_LOGE(TAG, "Invalid full preset parameter %u", index);
            return false;
        }

        parameter++;
        memcpy(parameter, &preset_params[index], sizeof(preset_params[index]));
        parameter += sizeof(preset_params[index]);
    }

    return true;
}

static bool usb_tonex_one_copy_full_preset_parameter_banks(uint8_t *destination, size_t destination_length,
                                                            const uint8_t *source, size_t source_length)
{
    static const uint8_t parameter_marker[] = {0xBA, 0x03, 0xBA, 0x6D};
    uint8_t *destination_parameter = memmem(destination, destination_length, parameter_marker,
                                            sizeof(parameter_marker));
    const uint8_t *source_parameter = memmem(source, source_length, parameter_marker,
                                              sizeof(parameter_marker));
    if (destination_parameter == NULL || source_parameter == NULL)
    {
        ESP_LOGE(TAG, "Full preset parameter banks marker not found");
        return false;
    }

    destination_parameter += sizeof(parameter_marker);
    source_parameter += sizeof(parameter_marker);
    for (uint8_t bank = 0; bank < 3; bank++)
    {
        if (bank != 0)
        {
            if ((destination_parameter + 2 > destination + destination_length) ||
                (source_parameter + 2 > source + source_length) ||
                destination_parameter[0] != 0xBA || destination_parameter[1] != 0x6D ||
                source_parameter[0] != 0xBA || source_parameter[1] != 0x6D)
            {
                ESP_LOGE(TAG, "Invalid full preset parameter bank %u", bank);
                return false;
            }
            destination_parameter += 2;
            source_parameter += 2;
        }

        for (uint16_t parameter = 0; parameter < TONEX_PARAM_LAST; parameter++)
        {
            if ((destination_parameter + 1 + sizeof(float) > destination + destination_length) ||
                (source_parameter + 1 + sizeof(float) > source + source_length) ||
                destination_parameter[0] != 0x88 || source_parameter[0] != 0x88)
            {
                ESP_LOGE(TAG, "Invalid full preset parameter %u in bank %u", parameter, bank);
                return false;
            }
            memcpy(destination_parameter + 1, source_parameter + 1, sizeof(float));
            destination_parameter += 1 + sizeof(float);
            source_parameter += 1 + sizeof(float);
        }
    }
    return true;
}

static void usb_tonex_one_send_import(uint8_t *body, size_t body_length, uint8_t slot)
{
    memcpy(TonexData->Message.PedalData.FullPresetData, body, body_length);
    TonexData->Message.PedalData.FullPresetDataLength = body_length;
    esp_err_t result = usb_tonex_one_send_full_preset_data();
    if (result == ESP_OK)
    {
        // Validated body: B9 03 01 slot B9 04 B9 04 B9 02 BC 21 name[33].
        char name[33];
        memcpy(name, body + 12, sizeof(name));
        name[32] = 0;
        control_sync_preset_name(slot, name);
        tScene *scene = scenes_get_current();
        if (scene != NULL) scene->Presets[slot].Modified = true;
        UI_UpdatePresetList();
        if (slot == usb_tonex_one_get_current_active_preset())
            usb_tonex_one_request_preset_details(slot, 0);
    }
    else
    {
        wifi_log_msg("TXP preset transfer failed for slot %u", slot + 1);
    }
    portENTER_CRITICAL(&import_lock);
    import_state = result == ESP_OK ? TONEX_IMPORT_SENT : TONEX_IMPORT_FAILED;
    portEXIT_CRITICAL(&import_lock);
    free(body);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_send_single_parameter(uint16_t index, float value)
{
    uint16_t framed_length;

    // NOTE: only supported in newer Pedal firmware that came with Editor support!

    // Build message                                         len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x09, 0x03, 0x82, 0x0A,     0x00, 0x80, 0x0B, 0x03};

    // payload           unknown                 param index             4 byte float value
    uint8_t payload[] = {0xB9, 0x04, 0x02, 0x00, 0x00,         0x88, 0x00, 0x00, 0x00, 0x00 };

    // set param index
    payload[4] = index;

    // set param value
    memcpy((void*)&payload[6], (void*)&value, sizeof(value));

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));
    memcpy((void*)&TxBuffer[sizeof(message)], (void*)payload, sizeof(payload));

    // add framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message) + sizeof(payload), FramedBuffer);

    // debug
    //ESP_LOG_BUFFER_HEXDUMP(TAG, FramedBuffer, framed_length, ESP_LOG_INFO);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_send_master_volume(float value)
{
    uint16_t framed_length;

    // NOTE: only supported in newer Pedal firmware that came with Editor support!

    // Build message                                         len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x09, 0x03, 0x82, 0x0A,     0x00, 0x80, 0x0B, 0x03};

    // payload           unknown                 param index             4 byte float value
    uint8_t payload[] = {0xB9, 0x04, 0x03, 0x00, 0x00,         0x88, 0x00, 0x00, 0x00, 0x00 };

    // set value
    memcpy((void*)&payload[6], (void*)&value, sizeof(value));

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));
    memcpy((void*)&TxBuffer[sizeof(message)], (void*)payload, sizeof(payload));

    // add framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message) + sizeof(payload), FramedBuffer);

    // debug
    //ESP_LOG_BUFFER_HEXDUMP(TAG, FramedBuffer, framed_length, ESP_LOG_INFO);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_request_master_volume(void)
{
    uint16_t framed_length;

    // NOTE: only supported in newer Pedal firmware that came with Editor support!

    // Build message                                         len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x0D, 0x03, 0x82, 0x05,     0x00, 0x80, 0x0B, 0x03, 0xB9, 0x03, 0x03, 0x00, 0x00 };

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));

    // add framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message), FramedBuffer);

    // debug
    //ESP_LOG_BUFFER_HEXDUMP(TAG, FramedBuffer, framed_length, ESP_LOG_INFO);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_request_tuner(uint8_t state)
{
    uint16_t outlength;

    // WARNING: doesn't work on the One, only on One Plus :(

    //                                                                                                 ! state
    uint8_t request[] = {0xb9, 0x03, 0x81, 0x0F, 0x03, 0x82, 0x03, 0x00, 0x80, 0x19, 0x03, 0xB9, 0x01, 0x00};
    request[13] = state;

    ESP_LOGI(TAG, "Requesting Tuner");

    // add framing
    outlength = tonex_common_add_framing(request, sizeof(request), FramedBuffer);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, outlength, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void __attribute__((unused)) usb_tonex_one_dump_state(void)
{
    float InputTrim;
    float BPM;
    uint16_t TuningRef;

    memcpy((void*)&BPM, (void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BPM], sizeof(float));
    memcpy((void*)&InputTrim, (void*)&TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_INPUT_TRIM], sizeof(float));    
    memcpy((void*)&TuningRef, (void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TUNING_REF], sizeof(uint16_t));

    ESP_LOGI(TAG, "**** Tonex State Data ****");
    ESP_LOGI(TAG, "Input Trim: %3.2f.\t\tStomp Mode: %d", InputTrim, 
                                                          (int)TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_STOMP_MODE]);

    ESP_LOGI(TAG, "Cab Sim Bypass: %d.\t\tTuning Mode: %d", (int)TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_CAB_BYPASS], 
                                                            (int)TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_TUNING_MODE]);

    ESP_LOGI(TAG, "Slot A Preset: %d,\t\tSlot B Preset: %d", (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_A_PRESET], 
                                                             (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_B_PRESET]);

    ESP_LOGI(TAG, "Slot C Preset: %d.\t\tCurrent Slot: %d", (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_C_PRESET], 
                                                            (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_CURRENT_SLOT]);

    ESP_LOGI(TAG, "Tuning Reference: %d.\t\tDirect Monitoring: %d", (int)TuningRef, 
                                                                    (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_DIRECT_MONITOR]);

    ESP_LOGI(TAG, "BPM: %3.2f\t\t\tTempo Source: %d", BPM, (int)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TEMPO_SOURCE]);     
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t __attribute__((unused)) usb_tonex_one_set_active_slot(Slot newSlot)
{
    uint16_t framed_length;

    ESP_LOGI(TAG, "Setting slot %d", (int)newSlot);

    // Build message, length to 0 for now                    len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x06, 0x03, 0x82, 0,       0,       0x80, 0x0b, 0x03};
    
    // set length 
    message[6] = TonexData->Message.PedalData.StateDataLength & 0xFF;
    message[7] = (TonexData->Message.PedalData.StateDataLength >> 8) & 0xFF;

    // save the slot
    TonexData->Message.CurrentSlot = newSlot;

    // modify the buffer with the new slot
    TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_CURRENT_SLOT] = (uint8_t)newSlot;

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));
    memcpy((void*)&TxBuffer[sizeof(message)], (void*)TonexData->Message.PedalData.StateData, TonexData->Message.PedalData.StateDataLength);

    // add framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message) + TonexData->Message.PedalData.StateDataLength, FramedBuffer);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE);    
}


/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_set_preset_in_slot(uint16_t preset, Slot newSlot, uint8_t selectSlot)
{
    uint16_t framed_length;
    
    ESP_LOGI(TAG, "Setting preset %d in slot %d", (int)preset, (int)newSlot);

    // Build message, length to 0 for now                    len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x06, 0x03, 0x82, 0,       0,       0x80, 0x0b, 0x03};
    
    // set length 
    message[6] = TonexData->Message.PedalData.StateDataLength & 0xFF;
    message[7] = (TonexData->Message.PedalData.StateDataLength >> 8) & 0xFF;

    switch (control_get_config_item_int(CONFIG_ITEM_SAVE_PRESET_TO_SLOT))
    {
        // force pedal to A/B or Stomp mode. 0 here = A/B mode, 1 = stomp mode
        // thanks to Riccardo for finding
        case SAVE_PRESET_SLOT_A:
        case SAVE_PRESET_SLOT_B:
        {
            TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_STOMP_MODE] = 0;
        } break;

        case SAVE_PRESET_SLOT_C:
        {
            TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_STOMP_MODE] = 1;
        } break;

        case SAVE_PRESET_SLOT_CURRENT:
        {
            // do nothing
        } break;
    }

    // make sure direct monitoring is on so sound not muted from USB connection
    //Removed now, allowing config from UI. TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_DIRECT_MONITOR] = 1;

    // check if setting same preset twice will set bypass
    if (control_get_config_item_int(CONFIG_ITEM_TOGGLE_BYPASS))
    {
        if (selectSlot && (TonexData->Message.CurrentSlot == newSlot) && (preset == usb_tonex_one_get_current_active_preset()))
        {
            // are we in bypass mode?
            if (TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE] == 1)
            {
                ESP_LOGI(TAG, "Disabling bypass mode");

                // disable bypass mode
                TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE] = 0;
            }
            else
            {
                ESP_LOGI(TAG, "Enabling bypass mode");

                // enable bypass mode
                TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE] = 1;
            }
        }
        else
        {
            // new preset, disable bypass mode to be sure
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE] = 0;
        }
    }

    TonexData->Message.CurrentSlot = newSlot;

  
    // set the preset index into the slot position
    switch (newSlot)
    {
        case A:
        {
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_A_PRESET] = preset;
        } break;

        case B:
        {
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_B_PRESET] = preset;
        } break;

        case C:
        {
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_C_PRESET] = preset;
        } break;
    }

    if (selectSlot)
    {
        // modify the buffer with the new slot
        TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_CURRENT_SLOT] = (uint8_t)newSlot;
    }

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));
    memcpy((void*)&TxBuffer[sizeof(message)], (void*)TonexData->Message.PedalData.StateData, TonexData->Message.PedalData.StateDataLength);

    // do framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message) + TonexData->Message.PedalData.StateDataLength, FramedBuffer);

    //ESP_LOGI(TAG, "State Data after changes - framed");
    //ESP_LOG_BUFFER_HEXDUMP(TAG, FramedBuffer, framed_length, ESP_LOG_INFO);

    // send it
    return tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE);
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
static esp_err_t usb_tonex_one_set_ab_slots(uint16_t preset_a, uint16_t preset_b)
{
    uint16_t framed_length;
    uint16_t len = TonexData->Message.PedalData.StateDataLength;

    ESP_LOGI(TAG, "Setting AB slots. A: %d B: %d (Double mode, Slot A active)", (int)preset_a, (int)preset_b);

    // Build message, length to 0 for now                    len LSB  len MSB
    uint8_t message[] = {0xb9, 0x03, 0x81, 0x06, 0x03, 0x82, 0,       0,       0x80, 0x0b, 0x03};

    // set length
    message[6] = len & 0xFF;
    message[7] = (len >> 8) & 0xFF;

    // force A/B (Double) mode (0 = A/B mode, 1 = stomp mode)
    TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_STOMP_MODE] = 0;

    // make sure direct monitoring is on so sound not muted from USB connection
    // removed now, allowing config from UI. TonexData->Message.PedalData.StateData[len - TONEX_STATE_OFFSET_END_DIRECT_MONITOR] = 1;

    // set both slot presets
    TonexData->Message.PedalData.StateData[len - TONEX_STATE_OFFSET_END_SLOT_A_PRESET] = preset_a;
    TonexData->Message.PedalData.StateData[len - TONEX_STATE_OFFSET_END_SLOT_B_PRESET] = preset_b;

    // make Slot A the active slot
    TonexData->Message.PedalData.StateData[len - TONEX_STATE_OFFSET_END_CURRENT_SLOT] = (uint8_t)A;
    TonexData->Message.CurrentSlot = A;

    // update cached slot presets so the active preset reports correctly
    TonexData->Message.SlotAPreset = preset_a;
    TonexData->Message.SlotBPreset = preset_b;

    // build total message
    memcpy((void*)TxBuffer, (void*)message, sizeof(message));
    memcpy((void*)&TxBuffer[sizeof(message)], (void*)TonexData->Message.PedalData.StateData, len);

    // do framing
    framed_length = tonex_common_add_framing(TxBuffer, sizeof(message) + len, FramedBuffer);

    // send it
    if (tonex_common_transmit(cdc_dev, FramedBuffer, framed_length, TONEX_USB_TX_BUFFER_SIZE) != ESP_OK)
    {
        return ESP_FAIL;
    }

    // refresh the display to show Slot A's preset as active
    return usb_tonex_one_request_preset_details(preset_a, 0);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static bool usb_tonex_one_handle_rx(const uint8_t* data, size_t data_len, void* arg)
{
    tInputBufferEntry *input_buffer = NULL;

    // debug
    //ESP_LOGI(TAG, "CDC Data received %d", (int)data_len);
    //ESP_LOG_BUFFER_HEXDUMP(TAG, data, data_len, ESP_LOG_INFO);

    if ((data_len == 0) || (data_len > TONEX_RX_TEMP_BUFFER_SIZE))
    {
        ESP_LOGE(TAG, "usb_tonex_one_handle_rx data too long! %d", (int)data_len);
        return false;
    }

    // Continue an incomplete frame before taking an unused buffer.
    for (uint8_t loop = 0; loop < MAX_INPUT_BUFFERS; loop++)
    {
        if ((InputBuffers[loop].ReadyToWrite == 0) && (InputBuffers[loop].ReadyToRead == 0))
        {
            input_buffer = (tInputBufferEntry *)&InputBuffers[loop];
            break;
        }
    }

    if (input_buffer == NULL)
    {
        for (uint8_t loop = 0; loop < MAX_INPUT_BUFFERS; loop++)
        {
            if ((InputBuffers[loop].ReadyToWrite == 1) && (InputBuffers[loop].ReadyToRead == 0))
            {
                input_buffer = (tInputBufferEntry *)&InputBuffers[loop];
                input_buffer->Length = 0;
                input_buffer->ReadyToWrite = 0;
                break;
            }
        }
    }

    if (input_buffer == NULL)
    {
        ESP_LOGE(TAG, "usb_tonex_one_handle_rx no available buffers!");
        return false;
    }

    if ((input_buffer->Length + data_len) > TONEX_RX_TEMP_BUFFER_SIZE)
    {
        ESP_LOGE(TAG, "usb_tonex_one_handle_rx frame too long! %u + %u",
                 input_buffer->Length, (unsigned)data_len);
        input_buffer->Length = 0;
        input_buffer->ReadyToWrite = 1;
        return false;
    }

    memcpy(&input_buffer->Data[input_buffer->Length], data, data_len);
    input_buffer->Length += data_len;

    // The TONEX protocol uses 0x7E as its end-of-frame delimiter. Keep the
    // buffer private until the final CDC chunk arrives.
    if (data[data_len - 1] == 0x7E)
    {
        input_buffer->ReadyToRead = 1;
    }

    return true;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_modify_global(uint16_t global_val, float value)
{
    esp_err_t res = ESP_FAIL;

    switch (global_val)
    {
        case TONEX_GLOBAL_BPM:
        {
            // modify the BPM value in state packet
            memcpy((void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BPM], (void*)&value, sizeof(float));
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_INPUT_TRIM:
        {
            // modify the input trim value in state
            memcpy((void*)&TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_INPUT_TRIM], (void*)&value, sizeof(float));
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_CABSIM_BYPASS:
        {
            // modify the cabsim bypass in state
            TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_CAB_BYPASS] = (uint8_t)value;
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_TEMPO_SOURCE:
        {
            // modify the tempo source value in state
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TEMPO_SOURCE] = (uint8_t)value;
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_TUNING_REFERENCE:
        {
            // modify the tuning ref value in state packet
            uint16_t freq = (uint16_t)value;
            memcpy((void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TUNING_REF], (void*)&freq, sizeof(uint16_t));
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_BYPASS:
        {
            // modify bypass in state
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE] = (uint8_t)value;
            res = ESP_OK;
        } break;

        case TONEX_GLOBAL_MASTER_VOLUME:
        {                        
            usb_tonex_one_send_master_volume(value);

            // wait a little
            vTaskDelay(20);

            // read value back to update the UI
            usb_tonex_one_request_master_volume();

            // bit of a hack here. Return fail code, so caller can avoid sending the state data unneccessarily
            res = ESP_FAIL;
        } break;

        case TONEX_GLOBAL_DIRECT_MONITOR:
        {
            // modify the direct monitor value in state
            TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_DIRECT_MONITOR] = (uint8_t)value;
            res = ESP_OK;
        } break;
    }

    return res;
}

static bool usb_tonex_one_color_value_needs_escape(uint8_t value)
{
    static const uint8_t escapedValues[] = {
        0xFF,
        0x9F,
        0xBF,
        0xC7,
        0xA2, 0xA3, 0xA4, 0xA5
    };

    for (uint8_t index = 0; index < sizeof(escapedValues); index++)
    {
        if (escapedValues[index] == value)
        {
            return true;
        }
    }

    return false;
}

static esp_err_t usb_tonex_one_modify_preset_color(uint16_t preset_index, uint32_t color)
{
    uint8_t* state_data = TonexData->Message.PedalData.StateData;
    uint16_t state_length = TonexData->Message.PedalData.StateDataLength;
    uint16_t data_offset = TONEX_STATE_OFFSET_START_COLORS;

    if ((data_offset + 2 > state_length)
     || (state_data[data_offset] != 0xBA)
     || (state_data[data_offset + 1] != MAX_PRESETS_TONEX_ONE)
     || (preset_index >= MAX_PRESETS_TONEX_ONE))
    {
        ESP_LOGE(TAG, "Invalid preset color list or preset index %d", (int)preset_index);
        return ESP_FAIL;
    }

    data_offset += 2; // skip `ba 14` list header

    for (uint16_t current_index = 0; current_index <= preset_index; current_index++)
    {
        if ((data_offset + 2 > state_length)
         || (state_data[data_offset] != 0xB9)
         || (state_data[data_offset + 1] != 0x03))
        {
            ESP_LOGE(TAG, "Invalid color sublist at preset index %d", (int)current_index);
            return ESP_FAIL;
        }

        data_offset += 2; // skip `b9 03` list header
        uint16_t old_color_start = data_offset;

        for (uint8_t component = 0; component < 3; component++)
        {
            if (data_offset >= state_length)
            {
                return ESP_FAIL;
            }

            data_offset += state_data[data_offset] == 0x80 ? 2 : 1;
            if (data_offset > state_length)
            {
                return ESP_FAIL;
            }
        }

        if (current_index == preset_index)
        {
            uint8_t color_values[] = {
                (uint8_t)(color >> 16),
                (uint8_t)(color >> 8),
                (uint8_t)color
            };
            uint8_t encoded_color[6];
            uint8_t encoded_length = 0;

            for (uint8_t component = 0; component < 3; component++)
            {
                if (usb_tonex_one_color_value_needs_escape(color_values[component]))
                {
                    encoded_color[encoded_length++] = 0x80;
                }
                encoded_color[encoded_length++] = color_values[component];
            }

            uint8_t old_length = data_offset - old_color_start;
            uint16_t new_state_length = state_length - old_length + encoded_length;
            if (new_state_length > MAX_STATE_DATA)
            {
                ESP_LOGE(TAG, "Preset color update exceeds state data buffer");
                return ESP_FAIL;
            }

            memmove(&state_data[old_color_start + encoded_length],
                    &state_data[data_offset],
                    state_length - data_offset);
            memcpy(&state_data[old_color_start], encoded_color, encoded_length);
            TonexData->Message.PedalData.StateDataLength = new_state_length;

            return ESP_OK;
        }
    }

    return ESP_FAIL;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static TonexStatus usb_tonex_one_parse_state(uint8_t* unframed, uint16_t length, uint16_t index)
{
    tModellerParameter* param_ptr;

    TonexData->Message.Header.type = TYPE_STATE_UPDATE;

    TonexData->Message.PedalData.StateDataLength = length - index;
    memcpy((void*)TonexData->Message.PedalData.StateData, (void*)&unframed[index], TonexData->Message.PedalData.StateDataLength);
    ESP_LOGI(TAG, "Saved Pedal StateData: %d", TonexData->Message.PedalData.StateDataLength);
    
    // save preset details
    TonexData->Message.SlotAPreset = TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_A_PRESET];
    TonexData->Message.SlotBPreset = TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_B_PRESET];
    TonexData->Message.SlotCPreset = TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_SLOT_C_PRESET];
    TonexData->Message.CurrentSlot = TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_CURRENT_SLOT];
 
    // update global params
    if (tonex_params_get_locked_access(&param_ptr) == ESP_OK)
    {
        memcpy((void*)&param_ptr[TONEX_GLOBAL_BPM].Value, (void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BPM], sizeof(float));
        memcpy((void*)&param_ptr[TONEX_GLOBAL_INPUT_TRIM].Value, (void*)&TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_INPUT_TRIM], sizeof(float));
        param_ptr[TONEX_GLOBAL_CABSIM_BYPASS].Value = (float)TonexData->Message.PedalData.StateData[TONEX_STATE_OFFSET_START_CAB_BYPASS];
        param_ptr[TONEX_GLOBAL_TEMPO_SOURCE].Value = (float)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TEMPO_SOURCE];        
        
        uint16_t freq;
        memcpy((void*)&freq, (void*)&TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_TUNING_REF], sizeof(uint16_t));
        param_ptr[TONEX_GLOBAL_TUNING_REFERENCE].Value = (float)freq;

        param_ptr[TONEX_GLOBAL_BYPASS].Value = (float)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_BYPASS_MODE];

        param_ptr[TONEX_GLOBAL_DIRECT_MONITOR].Value = (float)TonexData->Message.PedalData.StateData[TonexData->Message.PedalData.StateDataLength - TONEX_STATE_OFFSET_END_DIRECT_MONITOR];

        tonex_params_release_locked_access();
    }

    tTonexPresetColor* color_ptr;
    // update preset colors
    if (tonex_params_colors_get_locked_access(&color_ptr) == ESP_OK)
    {
        uint8_t data_offset = TONEX_STATE_OFFSET_START_COLORS;
        data_offset += 2; // skip `ba 14` list header
        for (uint16_t preset_index = 0; preset_index < MAX_PRESETS_TONEX_ONE; preset_index++) {
            data_offset += 2; // skip `b9 03` list header

            color_ptr[preset_index].red = tonex_common_parse_value(TonexData->Message.PedalData.StateData, &data_offset);
            color_ptr[preset_index].green = tonex_common_parse_value(TonexData->Message.PedalData.StateData, &data_offset);
            color_ptr[preset_index].blue = tonex_common_parse_value(TonexData->Message.PedalData.StateData, &data_offset);
        }

        tonex_params_release_locked_access();
    }

    // debug
    //ESP_LOG_BUFFER_HEXDUMP(TAG, TonexData->Message.PedalData.StateData, TonexData->Message.PedalData.StateDataLength, ESP_LOG_INFO);
    //tonex_dump_parameters();
    usb_tonex_one_dump_state();

    ESP_LOGI(TAG, "Slot A: %d. Slot B:%d. Slot C:%d. Current slot: %d", (int)TonexData->Message.SlotAPreset, (int)TonexData->Message.SlotBPreset, (int)TonexData->Message.SlotCPreset, (int)TonexData->Message.CurrentSlot);

    return STATUS_OK;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static TonexStatus usb_tonex_one_parse_preset_details(uint8_t* unframed, uint16_t length, uint16_t index)
{
    TonexData->Message.Header.type = TYPE_STATE_PRESET_DETAILS;

    TonexData->Message.PedalData.PresetDataLength = length - index;
    memcpy((void*)TonexData->Message.PedalData.PresetData, (void*)&unframed[index], TonexData->Message.PedalData.PresetDataLength);
    ESP_LOGI(TAG, "Saved Preset Details: %d", TonexData->Message.PedalData.PresetDataLength);

    // debug
    //ESP_LOGI(TAG, "Preset Data Rx: %d %d", (int)length, (int)index);
    //ESP_LOG_BUFFER_HEXDUMP(TAG, TonexData->Message.PedalData.PresetData, TonexData->Message.PedalData.PresetDataLength, ESP_LOG_INFO);

    return STATUS_OK;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static TonexStatus usb_tonex_one_parse_preset_full_details(uint8_t* unframed, uint16_t length, uint16_t index)
{
    TonexData->Message.Header.type = TYPE_STATE_PRESET_DETAILS_FULL;

    TonexData->Message.PedalData.FullPresetDataLength = length - index;
    if (TonexData->Message.PedalData.FullPresetDataLength > sizeof(TonexData->Message.PedalData.FullPresetData))
    {
        ESP_LOGE(TAG, "Full preset details exceed buffer: %u", TonexData->Message.PedalData.FullPresetDataLength);
        return STATUS_INVALID_FRAME;
    }
    memcpy((void*)TonexData->Message.PedalData.FullPresetData, (void*)&unframed[index], TonexData->Message.PedalData.FullPresetDataLength);
    ESP_LOGI(TAG, "Saved Full Preset Details: %d", TonexData->Message.PedalData.FullPresetDataLength);

    // debug
    //ESP_LOGI(TAG, "Full Preset Data Rx: %d %d", (int)length, (int)index);
    //ESP_LOG_BUFFER_HEXDUMP(TAG, TonexData->Message.PedalData.FullPresetData, TonexData->Message.PedalData.FullPresetDataLength, ESP_LOG_INFO);

    return STATUS_OK;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static TonexStatus usb_tonex_one_parse_param_changed(uint8_t* unframed, uint16_t length, uint16_t index)
{
    uint16_t param_index;
    float value;
    tModellerParameter* param_ptr = NULL;
    uint8_t param_start_marker[] = { 0xB9, 0x04 };
    uint32_t sync_param_index = TONEX_CONTROLLER_LAST;

    if (index >= length)
    {
        ESP_LOGW(TAG, "Param changed missing body");
        return STATUS_OK;
    }

    // try to locate the start of the parameter body
    uint8_t* temp_ptr = memmem((void*)&unframed[index], length - index, (void*)param_start_marker, sizeof(param_start_marker));
    if (temp_ptr != NULL)
    {
        // skip the start marker
        temp_ptr += sizeof(param_start_marker);

        if ((temp_ptr + 8) > (unframed + length))
        {
            ESP_LOGW(TAG, "Param changed message too short");
            return STATUS_OK;
        }

        // next byte is the scope: 0x02 preset, 0x03 global
        uint8_t param_scope = *temp_ptr++;

        // next 2 bytes are the param index
        param_index = ((uint16_t)temp_ptr[0] << 8) | temp_ptr[1];
        temp_ptr += 2;

        // next should be float start marker
        if (*temp_ptr == 0x88)
        {
            // skip it
            temp_ptr++;

            // get the value
            memcpy((void*)&value, (void*)temp_ptr, sizeof(float));

            switch (param_scope)
            {
                case 0x02:
                {
                    if (param_index < TONEX_PARAM_LAST)
                    {
                        TonexData->Message.Header.type = TYPE_PARAM_CHANGED;

                        if (tonex_params_get_locked_access(&param_ptr) == ESP_OK)
                        {
                            param_ptr[param_index].Value = value;
                            tonex_params_release_locked_access();

                            usb_tonex_one_mark_current_scene_preset_modified();
                            sync_param_index = param_index;
                            ESP_LOGI(TAG, "Got preset param: %d raw:%3.2f", (int)param_index, value);
                        }
                    }
                    else
                    {
                        ESP_LOGW(TAG, "Unsupported preset param index: %d", (int)param_index);
                    }
                } break;

                case 0x03:
                {
                    if (param_index == 0x00)
                    {
                        TonexData->Message.Header.type = TYPE_PARAM_CHANGED;

                        // save it
                        if (tonex_params_get_locked_access(&param_ptr) == ESP_OK)
                        {
                            // global volume
                            // Big Tonex uses values -40 to +3, and One uses values from 0 to 10.
                            // Overriding default values
                            param_ptr[TONEX_GLOBAL_MASTER_VOLUME].Min = 0;
                            param_ptr[TONEX_GLOBAL_MASTER_VOLUME].Max = 10;
                            param_ptr[TONEX_GLOBAL_MASTER_VOLUME].Value = value;

                            tonex_params_release_locked_access();

                            sync_param_index = TONEX_GLOBAL_MASTER_VOLUME;
                            ESP_LOGI(TAG, "Got global volume: raw:%3.2f", value);
                        }
                    }
                    else
                    {
                        ESP_LOGW(TAG, "Unsupported global param index: %d", (int)param_index);
                    }
                } break;

                default:
                {
                    ESP_LOGW(TAG, "Unsupported param scope: 0x%02X index: %d", (int)param_scope, (int)param_index);
                } break;
            }

            if (sync_param_index < TONEX_CONTROLLER_LAST)
            {
                // signal to refresh param UI
                UI_RefreshParameterValues();

                // update web UI
                wifi_request_sync(WIFI_SYNC_TYPE_SINGLE_PARAM, &sync_param_index, &value);

                // refresh the footswitch leds
                control_update_footswitch_leds();
            }
        }
        else
        {
            ESP_LOGW(TAG, "Param changed unexpected value marker: %d", (int)*temp_ptr);
        }
    }

    return STATUS_OK;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static uint16_t usb_tonex_one_get_current_active_preset(void)
{
    uint16_t result = 0;

    switch (TonexData->Message.CurrentSlot)
    {
        case A:
        {        
            result = TonexData->Message.SlotAPreset;
        } break;
    
        case B:
        {
            result = TonexData->Message.SlotBPreset;
        } break;
    
        case C:
        default:
        {
            result = TonexData->Message.SlotCPreset;
        } break;
    }
    
    return result;
}

static void usb_tonex_one_mark_current_scene_preset_modified(void)
{
    tScene *scene = scenes_get_current();
    uint16_t preset = usb_tonex_one_get_current_active_preset();

    if ((scene == NULL) || (preset >= MAX_SUPPORTED_PRESETS) || scene->Presets[preset].Modified)
    {
        return;
    }

    scene->Presets[preset].Modified = true;

    char current_preset_name[MAX_PRESET_NAME_LENGTH];
    control_get_current_preset_name(current_preset_name);
    UI_SetPresetLabel(control_get_current_preset_mapped_index(), current_preset_name);
    UI_UpdatePresetList();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static Slot usb_tonex_one_slot_for_saving_preset(void)
{
    Slot slot = C;
    switch (control_get_config_item_int(CONFIG_ITEM_SAVE_PRESET_TO_SLOT))
    {
        case SAVE_PRESET_SLOT_CURRENT:
        {
            slot = TonexData->Message.CurrentSlot;
        } break;

        case SAVE_PRESET_SLOT_A:
        {
            slot = A;
        } break;

        case SAVE_PRESET_SLOT_B:
        {
            slot = B;
        } break;

        case SAVE_PRESET_SLOT_C:
        {
            slot = C;
        } break;
    }

    return slot;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static bool usb_tonex_one_parse_preset_parameters(uint8_t* raw_data, uint16_t length, float *preset_params, bool update_live_params)
{
    uint8_t param_start_marker[] = {0xBA, 0x03, 0xBA, 0x6D}; 
    tModellerParameter* param_ptr = NULL;
    bool parsed = true;

    ESP_LOGI(TAG, "Parsing Preset parameters");

    // try to locate the start of the first parameter block 
    uint8_t* temp_ptr = memmem((void*)raw_data, length, (void*)param_start_marker, sizeof(param_start_marker));
    if (temp_ptr != NULL)
    {
        // skip the start marker
        temp_ptr += sizeof(param_start_marker);

        if (update_live_params && (tonex_params_get_locked_access(&param_ptr) != ESP_OK))
        {
            return false;
        }

        for (uint32_t loop = 0; loop < TONEX_PARAM_LAST; loop++)
        {
            if ((temp_ptr + 1 + sizeof(float)) > (raw_data + length))
            {
                ESP_LOGW(TAG, "Preset parameters end unexpectedly at %d", (int)loop);
                parsed = false;
                break;
            }

            if (*temp_ptr != 0x88)
            {
                ESP_LOGW(TAG, "Unexpected value during Param parse: %d, %d", (int)loop, (int)*temp_ptr);
                parsed = false;
                break;
            }

            temp_ptr++;
            float value;
            memcpy(&value, temp_ptr, sizeof(value));
            if (update_live_params)
            {
                param_ptr[loop].Value = value;
            }
            if (preset_params != NULL)
            {
                preset_params[loop] = value;
            }
            temp_ptr += sizeof(value);
        }

        if (update_live_params)
        {
            tonex_params_release_locked_access();
        }

        if (parsed)
        {
            ESP_LOGI(TAG, "Parsing Preset parameters complete");
            return true;
        }
    }
    else
    {
        ESP_LOGW(TAG, "Parsing Preset parameters failed to find start marker");
    }

    return false;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static TonexStatus usb_tonex_one_parse(uint8_t* message, uint16_t inlength)
{
    uint16_t out_len = 0;

    TonexStatus status = tonex_common_remove_framing(message, inlength, FramedBuffer, &out_len);

    if (status != STATUS_OK)
    {
        ESP_LOGE(TAG, "Remove framing failed");
        return STATUS_INVALID_FRAME;
    }
    
    if (out_len < 5)
    {
        ESP_LOGE(TAG, "Message too short");
        return STATUS_INVALID_FRAME;
    }
    
    if ((FramedBuffer[0] != 0xB9) || (FramedBuffer[1] != 0x03))
    {
        ESP_LOGE(TAG, "Invalid header");
        return STATUS_INVALID_FRAME;
    }
    
    tHeader header;
    uint8_t index = 2;
    uint16_t type = tonex_common_parse_value(FramedBuffer, &index);

    switch (type)
    {
        case 0x0306:
        {
            header.type = TYPE_STATE_UPDATE;
        } break;

        case 0x0304:
        {
            // preset details summary
            header.type = TYPE_STATE_PRESET_DETAILS;
        } break;

        case 0x0303:
        {
            // preset details in full
            header.type = TYPE_STATE_PRESET_DETAILS_FULL;
        } break;

        case 0x02:
        {
            header.type = TYPE_HELLO;
        } break;

        case 0x0309:
        {           
            header.type = TYPE_PARAM_CHANGED;
        } break;

        default:
        {
            ESP_LOGI(TAG, "Unknown type %d", (int)type);
            header.type = TYPE_UNKNOWN;
        } break;
    };
    
    header.size = tonex_common_parse_value(FramedBuffer, &index);
    header.unknown = tonex_common_parse_value(FramedBuffer, &index);

    ESP_LOGI(TAG, "usb_tonex_one_parse: type: %d size: %d", (int)header.type, (int)header.size);

    if ((out_len - index) != header.size)
    {
        ESP_LOGE(TAG, "Invalid message size");
        return STATUS_INVALID_FRAME;
    }

    // make sure we don't trip the task watchdog
    vTaskDelay(pdMS_TO_TICKS(5));

    // check message type
    switch (header.type)
    {
        case TYPE_HELLO:
        {
            ESP_LOGI(TAG, "Hello response");
            memcpy((void*)&TonexData->Message.Header,  (void*)&header, sizeof(header));        
            return STATUS_OK;
        }

        case TYPE_STATE_UPDATE:
        {
            return usb_tonex_one_parse_state(FramedBuffer, out_len, index);
        }
        
        case TYPE_STATE_PRESET_DETAILS:
        {
            return usb_tonex_one_parse_preset_details(FramedBuffer, out_len, index);
        }

        case TYPE_STATE_PRESET_DETAILS_FULL:
        {
            return usb_tonex_one_parse_preset_full_details(FramedBuffer, out_len, index);
        }

        case TYPE_PARAM_CHANGED:
        {
            return usb_tonex_one_parse_param_changed(FramedBuffer, out_len, index);
        } break;

        default:
        {
            ESP_LOGI(TAG, "Unknown structure. Skipping.");            
            memcpy((void*)&TonexData->Message.Header, (void*)&header, sizeof(header));
            return STATUS_OK;
        }
    };
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static esp_err_t usb_tonex_one_process_single_message(uint8_t* data, uint16_t length)
{
    void* temp_ptr;  
    uint16_t current_preset;

    // check if we got a complete message(s)
    if ((length >= 2) && (data[0] == 0x7E) && (data[length - 1] == 0x7E))
    {
        ESP_LOGI(TAG, "Processing messages len: %d", (int)length);
        TonexStatus status = usb_tonex_one_parse(data, length);

        if (status != STATUS_OK)
        {
            ESP_LOGE(TAG, "Error parsing message: %d", (int)status);
        }
        else
        {
            ESP_LOGI(TAG, "Message Header type: %d", (int)TonexData->Message.Header.type);

            // check what we got
            switch (TonexData->Message.Header.type)
            {
                case TYPE_STATE_UPDATE:
                {
                    current_preset = usb_tonex_one_get_current_active_preset();
                    ESP_LOGI(TAG, "Received State Update. Current slot: %d. Preset: %d", (int)TonexData->Message.CurrentSlot, (int)current_preset);
                    
                    // debug
                    //ESP_LOG_BUFFER_HEXDUMP(TAG, data, length, ESP_LOG_INFO);

                    TonexData->TonexState = COMMS_STATE_READY;   

                    if (boot_init_needed)
                    {
                        // start getting preset names
                        usb_tonex_one_request_preset_details(boot_preset_request, 0);
                        boot_init_needed = 0;
                    }
                    else
                    {
                        // if we have messages waiting in the queue, it will trigger another
                        // change that will overwrite this one. Skip the UI refresh to save time
                        if (uxQueueMessagesWaiting(input_queue) == 0)
                        {
                            // signal to refresh param UI with Globals
                            UI_RefreshParameterValues();

                            // update web UI
                            wifi_request_sync(WIFI_SYNC_TYPE_PARAMS, NULL, NULL);
                                                     
                            // refresh the footswitch leds
                            control_update_footswitch_leds();
                        }
                    }
                } break;

                case TYPE_STATE_PRESET_DETAILS:
                {
                    // UI_Log_Delay("PARTIAL %d %d", scene_sync_in_progress, scene_sync_preset_request);

                    // locate the ToneOnePresetByteMarker[] to get preset name
                    temp_ptr = memmem((void*)data, length, (void*)ToneOnePresetByteMarker, sizeof(ToneOnePresetByteMarker));
                    if (temp_ptr != NULL)
                    {
                        ESP_LOGI(TAG, "Got preset name");

                        // grab name
                        memcpy((void*)preset_name, (void*)(temp_ptr + sizeof(ToneOnePresetByteMarker)), TONEX_ONE_RESP_OFFSET_PRESET_NAME_LEN);                
                    }

                    current_preset = usb_tonex_one_get_current_active_preset();

                    if (scene_save_preset_in_progress)
                    {
                        scene_save_preset_in_progress = false;

                        if (usb_tonex_one_parse_preset_parameters(data, length, PresetParamsBuffer, false) &&
                            (scenes_save_preset_params(scene_save_preset_request, PresetParamsBuffer) == ESP_OK))
                        {
                            char current_preset_name[MAX_PRESET_NAME_LENGTH];
                            control_get_current_preset_name(current_preset_name);
                            UI_SetPresetLabel(control_get_current_preset_mapped_index(), current_preset_name);
                            UI_UpdatePresetList();
                        }
                        else
                        {
                            ESP_LOGE(TAG, "Failed to save scene preset %u", scene_save_preset_request);
                        }
                    }
                    else if (boot_preset_request < MAX_PRESETS_TONEX_ONE)
                    {
                        if (usb_tonex_one_parse_preset_parameters(data, length, PresetParamsBuffer, true))
                        {
                            tScene *scene = scenes_get_current();
                            if (scene != NULL)
                            {
                                uint32_t preset_hash = scenes_hash_preset_params(PresetParamsBuffer);
                                scene->Presets[boot_preset_request].Modified =
                                    (preset_hash != scene->Presets[boot_preset_request].PresetParamsHash);
                            }
                        }

                        // save preset name 
                        control_sync_preset_name(boot_preset_request, preset_name);

                        UI_SetProgressBar(((boot_preset_request + 1) * 100) / MAX_PRESETS_TONEX_ONE, PROGRESS_SYNC_INIT);

                        // get next preset name
                        boot_preset_request++;
                        usb_tonex_one_request_preset_details(boot_preset_request, 0);
                    } 
                    else if (boot_preset_request == MAX_PRESETS_TONEX_ONE) 
                    {
                        // all other preset nammes grabbed, get current preset details
                        boot_preset_request++;
                        usb_tonex_one_request_preset_details(current_preset, 0);
                    } 
                    else 
                    {
                        ESP_LOGI(TAG, "Received State Update. Current slot: %d. Preset: %d", (int)TonexData->Message.CurrentSlot, (int)current_preset);
                        
                        // make sure we are showing the correct preset as active                
                        control_sync_preset_details(current_preset, preset_name);

                        // read the preset params
                        usb_tonex_one_parse_preset_parameters(data, length, NULL, true);

                        // if we have messages waiting in the queue, it will trigger another
                        // change that will overwrite this one. Skip the UI refresh to save time
                        if (uxQueueMessagesWaiting(input_queue) == 0)
                        {
                            // signal to refresh param UI
                            UI_RefreshParameterValues();

                            // update web UI
                            wifi_request_sync(WIFI_SYNC_TYPE_PARAMS, NULL, NULL);
                                                     
                            // refresh the footswitch leds
                            control_update_footswitch_leds();
                        }

                        if (boot_global_request)
                        {
                            // request global volume
                            usb_tonex_one_request_master_volume();

                            boot_global_request = 0;
                        }

                        control_set_sync_complete();

                        if (!scene_sync_in_progress) {
                            UI_HideProgressBar();
                        }
                        
                        // debug dump parameters
                        //tonex_dump_parameters();
                    }
                } break;

                case TYPE_HELLO:
                {
                    ESP_LOGI(TAG, "Received Hello");

                    // get current state
                    usb_tonex_one_request_state();
                    TonexData->TonexState = COMMS_STATE_GET_STATE;

                    // flag that we need to do the boot init procedure
                    boot_init_needed = 1;
                    boot_global_request = 1;
                    boot_preset_request = 0;

                    UI_SetProgressBar(0, PROGRESS_SYNC_INIT);

#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
                    // show sync message
                    UI_SetPresetLabel(0, "Syncing....");
#endif
                } break;

                case TYPE_STATE_PRESET_DETAILS_FULL:
                {
                    // UI_Log_Delay("FULL %d %d", scene_sync_in_progress, scene_sync_preset_request);
                    ESP_LOGI(TAG, "Received Preset details full");

                    uint8_t *imported_body = NULL;
                    size_t imported_length = 0;
                    uint8_t imported_slot = 0;
                    portENTER_CRITICAL(&import_lock);
                    if (import_state == TONEX_IMPORT_WAITING_FOR_PARAMETERS)
                    {
                        imported_body = import_body;
                        imported_length = import_length;
                        imported_slot = import_slot;
                        import_body = NULL;
                        import_state = TONEX_IMPORT_SENDING;
                    }
                    portEXIT_CRITICAL(&import_lock);

                    if (imported_body != NULL)
                    {
                        if (usb_tonex_one_copy_full_preset_parameter_banks(
                                imported_body, imported_length,
                                TonexData->Message.PedalData.FullPresetData,
                                TonexData->Message.PedalData.FullPresetDataLength))
                        {
                            usb_tonex_one_send_import(imported_body, imported_length, imported_slot);
                        }
                        else
                        {
                            ESP_LOGE(TAG, "Failed to preserve parameters for TXP import slot %u", imported_slot);
                            portENTER_CRITICAL(&import_lock);
                            import_state = TONEX_IMPORT_FAILED;
                            portEXIT_CRITICAL(&import_lock);
                            free(imported_body);
                        }
                    }
                    else
                    {
                        bool exporting = false;
                        portENTER_CRITICAL(&import_lock);
                        if (export_state == TONEX_EXPORT_WAITING_FOR_PRESET)
                            exporting = true;
                        portEXIT_CRITICAL(&import_lock);
                        if (exporting)
                        {
                            uint8_t *body = heap_caps_malloc(
                                TonexData->Message.PedalData.FullPresetDataLength,
                                MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
                            if (body == NULL) body = malloc(TonexData->Message.PedalData.FullPresetDataLength);
                            if (body != NULL)
                            {
                                memcpy(body, TonexData->Message.PedalData.FullPresetData,
                                       TonexData->Message.PedalData.FullPresetDataLength);
                            }
                            portENTER_CRITICAL(&import_lock);
                            if (body != NULL)
                            {
                                export_body = body;
                                export_length = TonexData->Message.PedalData.FullPresetDataLength;
                                export_state = TONEX_EXPORT_READY;
                            }
                            else
                            {
                                export_state = TONEX_EXPORT_FAILED;
                            }
                            portEXIT_CRITICAL(&import_lock);
                        }
                        else if (scene_sync_in_progress)
                        {
                            tScene *scene = scenes_get_current();

                            if ((scene == NULL) ||
                                !usb_tonex_one_replace_full_preset_parameters(
                                    scene->Presets[scene_sync_preset_request].PresetParams) ||
                                (usb_tonex_one_send_full_preset_data() != ESP_OK))
                            {
                                wifi_log_msg("Failed to apply scene preset %u", scene_sync_preset_request);
                                ESP_LOGE(TAG, "Failed to apply scene preset %u", scene_sync_preset_request);
                                scene_sync_in_progress = false;
                                UI_HideProgressBar();
                                break;
                            }

                            scene->Presets[scene_sync_preset_request].Modified = false;

                            scene_sync_preset_request++;
                            UI_SetProgressBar((scene_sync_preset_request * 100) / MAX_PRESETS_TONEX_ONE, PROGRESS_SYNC_SCENE);

                            if (scene_sync_preset_request < MAX_PRESETS_TONEX_ONE)
                            {
                                if (usb_tonex_one_request_preset_details(scene_sync_preset_request, 1) != ESP_OK)
                                {
                                    ESP_LOGE(TAG, "Failed to request scene preset %u", scene_sync_preset_request);
                                    wifi_log_msg("Failed to request scene preset %u", scene_sync_preset_request);
                                    scene_sync_in_progress = false;
                                    UI_HideProgressBar();
                                }
                            }
                            else
                            {
                                char current_preset_name[MAX_PRESET_NAME_LENGTH];
                                scene_sync_in_progress = false;
                                control_get_current_preset_name(current_preset_name);
                                UI_SetPresetLabel(control_get_current_preset_mapped_index(), current_preset_name);
                                UI_UpdatePresetList();
                                UI_HideProgressBar();

                                // Refresh the active preset from TONEX after all full preset
                                // updates have been applied. This updates the live parameters and
                                // all dependent UI from the pedal's response.
                                // current_preset = usb_tonex_one_get_current_active_preset();
                                // if (usb_tonex_one_request_preset_details(current_preset, 0) != ESP_OK)
                                // {
                                //     wifi_log_msg("Failed to refresh active preset after scene sync");
                                //     ESP_LOGE(TAG, "Failed to refresh active preset after scene sync");
                                //     UI_HideProgressBar();
                                // }
                            }
                        }
                    }
                } break;

                case TYPE_PARAM_CHANGED:
                {
                    // handled by usb_tonex_one_parse_param_changed()
                } break;

                default:
                {
                    ESP_LOGI(TAG, "Message unknown %d", (int)TonexData->Message.Header.type);
                } break;
            }
        }

        return ESP_OK;
    }
    else
    {
        ESP_LOGW(TAG, "Missing start or end bytes. %d, %d, %d", (int)length, (int)data[0], (int)data[length - 1]);
        //ESP_LOG_BUFFER_HEXDUMP(TAG, data, length, ESP_LOG_INFO);
        return ESP_FAIL;
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void usb_tonex_one_handle(class_driver_t* driver_obj)
{        
    tUSBMessage message;
    tUSBMessage next_message;

    bool can_import = TonexData->TonexState == COMMS_STATE_READY &&
        boot_preset_request > MAX_PRESETS_TONEX_ONE && control_get_sync_complete() &&
        !scene_save_preset_in_progress && !scene_sync_in_progress &&
        uxQueueMessagesWaiting(input_queue) == 0;
    uint8_t *body = NULL;
    size_t body_length = 0;
    uint8_t slot = 0;
    bool import_expired = false;
    bool request_import_parameters = false;
    bool request_export_preset = false;
    uint8_t requested_export_slot = 0;
    TickType_t now = xTaskGetTickCount();
    portENTER_CRITICAL(&import_lock);
    import_ready = can_import;
    if (import_state == TONEX_IMPORT_QUEUED || import_state == TONEX_IMPORT_WAITING_FOR_PARAMETERS)
    {
        import_expired = (now - import_queued_at) > pdMS_TO_TICKS(10000);
        if (import_state == TONEX_IMPORT_QUEUED && can_import && import_keep_parameters)
        {
            request_import_parameters = true;
            slot = import_slot;
            import_state = TONEX_IMPORT_WAITING_FOR_PARAMETERS;
        }
        else if ((import_state == TONEX_IMPORT_QUEUED && can_import) || import_expired)
        {
            body = import_body;
            body_length = import_length;
            slot = import_slot;
            import_body = NULL;
            import_state = import_expired ? TONEX_IMPORT_FAILED : TONEX_IMPORT_SENDING;
        }
    }
    if (export_state == TONEX_EXPORT_QUEUED || export_state == TONEX_EXPORT_WAITING_FOR_PRESET)
    {
        if ((now - export_queued_at) > pdMS_TO_TICKS(10000))
        {
            export_state = TONEX_EXPORT_FAILED;
        }
        else if (export_state == TONEX_EXPORT_QUEUED && can_import)
        {
            requested_export_slot = export_slot;
            export_state = TONEX_EXPORT_WAITING_FOR_PRESET;
            request_export_preset = true;
        }
    }
    portEXIT_CRITICAL(&import_lock);
    const bool handled_import = body != NULL || request_import_parameters || request_export_preset;
    if (request_import_parameters && usb_tonex_one_request_preset_details(slot, 1) != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to request current parameters for TXP import slot %u", slot);
        portENTER_CRITICAL(&import_lock);
        body = import_body;
        import_body = NULL;
        import_state = TONEX_IMPORT_FAILED;
        portEXIT_CRITICAL(&import_lock);
        free(body);
    }
    if (request_export_preset && usb_tonex_one_request_preset_details(requested_export_slot, 1) != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to request preset export slot %u", requested_export_slot);
        portENTER_CRITICAL(&import_lock);
        export_state = TONEX_EXPORT_FAILED;
        portEXIT_CRITICAL(&import_lock);
    }
    if (handled_import)
    {
        if (!import_expired)
        {
            if (body != NULL)
                usb_tonex_one_send_import(body, body_length, slot);
        }
        else
            free(body);
    }

    // check state
    switch (TonexData->TonexState)
    {
        case COMMS_STATE_IDLE:
        default:
        {
            // do the hello 
            if (usb_tonex_one_hello() == ESP_OK)
            {
                TonexData->TonexState = COMMS_STATE_HELLO;
            }
            else
            {
                ESP_LOGI(TAG, "Send Hello failed");
            }
        } break;

        case COMMS_STATE_HELLO:
        {
            // waiting for response to arrive
        } break;

        case COMMS_STATE_READY:
        {
            // check for any input messages
            if (!handled_import && !scene_save_preset_in_progress && !scene_sync_in_progress &&
                (xQueueReceive(input_queue, (void*)&message, 0) == pdPASS))
            {
                ESP_LOGI(TAG, "Got Input message: %d. Queue: %d", message.Command, uxQueueMessagesWaiting(input_queue));

                // check if the next commands in the input queue would change the same item as this message.
                // if so, no point in processing as it will be overwritten shortly.
                while (uxQueueMessagesWaiting(input_queue) != 0)
                {
                    // get a copy of the next message without removing it from the queue
                    if (xQueuePeek(input_queue, (void*)&next_message, 0) == pdPASS)
                    {
                        // check what it is
                        if (((next_message.Command == USB_COMMAND_MODIFY_PARAMETER) && (next_message.Payload == message.Payload))
                          || (next_message.Command == USB_COMMAND_SET_PRESET)) 
                        {
                            // don't send the current mesage. Instead, receive this next one properly and pull it off the queue
                            // so it can be processed (or overwritten again by another message in the queue still)
                            xQueueReceive(input_queue, (void*)&message, 0);

                            // debug
                            //ESP_LOGW(TAG, "Input message consumed");
                        }
                        else
                        {
                            // this next message is not the same, exit loop and send it
                            break;
                        }
                    }
                    else
                    {
                        // something went wrong with the Peek, don't get stuck in loop
                        break;
                    }
                }

                // process it
                switch (message.Command)
                {
                    case USB_COMMAND_SET_PRESET:
                    {
                        if (message.Payload < MAX_PRESETS_TONEX_ONE)
                        {
                            if (usb_tonex_one_set_preset_in_slot(message.Payload, usb_tonex_one_slot_for_saving_preset(), 1) != ESP_OK)
                            {
                                // failed return to queue?
                            }
                        }
                    } break;
                    
                    case USB_COMMAND_LOAD_PRESET_TO_SLOT_A:
                    {
                        if (message.Payload < MAX_PRESETS_TONEX_ONE)
                        {
                            ESP_LOGI(TAG, "Loading preset %d to Slot A via MIDI CC 120", (int)message.Payload);
                            if (usb_tonex_one_set_preset_in_slot(message.Payload, A, 0) != ESP_OK)
                            {
                                ESP_LOGE(TAG, "Failed to load preset %d to Slot A", (int)message.Payload);
                            }
                        }
                        else
                        {
                            ESP_LOGW(TAG, "Invalid preset index %d for Slot A (max %d)", (int)message.Payload, MAX_PRESETS_TONEX_ONE - 1);
                        }
                    } break;
                    
                    case USB_COMMAND_LOAD_PRESET_TO_SLOT_B:
                    {
                        if (message.Payload < MAX_PRESETS_TONEX_ONE)
                        {
                            ESP_LOGI(TAG, "Loading preset %d to Slot B via MIDI CC 121", (int)message.Payload);
                            if (usb_tonex_one_set_preset_in_slot(message.Payload, B, 0) != ESP_OK)
                            {
                                ESP_LOGE(TAG, "Failed to load preset %d to Slot B", (int)message.Payload);
                            }
                        }
                        else
                        {
                            ESP_LOGW(TAG, "Invalid preset index %d for Slot B (max %d)", (int)message.Payload, MAX_PRESETS_TONEX_ONE - 1);
                        }
                    } break;   
                    
                    case USB_COMMAND_SET_AB_SLOTS:
                    {
                        uint16_t preset_a = (message.Payload >> 8) & 0xFF;
                        uint16_t preset_b = message.Payload & 0xFF;

                        if ((preset_a < MAX_PRESETS_TONEX_ONE) && (preset_b < MAX_PRESETS_TONEX_ONE))
                        {
                            ESP_LOGI(TAG, "Set AB slots via MIDI. A: %d B: %d", (int)preset_a, (int)preset_b);
                            if (usb_tonex_one_set_ab_slots(preset_a, preset_b) != ESP_OK)
                            {
                                ESP_LOGE(TAG, "Failed to set AB slots A:%d B:%d", (int)preset_a, (int)preset_b);
                            }
                        }
                        else
                        {
                            ESP_LOGW(TAG, "Invalid AB slot presets A:%d B:%d (max %d)", (int)preset_a, (int)preset_b, MAX_PRESETS_TONEX_ONE - 1);
                        }
                    } break;
                    
                    case USB_COMMAND_MODIFY_PARAMETER:
                    {
                        if (message.Payload < TONEX_PARAM_LAST)
                        {
                            // modify the param
                            if (tonex_common_modify_parameter(message.Payload, message.PayloadFloat) == ESP_OK)
                            {
                                usb_tonex_one_mark_current_scene_preset_modified();

                                // send it
                                usb_tonex_one_send_single_parameter(message.Payload, message.PayloadFloat);
                            }
                        }
                        else if (message.Payload < TONEX_GLOBAL_LAST)
                        {
                            // modify the global
                            if (usb_tonex_one_modify_global(message.Payload, message.PayloadFloat) == ESP_OK)
                            {
                                // debug
                                //usb_tonex_one_dump_state(&TonexData->Message.PedalData.TonexStateData);

                                // send it by setting the same preset active again, which sends the state data
                                usb_tonex_one_set_preset_in_slot(usb_tonex_one_get_current_active_preset(), usb_tonex_one_slot_for_saving_preset(), 1);
                            }
                        }
                        else
                        {
                            ESP_LOGW(TAG, "Attempt to modify unknown param %d", (int)message.Payload);
                        }
                    } break;

                    case USB_COMMAND_SAVE_PRESET:
                    {
                        // Tonex One uses auto save, nothing needed
                    } break;

                    case USB_COMMAND_SET_COLOR:
                    {
                        if (usb_tonex_one_modify_preset_color(message.Payload, message.Payload1Temp) == ESP_OK)
                        {
                            usb_tonex_one_set_active_slot(TonexData->Message.CurrentSlot);
                        }
                    } break;

                    case USB_COMMAND_COPY_SETTINGS:
                    {
                        if (settings_copy(message.Payload, &settingsClipboard) != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to copy settings");
                        }
                        else UI_SettingsCopied(settingsClipboard.type);
                    } break;

                    case USB_COMMAND_PASTE_SETTINGS:
                    {
                        if (settings_paste(&settingsClipboard) != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to paste settings");
                        }
                    } break;

                    case USB_COMMAND_LOAD_SETTINGS_DEFAULT:
                    {
                        tSettingsClipboard settings;
                        esp_err_t err = settings_default_read(message.Payload, &settings);
                        if (err == ESP_OK)
                        {
                            err = settings_paste(&settings);
                        }
                        if (err != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to load default: %s", esp_err_to_name(err));
                        }
                    } break;

                    case USB_COMMAND_SET_SETTINGS_AS_DEFAULT:
                    {
                        esp_err_t err = settings_default_save(message.Payload);
                        if (err != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to save default: %s", esp_err_to_name(err));
                        }
                    } break;

                    case USB_COMMAND_REQUEST_TUNER:
                    {
                        usb_tonex_one_request_tuner((uint8_t)message.Payload);
                    } break;

                    case USB_COMMAND_SYNC_SCENE_PRESETS:
                    {
                        scene_sync_preset_request = 0;
                        scene_sync_in_progress = true;
                        UI_SetProgressBar(0, PROGRESS_SYNC_SCENE);

                        if (usb_tonex_one_request_preset_details(scene_sync_preset_request, 1) != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to start scene preset sync");
                            scene_sync_in_progress = false;
                            UI_HideProgressBar();
                        }
                    } break;

                    case USB_COMMAND_SAVE_SCENE_PRESET_PARAMS:
                    {
                        if (message.Payload >= MAX_PRESETS_TONEX_ONE)
                        {
                            ESP_LOGE(TAG, "Invalid scene preset %u", (unsigned)message.Payload);
                            break;
                        }

                        scene_save_preset_request = (uint8_t)message.Payload;
                        scene_save_preset_in_progress = true;
                        if (usb_tonex_one_request_preset_details(scene_save_preset_request, 0) != ESP_OK)
                        {
                            ESP_LOGE(TAG, "Failed to request scene preset %u", scene_save_preset_request);
                            scene_save_preset_in_progress = false;
                        }
                    } break;
                }
            }
        } break;

        case COMMS_STATE_GET_STATE:
        {
            // waiting for state data
        } break;
    }

    // check if we have received anything (via RX interrupt)
    for (uint8_t loop = 0; loop < MAX_INPUT_BUFFERS; loop++)
    {
        if (InputBuffers[loop].ReadyToRead)
        {
            ESP_LOGI(TAG, "Got data via CDC %d", InputBuffers[loop].Length);

            // debug
            //ESP_LOG_BUFFER_HEXDUMP(TAG, InputBuffers[loop].Data, InputBuffers[loop].Length, ESP_LOG_INFO);

            uint16_t end_marker_pos;
            uint16_t bytes_consumed = 0;
            uint8_t* rx_entry_ptr = (uint8_t*)InputBuffers[loop].Data;
            uint16_t rx_entry_length = InputBuffers[loop].Length;

            // process all messages received (may be multiple messages appended)
            do
            {    
                // locate the end of the message
                uint16_t remaining_length = rx_entry_length - bytes_consumed;
                end_marker_pos = tonex_common_locate_message_end(rx_entry_ptr, remaining_length);

                if (end_marker_pos == 0)
                {
                    ESP_LOGW(TAG, "Missing end marker!");
                    //ESP_LOG_BUFFER_HEXDUMP(TAG, rx_entry_ptr, rx_entry_length, ESP_LOG_INFO);
                    break;
                }
                else
                {
                    ESP_LOGI(TAG, "Found end marker: %d", end_marker_pos);
                }

                // debug
                //ESP_LOG_BUFFER_HEXDUMP(TAG, rx_entry_ptr, end_marker_pos + 1, ESP_LOG_INFO);

                // process it
                if (usb_tonex_one_process_single_message(rx_entry_ptr, end_marker_pos + 1) != ESP_OK)
                {
                    break;    
                }
            
                // skip this message
                rx_entry_ptr += (end_marker_pos + 1);
                bytes_consumed += (end_marker_pos + 1);

                //ESP_LOGI(TAG, "After message, pos %d cons %d len %d", (int)end_marker_pos, (int)bytes_consumed, (int)rx_entry_length);
            } while (bytes_consumed < rx_entry_length);

            // set buffer as available       
            InputBuffers[loop].ReadyToRead = 0;
            InputBuffers[loop].ReadyToWrite = 1;   

            vTaskDelay(pdMS_TO_TICKS(2)); 
        } 
    }

    vTaskDelay(pdMS_TO_TICKS(2));
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void usb_tonex_one_init(class_driver_t* driver_obj, QueueHandle_t comms_queue)
{
    // save the queue handle
    input_queue = comms_queue;

    // allocate RX buffers in PSRAM
    InputBuffers = heap_caps_malloc(sizeof(tInputBufferEntry) * MAX_INPUT_BUFFERS, MALLOC_CAP_SPIRAM);
    if (InputBuffers == NULL)
    {
        // ESP_LOGE(TAG, "Failed to allocate input buffers!");
        // return;
        usb_tonex_one_debug_halt("InputBuffers", sizeof(tInputBufferEntry) * MAX_INPUT_BUFFERS);
    }

    PresetParamsBuffer = heap_caps_malloc(sizeof(*PresetParamsBuffer) * TONEX_PARAM_LAST,
                                          MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (PresetParamsBuffer == NULL)
    {
        usb_tonex_one_debug_halt("PresetParamsBuffer", sizeof(*PresetParamsBuffer) * TONEX_PARAM_LAST);
    }

    // set all buffers as ready for writing
    for (uint8_t loop = 0; loop < MAX_INPUT_BUFFERS; loop++)
    {
        memset((void*)InputBuffers[loop].Data, 0, TONEX_RX_TEMP_BUFFER_SIZE);
        InputBuffers[loop].ReadyToWrite = 1;
        InputBuffers[loop].ReadyToRead = 0;
    }

    // more big buffers in PSRAM
    TxBuffer = heap_caps_malloc(TONEX_RX_TEMP_BUFFER_SIZE, MALLOC_CAP_SPIRAM);
    if (TxBuffer == NULL)
    {
        // ESP_LOGE(TAG, "Failed to allocate TxBuffer buffer!");
        // return;
        usb_tonex_one_debug_halt("TxBuffer", TONEX_RX_TEMP_BUFFER_SIZE);
    }
    
    FramedBuffer = heap_caps_malloc(TONEX_RX_TEMP_BUFFER_SIZE, MALLOC_CAP_SPIRAM);
    if (FramedBuffer == NULL)
    {
        // ESP_LOGE(TAG, "Failed to allocate FramedBuffer buffer!");
        // return;
        usb_tonex_one_debug_halt("FramedBuffer", TONEX_RX_TEMP_BUFFER_SIZE);
    }

    TonexData = heap_caps_malloc(sizeof(tTonexData), MALLOC_CAP_SPIRAM);
    if (TonexData == NULL)
    {
        // ESP_LOGE(TAG, "Failed to allocate TonexData buffer!");
        // return;
        usb_tonex_one_debug_halt("TonexData", sizeof(tTonexData));
    }

    memset((void*)TonexData, 0, sizeof(tTonexData));
    TonexData->TonexState = COMMS_STATE_IDLE;
    scene_sync_preset_request = 0;
    scene_sync_in_progress = false;
    scene_save_preset_request = 0;
    scene_save_preset_in_progress = false;

    // code from ESP support forums, work around start. Refer to https://www.esp32.com/viewtopic.php?t=30601
    // Relates to this:
    // 
    // Endpoint Descriptor:
    // ------------------------------
    // 0x07	bLength
    // 0x05	bDescriptorType
    // 0x87	bEndpointAddress  (IN endpoint 7)
    // 0x02	bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data)
    // 0x0040	wMaxPacketSize    (64 bytes)
    // 0x00	bInterval         
    // *** ERROR: Invalid wMaxPacketSize. Must be 512 bytes in high speed mode.

    //Endpoint Descriptor:
    //------------------------------
    // 0x07	bLength
    // 0x05	bDescriptorType
    // 0x07	bEndpointAddress  (OUT endpoint 7)
    // 0x02	bmAttributes      (Transfer: Bulk / Synch: None / Usage: Data)
    // 0x0200	wMaxPacketSize    (512 bytes)   <= invalid for full speed mode we are using here
    // 0x00	bInterval         
    const usb_config_desc_t* config_desc;
    usb_tonex_one_debug_check(usb_host_get_active_config_descriptor(driver_obj->dev_hdl, &config_desc), "get config descriptor");

    // fix wMaxPacketSize
    int off = 0;
    uint16_t wTotalLength = config_desc->wTotalLength;
    const usb_standard_desc_t *next_desc = (const usb_standard_desc_t *)config_desc;
    if (next_desc)
    {
        do
        {
            if (next_desc->bDescriptorType == USB_B_DESCRIPTOR_TYPE_ENDPOINT)
            {
                usb_ep_desc_t *mod_desc = (usb_ep_desc_t *)next_desc;
                if (mod_desc->wMaxPacketSize > 64)
                {
                    ESP_LOGW(TAG, "EP 0x%02X with wrong wMaxPacketSize %d - fixed to 64", mod_desc->bEndpointAddress, mod_desc->wMaxPacketSize);
                    mod_desc->wMaxPacketSize = 64;
                }
            }

            next_desc = usb_parse_next_descriptor(next_desc, wTotalLength, &off);
        } while (next_desc != NULL);
    }
    // code from forums, work around end

    // install CDC host driver
    usb_tonex_one_debug_check(cdc_acm_host_install(NULL), "install CDC");

    ESP_LOGI(TAG, "Opening CDC ACM device 0x%04X:0x%04X", IK_MULTIMEDIA_USB_VENDOR, TONEX_ONE_PRODUCT_ID);

    // set the config
    const cdc_acm_host_device_config_t dev_config = {
        .connection_timeout_ms = 1000,
        .out_buffer_size = TONEX_USB_TX_BUFFER_SIZE,
        .in_buffer_size = TONEX_ONE_CDC_RX_TRANSFER_SIZE,
        .user_arg = NULL,
        .event_cb = NULL,
        .data_cb = usb_tonex_one_handle_rx
    };

    // release the reserved large buffers space we malloc'd at boot
    tonex_common_release_memory();

    // debug
    //heap_caps_print_heap_info(MALLOC_CAP_DMA);

    // open it
    usb_tonex_one_debug_check(cdc_acm_host_open(IK_MULTIMEDIA_USB_VENDOR, TONEX_ONE_PRODUCT_ID, TONEX_ONE_CDC_INTERFACE_INDEX, &dev_config, &cdc_dev), "open CDC");
    assert(cdc_dev);
    
    //cdc_acm_host_desc_print(cdc_dev);
    vTaskDelay(pdMS_TO_TICKS(100));

    ESP_LOGI(TAG, "Setting up line coding");

    cdc_acm_line_coding_t line_coding;
    usb_tonex_one_debug_check(cdc_acm_host_line_coding_get(cdc_dev, &line_coding), "get line coding");
    ESP_LOGI(TAG, "Line Get: Rate: %d, Stop bits: %d, Parity: %d, Databits: %d", (int)line_coding.dwDTERate, (int)line_coding.bCharFormat, (int)line_coding.bParityType, (int)line_coding.bDataBits);

    // set line coding
    ESP_LOGI(TAG, "Set line coding");
    cdc_acm_line_coding_t new_line_coding = {
        .dwDTERate = 115200,
        .bCharFormat = 0,
        .bParityType = 0,
        .bDataBits = 8
    };

    usb_tonex_one_debug_check(cdc_acm_host_line_coding_set(cdc_dev, &new_line_coding), "set line coding");

    // disable flow control
    ESP_LOGI(TAG, "Set line state");
    usb_tonex_one_debug_check(cdc_acm_host_set_control_line_state(cdc_dev, true, true), "set line state");

    // let things finish init and settle
    vTaskDelay(pdMS_TO_TICKS(250));

    // update UI
    control_set_usb_status(1);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void usb_tonex_one_deinit(void)
{
    portENTER_CRITICAL(&import_lock);
    import_ready = false;
    uint8_t *pending_import = import_body;
    import_body = NULL;
    if (import_state == TONEX_IMPORT_QUEUED ||
        import_state == TONEX_IMPORT_WAITING_FOR_PARAMETERS || import_state == TONEX_IMPORT_SENDING)
        import_state = TONEX_IMPORT_FAILED;
    uint8_t *pending_export = export_body;
    export_body = NULL;
    export_length = 0;
    if (export_state == TONEX_EXPORT_QUEUED || export_state == TONEX_EXPORT_WAITING_FOR_PRESET ||
        export_state == TONEX_EXPORT_READY)
        export_state = TONEX_EXPORT_FAILED;
    portEXIT_CRITICAL(&import_lock);
    free(pending_import);
    free(pending_export);

    // close USB
    cdc_acm_host_close(cdc_dev);
    vTaskDelay(200);
    cdc_dev = NULL;
    cdc_acm_host_uninstall();

    // dealloc mem
    free((void*)InputBuffers);
    InputBuffers = NULL;

    heap_caps_free(PresetParamsBuffer);
    PresetParamsBuffer = NULL;

    free((void*)TxBuffer);    
    TxBuffer = NULL;

    free((void*)FramedBuffer);
    FramedBuffer = NULL;

    free((void*)TonexData);
    TonexData = NULL;

    boot_init_needed = 0;
    boot_global_request = 0;
    boot_preset_request = 0;
    scene_sync_preset_request = 0;
    scene_sync_in_progress = false;
    scene_save_preset_request = 0;
    scene_save_preset_in_progress = false;
    UI_HideProgressBar();

    // preallocate big memory again, ready for freeing on reconnect
    tonex_common_preallocate_memory();
}
