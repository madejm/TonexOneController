
#ifndef _DISPLAY_HELPERS_H
#define _DISPLAY_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void lv_helper_create_arc_gesture(lv_obj_t *arc);

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui();
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif