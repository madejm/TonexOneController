#ifndef _DISPLAY_SETTINGS_H
#define _DISPLAY_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "usb_comms.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
void updateSettingsDefaults(void);
void updateSettingsClipboard(Clipboard_t type);
void customize_ui_settings();
void loadSavedTheme();
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif