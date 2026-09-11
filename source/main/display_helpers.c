#include "display_helpers.h"
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#include "screens.h"
#include "eq_canvas.h"
#include "tonex_params.h"
#include "control.h"
#include "actions.h"
#include "display_cab_vir.h"

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

const tCustomPresetColorMapping CustomColorMap[TONEX_COLORS_COUNT] = {
    {0xFF0000, 0xE61E2D, 0x6E0B14}, // red
    {0xFF3F00, 0xF26500, 0x6A2B00}, // orange
    {0x9FFF00, 0xD4C200, 0x5B4E00}, // yellow
    {0x00FF00, 0x00C853, 0x005E1F}, // green
    {0x0FFF2F, 0x00CFA6, 0x005A4E}, // cyan
    {0x00FFFF, 0x0096DC, 0x00547E}, // azure
    {0x0000FF, 0x4B5CF0, 0x252B70}, // blue
    {0x2F00FF, 0xA84BE5, 0x54216F}, // purple
    {0xFF00FF, 0xD03AB4, 0x68045E}, // magenta
    {0xBFBFBF, 0xF06F9D, 0x861E49}, // pink

    {0x110000, 0xB64F4F, 0x673232}, // dark red
    {0x111100, 0xA76542, 0x6A4A35}, // dark orange
    {0x112200, 0x9A8F59, 0x625A34}, // dark yellow
    {0x001100, 0x748E62, 0x40533A}, // dark green
    {0x002206, 0x559486, 0x35605A}, // dark cyan
    {0x001919, 0x4B8EAF, 0x285A70}, // dark azure
    {0x000011, 0x6B76B8, 0x3A426F}, // dark blue
    {0x050011, 0x8C63B5, 0x493B64}, // dark purple
    {0x0A000A, 0xA866A0, 0x593953}, // dark magenta
    {0x0B0B0B, 0xC67C90, 0x76515A}, // dark pink

    {0x000000, 0x7A7A7A, 0x303030}, // grey
};

