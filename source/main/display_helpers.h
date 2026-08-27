
#ifndef _DISPLAY_HELPERS_H
#define _DISPLAY_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#define LV_SLIDER_SET_RANGE(obj, min, max) lv_arc_set_range(obj, min, max)
#define LV_SLIDER_SET_VALUE(obj, val) lv_arc_set_value(obj, val)
#define LV_SLIDER_GET_VALUE(obj) lv_arc_get_value(obj)
#define FRMT(fmt, unit) fmt
#define FRMT_NS(fmt, unit) fmt
#else
#define LV_SLIDER_SET_RANGE(obj, min, max) lv_slider_set_range(obj, min, max)
#define LV_SLIDER_SET_VALUE(obj, val) lv_slider_set_value(obj, val, LV_ANIM_OFF)
#define LV_SLIDER_GET_VALUE(obj) lv_slider_get_value(obj)
#define FRMT(fmt, unit) fmt " " unit
#define FRMT_NS(fmt, unit) fmt unit
#endif

void lv_obj_set_checked(lv_obj_t * obj, bool checked);

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui();
uint32_t get_preset_color_raw(uint16_t index);
uint32_t get_preset_color(uint16_t index);
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif