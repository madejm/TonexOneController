#ifndef _DISPLAY_CAB_VIR_H
#define _DISPLAY_CAB_VIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
uint8_t getVirCabSelectedModelIndex();
void setVirCabSelectedModelIndex(uint8_t index);
void setVirCabSelectedButtonIndex(uint8_t index);
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif