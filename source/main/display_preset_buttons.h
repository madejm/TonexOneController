#ifndef _DISPLAY_PRESET_BUTTONS_H
#define _DISPLAY_PRESET_BUTTONS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void display_preset_buttons_clicked(uint32_t buttonIndex, bool longPress);
void display_preset_buttons_updatePresetNumberLabel(uint8_t ui_PresetIndex);
void display_preset_buttons_updateFSButtons(
    bool ui_AltMode,
    uint8_t ui_PresetIndex,
    uint8_t ui_BankIndex
);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif