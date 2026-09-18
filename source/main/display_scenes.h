#ifndef _DISPLAY_SCENES_H
#define _DISPLAY_SCENES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void selectScene(uint8_t index);
void sceneOptionsSelected(uint8_t index, const char *option);
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif