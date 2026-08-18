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

// Style: Button Preset List Options
lv_style_t *get_style_button_preset_list_options_MAIN_DEFAULT();
lv_style_t *get_style_button_preset_list_options_MAIN_PRESSED();
void add_style_button_preset_list_options(lv_obj_t *obj);
void remove_style_button_preset_list_options(lv_obj_t *obj);

// Style: Button Chain
lv_style_t *get_style_button_chain_MAIN_DEFAULT();
lv_style_t *get_style_button_chain_MAIN_CHECKED();
lv_style_t *get_style_button_chain_MAIN_PRESSED();
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

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/