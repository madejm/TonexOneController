#ifndef _DISPLAY_PRESET_LIST_H
#define _DISPLAY_PRESET_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
void selectPresetListPreset(uint8_t buttonIndex);
void presetOptionsSelected(uint8_t buttonIndex, const char *option);
void updatePresetListSelection();
void updatePresetListColors();
void updatePresetListNames();
void updatePresetListOptions();
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif