#ifndef _DISPLAY_CUSTOM_ARC_H
#define _DISPLAY_CUSTOM_ARC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#define SETUP_ARC(arc, format, unit, defaultValue) \
    setup_arc_elements(arc, ARC_ARC(arc), ARC_VALUE(arc), ARC_UNIT(arc), ARC_DRAG(arc), ARC_CONTENT(arc), format, unit, defaultValue, NULL)

#define SETUP_ARC_CANV(arc, format, unit, defaultValue, update_canvas) \
    setup_arc_elements(arc, ARC_ARC(arc), ARC_VALUE(arc), ARC_UNIT(arc), ARC_DRAG(arc), ARC_CONTENT(arc), format, unit, defaultValue, update_canvas)

#define SETUP_ARC_FORMAT_CB(arc, format_cb) \
    setup_arc_elements_format_cb(arc, ARC_ARC(arc), ARC_VALUE(arc), ARC_UNIT(arc), ARC_DRAG(arc), ARC_CONTENT(arc), format_cb)

typedef struct {
    const char *format;
    float multiplier;
} TonexParamFormat_t;

typedef void (*UpdateCanvas)(float value);

typedef struct {
    TonexParamFormat_t format;
    float defaultValue;
    UpdateCanvas update_canvas;
} format_data_t;

typedef format_data_t (*format_cb_t)(lv_obj_t *);

int16_t lv_custom_arc_get_value(lv_obj_t *arc);

void setup_arc_elements(
    lv_obj_t *root,
    lv_obj_t *arc,
    lv_obj_t *label,
    lv_obj_t *unitLabel,
    lv_obj_t *drag,
    lv_obj_t *content,
    TonexParamFormat_t format,
    const char *unit,
    float defaultValue,
    UpdateCanvas update_canvas
);

void setup_arc_elements_format_cb(
    lv_obj_t *root,
    lv_obj_t *arc,
    lv_obj_t *label,
    lv_obj_t *unitLabel,
    lv_obj_t *drag,
    lv_obj_t *content,
    format_cb_t format_cb
);
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif