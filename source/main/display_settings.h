#ifndef _DISPLAY_SETTINGS_H
#define _DISPLAY_SETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "usb_comms.h"

void updateSettingsClipboard(Clipboard_t type);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif