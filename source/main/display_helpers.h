
#ifndef _DISPLAY_HELPERS_H
#define _DISPLAY_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#define LV_SLIDER_SET_RANGE(obj, param_entry, mult) \
    lv_arc_set_range(obj, round(param_entry->Min * mult), round(param_entry->Max * mult))

#define LV_SLIDER_SET_VALUE(obj, val, mult) \
    lv_arc_set_value(obj, round(val * mult))

#define LV_SLIDER_GET_VALUE(obj) ((float)lv_arc_get_value(obj))
#define FRMT(fmt, unit) fmt
#define FRMT_NS(fmt, unit) fmt

#else

#define LV_SLIDER_SET_RANGE(obj, param_entry, mult) \
    lv_slider_set_range(obj, round(param_entry->Min * mult), round(param_entry->Max * mult))

#define LV_SLIDER_SET_VALUE(obj, val, mult) \
    lv_slider_set_value(obj, round(val * mult), LV_ANIM_OFF)

#define LV_SLIDER_GET_VALUE(obj) ((float)lv_slider_get_value(obj))
#define FRMT(fmt, unit) fmt " " unit
#define FRMT_NS(fmt, unit) fmt unit

#endif

typedef struct {
    const char *format;
    float multiplier;
} TonexParamFormat_t;

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
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif