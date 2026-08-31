#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Screens

enum ScreensEnum {
    _SCREEN_ID_FIRST = 1,
    SCREEN_ID_SCREEN1 = 1,
    SCREEN_ID_SETTINGS = 2,
    SCREEN_ID_PRESETS = 3,
    _SCREEN_ID_LAST = 3
};

typedef struct _objects_t {
    lv_obj_t *screen1;
    lv_obj_t *settings;
    lv_obj_t *presets;
    lv_obj_t *obj0;
    lv_obj_t *ui_usb_button;
    lv_obj_t *ui_wi_fi_button;
    lv_obj_t *ui_bt_midi_button;
    lv_obj_t *ui_bt_app_button;
    lv_obj_t *ui_bpm_button;
    lv_obj_t *ui_bpm_title_label_1;
    lv_obj_t *ui_bpm_value_label;
    lv_obj_t *ui_bpm_indicator;
    lv_obj_t *ui_settings_button;
    lv_obj_t *ui_alt_button;
    lv_obj_t *ui_buttons_regular;
    lv_obj_t *ui_buttons_top;
    lv_obj_t *ui_effect_button7;
    lv_obj_t *ui_effect_label7;
    lv_obj_t *ui_effect_label7_off;
    lv_obj_t *ui_effect_label7_on;
    lv_obj_t *ui_effect_button_small7;
    lv_obj_t *ui_effect_label_small7;
    lv_obj_t *ui_effect_button8;
    lv_obj_t *ui_effect_label8;
    lv_obj_t *ui_effect_label8_off;
    lv_obj_t *ui_effect_label8_on;
    lv_obj_t *ui_effect_button_small8;
    lv_obj_t *ui_effect_label_small8;
    lv_obj_t *ui_effect_button6;
    lv_obj_t *ui_effect_label6;
    lv_obj_t *ui_effect_label6_off;
    lv_obj_t *ui_effect_label6_on;
    lv_obj_t *ui_effect_button_small6;
    lv_obj_t *ui_effect_label_small6;
    lv_obj_t *ui_buttons_bottom;
    lv_obj_t *ui_effect_button1;
    lv_obj_t *ui_effect_label1;
    lv_obj_t *ui_effect_label1_off;
    lv_obj_t *ui_effect_label1_on;
    lv_obj_t *ui_preset_index1;
    lv_obj_t *ui_effect_button_small1;
    lv_obj_t *ui_effect_label_small1;
    lv_obj_t *ui_effect_button2;
    lv_obj_t *ui_effect_label2;
    lv_obj_t *ui_effect_label2_off;
    lv_obj_t *ui_effect_label2_on;
    lv_obj_t *ui_preset_index2;
    lv_obj_t *ui_effect_button_small2;
    lv_obj_t *ui_effect_label_small2;
    lv_obj_t *ui_effect_button3;
    lv_obj_t *ui_effect_label3;
    lv_obj_t *ui_effect_label3_off;
    lv_obj_t *ui_effect_label3_on;
    lv_obj_t *ui_preset_index3;
    lv_obj_t *ui_effect_button_small3;
    lv_obj_t *ui_effect_label_small3;
    lv_obj_t *ui_effect_button4;
    lv_obj_t *ui_effect_label4;
    lv_obj_t *ui_effect_label4_off;
    lv_obj_t *ui_effect_label4_on;
    lv_obj_t *ui_preset_index4;
    lv_obj_t *ui_effect_button_small4;
    lv_obj_t *ui_effect_label_small4;
    lv_obj_t *ui_effect_button5;
    lv_obj_t *ui_effect_label5;
    lv_obj_t *ui_effect_label5_off;
    lv_obj_t *ui_effect_label5_on;
    lv_obj_t *ui_effect_button_small5;
    lv_obj_t *ui_effect_label_small5;
    lv_obj_t *ui_preset_details;
    lv_obj_t *ui_preset_number_label;
    lv_obj_t *ui_preset_letter_label;
    lv_obj_t *ui_preset_heading_label;
    lv_obj_t *ui_effect_chain_container;
    lv_obj_t *obj1;
    lv_obj_t *ui_icon_gate;
    lv_obj_t *ui_icon_image_gate;
    lv_obj_t *ui_icon_comp;
    lv_obj_t *ui_icon_image_comp;
    lv_obj_t *ui_icon_amp;
    lv_obj_t *ui_icon_image_amp;
    lv_obj_t *ui_icon_cab;
    lv_obj_t *ui_icon_image_cab;
    lv_obj_t *ui_cab_global_disabled;
    lv_obj_t *ui_icon_eq;
    lv_obj_t *ui_icon_image_eq;
    lv_obj_t *ui_icon_mod;
    lv_obj_t *ui_icon_image_mod;
    lv_obj_t *ui_icon_delay;
    lv_obj_t *ui_icon_image_delay;
    lv_obj_t *ui_icon_reverb;
    lv_obj_t *ui_icon_image_reverb;
    lv_obj_t *ui_settings_tab_view;
    lv_obj_t *obj2;
    lv_obj_t *ui_gate_tab;
    lv_obj_t *obj3;
    lv_obj_t *ui_noise_gate_switch;
    lv_obj_t *obj4;
    lv_obj_t *ui_noise_gate_post_switch;
    lv_obj_t *ui_settings_paste_gate;
    lv_obj_t *obj5;
    lv_obj_t *ui_noise_gate_threshold_slider;
    lv_obj_t *ui_noise_gate_threshold_value;
    lv_obj_t *obj6;
    lv_obj_t *ui_noise_gate_release_slider;
    lv_obj_t *ui_noise_gate_release_value;
    lv_obj_t *obj7;
    lv_obj_t *ui_noise_gate_depth_slider;
    lv_obj_t *ui_noise_gate_depth_value;
    lv_obj_t *ui_compresssor_tab;
    lv_obj_t *obj8;
    lv_obj_t *ui_compressor_enable_switch;
    lv_obj_t *obj9;
    lv_obj_t *ui_compressor_post_switch;
    lv_obj_t *ui_settings_paste_compressor;
    lv_obj_t *obj10;
    lv_obj_t *ui_compressor_threshold_slider;
    lv_obj_t *ui_compressor_threshold_value;
    lv_obj_t *obj11;
    lv_obj_t *ui_compressor_gain_slider;
    lv_obj_t *ui_compressor_gain_value;
    lv_obj_t *obj12;
    lv_obj_t *ui_compressor_attack_slider;
    lv_obj_t *ui_compressor_attack_value;
    lv_obj_t *ui_amp_tab;
    lv_obj_t *obj13;
    lv_obj_t *ui_amp_enable_switch;
    lv_obj_t *obj14;
    lv_obj_t *ui_cabinet_model_dropdown;
    lv_obj_t *ui_settings_paste_amp;
    lv_obj_t *obj15;
    lv_obj_t *ui_amplifier_gain_slider;
    lv_obj_t *ui_amplifier_gain_value;
    lv_obj_t *obj16;
    lv_obj_t *ui_amplifier_volume_slider;
    lv_obj_t *ui_amplifier_volume_value;
    lv_obj_t *ui_eq_tab;
    lv_obj_t *ui_eq_canvas;
    lv_obj_t *ui_amplifier_depth_slider;
    lv_obj_t *ui_amplifier_depth_value;
    lv_obj_t *ui_eq_bass_freq_slider;
    lv_obj_t *ui_eq_bass_freq_value;
    lv_obj_t *ui_eq_bass_slider;
    lv_obj_t *ui_eq_bass_value;
    lv_obj_t *ui_eq_mid_freq_slider;
    lv_obj_t *ui_eq_mid_freq_value;
    lv_obj_t *ui_eq_mid_qslider;
    lv_obj_t *ui_eq_mid_qvalue;
    lv_obj_t *ui_eq_mid_slider;
    lv_obj_t *ui_eq_mid_value;
    lv_obj_t *ui_eq_treble_freq_slider;
    lv_obj_t *ui_eq_treble_freq_value;
    lv_obj_t *ui_eq_treble_slider;
    lv_obj_t *ui_eq_treble_value;
    lv_obj_t *ui_amplifier_presense_slider;
    lv_obj_t *ui_amplifier_presense_value;
    lv_obj_t *ui_settings_paste_eq;
    lv_obj_t *ui_eq_post_switch;
    lv_obj_t *ui_modulation_tab;
    lv_obj_t *obj17;
    lv_obj_t *ui_modulation_enable_switch;
    lv_obj_t *obj18;
    lv_obj_t *ui_modulation_post_switch;
    lv_obj_t *obj19;
    lv_obj_t *ui_modulation_sync_switch;
    lv_obj_t *obj20;
    lv_obj_t *ui_modulation_model_dropdown;
    lv_obj_t *ui_settings_paste_modulation;
    lv_obj_t *ui_modulation_param1_label;
    lv_obj_t *ui_modulation_param1_slider;
    lv_obj_t *ui_modulation_param1_value;
    lv_obj_t *ui_modulation_param1_unit;
    lv_obj_t *ui_modulation_ts_dropdown;
    lv_obj_t *ui_modulation_param2_label;
    lv_obj_t *ui_modulation_param2_slider;
    lv_obj_t *ui_modulation_param2_value;
    lv_obj_t *ui_modulation_param2_unit;
    lv_obj_t *ui_modulation_param3_label;
    lv_obj_t *ui_modulation_param3_slider;
    lv_obj_t *ui_modulation_param3_value;
    lv_obj_t *ui_modulation_param3_unit;
    lv_obj_t *ui_modulation_param4_label;
    lv_obj_t *ui_modulation_param4_slider;
    lv_obj_t *ui_modulation_param4_value;
    lv_obj_t *ui_modulation_param4_unit;
    lv_obj_t *ui_delay_tab;
    lv_obj_t *obj21;
    lv_obj_t *ui_delay_enable_switch;
    lv_obj_t *obj22;
    lv_obj_t *ui_delay_post_switch;
    lv_obj_t *obj23;
    lv_obj_t *ui_delay_sync_switch;
    lv_obj_t *obj24;
    lv_obj_t *ui_delay_ping_pong_switch;
    lv_obj_t *obj25;
    lv_obj_t *ui_delay_model_dropdown;
    lv_obj_t *ui_settings_paste_delay;
    lv_obj_t *obj26;
    lv_obj_t *ui_delay_ts_slider;
    lv_obj_t *ui_delay_ts_value;
    lv_obj_t *ui_delay_ts_dropdown;
    lv_obj_t *obj27;
    lv_obj_t *ui_delay_feedback_slider;
    lv_obj_t *ui_delay_feedback_value;
    lv_obj_t *obj28;
    lv_obj_t *ui_delay_mix_slider;
    lv_obj_t *ui_delay_mix_value;
    lv_obj_t *ui_reverb_tab;
    lv_obj_t *obj29;
    lv_obj_t *ui_reverb_enable_switch;
    lv_obj_t *obj30;
    lv_obj_t *ui_reverb_post_switch;
    lv_obj_t *obj31;
    lv_obj_t *ui_reverb_model_dropdown;
    lv_obj_t *ui_settings_paste_reverb;
    lv_obj_t *obj32;
    lv_obj_t *ui_reverb_time_slider;
    lv_obj_t *ui_reverb_time_value;
    lv_obj_t *obj33;
    lv_obj_t *ui_reverb_predelay_slider;
    lv_obj_t *ui_reverb_predelay_value;
    lv_obj_t *obj34;
    lv_obj_t *ui_reverb_color_slider;
    lv_obj_t *ui_reverb_color_value;
    lv_obj_t *obj35;
    lv_obj_t *ui_reverb_mix_slider;
    lv_obj_t *ui_reverb_mix_value;
    lv_obj_t *ui_global_tab;
    lv_obj_t *obj36;
    lv_obj_t *ui_cab_bypass_switch;
    lv_obj_t *obj37;
    lv_obj_t *ui_tempo_source_switch;
    lv_obj_t *obj38;
    lv_obj_t *ui_bpm_slider;
    lv_obj_t *ui_bpm_value;
    lv_obj_t *obj39;
    lv_obj_t *ui_input_trim_slider;
    lv_obj_t *ui_input_trim_value;
    lv_obj_t *obj40;
    lv_obj_t *ui_tuning_reference_slider;
    lv_obj_t *ui_tuning_reference_value;
    lv_obj_t *obj41;
    lv_obj_t *ui_volume_slider;
    lv_obj_t *ui_volume_value;
    lv_obj_t *ui_wi_fi_tab;
    lv_obj_t *ui_wifi_mode_dropdown;
    lv_obj_t *ui_wifi_power_dropdown;
    lv_obj_t *ui_wifi_ssid_textarea;
    lv_obj_t *ui_wifi_password_textarea;
    lv_obj_t *ui_mdns_name_textarea;
    lv_obj_t *obj42;
    lv_obj_t *ui_wi_fi_switch;
    lv_obj_t *ui_usb_tab;
    lv_obj_t *ui_usb_reboot_button;
    lv_obj_t *ui_usb_flash_button;
    lv_obj_t *obj43;
    lv_obj_t *ui_controller_dialog;
    lv_obj_t *obj44;
    lv_obj_t *ui_controller_dialog_entry;
    lv_obj_t *ui_controller_dialog_keyboard;
    lv_obj_t *ui_settings_dialog;
    lv_obj_t *ui_settings_text_entry;
    lv_obj_t *ui_settings_keyboard;
    lv_obj_t *ui_preset_list_cancel_button;
    lv_obj_t *obj45;
    lv_obj_t *ui_preset_list_element_0;
    lv_obj_t *ui_preset_list_button_0;
    lv_obj_t *ui_preset_list_color_0;
    lv_obj_t *ui_preset_list_label_0;
    lv_obj_t *ui_preset_list_element_1;
    lv_obj_t *ui_preset_list_button_1;
    lv_obj_t *ui_preset_list_color_1;
    lv_obj_t *ui_preset_list_label_1;
    lv_obj_t *ui_preset_list_element_2;
    lv_obj_t *ui_preset_list_button_2;
    lv_obj_t *ui_preset_list_color_2;
    lv_obj_t *ui_preset_list_label_2;
    lv_obj_t *ui_preset_list_element_3;
    lv_obj_t *ui_preset_list_button_3;
    lv_obj_t *ui_preset_list_color_3;
    lv_obj_t *ui_preset_list_label_3;
    lv_obj_t *ui_preset_list_element_4;
    lv_obj_t *ui_preset_list_button_4;
    lv_obj_t *ui_preset_list_color_4;
    lv_obj_t *ui_preset_list_label_4;
    lv_obj_t *ui_preset_list_element_5;
    lv_obj_t *ui_preset_list_button_5;
    lv_obj_t *ui_preset_list_color_5;
    lv_obj_t *ui_preset_list_label_5;
    lv_obj_t *ui_preset_list_element_6;
    lv_obj_t *ui_preset_list_button_6;
    lv_obj_t *ui_preset_list_color_6;
    lv_obj_t *ui_preset_list_label_6;
    lv_obj_t *ui_preset_list_element_7;
    lv_obj_t *ui_preset_list_button_7;
    lv_obj_t *ui_preset_list_color_7;
    lv_obj_t *ui_preset_list_label_7;
    lv_obj_t *ui_preset_list_element_8;
    lv_obj_t *ui_preset_list_button_8;
    lv_obj_t *ui_preset_list_color_8;
    lv_obj_t *ui_preset_list_label_8;
    lv_obj_t *ui_preset_list_element_9;
    lv_obj_t *ui_preset_list_button_9;
    lv_obj_t *ui_preset_list_color_9;
    lv_obj_t *ui_preset_list_label_9;
    lv_obj_t *ui_preset_list_dialog;
    lv_obj_t *obj46;
    lv_obj_t *ui_preset_list_dialog_name;
    lv_obj_t *ui_preset_list_dialog_button_insert;
    lv_obj_t *ui_preset_list_dialog_button_swap;
    lv_obj_t *ui_preset_list_color0;
    lv_obj_t *ui_preset_list_color1;
    lv_obj_t *ui_preset_list_color2;
    lv_obj_t *ui_preset_list_color3;
    lv_obj_t *ui_preset_list_color4;
    lv_obj_t *ui_preset_list_color5;
    lv_obj_t *ui_preset_list_color6;
    lv_obj_t *ui_preset_list_color7;
    lv_obj_t *ui_preset_list_color8;
    lv_obj_t *ui_preset_list_color9;
    lv_obj_t *ui_preset_list_color10;
    lv_obj_t *ui_preset_list_color11;
    lv_obj_t *ui_preset_list_color12;
    lv_obj_t *ui_preset_list_color13;
    lv_obj_t *ui_preset_list_color14;
    lv_obj_t *ui_preset_list_color15;
    lv_obj_t *ui_preset_list_color16;
    lv_obj_t *ui_preset_list_color17;
    lv_obj_t *ui_preset_list_color18;
    lv_obj_t *ui_preset_list_color19;
    lv_obj_t *ui_preset_list_color20;
    lv_obj_t *obj47;
} objects_t;

extern objects_t objects;

void create_screen_screen1();
void tick_screen_screen1();

void create_screen_settings();
void tick_screen_settings();

void create_screen_presets();
void tick_screen_presets();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

// Color themes

enum Themes {
    THEME_ID_DEFAULT,
};
enum Colors {
    COLOR_ID_BUTTON_PRIMARY,
    COLOR_ID_BUTTON_SECONDARY,
    COLOR_ID_HIGHLIGHT,
    COLOR_ID_LABEL_GRAY,
    COLOR_ID_NOISE_GATE,
    COLOR_ID_NOISE_GATE_1,
    COLOR_ID_COMPRESSOR,
    COLOR_ID_AMPLIFIER,
    COLOR_ID_CABINET,
    COLOR_ID_DEFAULT_GRAY,
    COLOR_ID_MODULATION,
    COLOR_ID_DELAY,
    COLOR_ID_REVERB,
};
void change_color_theme(uint32_t themeIndex);
extern uint32_t theme_colors[1][13];
extern uint32_t active_theme_index;

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/