
#ifndef _DISPLAY_HELPERS_H
#define _DISPLAY_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "display_custom_arc.h"
#include "tonex_params.h"

#define _MAKE_COMPONENT(obj, component) obj##component
#define OBJ_VALUE(label)                _MAKE_COMPONENT(label, _value)
#define OBJ_SLIDER(label)               _MAKE_COMPONENT(label, _slider)
#define ARC_ARC(arc)                    _MAKE_COMPONENT(arc, __arc)
#define ARC_VALUE(arc)                  _MAKE_COMPONENT(arc, __value)
#define ARC_UNIT(arc)                   _MAKE_COMPONENT(arc, __unit)
#define ARC_DRAG(arc)                   _MAKE_COMPONENT(arc, __drag)
#define ARC_CONTENT(arc)                _MAKE_COMPONENT(arc, __content)

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#define LV_SLIDER_SET_RANGE(obj, param_entry, mult) \
    lv_arc_set_range(ARC_ARC(obj), round(param_entry->Min * mult), round(param_entry->Max * mult))

#define LV_SLIDER_SET_VALUE(obj, val, mult) \
    lv_arc_set_value(ARC_ARC(obj), round(val * mult))

#define LV_SLIDER_GET_VALUE(obj) ((float)lv_custom_arc_get_value(obj))
#define FRMT(fmt, unit) fmt
#define FRMT_NS(fmt, unit) fmt

#define LV_LABEL_SET_TEXT(label, value) \
    lv_label_set_text(ARC_VALUE(OBJ_SLIDER(label)), value)

#define LV_OBJ_SET_USER_DATA(label, value) \
    lv_obj_set_user_data(ARC_VALUE(OBJ_SLIDER(label)), value)

#else

#define LV_SLIDER_SET_RANGE(obj, param_entry, mult) \
    lv_slider_set_range(obj, round(param_entry->Min * mult), round(param_entry->Max * mult))

#define LV_SLIDER_SET_VALUE(obj, val, mult) \
    lv_slider_set_value(obj, round(val * mult), LV_ANIM_OFF)

#define LV_SLIDER_GET_VALUE(obj) ((float)lv_slider_get_value(obj))
#define FRMT(fmt, unit) fmt " " unit
#define FRMT_NS(fmt, unit) fmt unit

#define LV_LABEL_SET_TEXT(label, value) \
    lv_label_set_text(OBJ_VALUE(label), value)

#define LV_OBJ_SET_USER_DATA(label, value) \
    lv_obj_set_user_data(OBJ_VALUE(label), value)

#endif

/*
shorthand macros for switching on strings

    str_switch(option)
    {
        str_case("val a") {
            function_a();
        }
        
        str_case("val a") {
            function_a();
        }

        str_default {
            function_a();
        }
    }

expands into:

    const char *_s=x;
    if (0) {
    } else if (strcmp(_s, "val a") == 0) {
        {
            function_a();
        }
    } else if (strcmp(_s, "val b") == 0) {
        {
            function_b();
        }
    } else {
        {
            function_c();
        }
    }
*/
#define str_switch(x)   const char *_s=x; if (0)
#define str_case(y)     } else if (strcmp(_s, y) == 0) {
#define str_default     } else {

typedef struct {
    uint32_t rawColor;
    uint32_t onColor;
    uint32_t offColor;
} tCustomPresetColorMapping;

extern const tCustomPresetColorMapping CustomColorMap[TONEX_COLORS_COUNT];

tCustomPresetColorMapping getCustomPresetColorMapping(uint32_t rawColor);

typedef struct {
    TonexParamFormat_t GATE_THRESHOLD;
    TonexParamFormat_t GATE_RELEASE;
    TonexParamFormat_t GATE_DEPTH;

    TonexParamFormat_t COMPRESSOR_THRESHOLD;
    TonexParamFormat_t COMPRESSOR_GAIN;
    TonexParamFormat_t COMPRESSOR_ATTACK;

    TonexParamFormat_t AMP_GAIN;
    TonexParamFormat_t AMP_VOLUME;
    TonexParamFormat_t AMP_DEPTH;
    TonexParamFormat_t AMP_PRESENCE;
    TonexParamFormat_t AMP_MIX;

    TonexParamFormat_t CAB_VIR_RESONANCE;
    TonexParamFormat_t CAB_VIR_MIC_BLEND;
    TonexParamFormat_t CAB_VIR_MIC_POS;

    TonexParamFormat_t EQ_BASS_FREQ;
    TonexParamFormat_t EQ_BASS;
    TonexParamFormat_t EQ_MID_FREQ;
    TonexParamFormat_t EQ_MID_Q;
    TonexParamFormat_t EQ_MID;
    TonexParamFormat_t EQ_TREBLE_FREQ;
    TonexParamFormat_t EQ_TREBLE;
    
    TonexParamFormat_t CHORUS_RATE;
    TonexParamFormat_t CHORUS_DEPTH;
    TonexParamFormat_t CHORUS_LEVEL;

    TonexParamFormat_t TREMOLO_RATE;
    TonexParamFormat_t TREMOLO_SHAPE;
    TonexParamFormat_t TREMOLO_SPREAD;
    TonexParamFormat_t TREMOLO_LEVEL;

    TonexParamFormat_t PHASER_RATE;
    TonexParamFormat_t PHASER_DEPTH;
    TonexParamFormat_t PHASER_LEVEL;

    TonexParamFormat_t FLANGER_RATE;
    TonexParamFormat_t FLANGER_DEPTH;
    TonexParamFormat_t FLANGER_FEEDBACK;
    TonexParamFormat_t FLANGER_LEVEL;

    TonexParamFormat_t ROTARY_SPEED;
    TonexParamFormat_t ROTARY_RADIUS;
    TonexParamFormat_t ROTARY_SPREAD;
    TonexParamFormat_t ROTARY_LEVEL;

    TonexParamFormat_t DELAY_TIME;
    TonexParamFormat_t DELAY_MIX;
    TonexParamFormat_t DELAY_FEEDBACK;

    TonexParamFormat_t REVERB_TIME;
    TonexParamFormat_t REVERB_PREDELAY;
    TonexParamFormat_t REVERB_COLOR;
    TonexParamFormat_t REVERB_MIX;

    TonexParamFormat_t BPM;
    TonexParamFormat_t INPUT_TRIM;
    TonexParamFormat_t TUNING_REF;
    TonexParamFormat_t MASTER;
} TonexParamFormatValues_t;

extern const TonexParamFormatValues_t ParamFormats;

void lv_obj_set_checked(lv_obj_t * obj, bool checked);
void lv_obj_set_disabled(lv_obj_t * obj, bool disabled);

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui();
uint32_t get_preset_color_raw(uint16_t index);
uint32_t get_preset_color(uint16_t index);
void lv_keyboard_set_custom_map(lv_obj_t *obj);
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif