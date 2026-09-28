#ifndef _DISPLAY_PRESET_BACKUP_LIST_H
#define _DISPLAY_PRESET_BACKUP_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
void openPresetsBackupPageLoad(uint8_t presetIndex);
void selectPresetListBackupPreset(uint8_t buttonIndex);
void presetBackupOptionsSelected(uint8_t buttonIndex, const char *option);
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif