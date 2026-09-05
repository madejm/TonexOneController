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

#ifndef _USB_TONEX_TUNER_H
#define _USB_TONEX_TUNER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"
#include "usb_comms.h"

typedef struct {
    const uint8_t *data;
    size_t data_size;
    const uint8_t *packet_trace;
    size_t packet_trace_size;
    uint16_t packet_trace_record_size;
    uint32_t sample_rate;
    uint16_t channels;
    uint16_t subslot_size;
    uint16_t valid_bits;
    uint32_t capture_wall_ms;
    uint32_t packets_40;
    uint32_t packets_48;
    uint32_t packets_56;
    uint32_t packets_96;
    uint32_t packets_352;
    uint32_t packets_360;
    uint32_t packets_other;
    uint32_t packets_completed;
    uint32_t packets_skipped;
    uint32_t packets_failed;
    uint8_t qualifier_status;
    uint8_t qualifier_length;
    uint8_t other_speed_status;
    uint8_t other_speed_length;
} usb_tonex_capture_view_t;

/*
 * Proof-of-concept TONEX ONE UAC2 / UC02 UAC1 capture and chromatic tuner.
 * Capture is started immediately by init; tuner-mode gating can be added later.
 */
esp_err_t usb_tonex_tuner_init(class_driver_t *driver_obj);
void usb_tonex_tuner_deinit(void);
bool usb_tonex_tuner_is_active(void);
bool usb_tonex_tuner_is_uac1_capture_device(class_driver_t *driver_obj);

/* A successful acquire pins the capture until the matching release call. */
bool usb_tonex_tuner_capture_acquire(usb_tonex_capture_view_t *view);
void usb_tonex_tuner_capture_release(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