tCustomPresetColorMapping getCustomPresetColorMapping(uint32_t rawColor)
{
    for (uint8_t i = 0; i < TONEX_COLORS_COUNT; i++) {
        if (CustomColorMap[i].rawColor == rawColor) {
            return CustomColorMap[i];
        }
    }

    return CustomColorMap[TONEX_COLORS_COUNT - 1];
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
    .AMP_MIX =              { .format = "%1.0f", .multiplier = 1.0f },

    .CAB_VIR_RESONANCE =    { .format = "%1.1f", .multiplier = 10.0f },
    .CAB_VIR_MIC_BLEND =    { .format = "%1.0f", .multiplier = 1.0f },
    .CAB_VIR_MIC_POS =      { .format = "%1.1f", .multiplier = 10.0f },

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

    SETUP_ARC(objects.ui_noise_gate_threshold_slider,    ParamFormats.GATE_THRESHOLD,       "dB", -100);
    SETUP_ARC(objects.ui_noise_gate_release_slider,      ParamFormats.GATE_RELEASE,         "ms",   20);
    SETUP_ARC(objects.ui_noise_gate_depth_slider,        ParamFormats.GATE_DEPTH,           "dB",   60);

    SETUP_ARC(objects.ui_compressor_threshold_slider,    ParamFormats.COMPRESSOR_THRESHOLD, "dB",    0);
    SETUP_ARC(objects.ui_compressor_gain_slider,         ParamFormats.COMPRESSOR_GAIN,      "dB",   -8);
    SETUP_ARC(objects.ui_compressor_attack_slider,       ParamFormats.COMPRESSOR_ATTACK,    "ms",    5);

    SETUP_ARC(objects.ui_amplifier_gain_slider,          ParamFormats.AMP_GAIN,             "dB",    5);
    SETUP_ARC(objects.ui_amplifier_mix_slider,           ParamFormats.AMP_MIX,              "%",   100);
    SETUP_ARC(objects.ui_amplifier_volume_slider,        ParamFormats.AMP_VOLUME,           "dB",    5);
    SETUP_ARC_CANV(objects.ui_amplifier_depth_slider,    ParamFormats.AMP_DEPTH,            "dB",    5, eq_canvas_update_depth_gain_opt);
    SETUP_ARC_CANV(objects.ui_amplifier_presense_slider, ParamFormats.AMP_PRESENCE,         "dB",    5, eq_canvas_update_presence_gain_opt);

    SETUP_ARC(objects.ui_cabinet_vir_resonance_slider,   ParamFormats.CAB_VIR_RESONANCE,    NULL,    5);
    SETUP_ARC(objects.ui_cabinet_vir_blend_slider,       ParamFormats.CAB_VIR_MIC_BLEND,    NULL,    0);
    lv_arc_set_mode(objects.ui_cabinet_vir_blend_slider__arc, LV_ARC_MODE_SYMMETRICAL);
    SETUP_ARC(objects.ui_cabinet_vir_mic1_x_slider,      ParamFormats.CAB_VIR_MIC_POS,      "X",     0);
    SETUP_ARC(objects.ui_cabinet_vir_mic1_z_slider,      ParamFormats.CAB_VIR_MIC_POS,      "Z",     0);
    SETUP_ARC(objects.ui_cabinet_vir_mic2_x_slider,      ParamFormats.CAB_VIR_MIC_POS,      "X",     0);
    SETUP_ARC(objects.ui_cabinet_vir_mic2_z_slider,      ParamFormats.CAB_VIR_MIC_POS,      "Z",     0);

    SETUP_ARC_CANV(objects.ui_eq_bass_freq_slider,       ParamFormats.EQ_BASS_FREQ,         "Hz",  300, eq_canvas_update_bass_frequency);
    SETUP_ARC_CANV(objects.ui_eq_bass_slider,            ParamFormats.EQ_BASS,              "dB",    5, eq_canvas_update_bass_gain);
    SETUP_ARC_CANV(objects.ui_eq_mid_freq_slider,        ParamFormats.EQ_MID_FREQ,          "Hz",  750, eq_canvas_update_mid_frequency);
    SETUP_ARC_CANV(objects.ui_eq_mid_qslider,            ParamFormats.EQ_MID_Q,             "Q",   0.7, eq_canvas_update_mid_q);
    SETUP_ARC_CANV(objects.ui_eq_mid_slider,             ParamFormats.EQ_MID,               "dB",    5, eq_canvas_update_mid_gain);
    SETUP_ARC_CANV(objects.ui_eq_treble_freq_slider,     ParamFormats.EQ_TREBLE_FREQ,       "Hz", 2000, eq_canvas_update_treble_frequency);
    SETUP_ARC_CANV(objects.ui_eq_treble_slider,          ParamFormats.EQ_TREBLE,            "dB",    5, eq_canvas_update_treble_gain);

    SETUP_ARC(objects.ui_delay_ts_slider,                ParamFormats.DELAY_TIME,           "ms",  350);
    SETUP_ARC(objects.ui_delay_mix_slider,               ParamFormats.DELAY_MIX,            "%",    50);
    SETUP_ARC(objects.ui_delay_feedback_slider,          ParamFormats.DELAY_FEEDBACK,       "%",    20);

    SETUP_ARC(objects.ui_reverb_time_slider,             ParamFormats.REVERB_TIME,          "s",     5);
    SETUP_ARC(objects.ui_reverb_predelay_slider,         ParamFormats.REVERB_PREDELAY,      "ms",    0);
    SETUP_ARC(objects.ui_reverb_color_slider,            ParamFormats.REVERB_COLOR,         NULL,    0);
    SETUP_ARC(objects.ui_reverb_mix_slider,              ParamFormats.REVERB_MIX,           "%",    30);

    SETUP_ARC(objects.ui_bpm_slider,                     ParamFormats.BPM,                  NULL,  120);
    SETUP_ARC(objects.ui_input_trim_slider,              ParamFormats.INPUT_TRIM,           "dB",    0);
    SETUP_ARC(objects.ui_tuning_reference_slider,        ParamFormats.TUNING_REF,           "Hz",  440);
    SETUP_ARC(objects.ui_volume_slider,                  ParamFormats.MASTER,               "dB",    5);

    SETUP_ARC_FORMAT_CB(objects.ui_modulation_param1_slider,    mod_format_cb);
    SETUP_ARC_FORMAT_CB(objects.ui_modulation_param2_slider,    mod_format_cb);
    SETUP_ARC_FORMAT_CB(objects.ui_modulation_param3_slider,    mod_format_cb);
    SETUP_ARC_FORMAT_CB(objects.ui_modulation_param4_slider,    mod_format_cb);

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
