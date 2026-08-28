
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#include "screens.h"
#include "display_helpers.h"
#include "eq_canvas.h"
#include "tonex_params.h"

#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })

#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })

#define clamp(mi,ma,val) \
    ({ __typeof__ (mi) _mi = (mi); \
       __typeof__ (ma) _ma = (ma); \
       __typeof__ (val) _val = (val); \
       _val < _mi ? _mi : (_val > _ma ? _ma : _val); })

void lv_obj_set_checked(lv_obj_t * obj, bool checked) {
    if (checked) {
        lv_obj_add_state(obj, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(obj, LV_STATE_CHECKED);
    }
}

typedef struct {
    const char *format;
    float defaultValue;
} format_data_t;

typedef format_data_t (*format_cb_t)(lv_obj_t *);

typedef struct {
    lv_obj_t * arc;
    lv_obj_t * label;
    float multiplier;
    format_data_t format_data;
    format_cb_t format_cb;
} drag_data_t;

static format_data_t drag_data_get_format(drag_data_t *data)
{
    if (data->format_cb == NULL) {
        return data->format_data;
    } else {
        return data->format_cb(data->label);
    }
}

static format_data_t mod_format_cb(lv_obj_t *label)
{
    uintptr_t user_data = (uintptr_t)lv_obj_get_user_data(label);
    TonexParameter_t param_index = (TonexParameter_t)user_data;

    switch (param_index)
    {
        case TONEX_PARAM_MODULATION_CHORUS_RATE:      return (format_data_t){ .format = "%1.1f", .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_CHORUS_DEPTH:     return (format_data_t){ .format = "%1.0f", .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_CHORUS_LEVEL:     return (format_data_t){ .format = "%1.1f", .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_TREMOLO_RATE:     return (format_data_t){ .format = "%1.1f", .defaultValue = 6.5 };
        case TONEX_PARAM_MODULATION_TREMOLO_SHAPE:    return (format_data_t){ .format = "%1.1f", .defaultValue = 0 };
        case TONEX_PARAM_MODULATION_TREMOLO_SPREAD:   return (format_data_t){ .format = "%1.0f", .defaultValue = 0 };
        case TONEX_PARAM_MODULATION_TREMOLO_LEVEL:    return (format_data_t){ .format = "%1.1f", .defaultValue = 6 };

        case TONEX_PARAM_MODULATION_PHASER_RATE:      return (format_data_t){ .format = "%1.1f", .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_PHASER_DEPTH:     return (format_data_t){ .format = "%1.0f", .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_PHASER_LEVEL:     return (format_data_t){ .format = "%1.1f", .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_FLANGER_RATE:     return (format_data_t){ .format = "%1.1f", .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_FLANGER_DEPTH:    return (format_data_t){ .format = "%1.0f", .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_FLANGER_FEEDBACK: return (format_data_t){ .format = "%1.0f", .defaultValue = 25 };
        case TONEX_PARAM_MODULATION_FLANGER_LEVEL:    return (format_data_t){ .format = "%1.1f", .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_ROTARY_SPEED:     return (format_data_t){ .format = "%1.0f", .defaultValue = 360 };
        case TONEX_PARAM_MODULATION_ROTARY_RADIUS:    return (format_data_t){ .format = "%1.0f", .defaultValue = 120 };
        case TONEX_PARAM_MODULATION_ROTARY_SPREAD:    return (format_data_t){ .format = "%1.0f", .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_ROTARY_LEVEL:     return (format_data_t){ .format = "%1.1f", .defaultValue = 5 };

        default:                                      return (format_data_t){ .format = "%1.0f", .defaultValue = 5 };
    }
}

static void label_set_value(drag_data_t * data, int32_t value)
{
    const char *format = drag_data_get_format(data).format;
    char buf[20];
    sprintf(buf, format, ((float)value) / data->multiplier);
    lv_label_set_text(data->label, buf);
}

static int32_t arc_drag_accumulator = 0;
static bool arc_dragging = false;

static void arc_drag_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);
    lv_obj_t * arc = data->arc;

    lv_point_t v;
    lv_indev_get_vect(lv_indev_get_act(), &v);

    int32_t minValue = lv_arc_get_min_value(arc);
    int32_t maxValue = lv_arc_get_max_value(arc);
    int32_t range = maxValue - minValue;

    arc_drag_accumulator += v.x * range;
    arc_drag_accumulator -= v.y * range;

    int32_t delta = arc_drag_accumulator / 400;
    arc_drag_accumulator %= 400;

    if (delta) {
        arc_dragging = true;

        int32_t rawValue = lv_arc_get_value(arc) + delta;
        // int32_t value = max(minValue, min(rawValue, maxValue));
        int32_t value = clamp(minValue, maxValue, rawValue);
        lv_arc_set_value(arc, value);
        label_set_value(data, value);
        lv_event_send(arc, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void drag_released_cb(lv_event_t * e)
{
    arc_drag_accumulator = 0;
    arc_dragging = false;

    lv_obj_t * arc = lv_event_get_user_data(e);

    lv_event_send(arc, LV_EVENT_RELEASED, NULL);
}

static void arc_reset_cb(lv_event_t * e)
{
    if (arc_dragging) {
        return;
    }

    drag_data_t * data = lv_event_get_user_data(e);
    float defaultValue = drag_data_get_format(data).defaultValue;

    lv_arc_set_value(data->arc, (int16_t)(defaultValue * data->multiplier));
    label_set_value(data,       (int16_t)(defaultValue * data->multiplier));
    lv_event_send(data->arc, LV_EVENT_VALUE_CHANGED, NULL);
}

static void drag_delete_cb(lv_event_t *e)
{
    drag_data_t *data = lv_event_get_user_data(e);
    lv_mem_free(data);
}

static void lv_helper_create_arc_gesture_data(
    lv_obj_t *arc,
    lv_obj_t *label,
    float multiplier,
    drag_data_t *data
) {
    lv_obj_t * parent = lv_obj_get_parent(arc);

    /* Remember position in parent's child list */
    uint32_t index = lv_obj_get_index(arc);

    /* Remember arc geometry */
    lv_coord_t x = lv_obj_get_x(arc);
    lv_coord_t y = lv_obj_get_y(arc);
    lv_coord_t w = lv_obj_get_width(arc);
    lv_coord_t h = lv_obj_get_height(arc);

    /* Create wrapper in same flex container */
    lv_obj_t * drag = lv_obj_create(parent);

    /* Put wrapper exactly where arc was in child order */
    lv_obj_move_to_index(drag, index);

    /* Wrapper now participates in flex instead of arc */
    lv_obj_set_pos(drag, x, y);
    lv_obj_set_size(drag, w, h);

    lv_obj_set_style_pad_all(drag, 0, 0);
    lv_obj_set_style_border_width(drag, 0, 0);
    lv_obj_set_style_bg_opa(drag, LV_OPA_TRANSP, 0);

    /* Move arc into wrapper */
    lv_obj_set_parent(arc, drag);

    lv_obj_set_pos(arc, 0, 0);
    lv_obj_set_size(arc, LV_PCT(100), LV_PCT(100));

    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSING, data);
    lv_obj_add_event_cb(drag, drag_delete_cb, LV_EVENT_DELETE, data);
    lv_obj_add_event_cb(drag, arc_reset_cb, LV_EVENT_LONG_PRESSED, data);
    lv_obj_add_event_cb(drag, drag_released_cb, LV_EVENT_RELEASED, arc);
}

static void lv_helper_create_arc_gesture(
    lv_obj_t *arc,
    lv_obj_t *label,
    const char *format,
    float multiplier,
    float defaultValue
) {
    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->arc = arc;
    data->label = label;
    data->multiplier = multiplier;

    data->format_data.format = format;
    data->format_data.defaultValue = defaultValue;
    data->format_cb = NULL;
    
    lv_helper_create_arc_gesture_data(arc, label, multiplier, data);
}

static void lv_helper_create_arc_gesture_c(
    lv_obj_t *arc,
    lv_obj_t *label,
    float multiplier,
    format_cb_t format_cb
) {
    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->arc = arc;
    data->label = label;
    data->multiplier = multiplier;

    data->format_cb = format_cb;
    
    lv_helper_create_arc_gesture_data(arc, label, multiplier, data);
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui() {
    lv_obj_set_style_bg_opa(objects.ui_wi_fi_button, 255, LV_PART_MAIN | LV_STATE_USER_1);

    lv_helper_create_arc_gesture(objects.ui_noise_gate_threshold_slider, objects.ui_noise_gate_threshold_value, "%1.0f", 1.0f, -100);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_release_slider,   objects.ui_noise_gate_release_value,   "%1.0f", 1.0f, 20);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_depth_slider,     objects.ui_noise_gate_depth_value,     "%1.0f", 1.0f, 60);

    lv_helper_create_arc_gesture(objects.ui_compressor_threshold_slider, objects.ui_compressor_threshold_value, "%1.1f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_compressor_gain_slider,      objects.ui_compressor_gain_value,      "%1.0f", 1.0f, -8);
    lv_helper_create_arc_gesture(objects.ui_compressor_attack_slider,    objects.ui_compressor_attack_value,    "%1.0f", 1.0f, 5);

    lv_helper_create_arc_gesture(objects.ui_amplifier_gain_slider,       objects.ui_amplifier_gain_value,       "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_volume_slider,     objects.ui_amplifier_volume_value,     "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_depth_slider,      objects.ui_amplifier_depth_value,      "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_presense_slider,   objects.ui_amplifier_presense_value,   "%1.1f", 10.0f, 5);

    lv_helper_create_arc_gesture(objects.ui_eq_bass_freq_slider,         objects.ui_eq_bass_freq_value,         "%1.0f", 1.0f,  300);
    lv_helper_create_arc_gesture(objects.ui_eq_bass_slider,              objects.ui_eq_bass_value,              "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_freq_slider,          objects.ui_eq_mid_freq_value,          "%1.0f", 1.0f,  750);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_qslider,              objects.ui_eq_mid_qvalue,              "%1.1f", 10.0f, 0.7);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_slider,               objects.ui_eq_mid_value,               "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_freq_slider,       objects.ui_eq_treble_freq_value,       "%1.0f", 1.0f,  2000);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_slider,            objects.ui_eq_treble_value,            "%1.1f", 10.0f, 5);

    lv_helper_create_arc_gesture_c(objects.ui_modulation_param1_slider,  objects.ui_modulation_param1_value,    1.0f, mod_format_cb);
    lv_helper_create_arc_gesture_c(objects.ui_modulation_param2_slider,  objects.ui_modulation_param2_value,    1.0f, mod_format_cb);
    lv_helper_create_arc_gesture_c(objects.ui_modulation_param3_slider,  objects.ui_modulation_param3_value,    1.0f, mod_format_cb);
    lv_helper_create_arc_gesture_c(objects.ui_modulation_param4_slider,  objects.ui_modulation_param4_value,    1.0f, mod_format_cb);

    lv_helper_create_arc_gesture(objects.ui_delay_ts_slider,             objects.ui_delay_ts_value,             "%1.0f", 1.0f, 350);
    lv_helper_create_arc_gesture(objects.ui_delay_mix_slider,            objects.ui_delay_mix_value,            "%1.0f", 1.0f, 50);
    lv_helper_create_arc_gesture(objects.ui_delay_feedback_slider,       objects.ui_delay_feedback_value,       "%1.0f", 1.0f, 20);

    lv_helper_create_arc_gesture(objects.ui_reverb_time_slider,          objects.ui_reverb_time_value,          "%1.1f", 1.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_reverb_predelay_slider,      objects.ui_reverb_predelay_value,      "%1.0f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_reverb_color_slider,         objects.ui_reverb_color_value,         "%1.0f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_reverb_mix_slider,           objects.ui_reverb_mix_value,           "%1.0f", 1.0f, 30);

    lv_helper_create_arc_gesture(objects.ui_bpm_slider,                  objects.ui_bpm_value,                  "%1.0f", 1.0f, 120);
    lv_helper_create_arc_gesture(objects.ui_input_trim_slider,           objects.ui_input_trim_value,           "%1.0f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_tuning_reference_slider,     objects.ui_tuning_reference_value,     "%1.0f", 1.0f, 440);
    lv_helper_create_arc_gesture(objects.ui_volume_slider,               objects.ui_volume_value,               "%1.0f", 1.0f, 5);

    eq_canvas_setup();
}

static uint32_t get_preset_color_raw_or_real(uint16_t index, bool real)
{
    uint8_t *preset_order = control_get_preset_order();
    uint8_t preset_index = preset_order[index];
    
    uint32_t color = 0x000000;
    if (real) {
        tonex_params_colors_get_color(preset_index, &color);
    } else {
        tonex_params_colors_get_color_raw(preset_index, &color);
    }
    return color;
}

uint32_t get_preset_color_raw(uint16_t index)
{
    return get_preset_color_raw_or_real(index, false);
}

uint32_t get_preset_color(uint16_t index)
{
    return get_preset_color_raw_or_real(index, true);
}
#endif