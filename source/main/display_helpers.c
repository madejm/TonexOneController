
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#include "screens.h"
#include "display_helpers.h"
#include "eq_canvas.h"
#include "tonex_params.h"

#define CANVAS_ARC_DRAG_UPDATE_PERIOD_MS 750
#define CANVAS_ARC_IDLE_UPDATE_DELAY_MS  150

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

void lv_obj_set_disabled(lv_obj_t * obj, bool disabled) {
    if (disabled) {
        lv_obj_add_state(obj, LV_STATE_DISABLED);
    } else {
        lv_obj_clear_state(obj, LV_STATE_DISABLED);
    }
}

const TonexParamFormatValues_t ParamFormats = {
    .GATE_THRESHOLD =       { .format = "%1.0f", .multiplier = 1.0f  },
    .GATE_RELEASE =         { .format = "%1.0f", .multiplier = 1.0f  },
    .GATE_DEPTH =           { .format = "%1.0f", .multiplier = 1.0f  },

    .COMPRESSOR_THRESHOLD = { .format = "%1.1f", .multiplier = 2.0f  },
    .COMPRESSOR_GAIN =      { .format = "%1.0f", .multiplier = 1.0f  },
    .COMPRESSOR_ATTACK =    { .format = "%1.0f", .multiplier = 1.0f  },

    .AMP_GAIN =             { .format = "%1.1f", .multiplier = 10.0f },
    .AMP_VOLUME =           { .format = "%1.1f", .multiplier = 10.0f },
    .AMP_DEPTH =            { .format = "%1.1f", .multiplier = 10.0f },
    .AMP_PRESENCE =         { .format = "%1.1f", .multiplier = 10.0f },

    .EQ_BASS_FREQ =         { .format = "%1.0f", .multiplier = 0.2f  },
    .EQ_BASS =              { .format = "%1.1f", .multiplier = 10.0f },
    .EQ_MID_FREQ =          { .format = "%1.0f", .multiplier = 0.02f },
    .EQ_MID_Q =             { .format = "%1.2f", .multiplier = 20.0f },
    .EQ_MID =               { .format = "%1.1f", .multiplier = 10.0f },
    .EQ_TREBLE_FREQ =       { .format = "%1.0f", .multiplier = 0.01f },
    .EQ_TREBLE =            { .format = "%1.1f", .multiplier = 10.0f },
    
    .CHORUS_RATE =          { .format = "%1.2f", .multiplier = 50.0f },
    .CHORUS_DEPTH =         { .format = "%1.0f", .multiplier = 1.0f  },
    .CHORUS_LEVEL =         { .format = "%1.1f", .multiplier = 10.0f },

    .TREMOLO_RATE =         { .format = "%1.1f", .multiplier = 10.0f },
    .TREMOLO_SHAPE =        { .format = "%1.1f", .multiplier = 10.0f },
    .TREMOLO_SPREAD =       { .format = "%1.0f", .multiplier = 1.0f  },
    .TREMOLO_LEVEL =        { .format = "%1.1f", .multiplier = 10.0f },

    .PHASER_RATE =          { .format = "%1.2f", .multiplier = 50.0f },
    .PHASER_DEPTH =         { .format = "%1.0f", .multiplier = 1.0f  },
    .PHASER_LEVEL =         { .format = "%1.1f", .multiplier = 10.0f },

    .FLANGER_RATE =         { .format = "%1.2f", .multiplier = 50.0f },
    .FLANGER_DEPTH =        { .format = "%1.0f", .multiplier = 1.0f  },
    .FLANGER_FEEDBACK =     { .format = "%1.0f", .multiplier = 1.0f  },
    .FLANGER_LEVEL =        { .format = "%1.1f", .multiplier = 10.0f },

    .ROTARY_SPEED =         { .format = "%1.0f", .multiplier = 0.2f  },
    .ROTARY_RADIUS =        { .format = "%1.0f", .multiplier = 0.2f  },
    .ROTARY_SPREAD =        { .format = "%1.0f", .multiplier = 1.0f  },
    .ROTARY_LEVEL =         { .format = "%1.1f", .multiplier = 10.0f },

    .DELAY_TIME =           { .format = "%1.0f", .multiplier = 0.1f  },
    .DELAY_MIX =            { .format = "%1.0f", .multiplier = 1.0f  },
    .DELAY_FEEDBACK =       { .format = "%1.0f", .multiplier = 1.0f  },

    .REVERB_TIME =          { .format = "%1.1f", .multiplier = 2.0f  },
    .REVERB_PREDELAY =      { .format = "%1.0f", .multiplier = 0.1f  },
    .REVERB_COLOR =         { .format = "%1.0f", .multiplier = 1.0f  },
    .REVERB_MIX =           { .format = "%1.0f", .multiplier = 1.0f  },

    .BPM =                  { .format = "%1.0f", .multiplier = 1.0f  },
    .INPUT_TRIM =           { .format = "%1.1f", .multiplier = 10.0f },
    .TUNING_REF =           { .format = "%1.0f", .multiplier = 1.0f  },
    .MASTER =               { .format = "%1.1f", .multiplier = 10.0f },
};

typedef void (*UpdateCanvas)(float value);

typedef struct {
    TonexParamFormat_t format;
    float defaultValue;
    UpdateCanvas update_canvas;
} format_data_t;

typedef format_data_t (*format_cb_t)(lv_obj_t *);

typedef struct {
    lv_obj_t * arc;
    lv_obj_t * label;
    format_data_t format_data;
    format_cb_t format_cb;
    uint32_t last_canvas_update_tick;
    lv_timer_t * canvas_idle_timer;
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
        case TONEX_PARAM_MODULATION_CHORUS_RATE:      return (format_data_t){ .format = ParamFormats.CHORUS_RATE,      .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_CHORUS_DEPTH:     return (format_data_t){ .format = ParamFormats.CHORUS_DEPTH,     .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_CHORUS_LEVEL:     return (format_data_t){ .format = ParamFormats.CHORUS_LEVEL,     .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_TREMOLO_RATE:     return (format_data_t){ .format = ParamFormats.TREMOLO_RATE,     .defaultValue = 6.5 };
        case TONEX_PARAM_MODULATION_TREMOLO_SHAPE:    return (format_data_t){ .format = ParamFormats.TREMOLO_SHAPE,    .defaultValue = 0 };
        case TONEX_PARAM_MODULATION_TREMOLO_SPREAD:   return (format_data_t){ .format = ParamFormats.TREMOLO_SPREAD,   .defaultValue = 0 };
        case TONEX_PARAM_MODULATION_TREMOLO_LEVEL:    return (format_data_t){ .format = ParamFormats.TREMOLO_LEVEL,    .defaultValue = 6 };

        case TONEX_PARAM_MODULATION_PHASER_RATE:      return (format_data_t){ .format = ParamFormats.PHASER_RATE,      .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_PHASER_DEPTH:     return (format_data_t){ .format = ParamFormats.PHASER_DEPTH,     .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_PHASER_LEVEL:     return (format_data_t){ .format = ParamFormats.PHASER_LEVEL,     .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_FLANGER_RATE:     return (format_data_t){ .format = ParamFormats.FLANGER_RATE,     .defaultValue = 0.5 };
        case TONEX_PARAM_MODULATION_FLANGER_DEPTH:    return (format_data_t){ .format = ParamFormats.FLANGER_DEPTH,    .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_FLANGER_FEEDBACK: return (format_data_t){ .format = ParamFormats.FLANGER_FEEDBACK, .defaultValue = 25 };
        case TONEX_PARAM_MODULATION_FLANGER_LEVEL:    return (format_data_t){ .format = ParamFormats.FLANGER_LEVEL,    .defaultValue = 7.5 };

        case TONEX_PARAM_MODULATION_ROTARY_SPEED:     return (format_data_t){ .format = ParamFormats.ROTARY_SPEED,     .defaultValue = 360 };
        case TONEX_PARAM_MODULATION_ROTARY_RADIUS:    return (format_data_t){ .format = ParamFormats.ROTARY_RADIUS,    .defaultValue = 120 };
        case TONEX_PARAM_MODULATION_ROTARY_SPREAD:    return (format_data_t){ .format = ParamFormats.ROTARY_SPREAD,    .defaultValue = 50 };
        case TONEX_PARAM_MODULATION_ROTARY_LEVEL:     return (format_data_t){ .format = ParamFormats.ROTARY_LEVEL,     .defaultValue = 5 };

        default:                         return (format_data_t){ .format = { .format = "%1.0f", .multiplier = 1.0f },  .defaultValue = 5 };
    }
}

static void label_set_value(drag_data_t * data, int32_t value, bool notify_canvas)
{
    format_data_t format = drag_data_get_format(data);
    float result = ((float)value) / format.format.multiplier;
    char buf[20];
    sprintf(buf, format.format.format, result);
    lv_label_set_text(data->label, buf);

    UpdateCanvas update_canvas = format.update_canvas;
    if (notify_canvas && update_canvas != NULL) {
        update_canvas(result);
    }
}

static void canvas_idle_timer_cb(lv_timer_t * timer)
{
    drag_data_t * data = timer->user_data;

    lv_timer_pause(timer);
    data->last_canvas_update_tick = lv_tick_get();
    label_set_value(data, lv_arc_get_value(data->arc), true);
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
        uint32_t now = lv_tick_get();
        if (!arc_dragging) {
            data->last_canvas_update_tick = now;
        }
        arc_dragging = true;

        int32_t rawValue = lv_arc_get_value(arc) + delta;
        // int32_t value = max(minValue, min(rawValue, maxValue));
        int32_t value = clamp(minValue, maxValue, rawValue);
        bool update_canvas = lv_tick_elaps(data->last_canvas_update_tick)
            >= CANVAS_ARC_DRAG_UPDATE_PERIOD_MS;

        if (update_canvas) {
            data->last_canvas_update_tick = now;
        }

        if (data->canvas_idle_timer != NULL) {
            lv_timer_reset(data->canvas_idle_timer);
            lv_timer_resume(data->canvas_idle_timer);
        }

        lv_arc_set_value(arc, value);
        label_set_value(data, value, update_canvas);
        lv_event_send(arc, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void drag_released_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);

    arc_drag_accumulator = 0;
    arc_dragging = false;
    data->last_canvas_update_tick = 0;

    if (data->canvas_idle_timer != NULL) {
        lv_timer_pause(data->canvas_idle_timer);
    }

    /* Always send the final dragged value to the canvas. */
    label_set_value(data, lv_arc_get_value(data->arc), true);

    lv_event_send(data->arc, LV_EVENT_RELEASED, NULL);
}

static void arc_reset_cb(lv_event_t * e)
{
    if (arc_dragging) {
        return;
    }

    drag_data_t * data = lv_event_get_user_data(e);
    format_data_t format = drag_data_get_format(data);
    int16_t value = (int16_t)(format.defaultValue * format.format.multiplier);

    lv_arc_set_value(data->arc, value);
    label_set_value(data, value, true);
    lv_event_send(data->arc, LV_EVENT_VALUE_CHANGED, NULL);
}

static void drag_delete_cb(lv_event_t *e)
{
    drag_data_t *data = lv_event_get_user_data(e);

    if (data->canvas_idle_timer != NULL) {
        lv_timer_del(data->canvas_idle_timer);
        data->canvas_idle_timer = NULL;
    }

    lv_mem_free(data);
}

static void lv_helper_create_arc_gesture_data(
    lv_obj_t *arc,
    lv_obj_t *label,
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
    lv_obj_add_event_cb(drag, drag_released_cb, LV_EVENT_RELEASED, data);
}

static void lv_helper_create_arc_gesture_canv(
    lv_obj_t *arc,
    lv_obj_t *label,
    TonexParamFormat_t format,
    float defaultValue,
    UpdateCanvas update_canvas
) {
    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->arc = arc;
    data->label = label;

    data->format_data.format = format;
    data->format_data.defaultValue = defaultValue;
    data->format_data.update_canvas = update_canvas;
    data->format_cb = NULL;
    data->last_canvas_update_tick = 0;
    data->canvas_idle_timer = NULL;

    if (update_canvas != NULL) {
        data->canvas_idle_timer = lv_timer_create(
            canvas_idle_timer_cb,
            CANVAS_ARC_IDLE_UPDATE_DELAY_MS,
            data
        );
        if (data->canvas_idle_timer != NULL) {
            lv_timer_pause(data->canvas_idle_timer);
        }
    }
    
    lv_helper_create_arc_gesture_data(arc, label, data);
}

static void lv_helper_create_arc_gesture(
    lv_obj_t *arc,
    lv_obj_t *label,
    TonexParamFormat_t format,
    float defaultValue
) {
    lv_helper_create_arc_gesture_canv(
        arc,
        label,
        format,
        defaultValue,
        NULL
    );
}

static void lv_helper_create_arc_gesture_cb(
    lv_obj_t *arc,
    lv_obj_t *label,
    format_cb_t format_cb
) {
    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->arc = arc;
    data->label = label;

    data->format_data.update_canvas = NULL;
    data->format_cb = format_cb;
    data->last_canvas_update_tick = 0;
    data->canvas_idle_timer = NULL;
    
    lv_helper_create_arc_gesture_data(arc, label, data);
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

static void eq_canvas_update_presence_gain_opt(float value)
{
    if (lv_obj_has_state(objects.ui_amp_enable_switch, LV_STATE_CHECKED)) {
        eq_canvas_update_presence_gain(value);
    }
}

static void eq_canvas_update_depth_gain_opt(float value)
{
    if (lv_obj_has_state(objects.ui_amp_enable_switch, LV_STATE_CHECKED)) {
        eq_canvas_update_depth_gain(value);
    }
}

void customize_ui() {
    lv_obj_set_style_bg_opa(objects.ui_wi_fi_button, 255, LV_PART_MAIN | LV_STATE_USER_1);

    lv_helper_create_arc_gesture(objects.ui_noise_gate_threshold_slider,    objects.ui_noise_gate_threshold_value, ParamFormats.GATE_THRESHOLD,      -100);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_release_slider,      objects.ui_noise_gate_release_value,   ParamFormats.GATE_RELEASE,          20);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_depth_slider,        objects.ui_noise_gate_depth_value,     ParamFormats.GATE_DEPTH,            60);

    lv_helper_create_arc_gesture(objects.ui_compressor_threshold_slider,    objects.ui_compressor_threshold_value, ParamFormats.COMPRESSOR_THRESHOLD,   0);
    lv_helper_create_arc_gesture(objects.ui_compressor_gain_slider,         objects.ui_compressor_gain_value,      ParamFormats.COMPRESSOR_GAIN,       -8);
    lv_helper_create_arc_gesture(objects.ui_compressor_attack_slider,       objects.ui_compressor_attack_value,    ParamFormats.COMPRESSOR_ATTACK,      5);

    lv_helper_create_arc_gesture(objects.ui_amplifier_gain_slider,          objects.ui_amplifier_gain_value,       ParamFormats.AMP_GAIN,               5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_volume_slider,        objects.ui_amplifier_volume_value,     ParamFormats.AMP_VOLUME,             5);
    lv_helper_create_arc_gesture_canv(objects.ui_amplifier_depth_slider,    objects.ui_amplifier_depth_value,      ParamFormats.AMP_DEPTH,              5, eq_canvas_update_depth_gain_opt);
    lv_helper_create_arc_gesture_canv(objects.ui_amplifier_presense_slider, objects.ui_amplifier_presense_value,   ParamFormats.AMP_PRESENCE,           5, eq_canvas_update_presence_gain_opt);

    lv_helper_create_arc_gesture_canv(objects.ui_eq_bass_freq_slider,       objects.ui_eq_bass_freq_value,         ParamFormats.EQ_BASS_FREQ,         300, eq_canvas_update_bass_frequency);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_bass_slider,            objects.ui_eq_bass_value,              ParamFormats.EQ_BASS,                5, eq_canvas_update_bass_gain);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_mid_freq_slider,        objects.ui_eq_mid_freq_value,          ParamFormats.EQ_MID_FREQ,          750, eq_canvas_update_mid_frequency);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_mid_qslider,            objects.ui_eq_mid_qvalue,              ParamFormats.EQ_MID_Q,             0.7, eq_canvas_update_mid_q);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_mid_slider,             objects.ui_eq_mid_value,               ParamFormats.EQ_MID,                 5, eq_canvas_update_mid_gain);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_treble_freq_slider,     objects.ui_eq_treble_freq_value,       ParamFormats.EQ_TREBLE_FREQ,      2000, eq_canvas_update_treble_frequency);
    lv_helper_create_arc_gesture_canv(objects.ui_eq_treble_slider,          objects.ui_eq_treble_value,            ParamFormats.EQ_TREBLE,              5, eq_canvas_update_treble_gain);

    lv_helper_create_arc_gesture(objects.ui_delay_ts_slider,                objects.ui_delay_ts_value,             ParamFormats.DELAY_TIME,           350);
    lv_helper_create_arc_gesture(objects.ui_delay_mix_slider,               objects.ui_delay_mix_value,            ParamFormats.DELAY_MIX,             50);
    lv_helper_create_arc_gesture(objects.ui_delay_feedback_slider,          objects.ui_delay_feedback_value,       ParamFormats.DELAY_FEEDBACK,        20);

    lv_helper_create_arc_gesture(objects.ui_reverb_time_slider,             objects.ui_reverb_time_value,          ParamFormats.REVERB_TIME,            5);
    lv_helper_create_arc_gesture(objects.ui_reverb_predelay_slider,         objects.ui_reverb_predelay_value,      ParamFormats.REVERB_PREDELAY,        0);
    lv_helper_create_arc_gesture(objects.ui_reverb_color_slider,            objects.ui_reverb_color_value,         ParamFormats.REVERB_COLOR,           0);
    lv_helper_create_arc_gesture(objects.ui_reverb_mix_slider,              objects.ui_reverb_mix_value,           ParamFormats.REVERB_MIX,            30);

    lv_helper_create_arc_gesture(objects.ui_bpm_slider,                     objects.ui_bpm_value,                  ParamFormats.BPM,                  120);
    lv_helper_create_arc_gesture(objects.ui_input_trim_slider,              objects.ui_input_trim_value,           ParamFormats.INPUT_TRIM,             0);
    lv_helper_create_arc_gesture(objects.ui_tuning_reference_slider,        objects.ui_tuning_reference_value,     ParamFormats.TUNING_REF,           440);
    lv_helper_create_arc_gesture(objects.ui_volume_slider,                  objects.ui_volume_value,               ParamFormats.MASTER,                 5);

    lv_helper_create_arc_gesture_cb(objects.ui_modulation_param1_slider,    objects.ui_modulation_param1_value,    mod_format_cb);
    lv_helper_create_arc_gesture_cb(objects.ui_modulation_param2_slider,    objects.ui_modulation_param2_value,    mod_format_cb);
    lv_helper_create_arc_gesture_cb(objects.ui_modulation_param3_slider,    objects.ui_modulation_param3_value,    mod_format_cb);
    lv_helper_create_arc_gesture_cb(objects.ui_modulation_param4_slider,    objects.ui_modulation_param4_value,    mod_format_cb);

    lv_keyboard_set_custom_map(objects.ui_scene_rename_dialog_keyboard);

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

static void keyboard_value_changed_cb(lv_event_t * e)
{
    lv_obj_t *keyboard = lv_event_get_target(e);
    lv_obj_t *textArea = lv_keyboard_get_textarea(keyboard);

    // uint32_t keyId = (uint32_t)(intptr_t)lv_event_get_user_data(e);
    lv_keyboard_mode_t keyboardMode = lv_keyboard_get_mode(keyboard);
    const char *text = lv_textarea_get_text(textArea);

    uint16_t buttonId = lv_btnmatrix_get_selected_btn(keyboard);
    const char *buttonText = lv_btnmatrix_get_btn_text(keyboard, buttonId);

    if (strcmp(buttonText, LV_SYMBOL_BACKSPACE) == 0) { 
        if (strlen(text) == 0 && keyboardMode == LV_KEYBOARD_MODE_TEXT_LOWER) {
            lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_UPPER);
        }
    } else if (strcmp(buttonText, LV_SYMBOL_NEW_LINE) == 0) {
    } else if (strcmp(buttonText, LV_SYMBOL_CLOSE) == 0) {
    } else if (strcmp(buttonText, LV_SYMBOL_LEFT) == 0) {
    } else if (strcmp(buttonText, LV_SYMBOL_RIGHT) == 0) {
    } else if (strcmp(buttonText, LV_SYMBOL_OK) == 0) {
    } else if (strcmp(buttonText, "abc") == 0) {
    } else if (strcmp(buttonText, "ABC") == 0) {
    } else if (strcmp(buttonText, "1#") == 0) {
    } else if (strcmp(buttonText, " ") == 0) {
    } else {
        if (strlen(text) == 1 && keyboardMode == LV_KEYBOARD_MODE_TEXT_UPPER) {
            lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
        }
    }
}

