#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Button Selectable
//

void init_style_button_selectable_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_radius(style, 8);
    lv_style_set_text_font(style, &ui_font_ibm_18);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_text_opa(style, 255);
    lv_style_set_pad_left(style, 17);
    lv_style_set_pad_right(style, 17);
    lv_style_set_pad_top(style, 2);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_border_width(style, 3);
    lv_style_set_border_opa(style, 0);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
};

lv_style_t *get_style_button_selectable_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_selectable_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_selectable_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][1]));
};

lv_style_t *get_style_button_selectable_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_selectable_MAIN_PRESSED(style);
    }
    return style;
};

void init_style_button_selectable_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_bg_opa(style, 50);
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_border_opa(style, 255);
};

lv_style_t *get_style_button_selectable_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_selectable_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_button_selectable(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_selectable_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_selectable_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_add_style(obj, get_style_button_selectable_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_button_selectable(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_selectable_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_selectable_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_remove_style(obj, get_style_button_selectable_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: Button Basic
//

void init_style_button_basic_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_radius(style, 8);
    lv_style_set_text_font(style, &ui_font_ibm_18);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_text_opa(style, 255);
    lv_style_set_pad_left(style, 20);
    lv_style_set_pad_right(style, 20);
    lv_style_set_pad_top(style, 2);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
};

lv_style_t *get_style_button_basic_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_basic_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_basic_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][1]));
};

lv_style_t *get_style_button_basic_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_basic_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_button_basic(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_basic_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_basic_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_button_basic(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_basic_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_basic_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: Button Preset List Options
//

void init_style_button_preset_list_options_MAIN_DEFAULT(lv_style_t *style) {
    init_style_button_basic_MAIN_DEFAULT(style);
    
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 15);
    lv_style_set_pad_right(style, 10);
    lv_style_set_radius(style, 12);
};

lv_style_t *get_style_button_preset_list_options_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_list_options_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_preset_list_options_MAIN_PRESSED(lv_style_t *style) {
    init_style_button_basic_MAIN_PRESSED(style);
    
};

lv_style_t *get_style_button_preset_list_options_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_list_options_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_button_preset_list_options(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_preset_list_options_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_preset_list_options_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_button_preset_list_options(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_preset_list_options_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_preset_list_options_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: Button Chain
//

void init_style_button_chain_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_border_color(style, lv_color_hex(0xffffff));
    lv_style_set_border_opa(style, 255);
    lv_style_set_border_width(style, 2);
    lv_style_set_radius(style, 12);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_opa(style, 80);
    lv_style_set_blend_mode(style, LV_BLEND_MODE_ADDITIVE);
};

lv_style_t *get_style_button_chain_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_chain_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_chain_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_opa(style, 255);
    lv_style_set_blend_mode(style, LV_BLEND_MODE_NORMAL);
    lv_style_set_bg_color(style, lv_color_hex(0x000000));
};

lv_style_t *get_style_button_chain_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_chain_MAIN_CHECKED(style);
    }
    return style;
};

void init_style_button_chain_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_blend_mode(style, LV_BLEND_MODE_NORMAL);
    lv_style_set_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(0x000000));
};

lv_style_t *get_style_button_chain_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_chain_MAIN_PRESSED(style);
    }
    return style;
};

void add_style_button_chain(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_chain_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_chain_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_button_chain_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

void remove_style_button_chain(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_chain_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_chain_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_button_chain_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
};

//
// Style: Container Preset Small
//

void init_style_container_preset_small_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_left(style, 4);
    lv_style_set_pad_right(style, 4);
    lv_style_set_text_font(style, &ui_font_ibm_22);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_CENTER);
    lv_style_set_radius(style, 8);
    lv_style_set_clip_corner(style, true);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][1]));
    lv_style_set_bg_opa(style, 76);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_height(style, 23);
    lv_style_set_min_height(style, 23);
    lv_style_set_pad_bottom(style, -1);
    lv_style_set_pad_top(style, 1);
};

lv_style_t *get_style_container_preset_small_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_preset_small_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_container_preset_small_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_text_color(style, lv_color_hex(0x000000));
    lv_style_set_bg_color(style, lv_color_hex(0xffffff));
};

lv_style_t *get_style_container_preset_small_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_preset_small_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_container_preset_small(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_preset_small_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_container_preset_small_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_container_preset_small(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_preset_small_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_container_preset_small_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: Button Preset
//

void init_style_button_preset_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 0);
    lv_style_set_pad_row(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_column(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_radius(style, 8);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_text_align(style, LV_TEXT_ALIGN_LEFT);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_style_set_bg_opa(style, 76);
    lv_style_set_text_font(style, &ui_font_ibm_36);
};

lv_style_t *get_style_button_preset_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_button_preset_MAIN_PRESSED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 128);
};

lv_style_t *get_style_button_preset_MAIN_PRESSED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_MAIN_PRESSED(style);
    }
    return style;
};

void init_style_button_preset_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(0xffffff));
    lv_style_set_text_color(style, lv_color_hex(0x000000));
};

lv_style_t *get_style_button_preset_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_button_preset(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_preset_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_button_preset_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_add_style(obj, get_style_button_preset_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_button_preset(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_preset_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_button_preset_MAIN_PRESSED(), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_remove_style(obj, get_style_button_preset_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: Label Preset Name
//

void init_style_label_preset_name_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_left(style, 8);
    lv_style_set_pad_right(style, 8);
    lv_style_set_pad_top(style, 8);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_LEFT);
    lv_style_set_text_font(style, &ui_font_ibm_36);
};

lv_style_t *get_style_label_preset_name_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_preset_name_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_preset_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_preset_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_preset_name(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_preset_name_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Container Effect On Off
//

void init_style_container_effect_on_off_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(style, 2);
    lv_style_set_pad_bottom(style, 8);
    lv_style_set_pad_left(style, 8);
    lv_style_set_pad_right(style, 8);
    lv_style_set_text_font(style, &ui_font_ibm_22);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
};

lv_style_t *get_style_container_effect_on_off_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_effect_on_off_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_effect_on_off(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_effect_on_off_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_effect_on_off(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_effect_on_off_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Label Preset Index
//

void init_style_label_preset_index_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_ibm_72);
    lv_style_set_text_align(style, LV_TEXT_ALIGN_RIGHT);
    lv_style_set_pad_right(style, 8);
    lv_style_set_pad_left(style, 8);
    lv_style_set_opa(style, 192);
};

lv_style_t *get_style_label_preset_index_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_preset_index_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_label_preset_index_MAIN_CHECKED(lv_style_t *style) {
    lv_style_set_opa(style, 165);
    lv_style_set_text_color(style, lv_color_hex(0x000000));
};

lv_style_t *get_style_label_preset_index_MAIN_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_preset_index_MAIN_CHECKED(style);
    }
    return style;
};

void add_style_label_preset_index(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_preset_index_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_label_preset_index_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

void remove_style_label_preset_index(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_preset_index_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_label_preset_index_MAIN_CHECKED(), LV_PART_MAIN | LV_STATE_CHECKED);
};

//
// Style: Container Preset
//

void init_style_container_preset_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_pad_row(style, 1);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
};

lv_style_t *get_style_container_preset_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_preset_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_preset(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_preset_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_preset(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_preset_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tab Settings Old
//

void init_style_tab_settings_old_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_top(style, 12);
    lv_style_set_pad_bottom(style, 12);
    lv_style_set_pad_left(style, 12);
    lv_style_set_pad_right(style, 12);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
};

lv_style_t *get_style_tab_settings_old_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_settings_old_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_settings_old(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_settings_old_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_settings_old(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_settings_old_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tab Sub Settings
//

void init_style_tab_sub_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_pad_column(style, 20);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_pad_top(style, 8);
    lv_style_set_pad_bottom(style, 12);
    lv_style_set_pad_left(style, 12);
    lv_style_set_pad_right(style, 12);
};

lv_style_t *get_style_tab_sub_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_sub_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tab Settings
//

void init_style_tab_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_bottom(style, 12);
    lv_style_set_pad_left(style, 12);
    lv_style_set_pad_right(style, 12);
    lv_style_set_pad_row(style, 8);
    lv_style_set_pad_column(style, 0);
    lv_style_set_pad_top(style, 12);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_END);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
};

lv_style_t *get_style_tab_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tab_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tab_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tab_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tab_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tab_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Arc Settings
//

void init_style_arc_settings_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_opa(style, 0);
};

lv_style_t *get_style_arc_settings_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_settings_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_arc_settings_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_arc_width(style, 8);
    lv_style_set_arc_rounded(style, true);
    lv_style_set_pad_top(style, 4);
};

lv_style_t *get_style_arc_settings_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_settings_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_arc_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_arc_width(style, 16);
    lv_style_set_arc_color(style, lv_color_hex(0x000000));
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_text_color(style, lv_color_hex(0x6f6f6f));
    lv_style_set_text_font(style, &ui_font_ibm_32);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
};

lv_style_t *get_style_arc_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_arc_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_arc_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_arc_settings_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_settings_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_arc_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_arc_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_arc_settings_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_settings_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_arc_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Button Preset List
//

