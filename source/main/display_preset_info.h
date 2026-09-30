#ifndef _DISPLAY_PRESET_INFO_H
#define _DISPLAY_PRESET_INFO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
typedef void (*display_preset_info_close_cb_t)(lv_event_t *);

void openPresetInfoPagePreset(uint8_t presetIndex, display_preset_info_close_cb_t close_action);
void openPresetInfoPageBackup(uint8_t slot, display_preset_info_close_cb_t close_action);
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif