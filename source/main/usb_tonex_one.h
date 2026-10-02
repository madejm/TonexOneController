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


#ifndef _USB_TONEX_ONE_H
#define _USB_TONEX_ONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "usb_comms.h"

#define MAX_PRESETS_TONEX_ONE             20

void usb_tonex_one_handle(class_driver_t* driver_obj);
void usb_tonex_one_init(class_driver_t* driver_obj, QueueHandle_t comms_queue);
void usb_tonex_one_deinit(void);
void usb_tonex_one_preallocate_memory(void);
bool usb_tonex_one_has_settings_default(Clipboard_t type);

typedef enum
{
    TONEX_IMPORT_NONE,
    TONEX_IMPORT_QUEUED,
    TONEX_IMPORT_WAITING_FOR_PARAMETERS,
    TONEX_IMPORT_SENDING,
    TONEX_IMPORT_SENT,
    TONEX_IMPORT_FAILED
} usb_tonex_one_import_state_t;

typedef enum
{
    TONEX_EXPORT_NONE,
    TONEX_EXPORT_QUEUED,
    TONEX_EXPORT_WAITING_FOR_PRESET,
    TONEX_EXPORT_READY,
    TONEX_EXPORT_FAILED
} usb_tonex_one_export_state_t;

// On ESP_OK ownership of body passes to USB. On error the caller must free it.
// SENT means USB transfer completed, not a verified pedal flash readback.
esp_err_t usb_tonex_one_import_preset(uint8_t *body, size_t length, uint8_t slot,
                                      bool keep_parameters, uint32_t *id);
usb_tonex_one_import_state_t usb_tonex_one_import_status(uint32_t id);
esp_err_t usb_tonex_one_export_preset(uint8_t slot, uint32_t *id);
usb_tonex_one_export_state_t usb_tonex_one_export_status(uint32_t id);
esp_err_t usb_tonex_one_export_take(uint32_t id, uint8_t **body, size_t *length);

// MIDI CC slot targeting functions
esp_err_t usb_tonex_one_load_preset_to_slot_a(uint16_t preset);
esp_err_t usb_tonex_one_load_preset_to_slot_b(uint16_t preset);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