void init_style_button_preset_list_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_left(style, 8);
    lv_style_set_pad_right(style, 8);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_radius(style, 12);
    lv_style_set_outline_width(style, 2);
    lv_style_set_outline_color(style, lv_color_hex(0xffa000));
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_outline_opa(style, 0);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_text_font(style, &ui_font_ibm_22);
};

lv_style_t *get_style_button_preset_list_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_button_preset_list_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_button_preset_list(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_button_preset_list_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_button_preset_list(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_button_preset_list_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Container Preset List Cell
//

void init_style_container_preset_list_cell_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    {
        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_row_dsc_array(style, dsc);
    }
    {
        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
        lv_style_set_grid_column_dsc_array(style, dsc);
    }
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_pad_top(style, 4);
    lv_style_set_pad_bottom(style, 4);
    lv_style_set_pad_left(style, 4);
    lv_style_set_pad_right(style, 4);
    lv_style_set_pad_column(style, 4);
};

lv_style_t *get_style_container_preset_list_cell_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_preset_list_cell_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_preset_list_cell(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_preset_list_cell_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_preset_list_cell(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_preset_list_cell_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Switch Default
//

void init_style_switch_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][1]));
};

lv_style_t *get_style_switch_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_default_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_switch_default_KNOB_DEFAULT(lv_style_t *style) {
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_border_opa(style, 255);
    lv_style_set_border_width(style, 4);
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_switch_default_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_default_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_switch_default_KNOB_CHECKED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
};

lv_style_t *get_style_switch_default_KNOB_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_default_KNOB_CHECKED(style);
    }
    return style;
};

void init_style_switch_default_INDICATOR_CHECKED(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_switch_default_INDICATOR_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_default_INDICATOR_CHECKED(style);
    }
    return style;
};

void add_style_switch_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_switch_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_default_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_default_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_switch_default_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

void remove_style_switch_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_switch_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_default_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_default_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_switch_default_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

//
// Style: Switch Dark
//

void init_style_switch_dark_MAIN_DEFAULT(lv_style_t *style) {
    init_style_switch_default_MAIN_DEFAULT(style);
    
    lv_style_set_bg_color(style, lv_color_hex(0x000000));
};

lv_style_t *get_style_switch_dark_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_dark_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_switch_dark_KNOB_DEFAULT(lv_style_t *style) {
    init_style_switch_default_KNOB_DEFAULT(style);
    
};

lv_style_t *get_style_switch_dark_KNOB_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_dark_KNOB_DEFAULT(style);
    }
    return style;
};

void init_style_switch_dark_KNOB_CHECKED(lv_style_t *style) {
    init_style_switch_default_KNOB_CHECKED(style);
    
};

lv_style_t *get_style_switch_dark_KNOB_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_dark_KNOB_CHECKED(style);
    }
    return style;
};

void init_style_switch_dark_INDICATOR_CHECKED(lv_style_t *style) {
    init_style_switch_default_INDICATOR_CHECKED(style);
    
};

lv_style_t *get_style_switch_dark_INDICATOR_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_switch_dark_INDICATOR_CHECKED(style);
    }
    return style;
};

void add_style_switch_dark(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_switch_dark_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_dark_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_switch_dark_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_switch_dark_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

void remove_style_switch_dark(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_switch_dark_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_dark_KNOB_DEFAULT(), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_switch_dark_KNOB_CHECKED(), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_switch_dark_INDICATOR_CHECKED(), LV_PART_INDICATOR | LV_STATE_CHECKED);
};

//
// Style: Label Arc Value
//

void init_style_label_arc_value_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
};

lv_style_t *get_style_label_arc_value_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label_arc_value_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label_arc_value(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label_arc_value_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label_arc_value(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label_arc_value_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Tabview Sub Settings
//

void init_style_tabview_sub_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
};

lv_style_t *get_style_tabview_sub_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_tabview_sub_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_tabview_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_tabview_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_tabview_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_tabview_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Bar Sub Settings
//

void init_style_bar_sub_settings_ITEMS_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][1]));
    lv_style_set_radius(style, 8);
};

lv_style_t *get_style_bar_sub_settings_ITEMS_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_sub_settings_ITEMS_DEFAULT(style);
    }
    return style;
};

void init_style_bar_sub_settings_ITEMS_CHECKED(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_border_color(style, lv_color_hex(theme_colors[active_theme_index][2]));
    lv_style_set_border_side(style, LV_BORDER_SIDE_FULL);
    lv_style_set_border_width(style, 2);
    lv_style_set_bg_opa(style, 50);
};

