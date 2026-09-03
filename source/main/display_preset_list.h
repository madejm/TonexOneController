#ifndef _DISPLAY_PRESET_LIST_H
#define _DISPLAY_PRESET_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void selectPresetListPreset(uint8_t buttonIndex);
void presetOptionsSelected(uint8_t buttonIndex, uint16_t option);
void updatePresetListSelection();
void updatePresetListColors();
void updatePresetListNames();

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif