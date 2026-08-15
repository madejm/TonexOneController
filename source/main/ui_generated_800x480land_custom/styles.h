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

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/