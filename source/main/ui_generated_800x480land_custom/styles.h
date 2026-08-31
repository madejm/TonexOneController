#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Button Selectable
lv_style_t *get_style_button_selectable_MAIN_DEFAULT();
lv_style_t *get_style_button_selectable_MAIN_PRESSED();
lv_style_t *get_style_button_selectable_MAIN_CHECKED();
void add_style_button_selectable(lv_obj_t *obj);
void remove_style_button_selectable(lv_obj_t *obj);

// Style: Button Basic
lv_style_t *get_style_button_basic_MAIN_DEFAULT();
lv_style_t *get_style_button_basic_MAIN_PRESSED();
void add_style_button_basic(lv_obj_t *obj);
void remove_style_button_basic(lv_obj_t *obj);

// Style: Button Secondary
lv_style_t *get_style_button_secondary_MAIN_DEFAULT();
lv_style_t *get_style_button_secondary_MAIN_PRESSED();
void add_style_button_secondary(lv_obj_t *obj);
void remove_style_button_secondary(lv_obj_t *obj);

// Style: Button Highlighted
lv_style_t *get_style_button_highlighted_MAIN_DEFAULT();
lv_style_t *get_style_button_highlighted_MAIN_PRESSED();
void add_style_button_highlighted(lv_obj_t *obj);
void remove_style_button_highlighted(lv_obj_t *obj);

// Style: Button Preset List Options
lv_style_t *get_style_button_preset_list_options_MAIN_DEFAULT();
lv_style_t *get_style_button_preset_list_options_MAIN_PRESSED();
void add_style_button_preset_list_options(lv_obj_t *obj);
void remove_style_button_preset_list_options(lv_obj_t *obj);

// Style: Button Chain
lv_style_t *get_style_button_chain_MAIN_DEFAULT();
lv_style_t *get_style_button_chain_MAIN_CHECKED();
lv_style_t *get_style_button_chain_MAIN_PRESSED();
lv_style_t *get_style_button_chain_MAIN_CHECKED_PRESSED();
void add_style_button_chain(lv_obj_t *obj);
void remove_style_button_chain(lv_obj_t *obj);

// Style: Container Preset Small
lv_style_t *get_style_container_preset_small_MAIN_DEFAULT();
lv_style_t *get_style_container_preset_small_MAIN_CHECKED();
void add_style_container_preset_small(lv_obj_t *obj);
void remove_style_container_preset_small(lv_obj_t *obj);

// Style: Button Preset
lv_style_t *get_style_button_preset_MAIN_DEFAULT();
lv_style_t *get_style_button_preset_MAIN_PRESSED();
lv_style_t *get_style_button_preset_MAIN_CHECKED();
void add_style_button_preset(lv_obj_t *obj);
void remove_style_button_preset(lv_obj_t *obj);

// Style: Button Effect
lv_style_t *get_style_button_effect_MAIN_DEFAULT();
lv_style_t *get_style_button_effect_MAIN_PRESSED();
lv_style_t *get_style_button_effect_MAIN_CHECKED();
void add_style_button_effect(lv_obj_t *obj);
void remove_style_button_effect(lv_obj_t *obj);

// Style: Label Preset Name
lv_style_t *get_style_label_preset_name_MAIN_DEFAULT();
void add_style_label_preset_name(lv_obj_t *obj);
void remove_style_label_preset_name(lv_obj_t *obj);

// Style: Container Effect On Off
lv_style_t *get_style_container_effect_on_off_MAIN_DEFAULT();
void add_style_container_effect_on_off(lv_obj_t *obj);
void remove_style_container_effect_on_off(lv_obj_t *obj);

// Style: Label Preset Index
lv_style_t *get_style_label_preset_index_MAIN_DEFAULT();
lv_style_t *get_style_label_preset_index_MAIN_CHECKED();
void add_style_label_preset_index(lv_obj_t *obj);
void remove_style_label_preset_index(lv_obj_t *obj);

// Style: Container Preset
lv_style_t *get_style_container_preset_MAIN_DEFAULT();
void add_style_container_preset(lv_obj_t *obj);
void remove_style_container_preset(lv_obj_t *obj);

// Style: Tab Settings Old
lv_style_t *get_style_tab_settings_old_MAIN_DEFAULT();
void add_style_tab_settings_old(lv_obj_t *obj);
void remove_style_tab_settings_old(lv_obj_t *obj);

// Style: Tab Sub Settings
lv_style_t *get_style_tab_sub_settings_MAIN_DEFAULT();
void add_style_tab_sub_settings(lv_obj_t *obj);
void remove_style_tab_sub_settings(lv_obj_t *obj);

// Style: Tab Settings
lv_style_t *get_style_tab_settings_MAIN_DEFAULT();
void add_style_tab_settings(lv_obj_t *obj);
void remove_style_tab_settings(lv_obj_t *obj);

// Style: Arc Settings
lv_style_t *get_style_arc_settings_KNOB_DEFAULT();
lv_style_t *get_style_arc_settings_INDICATOR_DEFAULT();
lv_style_t *get_style_arc_settings_MAIN_DEFAULT();
void add_style_arc_settings(lv_obj_t *obj);
void remove_style_arc_settings(lv_obj_t *obj);

// Style: Button Preset List
lv_style_t *get_style_button_preset_list_MAIN_DEFAULT();
lv_style_t *get_style_button_preset_list_MAIN_CHECKED();
void add_style_button_preset_list(lv_obj_t *obj);
void remove_style_button_preset_list(lv_obj_t *obj);

// Style: Container Preset List Cell
lv_style_t *get_style_container_preset_list_cell_MAIN_DEFAULT();
void add_style_container_preset_list_cell(lv_obj_t *obj);
void remove_style_container_preset_list_cell(lv_obj_t *obj);

// Style: Switch Default
lv_style_t *get_style_switch_default_MAIN_DEFAULT();
lv_style_t *get_style_switch_default_KNOB_DEFAULT();
lv_style_t *get_style_switch_default_KNOB_CHECKED();
lv_style_t *get_style_switch_default_INDICATOR_CHECKED();
void add_style_switch_default(lv_obj_t *obj);
void remove_style_switch_default(lv_obj_t *obj);

// Style: Switch Dark
lv_style_t *get_style_switch_dark_MAIN_DEFAULT();
lv_style_t *get_style_switch_dark_KNOB_DEFAULT();
lv_style_t *get_style_switch_dark_KNOB_CHECKED();
lv_style_t *get_style_switch_dark_INDICATOR_CHECKED();
void add_style_switch_dark(lv_obj_t *obj);
void remove_style_switch_dark(lv_obj_t *obj);

// Style: Label Arc Value
lv_style_t *get_style_label_arc_value_MAIN_DEFAULT();
void add_style_label_arc_value(lv_obj_t *obj);
void remove_style_label_arc_value(lv_obj_t *obj);

// Style: Tabview Sub Settings
lv_style_t *get_style_tabview_sub_settings_MAIN_DEFAULT();
void add_style_tabview_sub_settings(lv_obj_t *obj);
void remove_style_tabview_sub_settings(lv_obj_t *obj);

// Style: Bar Sub Settings
lv_style_t *get_style_bar_sub_settings_ITEMS_DEFAULT();
lv_style_t *get_style_bar_sub_settings_ITEMS_CHECKED();
lv_style_t *get_style_bar_sub_settings_MAIN_DEFAULT();
void add_style_bar_sub_settings(lv_obj_t *obj);
void remove_style_bar_sub_settings(lv_obj_t *obj);

// Style: Container Sub Settings
lv_style_t *get_style_container_sub_settings_MAIN_DEFAULT();
void add_style_container_sub_settings(lv_obj_t *obj);
void remove_style_container_sub_settings(lv_obj_t *obj);

// Style: Container Sub Settings 2
lv_style_t *get_style_container_sub_settings_2_MAIN_DEFAULT();
void add_style_container_sub_settings_2(lv_obj_t *obj);
void remove_style_container_sub_settings_2(lv_obj_t *obj);

// Style: Dropdown Sub Settings
lv_style_t *get_style_dropdown_sub_settings_MAIN_DEFAULT();
lv_style_t *get_style_dropdown_sub_settings_INDICATOR_DEFAULT();
void add_style_dropdown_sub_settings(lv_obj_t *obj);
void remove_style_dropdown_sub_settings(lv_obj_t *obj);

// Style: Dropdown List Sub Settings
lv_style_t *get_style_dropdown_list_sub_settings_MAIN_DEFAULT();
lv_style_t *get_style_dropdown_list_sub_settings_SELECTED_DEFAULT();
lv_style_t *get_style_dropdown_list_sub_settings_SELECTED_CHECKED();
void add_style_dropdown_list_sub_settings(lv_obj_t *obj);
void remove_style_dropdown_list_sub_settings(lv_obj_t *obj);

// Style: Textarea Settings
lv_style_t *get_style_textarea_settings_MAIN_DEFAULT();
lv_style_t *get_style_textarea_settings_TEXTAREA_PLACEHOLDER_DEFAULT();
void add_style_textarea_settings(lv_obj_t *obj);
void remove_style_textarea_settings(lv_obj_t *obj);

// Style: Checkbox Settings
lv_style_t *get_style_checkbox_settings_INDICATOR_DEFAULT();
lv_style_t *get_style_checkbox_settings_INDICATOR_CHECKED();
void add_style_checkbox_settings(lv_obj_t *obj);
void remove_style_checkbox_settings(lv_obj_t *obj);

// Style: Panel Preset List Color
lv_style_t *get_style_panel_preset_list_color_MAIN_DEFAULT();
void add_style_panel_preset_list_color(lv_obj_t *obj);
void remove_style_panel_preset_list_color(lv_obj_t *obj);

// Style: Button Settings Color
lv_style_t *get_style_button_settings_color_MAIN_DEFAULT();
lv_style_t *get_style_button_settings_color_MAIN_CHECKED();
void add_style_button_settings_color(lv_obj_t *obj);
void remove_style_button_settings_color(lv_obj_t *obj);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/