lv_style_t *get_style_bar_sub_settings_ITEMS_CHECKED() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_sub_settings_ITEMS_CHECKED(style);
    }
    return style;
};

void init_style_bar_sub_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_pad_column(style, 8);
    lv_style_set_bg_opa(style, 0);
    lv_style_set_pad_top(style, 4);
    lv_style_set_pad_bottom(style, 4);
    lv_style_set_pad_left(style, 4);
    lv_style_set_pad_right(style, 4);
};

lv_style_t *get_style_bar_sub_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_sub_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_bar_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_bar_sub_settings_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_bar_sub_settings_ITEMS_CHECKED(), LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_add_style(obj, get_style_bar_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_bar_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_bar_sub_settings_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_bar_sub_settings_ITEMS_CHECKED(), LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_remove_style(obj, get_style_bar_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Container Sub Settings
//

void init_style_container_sub_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_pad_column(style, 12);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_radius(style, 12);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_pad_top(style, 12);
    lv_style_set_pad_bottom(style, 12);
    lv_style_set_pad_left(style, 12);
    lv_style_set_pad_right(style, 12);
    lv_style_set_pad_row(style, 12);
};

lv_style_t *get_style_container_sub_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_sub_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Container Sub Settings 2
//

void init_style_container_sub_settings_2_MAIN_DEFAULT(lv_style_t *style) {
    init_style_container_sub_settings_MAIN_DEFAULT(style);
    
    lv_style_set_pad_column(style, 12);
    lv_style_set_bg_color(style, lv_color_hex(theme_colors[active_theme_index][0]));
    lv_style_set_bg_opa(style, 255);
    lv_style_set_radius(style, 12);
    lv_style_set_pad_top(style, 0);
    lv_style_set_pad_bottom(style, 0);
    lv_style_set_pad_right(style, 0);
    lv_style_set_pad_row(style, 10);
    lv_style_set_pad_left(style, 0);
};

lv_style_t *get_style_container_sub_settings_2_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_sub_settings_2_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_sub_settings_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_sub_settings_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_sub_settings_2(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_sub_settings_2_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Dropdown Sub Settings
//

void init_style_dropdown_sub_settings_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_color(style, lv_color_hex(0x000000));
    lv_style_set_text_font(style, &ui_font_ibm_22);
    lv_style_set_text_color(style, lv_color_hex(0xffffff));
    lv_style_set_border_width(style, 0);
};

lv_style_t *get_style_dropdown_sub_settings_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_dropdown_sub_settings_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_dropdown_sub_settings_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &lv_font_montserrat_20);
};

lv_style_t *get_style_dropdown_sub_settings_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = (lv_style_t *)lv_mem_alloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_dropdown_sub_settings_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_dropdown_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_dropdown_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_dropdown_sub_settings_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_dropdown_sub_settings(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_dropdown_sub_settings_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_dropdown_sub_settings_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_button_selectable,
        add_style_button_basic,
        add_style_button_preset_list_options,
        add_style_button_chain,
        add_style_container_preset_small,
        add_style_button_preset,
        add_style_label_preset_name,
        add_style_container_effect_on_off,
        add_style_label_preset_index,
        add_style_container_preset,
        add_style_tab_settings_old,
        add_style_tab_sub_settings,
        add_style_tab_settings,
        add_style_arc_settings,
        add_style_button_preset_list,
        add_style_container_preset_list_cell,
        add_style_switch_default,
        add_style_switch_dark,
        add_style_label_arc_value,
        add_style_tabview_sub_settings,
        add_style_bar_sub_settings,
        add_style_container_sub_settings,
        add_style_container_sub_settings_2,
        add_style_dropdown_sub_settings,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_button_selectable,
        remove_style_button_basic,
        remove_style_button_preset_list_options,
        remove_style_button_chain,
        remove_style_container_preset_small,
        remove_style_button_preset,
        remove_style_label_preset_name,
        remove_style_container_effect_on_off,
        remove_style_label_preset_index,
        remove_style_container_preset,
        remove_style_tab_settings_old,
        remove_style_tab_sub_settings,
        remove_style_tab_settings,
        remove_style_arc_settings,
        remove_style_button_preset_list,
        remove_style_container_preset_list_cell,
        remove_style_switch_default,
        remove_style_switch_dark,
        remove_style_label_arc_value,
        remove_style_tabview_sub_settings,
        remove_style_bar_sub_settings,
        remove_style_container_sub_settings,
        remove_style_container_sub_settings_2,
        remove_style_dropdown_sub_settings,
    };
    remove_style_funcs[styleIndex](obj);
}