// #define C(val) (LV_BTNMATRIX_CTRL_CHECKABLE | LV_BTNMATRIX_CTRL_CHECKED | val)
#define C(val) (LV_BTNMATRIX_CTRL_CHECKED | val)

#define KB_BOTTOM_ROW_MAP \
    LV_SYMBOL_CLOSE, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK

#define KB_BOTTOM_ROW_CTRL \
    C(4),            C(2),           8,   C(2),            C(4)

void lv_keyboard_set_custom_map(lv_obj_t *obj)
{
    static const char * upper_map[] = {
        "1#",  "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n",
        "abc", "A", "S", "D", "F", "G", "H", "J", "K", "L",      LV_SYMBOL_NEW_LINE,  "\n",
        "_",   "-", "Z", "X", "C", "V", "B", "N", "M", ",", ".", ":", "\n",
        KB_BOTTOM_ROW_MAP, NULL };

    static const char * lower_map[] = {
        "1#",  "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n",
        "ABC", "a", "s", "d", "f", "g", "h", "j", "k", "l",      LV_SYMBOL_NEW_LINE,  "\n",
        "_",   "-", "z", "x", "c", "v", "b", "n", "m", ",", ".", ":", "\n",
        KB_BOTTOM_ROW_MAP, NULL
    };

    static const lv_btnmatrix_ctrl_t abc_ctrl[] = {
        C(4),  4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   C(6),
        C(6),  4,   4,   4,   4,   4,   4,   4,   4,   4,        C(6),
        4,     4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        KB_BOTTOM_ROW_CTRL };

    static const char * special_map[] = {
        "~",   "1", "2", "3", "4",  "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n",
        "abc", "!", "@", "#", "$",  "%", "^", "&", "*", "(", ")", "\n",
        "{",   "}", ";", "'", "\"", "<", ">", "/", "|", "?", "[", "]", "\n",
        KB_BOTTOM_ROW_MAP, NULL };

    static const lv_btnmatrix_ctrl_t special_ctrl[] = {
        4,     4,   4,   4,   4,    4,   4,   4,   4,   4,   4,   C(6),
        C(6),  4,   4,   4,   4,    4,   4,   4,   4,   4,   4,
        4,     4,   4,   4,   4,    4,   4,   4,   4,   4,   4,   4,
        KB_BOTTOM_ROW_CTRL };

    lv_keyboard_set_map(obj, LV_KEYBOARD_MODE_TEXT_UPPER, upper_map, abc_ctrl);
    lv_keyboard_set_map(obj, LV_KEYBOARD_MODE_TEXT_LOWER, lower_map, abc_ctrl);
    lv_keyboard_set_map(obj, LV_KEYBOARD_MODE_SPECIAL, special_map, special_ctrl);

    lv_obj_add_event_cb(obj, keyboard_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
}
#endif
