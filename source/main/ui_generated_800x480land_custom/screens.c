#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;

//
// Event handlers
//

lv_obj_t *tick_value_change_obj;

//
// Screens
//

void create_screen_screen1() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 40);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_USBButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_usb_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                    lv_obj_add_event_cb(obj, action_usb, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_selectable_yellow(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "USB");
                                        }
                                    }
                                }
                                {
                                    // ui_WiFiButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_wi_fi_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                    lv_obj_add_event_cb(obj, action_wifi, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_selectable_purple(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Wi-Fi");
                                        }
                                    }
                                }
                                {
                                    // ui_BTMidiButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_bt_midi_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    add_style_button_selectable_blue(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "BT midi");
                                        }
                                    }
                                }
                                {
                                    // ui_BTAppButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_bt_app_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    add_style_button_selectable_blue(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "BT app");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // ui_BPMButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_bpm_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_add_event_cb(obj, action_tap_tempo_clicked, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj0 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "BPM");
                                        }
                                        {
                                            // ui_BPMValueLabel
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.ui_bpm_value_label = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 40, LV_SIZE_CONTENT);
                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "120");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 24, 24);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // ui_BPMIndicator
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_bpm_indicator = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_grad_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][4]), 51), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_add_event_cb(obj, action_open_presets_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "PRESETS");
                                }
                            }
                        }
                        {
                            // ui_SettingsButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_settings_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_add_event_cb(obj, action_show_settings_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "SETTINGS");
                                }
                            }
                        }
                        {
                            // ui_AltButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_alt_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_add_event_cb(obj, action_alt_button_clicked, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_selectable_green(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "ALT");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_ButtonsRegular
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_buttons_regular = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_ButtonsTop
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_buttons_top = obj;
                                    lv_obj_set_pos(obj, 0, 168);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_row_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    {
                                        static lv_coord_t dsc[] = {0, LV_GRID_TEMPLATE_LAST};
                                        lv_obj_set_style_grid_column_dsc_array(obj, dsc, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    }
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // ui_PresetButton_7
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_7 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 18);
                                        }
                                        {
                                            // ui_PresetButton_8
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_8 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 28);
                                        }
                                        {
                                            // ui_PresetButton_6
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_6 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 38);
                                        }
                                    }
                                }
                                {
                                    // ui_ButtonsBottom
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_buttons_bottom = obj;
                                    lv_obj_set_pos(obj, 0, 168);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // ui_PresetButton_1
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_1 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 49);
                                        }
                                        {
                                            // ui_PresetButton_2
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_2 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 59);
                                        }
                                        {
                                            // ui_PresetButton_3
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_3 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 69);
                                        }
                                        {
                                            // ui_PresetButton_4
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_4 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 79);
                                        }
                                        {
                                            // ui_PresetButton_5
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            objects.ui_preset_button_5 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 154, 212);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            create_user_widget_preset_button(obj, 89);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // ui_PresetDetails
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_preset_details = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 324, 228);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_add_event_cb(obj, action_open_presets_page, LV_EVENT_CLICKED, (void *)0);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, -3, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_PresetNumberLabel
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_preset_number_label = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_72, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "1");
                                                }
                                                {
                                                    // ui_PresetLetterLabel
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_preset_letter_label = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_72, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "A");
                                                }
                                            }
                                        }
                                        {
                                            // ui_PresetHeadingLabel
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.ui_preset_heading_label = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 234, 70);
                                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_36_italic, LV_PART_MAIN | LV_STATE_CHECKED);
                                            lv_label_set_text_static(obj, "Initializing...");
                                        }
                                    }
                                }
                                {
                                    // ui_EffectChainContainer
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_effect_chain_container = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), 150);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_line_create(parent_obj);
                                            objects.obj1 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                                            static lv_point_t line_points[] = {
                                                { 10, 35 },
                                                { 303, 35 },
                                                { 309, 41 },
                                                { 309, 69 },
                                                { 303, 75 },
                                                { 17, 75 },
                                                { 11, 81 },
                                                { 11, 109 },
                                                { 17, 115 },
                                                { 309, 115 }
                                            };
                                            lv_line_set_points(obj, line_points, 10);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_IconGate
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_gate = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][11]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][11]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageGate
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_gate = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_gate);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconComp
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_comp = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][13]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][13]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageComp
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_comp = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_comp);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconAmp
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_amp = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][14]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][14]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageAmp
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_amp = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_amp);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconCab
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_cab = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][15]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][15]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageCab
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_cab = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_cab);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                        {
                                                            // ui_CabGlobalDisabled
                                                            lv_obj_t *obj = lv_line_create(parent_obj);
                                                            objects.ui_cab_global_disabled = obj;
                                                            lv_obj_set_pos(obj, 2, 2);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            static lv_point_t line_points[] = {
                                                                { 0, 0 },
                                                                { 40, 40 }
                                                            };
                                                            lv_line_set_points(obj, line_points, 2);
                                                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[active_theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconEQ
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_eq = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][16]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][16]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageEQ
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_eq = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_eq);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconMod
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_mod = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][17]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][17]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageMod
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_mod = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_mod_phaser);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconDelay
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_delay = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][18]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][18]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageDelay
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_delay = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_delay_tape);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_IconReverb
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_icon_reverb = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 10, 10);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_effect_icon_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_button_chain(obj);
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][19]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][19]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_IconImageReverb
                                                            lv_obj_t *obj = lv_img_create(parent_obj);
                                                            objects.ui_icon_image_reverb = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_img_set_src(obj, &img_reverb_room);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_ProgressDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_progress_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_ProgressLabel
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ui_progress_label = obj;
                    lv_obj_set_pos(obj, 0, -260);
                    lv_obj_set_size(obj, LV_PCT(80), LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "...");
                }
                {
                    // ui_ProgressBar
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    objects.ui_progress_bar = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(80), 8);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ui_DebugContainer
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_debug_container = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 249, 406);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x3f0000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_DebugText
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.ui_debug_text = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text_static(obj, "");
                }
            }
        }
    }
    
    tick_screen_screen1();
}

void tick_screen_screen1() {
    tick_user_widget_preset_button(18);
    tick_user_widget_preset_button(28);
    tick_user_widget_preset_button(38);
    tick_user_widget_preset_button(49);
    tick_user_widget_preset_button(59);
    tick_user_widget_preset_button(69);
    tick_user_widget_preset_button(79);
    tick_user_widget_preset_button(89);
}

void create_screen_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, action_value_keyboard_ok, LV_EVENT_READY, (void *)0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x1f1f1f), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // ui_SettingsTabView
            lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 50);
            objects.ui_settings_tab_view = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_get_tab_btns(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 8, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_pad_right(obj, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ui_GateTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Gate");
                    objects.ui_gate_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj3 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_NoiseGateSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_noise_gate_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj4 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_NoiseGatePostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_noise_gate_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                            lv_obj_add_event_cb(obj, action_settings_copy_gate, LV_EVENT_CLICKED, (void *)0);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Copy");
                                                }
                                            }
                                        }
                                        {
                                            // ui_SettingsPasteGate
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.ui_settings_paste_gate = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                            lv_obj_add_state(obj, LV_STATE_DISABLED);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Paste");
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj5 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Threshold");
                                                }
                                                {
                                                    // ui_NoiseGateThresholdSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_noise_gate_threshold_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 136);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj6 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Release");
                                                }
                                                {
                                                    // ui_NoiseGateReleaseSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_noise_gate_release_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 143);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj7 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Depth");
                                                }
                                                {
                                                    // ui_NoiseGateDepthSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_noise_gate_depth_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 150);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_CompresssorTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Comp");
                    objects.ui_compresssor_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj8 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_CompressorEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_compressor_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj9 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_CompressorPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_compressor_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                            lv_obj_add_event_cb(obj, action_settings_copy_compressor, LV_EVENT_CLICKED, (void *)0);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Copy");
                                                }
                                            }
                                        }
                                        {
                                            // ui_SettingsPasteCompressor
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.ui_settings_paste_compressor = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                            lv_obj_add_state(obj, LV_STATE_DISABLED);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Paste");
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj10 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Threshold");
                                                }
                                                {
                                                    // ui_CompressorThresholdSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_compressor_threshold_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 163);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj11 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Gain");
                                                }
                                                {
                                                    // ui_CompressorGainSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_compressor_gain_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 170);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj12 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Attack");
                                                }
                                                {
                                                    // ui_CompressorAttackSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_compressor_attack_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 177);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_AmpTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Amp");
                    objects.ui_amp_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj13 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_AmpEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_amp_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_copy_amp, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Copy");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_SettingsPasteAmp
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_settings_paste_amp = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Paste");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj14 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Gain");
                                                }
                                                {
                                                    // ui_AmplifierGainSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_amplifier_gain_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 188);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj15 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mix");
                                                }
                                                {
                                                    // ui_AmplifierMixSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_amplifier_mix_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 195);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj16 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Volume");
                                                }
                                                {
                                                    // ui_AmplifierVolumeSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_amplifier_volume_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 202);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_CabTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Cab");
                    objects.ui_cab_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 23, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj17 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Cab");
                                                }
                                                {
                                                    // ui_CabinetModelDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_cabinet_model_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 85);
                                                    lv_obj_set_size(obj, 202, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Tone Model\nVIR\nDisabled");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_copy_cab, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Copy");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_SettingsPasteCab
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_settings_paste_cab = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Paste");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj18 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Model");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                                    lv_obj_add_event_cb(obj, action_settings_vir_dialog_open, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CabinetVIRModelLabel
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_cabinet_vir_model_label = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 160, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Model");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj19 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mic A");
                                                }
                                                {
                                                    // ui_CabinetVIRMic1Dropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_cabinet_vir_mic1_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 85);
                                                    lv_obj_set_size(obj, 170, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Conden 414\nDynamic 57\nRibbon 121");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj20 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mic B");
                                                }
                                                {
                                                    // ui_CabinetVIRMic2Dropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_cabinet_vir_mic2_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 85);
                                                    lv_obj_set_size(obj, 170, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Conden 414\nDynamic 57\nRibbon 121");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj21 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Resonance");
                                                }
                                                {
                                                    // ui_CabinetVIRResonanceSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_cabinet_vir_resonance_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 219);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj22 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Blend");
                                                }
                                                {
                                                    // ui_CabinetVIRBlendSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_cabinet_vir_blend_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 226);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 44);
                                            lv_obj_set_pos(obj, 0, 211);
                                            lv_obj_set_size(obj, 330, 202);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tabview_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_tabview_get_tab_btns(parent_obj);
                                                    add_style_bar_sub_settings(obj);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Mic A");
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                                    add_style_tab_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CabinetVIRMic1X_Slider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_cabinet_vir_mic1_x_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 232);
                                                        }
                                                        {
                                                            // ui_CabinetVIRMic1Z_Slider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_cabinet_vir_mic1_z_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 238);
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Mic B");
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                                    add_style_tab_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CabinetVIRMic2X_Slider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_cabinet_vir_mic2_x_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 244);
                                                        }
                                                        {
                                                            // ui_CabinetVIRMic2Z_Slider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_cabinet_vir_mic2_z_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 250);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_EQTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "EQ");
                    objects.ui_eq_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_EQCanvas
                            lv_obj_t *obj = lv_canvas_create(parent_obj);
                            objects.ui_eq_canvas = obj;
                            lv_obj_set_pos(obj, 26, -27);
                            lv_obj_set_size(obj, LV_PCT(100), 205);
                            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_opa(obj, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings_2(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_SettingsEQTabview
                                    lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 44);
                                    objects.ui_settings_eq_tabview = obj;
                                    lv_obj_set_pos(obj, 0, 211);
                                    lv_obj_set_size(obj, 644, 194);
                                    lv_tabview_set_act(obj, 1, LV_ANIM_OFF);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                    add_style_tabview_sub_settings(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_tabview_get_tab_btns(parent_obj);
                                            add_style_bar_sub_settings(obj);
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Depth");
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tab_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_AmplifierDepthSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_amplifier_depth_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 259);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Bass");
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tab_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EQBassFreqSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_bass_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 265);
                                                }
                                                {
                                                    // ui_EQBassSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_bass_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 271);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Mid");
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tab_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EQMidFreqSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_mid_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 277);
                                                }
                                                {
                                                    // ui_EQMidQSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_mid_qslider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 283);
                                                }
                                                {
                                                    // ui_EQMidSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_mid_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 289);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Treble");
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tab_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EQTrebleFreqSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_treble_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 295);
                                                }
                                                {
                                                    // ui_EQTrebleSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_eq_treble_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 301);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Presence");
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                                            add_style_tab_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_AmplifierPresenseSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_amplifier_presense_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 307);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_add_event_cb(obj, action_settings_copy_eq, LV_EVENT_CLICKED, (void *)0);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Copy");
                                                }
                                            }
                                        }
                                        {
                                            // ui_SettingsPasteEQ
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.ui_settings_paste_eq = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                            lv_obj_add_state(obj, LV_STATE_DISABLED);
                                            add_style_button_secondary(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Paste");
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_EQPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_eq_post_switch = obj;
                                                    lv_obj_set_pos(obj, 437, 68);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_ModulationTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Mod");
                    objects.ui_modulation_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj23 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_ModulationEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj24 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_ModulationPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj25 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Sync");
                                                }
                                                {
                                                    // ui_ModulationSyncSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_sync_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj26 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Model");
                                                }
                                                {
                                                    // ui_ModulationModelDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_modulation_model_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 94);
                                                    lv_obj_set_size(obj, 202, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Chorus\nTremolo\nPhaser\nFlanger\nRotary");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_copy_modulation, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Copy");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_SettingsPasteModulation
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_settings_paste_modulation = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Paste");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_ModulationParam1Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param1_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 1");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ModulationParam1Slider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_modulation_param1_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 326);
                                                        }
                                                        {
                                                            // ui_ModulationTSDropdown
                                                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                            objects.ui_modulation_ts_dropdown = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                                                            lv_dropdown_set_options_static(obj, "1/32\n1/32 D\n1/32 T\n1/16\n1/16 D\n1/16 T\n1/8\n1/8 D\n1/8 T\n1/4\n1/4 D\n1/4 T\n1/2\n1/2 D\n1/2 T\n1/1\n1/1 D\n1/1 T");
                                                            lv_dropdown_set_selected(obj, 0);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                            add_style_dropdown_sub_settings(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                                    add_style_dropdown_list_sub_settings(obj);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_ModulationParam2Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param2_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 2");
                                                }
                                                {
                                                    // ui_ModulationParam2Slider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_modulation_param2_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 334);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_ModulationParam3Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param3_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 3");
                                                }
                                                {
                                                    // ui_ModulationParam3Slider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_modulation_param3_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 341);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_ModulationParam4Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param4_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 4");
                                                }
                                                {
                                                    // ui_ModulationParam4Slider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_modulation_param4_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 348);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_DelayTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Dly");
                    objects.ui_delay_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj27 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_DelayEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj28 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_DelayPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj29 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Sync");
                                                }
                                                {
                                                    // ui_DelaySyncSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_sync_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj30 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Ping-Pong");
                                                }
                                                {
                                                    // ui_DelayPingPongSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_ping_pong_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj31 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Model");
                                                }
                                                {
                                                    // ui_DelayModelDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_delay_model_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 85);
                                                    lv_obj_set_size(obj, 202, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Digital\nTape");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_copy_delay, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Copy");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_SettingsPasteDelay
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_settings_paste_delay = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Paste");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj32 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Time");
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_DelayTSSlider
                                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                                            objects.ui_delay_ts_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            create_user_widget_arc(obj, 367);
                                                        }
                                                        {
                                                            // ui_DelayTSDropdown
                                                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                            objects.ui_delay_ts_dropdown = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, LV_SIZE_CONTENT);
                                                            lv_dropdown_set_options_static(obj, "1/32\n1/32 D\n1/32 T\n1/16\n1/16 D\n1/16 T\n1/8\n1/8 D\n1/8 T\n1/4\n1/4 D\n1/4 T\n1/2\n1/2 D\n1/2 T\n1/1\n1/1 D\n1/1 T");
                                                            lv_dropdown_set_selected(obj, 0);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                            add_style_dropdown_sub_settings(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                                    add_style_dropdown_list_sub_settings(obj);
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj33 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Feedback");
                                                }
                                                {
                                                    // ui_DelayFeedbackSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_delay_feedback_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 375);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj34 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mix");
                                                }
                                                {
                                                    // ui_DelayMixSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_delay_mix_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 382);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_ReverbTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Rev");
                    objects.ui_reverb_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj35 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_ReverbEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_reverb_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj36 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_ReverbPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_reverb_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj37 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Model");
                                                }
                                                {
                                                    // ui_ReverbModelDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_reverb_model_dropdown = obj;
                                                    lv_obj_set_pos(obj, 168, 97);
                                                    lv_obj_set_size(obj, 202, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Spring 1\nSpring 2\nSpring 3\nSpring 4\nRoom\nPlate");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_copy_reverb, LV_EVENT_CLICKED, (void *)0);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Copy");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_SettingsPasteReverb
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_settings_paste_reverb = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_CLICKED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_DISABLED);
                                                    add_style_button_secondary(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Paste");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj38 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Time");
                                                }
                                                {
                                                    // ui_ReverbTimeSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_reverb_time_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 397);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj39 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Pre-Delay");
                                                }
                                                {
                                                    // ui_ReverbPredelaySlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_reverb_predelay_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 404);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj40 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Color");
                                                }
                                                {
                                                    // ui_ReverbColorSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_reverb_color_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 411);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj41 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mix");
                                                }
                                                {
                                                    // ui_ReverbMixSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_reverb_mix_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 418);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_GlobalTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Glob");
                    objects.ui_global_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj42 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Cab Bypass");
                                                        }
                                                        {
                                                            // ui_CabBypassSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_cab_bypass_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark_green(obj);
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj43 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Direct Monitor");
                                                        }
                                                        {
                                                            // ui_DirectMonitorSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_direct_monitor_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark_green(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.obj44 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Tempo Per Preset");
                                                        }
                                                        {
                                                            // ui_TempoSourceSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_tempo_source_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark_green(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj45 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "BPM");
                                                }
                                                {
                                                    // ui_BPMSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_bpm_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 432);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj46 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Input Trim");
                                                }
                                                {
                                                    // ui_InputTrimSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_input_trim_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 439);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj47 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Tuning Ref");
                                                }
                                                {
                                                    // ui_TuningReferenceSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_tuning_reference_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 446);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj48 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Master Volume");
                                                }
                                                {
                                                    // ui_VolumeSlider
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_volume_slider = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    create_user_widget_arc(obj, 453);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_WiFiTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "WiFi");
                    objects.ui_wi_fi_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_label_set_text_static(obj, "WiFi mode");
                                                }
                                                {
                                                    // ui_WIFIModeDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_wifi_mode_dropdown = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 296, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "Access Point Timed\nStation\nAccess Point");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_label_set_text_static(obj, "WiFi transmit power");
                                                }
                                                {
                                                    // ui_WIFIPowerDropdown
                                                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                                    objects.ui_wifi_power_dropdown = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 296, LV_SIZE_CONTENT);
                                                    lv_dropdown_set_options_static(obj, "25%\n50%\n75%\n100%");
                                                    lv_dropdown_set_selected(obj, 0);
                                                    add_style_dropdown_sub_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                            add_style_dropdown_list_sub_settings(obj);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(49), LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "WiFi SSID");
                                                }
                                                {
                                                    // ui_WIFI_SSIDTextarea
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.ui_wifi_ssid_textarea = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                    lv_textarea_set_max_length(obj, 64);
                                                    lv_textarea_set_placeholder_text(obj, "name");
                                                    lv_textarea_set_one_line(obj, true);
                                                    lv_textarea_set_password_mode(obj, false);
                                                    lv_obj_add_event_cb(obj, action_edit_wifi_ssid_clicked, LV_EVENT_PRESSED, (void *)0);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_textarea_settings(obj);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_label_set_text_static(obj, "WiFi password");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_checkbox_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_checkbox_set_text_static(obj, "Hidden");
                                                            lv_obj_add_event_cb(obj, action_wifi_password_hidden_clicked, LV_EVENT_VALUE_CHANGED, (void *)0);
                                                            lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                            add_style_checkbox_settings(obj);
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_WIFI_PasswordTextarea
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.ui_wifi_password_textarea = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                    lv_textarea_set_max_length(obj, 64);
                                                    lv_textarea_set_placeholder_text(obj, "password");
                                                    lv_textarea_set_one_line(obj, true);
                                                    lv_textarea_set_password_mode(obj, true);
                                                    lv_obj_add_event_cb(obj, action_edit_wifi_password_clicked, LV_EVENT_PRESSED, (void *)0);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_textarea_settings(obj);
                                                }
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_label_set_text_static(obj, "mDNS name");
                                                }
                                                {
                                                    // ui_MDNSNameTextarea
                                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                                    objects.ui_mdns_name_textarea = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                    lv_textarea_set_max_length(obj, 64);
                                                    lv_textarea_set_placeholder_text(obj, "mDNS");
                                                    lv_textarea_set_one_line(obj, true);
                                                    lv_textarea_set_password_mode(obj, false);
                                                    lv_obj_add_event_cb(obj, action_edit_mdns_name_clicked, LV_EVENT_PRESSED, (void *)0);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICK_FOCUSABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_textarea_settings(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_AROUND, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.obj49 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "WiFi enable");
                                                }
                                                {
                                                    // ui_WiFiSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_wi_fi_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_wi_fi_enabled_changed, LV_EVENT_RELEASED, (void *)0);
                                                    lv_obj_add_state(obj, LV_STATE_CHECKED);
                                                    add_style_switch_dark_green(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                            lv_obj_add_event_cb(obj, action_save_wifi_settings, LV_EVENT_CLICKED, (void *)0);
                                            add_style_button_highlighted_blue(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_label_set_text_static(obj, "Save and Reboot");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    // ui_USBTab
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "USB");
                    objects.ui_usb_tab = obj;
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_tab_settings(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_sub_settings(obj);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj50 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Theme");
                                        }
                                        {
                                            // ui_ThemeDropdown
                                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                                            objects.ui_theme_dropdown = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 180, LV_SIZE_CONTENT);
                                            lv_dropdown_set_options_static(obj, "Default");
                                            lv_dropdown_set_selected(obj, 0);
                                            lv_obj_add_event_cb(obj, action_theme_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                                            add_style_dropdown_sub_settings(obj);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                                    add_style_dropdown_list_sub_settings(obj);
                                                }
                                            }
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.obj51 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "USB Host");
                                        }
                                        {
                                            // ui_USBHostSwitch
                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                            objects.ui_usb_host_switch = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, 50, 25);
                                            lv_obj_add_event_cb(obj, action_usb_host_changed, LV_EVENT_RELEASED, (void *)0);
                                            lv_obj_add_state(obj, LV_STATE_CHECKED);
                                            add_style_switch_dark_green(obj);
                                        }
                                    }
                                }
                                {
                                    // ui_USBRebootButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_usb_reboot_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_usb_reboot, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_highlighted_green(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Soft reboot");
                                        }
                                    }
                                }
                                {
                                    // ui_USBFlashButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_usb_flash_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_usb_flash, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_highlighted_red(obj);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Enter flash mode");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 726, 0);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_line_create(parent_obj);
                    objects.obj52 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    static lv_point_t line_points[] = {
                        { 0, 0 },
                        { 0, 40 }
                    };
                    lv_line_set_points(obj, line_points, 2);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 732, 0);
                    lv_obj_set_size(obj, 68, 50);
                    lv_obj_add_event_cb(obj, action_close_settings_page, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_basic(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "✓");
                        }
                    }
                }
            }
        }
        {
            // ui_ControllerDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_controller_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj53 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 686, 423);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_ControllerDialogEntry
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            objects.ui_controller_dialog_entry = obj;
                            lv_obj_set_pos(obj, 9262, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_textarea_set_max_length(obj, 64);
                            lv_textarea_set_placeholder_text(obj, "text");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xd1a60c), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                        {
                            // ui_ControllerDialogKeyboard
                            lv_obj_t *obj = lv_keyboard_create(parent_obj);
                            objects.ui_controller_dialog_keyboard = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), 325);
                            lv_obj_add_event_cb(obj, action_controller_keyboard_ok, LV_EVENT_READY, (void *)0);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
            }
        }
        {
            // ui_settings_dialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_settings_dialog = obj;
            lv_obj_set_pos(obj, 62, 33);
            lv_obj_set_size(obj, 686, 423);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_settings_text_entry
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ui_settings_text_entry = obj;
                    lv_obj_set_pos(obj, 153, -18);
                    lv_obj_set_size(obj, 326, LV_SIZE_CONTENT);
                    lv_textarea_set_max_length(obj, 8);
                    lv_textarea_set_text(obj, "0");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // ui_settings_keyboard
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    objects.ui_settings_keyboard = obj;
                    lv_obj_set_pos(obj, -12, 64);
                    lv_obj_set_size(obj, 657, 322);
                    lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
                    lv_obj_add_event_cb(obj, action_value_keyboard_ok, LV_EVENT_READY, (void *)0);
                    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // ui_SettingsVIRCabDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_settings_vir_cab_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj54 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_CabinetVIRButtonMatrix
                            lv_obj_t *obj = lv_btnmatrix_create(parent_obj);
                            objects.ui_cabinet_vir_button_matrix = obj;
                            lv_obj_set_pos(obj, 0, 56);
                            lv_obj_set_size(obj, LV_PCT(100), 398);
                            static const char *map[28] = {
                                "1x6 Brian May",
                                "1x8 Fend '57 Champ",
                                "1x10 Fend Princeton",
                                "\n",
                                "1x12 Fend '65 Delx Rev",
                                "1x12 Mesa MK III",
                                "1x12 Mesa Cali Tweed",
                                "\n",
                                "1x12 Dr. Z MAZ 18 Jr",
                                "1x12 Orange Tiny Terror",
                                "1x15 Fend '53 Bassman",
                                "\n",
                                "2x12 Fend '65 Twin Reverb",
                                "2x12 AC30 Alnico Blue",
                                "2x12 AC30 G12H",
                                "\n",
                                "2x12 Roland JC120",
                                "2x12 Silvertone",
                                "2x12 Orange PPC 212",
                                "\n",
                                "2x12 Mesa Recto Horiz",
                                "2x12 Dr. Z Z-Wreck",
                                "4x12 Marsh 1960AV",
                                "\n",
                                "4x12 Marsh 1960A V30",
                                "4x12 Marsh 1960 VG12-80",
                                "4x12 Marsh 1960A T75",
                                NULL,
                            };
                            lv_btnmatrix_set_map(obj, map);
                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 12, LV_PART_ITEMS | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 255, LV_PART_ITEMS | LV_STATE_CHECKED);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_ITEMS | LV_STATE_CHECKED);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
                            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][3]), 64), LV_PART_ITEMS | LV_STATE_PRESSED);
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 68, 50);
                                    lv_obj_add_event_cb(obj, action_settings_vir_dialog_page_previous, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_secondary(obj);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "←");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 68, 50);
                                    lv_obj_add_event_cb(obj, action_settings_vir_dialog_page_next, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_secondary(obj);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "→");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.obj55 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_settings_vir_dialog_close, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "X");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.ui_controller_dialog_keyboard, objects.ui_controller_dialog_entry);
    lv_keyboard_set_textarea(objects.ui_settings_keyboard, objects.ui_settings_text_entry);
    
    tick_screen_settings();
}

void tick_screen_settings() {
    tick_user_widget_arc(136);
    tick_user_widget_arc(143);
    tick_user_widget_arc(150);
    tick_user_widget_arc(163);
    tick_user_widget_arc(170);
    tick_user_widget_arc(177);
    tick_user_widget_arc(188);
    tick_user_widget_arc(195);
    tick_user_widget_arc(202);
    tick_user_widget_arc(219);
    tick_user_widget_arc(226);
    tick_user_widget_arc(232);
    tick_user_widget_arc(238);
    tick_user_widget_arc(244);
    tick_user_widget_arc(250);
    tick_user_widget_arc(259);
    tick_user_widget_arc(265);
    tick_user_widget_arc(271);
    tick_user_widget_arc(277);
    tick_user_widget_arc(283);
    tick_user_widget_arc(289);
    tick_user_widget_arc(295);
    tick_user_widget_arc(301);
    tick_user_widget_arc(307);
    tick_user_widget_arc(326);
    tick_user_widget_arc(334);
    tick_user_widget_arc(341);
    tick_user_widget_arc(348);
    tick_user_widget_arc(367);
    tick_user_widget_arc(375);
    tick_user_widget_arc(382);
    tick_user_widget_arc(397);
    tick_user_widget_arc(404);
    tick_user_widget_arc(411);
    tick_user_widget_arc(418);
    tick_user_widget_arc(432);
    tick_user_widget_arc(439);
    tick_user_widget_arc(446);
    tick_user_widget_arc(453);
}

void create_screen_presets() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.presets = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_PresetListCancelButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_list_cancel_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_cancel, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_highlighted_red(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Cancel");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 170, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_previous, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "←");
                                }
                            }
                        }
                        {
                            // ui_PresetListScenesButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_list_scenes_button = obj;
                            lv_obj_set_pos(obj, -60, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_open_scenes_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Scenes");
                                }
                            }
                        }
                        {
                            // ui_PresetListBackupsButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_list_backups_button = obj;
                            lv_obj_set_pos(obj, 66, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_open_presets_backup_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Backups");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 562, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_next, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "→");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_close_presets_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "✓");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(48), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_PresetLIstElement_0
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_0 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 489);
                                }
                                {
                                    // ui_PresetLIstElement_1
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 495);
                                }
                                {
                                    // ui_PresetLIstElement_2
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_2 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 501);
                                }
                                {
                                    // ui_PresetLIstElement_3
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_3 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 507);
                                }
                                {
                                    // ui_PresetLIstElement_4
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_4 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 513);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(48), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_PresetLIstElement_5
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_5 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 519);
                                }
                                {
                                    // ui_PresetLIstElement_6
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_6 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 525);
                                }
                                {
                                    // ui_PresetLIstElement_7
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_7 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 531);
                                }
                                {
                                    // ui_PresetLIstElement_8
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_8 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 537);
                                }
                                {
                                    // ui_PresetLIstElement_9
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_list_element_9 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_list_button(obj, 543);
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_PresetListColorDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_preset_list_color_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj56 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Edit preset");
                                        }
                                        {
                                            // ui_PresetListColorDialogName
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.ui_preset_list_color_dialog_name = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0: Preset");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_obj_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_PresetListColor0
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color0 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)0);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0619), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor1
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color1 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)1);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xe75116), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor2
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color2 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)2);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe12a), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor3
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color3 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)3);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00f642), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor4
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color4 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)4);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00fbcd), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor5
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color5 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)5);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x009dfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor6
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color6 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)6);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x0044fb), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor7
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color7 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)7);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x6c64fb), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor8
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color8 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)8);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff25c8), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor9
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color9 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)9);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff8bfc), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                {
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_PresetListColor10
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color10 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)10);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x871218), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor11
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color11 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)11);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x7a3616), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor12
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color12 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)12);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x85771c), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor13
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color13 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)13);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x05802d), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor14
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color14 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)14);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x00826e), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor15
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color15 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)15);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x005882), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor16
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color16 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)16);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x002e82), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor17
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color17 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)17);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x433e82), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor18
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color18 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)18);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x851a6b), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetListColor19
                                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                                            objects.ui_preset_list_color19 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)19);
                                                            add_style_button_settings_color(obj);
                                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x845083), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "✓");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        {
                                            // ui_PresetListColor20
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            objects.ui_preset_list_color20 = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_CLICKED, (void *)20);
                                            add_style_button_settings_color(obj);
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0x595959), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "✓");
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.obj57 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_dialog_close, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "X");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_presets();
}

void tick_screen_presets() {
    tick_user_widget_preset_list_button(489);
    tick_user_widget_preset_list_button(495);
    tick_user_widget_preset_list_button(501);
    tick_user_widget_preset_list_button(507);
    tick_user_widget_preset_list_button(513);
    tick_user_widget_preset_list_button(519);
    tick_user_widget_preset_list_button(525);
    tick_user_widget_preset_list_button(531);
    tick_user_widget_preset_list_button(537);
    tick_user_widget_preset_list_button(543);
}

void create_screen_scenes() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scenes = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, action_scene_rename_dialog_keyboard_ok, LV_EVENT_READY, (void *)0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(50), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // ui_SceneLIstElement_0
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_0 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 574);
                        }
                        {
                            // ui_SceneLIstElement_1
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 580);
                        }
                        {
                            // ui_SceneLIstElement_2
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_2 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 586);
                        }
                        {
                            // ui_SceneLIstElement_3
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_3 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 592);
                        }
                        {
                            // ui_SceneLIstElement_4
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 598);
                        }
                        {
                            // ui_SceneLIstElement_5
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 604);
                        }
                        {
                            // ui_SceneLIstElement_6
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_6 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 610);
                        }
                        {
                            // ui_SceneLIstElement_7
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_7 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 616);
                        }
                        {
                            // ui_SceneLIstElement_8
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_8 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 622);
                        }
                        {
                            // ui_SceneLIstElement_9
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_9 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 628);
                        }
                        {
                            // ui_SceneLIstElement_10
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_10 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 634);
                        }
                        {
                            // ui_SceneLIstElement_11
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_11 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 640);
                        }
                        {
                            // ui_SceneLIstElement_12
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_12 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 646);
                        }
                        {
                            // ui_SceneLIstElement_13
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_13 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 652);
                        }
                        {
                            // ui_SceneLIstElement_14
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_14 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 658);
                        }
                        {
                            // ui_SceneLIstElement_15
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_15 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 664);
                        }
                        {
                            // ui_SceneLIstElement_16
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_16 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 670);
                        }
                        {
                            // ui_SceneLIstElement_17
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_17 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 676);
                        }
                        {
                            // ui_SceneLIstElement_18
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_18 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 682);
                        }
                        {
                            // ui_SceneLIstElement_19
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            objects.ui_scene_list_element_19 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            create_user_widget_preset_list_button(obj, 688);
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // ui_NewSceneButton
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    objects.ui_new_scene_button = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                    lv_obj_add_event_cb(obj, action_new_scene, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_highlighted_blue(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "New scene");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.obj58 = obj;
                            lv_obj_set_pos(obj, 13, -148);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Sync presets");
                        }
                        {
                            // ui_ScenesSyncPresetsSwitch
                            lv_obj_t *obj = lv_switch_create(parent_obj);
                            objects.ui_scenes_sync_presets_switch = obj;
                            lv_obj_set_pos(obj, 168, -148);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_switch_blue(obj);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 68, 50);
                    lv_obj_add_event_cb(obj, action_close_scenes_page, LV_EVENT_CLICKED, (void *)0);
                    add_style_button_basic(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "✓");
                        }
                    }
                }
            }
        }
        {
            // ui_SceneDeleteDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_scene_delete_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj59 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "Delete scene");
                                }
                                {
                                    // ui_SceneDeleteDialogName
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_scene_delete_dialog_name = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "0: Preset");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_scene_delete_dialog_delete, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_highlighted_red(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Delete");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_scene_delete_dialog_cancel, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_secondary(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Cancel");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_SceneRenameDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_scene_rename_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj60 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.obj61 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Rename scene");
                                }
                                {
                                    // ui_SceneRenameDialogTextarea
                                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                                    objects.ui_scene_rename_dialog_textarea = obj;
                                    lv_obj_set_pos(obj, 2623, 0);
                                    lv_obj_set_size(obj, 318, LV_SIZE_CONTENT);
                                    lv_textarea_set_max_length(obj, 30);
                                    lv_textarea_set_one_line(obj, true);
                                    lv_textarea_set_password_mode(obj, false);
                                    add_style_textarea_settings(obj);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.obj62 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_scene_rename_dialog_close, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "X");
                                }
                            }
                        }
                    }
                }
                {
                    // ui_SceneRenameDialogKeyboard
                    lv_obj_t *obj = lv_keyboard_create(parent_obj);
                    objects.ui_scene_rename_dialog_keyboard = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 330);
                    lv_obj_add_event_cb(obj, action_scene_rename_dialog_keyboard_ok, LV_EVENT_READY, (void *)0);
                    lv_obj_add_event_cb(obj, action_scene_rename_dialog_close, LV_EVENT_CANCEL, (void *)0);
                    add_style_keyboard(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }
    lv_keyboard_set_textarea(objects.ui_scene_rename_dialog_keyboard, objects.ui_scene_rename_dialog_textarea);
    
    tick_screen_scenes();
}

void tick_screen_scenes() {
    tick_user_widget_preset_list_button(574);
    tick_user_widget_preset_list_button(580);
    tick_user_widget_preset_list_button(586);
    tick_user_widget_preset_list_button(592);
    tick_user_widget_preset_list_button(598);
    tick_user_widget_preset_list_button(604);
    tick_user_widget_preset_list_button(610);
    tick_user_widget_preset_list_button(616);
    tick_user_widget_preset_list_button(622);
    tick_user_widget_preset_list_button(628);
    tick_user_widget_preset_list_button(634);
    tick_user_widget_preset_list_button(640);
    tick_user_widget_preset_list_button(646);
    tick_user_widget_preset_list_button(652);
    tick_user_widget_preset_list_button(658);
    tick_user_widget_preset_list_button(664);
    tick_user_widget_preset_list_button(670);
    tick_user_widget_preset_list_button(676);
    tick_user_widget_preset_list_button(682);
    tick_user_widget_preset_list_button(688);
}

void create_screen_presets_backup() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.presets_backup = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_ELASTIC);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 170, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_backup_list_previous, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "←");
                                }
                            }
                        }
                        {
                            // ui_PresetBackupListPageLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.ui_preset_backup_list_page_label = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Page 1/1");
                        }
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 562, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_backup_list_next, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "→");
                                }
                            }
                        }
                        {
                            // ui_PresetBackupListCancelButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_backup_list_cancel_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_preset_backup_list_cancel, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_highlighted_red(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "Cancel");
                                }
                            }
                        }
                        {
                            // ui_PresetBackupListCloseButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_backup_list_close_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_close_presets_backup_page, LV_EVENT_CLICKED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "✓");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(48), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_PresetBackupLIstElement_0
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_0 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 709);
                                }
                                {
                                    // ui_PresetBackupLIstElement_1
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_1 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 718);
                                }
                                {
                                    // ui_PresetBackupLIstElement_2
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_2 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 727);
                                }
                                {
                                    // ui_PresetBackupLIstElement_3
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_3 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 736);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(48), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE|LV_OBJ_FLAG_SCROLL_CHAIN_HOR|LV_OBJ_FLAG_SCROLL_CHAIN_VER|LV_OBJ_FLAG_SCROLL_ELASTIC|LV_OBJ_FLAG_SCROLL_MOMENTUM|LV_OBJ_FLAG_SCROLL_WITH_ARROW);
                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                            lv_obj_set_scroll_dir(obj, LV_DIR_NONE);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_PresetBackupLIstElement_4
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_4 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 745);
                                }
                                {
                                    // ui_PresetBackupLIstElement_5
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_5 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 754);
                                }
                                {
                                    // ui_PresetBackupLIstElement_6
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_6 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 763);
                                }
                                {
                                    // ui_PresetBackupLIstElement_7
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    objects.ui_preset_backup_list_element_7 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    create_user_widget_preset_backup_list_button(obj, 772);
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_PresetBackupDeleteDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_preset_backup_delete_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj63 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_text_static(obj, "Delete preset");
                                }
                                {
                                    // ui_PresetBackupDeleteDialogName
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_preset_backup_delete_dialog_name = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "0: Preset");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_preset_backup_delete_dialog_delete, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_highlighted_red(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Delete");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_preset_backup_delete_dialog_cancel, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_secondary(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Cancel");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        {
            // ui_PresetBackupLoadDialog
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.ui_preset_backup_load_dialog = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj64 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "Load preset");
                                        }
                                        {
                                            // ui_PresetBackupLoadDialogName
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.ui_preset_backup_load_dialog_name = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0: Preset");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_column(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_label_set_text_static(obj, "This will replace");
                                        }
                                        {
                                            // ui_PresetBackupLoadDialogOldName
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            objects.ui_preset_backup_load_dialog_old_name = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "0: Preset");
                                        }
                                    }
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_preset_backup_load_dialog_load, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_highlighted_blue(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Load");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_preset_backup_load_dialog_cancel, LV_EVENT_CLICKED, (void *)0);
                                    add_style_button_secondary(obj);
                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Cancel");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    tick_screen_presets_backup();
}

void tick_screen_presets_backup() {
    tick_user_widget_preset_backup_list_button(709);
    tick_user_widget_preset_backup_list_button(718);
    tick_user_widget_preset_backup_list_button(727);
    tick_user_widget_preset_backup_list_button(736);
    tick_user_widget_preset_backup_list_button(745);
    tick_user_widget_preset_backup_list_button(754);
    tick_user_widget_preset_backup_list_button(763);
    tick_user_widget_preset_backup_list_button(772);
}

void create_user_widget_preset_list_button(lv_obj_t *parent_obj, int startWidgetIndex) {
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // Button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_add_event_cb(obj, action_preset_list_button, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Color
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 10, LV_PCT(100));
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(88), LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_pad_left(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22_italic, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_label_set_text_static(obj, "1: Preset");
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(12), LV_PCT(100));
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Options
                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_dropdown_set_options_static(obj, "Option 1\nOption 2\nOption 3");
                            lv_dropdown_set_selected(obj, 0);
                            lv_obj_add_event_cb(obj, action_preset_list_button_options, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, action_preset_list_button_options_released, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_line_space(obj, 34, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_max_height(obj, 320, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_CHECKED);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_preset_list_button(int startWidgetIndex) {
    (void)startWidgetIndex;
}

void create_user_widget_preset_button(lv_obj_t *parent_obj, int startWidgetIndex) {
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 154, LV_SIZE_CONTENT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Button
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), 188);
                    lv_obj_add_event_cb(obj, action_preset_button, LV_EVENT_SHORT_CLICKED, (void *)0);
                    lv_obj_add_event_cb(obj, action_preset_button, LV_EVENT_LONG_PRESSED, (void *)0);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 128, LV_PART_MAIN | LV_STATE_PRESSED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Label
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), 132);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "...");
                        }
                        {
                            // IconButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                            lv_obj_set_pos(obj, 0, 10);
                            lv_obj_set_size(obj, 44, 44);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_add_state(obj, LV_STATE_CHECKED);
                            add_style_button_chain(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_min_height(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_min_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                            lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // IconImage
                                    lv_obj_t *obj = lv_img_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_img_set_src(obj, &img_eq);
                                    lv_img_set_zoom(obj, 175);
                                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // LabelOff
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                    lv_label_set_text_static(obj, "...");
                                }
                                {
                                    // LabelOn
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                    lv_label_set_text_static(obj, "...");
                                }
                            }
                        }
                        {
                            // Index
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_72, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_opa(obj, 192, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                            lv_obj_set_style_opa(obj, 165, LV_PART_MAIN | LV_STATE_CHECKED);
                            lv_label_set_text_static(obj, "1A");
                        }
                    }
                }
                {
                    // ButtonSmall
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
                    lv_obj_set_pos(obj, 2200, 0);
                    lv_obj_set_size(obj, 138, 23);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_left(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_clip_corner(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // LabelSmall
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 8] = obj;
                            lv_obj_set_pos(obj, 0, 3);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_SCROLL);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_label_set_text_static(obj, "...");
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_preset_button(int startWidgetIndex) {
    (void)startWidgetIndex;
}

void create_user_widget_arc(lv_obj_t *parent_obj, int startWidgetIndex) {
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // Drag
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Arc
                    lv_obj_t *obj = lv_arc_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                    lv_arc_set_value(obj, 30);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_set_style_arc_width(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_width(obj, 8, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_arc_rounded(obj, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    lv_obj_set_style_opa(obj, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Content
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_shadow_width(obj, 24, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_shadow_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // Value
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "0");
                                }
                                {
                                    // Unit
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "dB");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_arc(int startWidgetIndex) {
    (void)startWidgetIndex;
}

void create_user_widget_preset_backup_list_button(lv_obj_t *parent_obj, int startWidgetIndex) {
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            // Button
            lv_obj_t *obj = lv_btn_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_add_event_cb(obj, action_preset_backup_list_button, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 96, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(88), LV_PCT(100));
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_pad_left(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_START, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // NameLabel
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text_static(obj, "Preset");
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_column(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(29), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Label1
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Hi-Gain");
                                        }
                                        {
                                            // Label2
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Stomp+Cab");
                                        }
                                    }
                                }
                                {
                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_PCT(71), LV_SIZE_CONTENT);
                                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_pad_row(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            // Label3
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_text_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Amplifier model");
                                        }
                                        {
                                            // Label4
                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                            ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_opa(obj, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_18, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_label_set_text_static(obj, "Cabinet model");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(12), LV_PCT(100));
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_RIGHT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // Options
                            lv_obj_t *obj = lv_dropdown_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                            lv_dropdown_set_options_static(obj, "Option 1\nOption 2\nOption 3");
                            lv_dropdown_set_selected(obj, 0);
                            lv_obj_add_event_cb(obj, action_preset_backup_list_button_options, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_add_event_cb(obj, action_preset_backup_list_button_options_released, LV_EVENT_RELEASED, (void *)0);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_line_space(obj, 34, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_CHECKED);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
                                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_SELECTED | LV_STATE_PRESSED);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_preset_backup_list_button(int startWidgetIndex) {
    (void)startWidgetIndex;
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_screen1,
    tick_screen_settings,
    tick_screen_presets,
    tick_screen_scenes,
    tick_screen_presets_backup,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 5) {
        tick_screen_funcs[screen_index]();
    }
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen(screenId - 1);
}

//
// Fonts
//

ext_font_desc_t fonts[] = {
    { "IBM 72", &ui_font_ibm_72 },
    { "IBM 36", &ui_font_ibm_36 },
    { "IBM 32", &ui_font_ibm_32 },
    { "IBM 22", &ui_font_ibm_22 },
    { "IBM 18", &ui_font_ibm_18 },
    { "IBM 22 Italic", &ui_font_ibm_22_italic },
    { "IBM 36 Italic", &ui_font_ibm_36_italic },
#if LV_FONT_MONTSERRAT_8
    { "MONTSERRAT_8", &lv_font_montserrat_8 },
#endif
#if LV_FONT_MONTSERRAT_10
    { "MONTSERRAT_10", &lv_font_montserrat_10 },
#endif
#if LV_FONT_MONTSERRAT_12
    { "MONTSERRAT_12", &lv_font_montserrat_12 },
#endif
#if LV_FONT_MONTSERRAT_14
    { "MONTSERRAT_14", &lv_font_montserrat_14 },
#endif
#if LV_FONT_MONTSERRAT_16
    { "MONTSERRAT_16", &lv_font_montserrat_16 },
#endif
#if LV_FONT_MONTSERRAT_18
    { "MONTSERRAT_18", &lv_font_montserrat_18 },
#endif
#if LV_FONT_MONTSERRAT_20
    { "MONTSERRAT_20", &lv_font_montserrat_20 },
#endif
#if LV_FONT_MONTSERRAT_22
    { "MONTSERRAT_22", &lv_font_montserrat_22 },
#endif
#if LV_FONT_MONTSERRAT_24
    { "MONTSERRAT_24", &lv_font_montserrat_24 },
#endif
#if LV_FONT_MONTSERRAT_26
    { "MONTSERRAT_26", &lv_font_montserrat_26 },
#endif
#if LV_FONT_MONTSERRAT_28
    { "MONTSERRAT_28", &lv_font_montserrat_28 },
#endif
#if LV_FONT_MONTSERRAT_30
    { "MONTSERRAT_30", &lv_font_montserrat_30 },
#endif
#if LV_FONT_MONTSERRAT_32
    { "MONTSERRAT_32", &lv_font_montserrat_32 },
#endif
#if LV_FONT_MONTSERRAT_34
    { "MONTSERRAT_34", &lv_font_montserrat_34 },
#endif
#if LV_FONT_MONTSERRAT_36
    { "MONTSERRAT_36", &lv_font_montserrat_36 },
#endif
#if LV_FONT_MONTSERRAT_38
    { "MONTSERRAT_38", &lv_font_montserrat_38 },
#endif
#if LV_FONT_MONTSERRAT_40
    { "MONTSERRAT_40", &lv_font_montserrat_40 },
#endif
#if LV_FONT_MONTSERRAT_42
    { "MONTSERRAT_42", &lv_font_montserrat_42 },
#endif
#if LV_FONT_MONTSERRAT_44
    { "MONTSERRAT_44", &lv_font_montserrat_44 },
#endif
#if LV_FONT_MONTSERRAT_46
    { "MONTSERRAT_46", &lv_font_montserrat_46 },
#endif
#if LV_FONT_MONTSERRAT_48
    { "MONTSERRAT_48", &lv_font_montserrat_48 },
#endif
};

//
// Color themes
//

uint32_t active_theme_index = 0;
void change_color_theme(uint32_t theme_index) {
    active_theme_index = theme_index;
    
    {
        lv_obj_set_style_bg_color(objects.screen1, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj0, lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_bpm_value_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_bpm_indicator, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_grad_color(objects.ui_bpm_indicator, lv_color_darken(lv_color_hex(theme_colors[theme_index][4]), 51), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_bpm_indicator, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_preset_number_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_preset_letter_label, lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_preset_heading_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_line_color(objects.obj1, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_icon_gate, lv_color_hex(theme_colors[theme_index][11]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_gate, lv_color_darken(lv_color_hex(theme_colors[theme_index][11]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_comp, lv_color_hex(theme_colors[theme_index][13]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_comp, lv_color_darken(lv_color_hex(theme_colors[theme_index][13]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_amp, lv_color_hex(theme_colors[theme_index][14]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_amp, lv_color_darken(lv_color_hex(theme_colors[theme_index][14]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_cab, lv_color_hex(theme_colors[theme_index][15]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_cab, lv_color_darken(lv_color_hex(theme_colors[theme_index][15]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_line_color(objects.ui_cab_global_disabled, lv_color_hex(theme_colors[theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_icon_eq, lv_color_hex(theme_colors[theme_index][16]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_eq, lv_color_darken(lv_color_hex(theme_colors[theme_index][16]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_mod, lv_color_hex(theme_colors[theme_index][17]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_mod, lv_color_darken(lv_color_hex(theme_colors[theme_index][17]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_delay, lv_color_hex(theme_colors[theme_index][18]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_delay, lv_color_darken(lv_color_hex(theme_colors[theme_index][18]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_reverb, lv_color_hex(theme_colors[theme_index][19]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_reverb, lv_color_darken(lv_color_hex(theme_colors[theme_index][19]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.ui_progress_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_progress_bar, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_progress_bar, lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_debug_text, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 18;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 28;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 38;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 49;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 59;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 69;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 79;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
            {
                startWidgetIndex = 89;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            }
        }
    }
    {
        lv_obj_set_style_bg_color(objects.ui_settings_tab_view, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_settings_tab_view, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][2]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.obj2, lv_color_hex(theme_colors[theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj3, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj4, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj5, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj6, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj7, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj8, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj9, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj10, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj11, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj12, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj13, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj14, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj15, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj16, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj17, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj18, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj19, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj20, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj21, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj22, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_line_color(objects.ui_eq_canvas, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_arc_color(objects.ui_eq_canvas, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_eq_canvas, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj23, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj24, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj25, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj26, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_modulation_param1_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_modulation_param2_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_modulation_param3_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_modulation_param4_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj27, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj28, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj29, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj30, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj31, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj32, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj33, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj34, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj35, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj36, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj37, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj38, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj39, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj40, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj41, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj42, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj43, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj44, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj45, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj46, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj47, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj48, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj49, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj50, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj51, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_line_color(objects.obj52, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_controller_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj53, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj53, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_settings_dialog, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_settings_dialog, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_settings_text_entry, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_settings_vir_cab_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj54, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj54, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_cabinet_vir_button_matrix, lv_color_hex(theme_colors[theme_index][3]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_cabinet_vir_button_matrix, lv_color_hex(theme_colors[theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_cabinet_vir_button_matrix, lv_color_hex(theme_colors[theme_index][5]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_cabinet_vir_button_matrix, lv_color_hex(theme_colors[theme_index][3]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.ui_cabinet_vir_button_matrix, lv_color_hex(theme_colors[theme_index][5]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.ui_cabinet_vir_button_matrix, lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_ITEMS | LV_STATE_PRESSED);
        lv_obj_set_style_bg_color(objects.obj55, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 136;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 143;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 150;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 163;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 170;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 177;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 188;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 195;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 202;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 219;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 226;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 232;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 238;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 244;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 250;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 259;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 265;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 271;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 277;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 283;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 289;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 295;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 301;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 307;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 326;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 334;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 341;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 348;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 367;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 375;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 382;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 397;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 404;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 411;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 418;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 432;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 439;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 446;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
            {
                startWidgetIndex = 453;
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_arc_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][5]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 2], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
            }
        }
    }
    {
        lv_obj_set_style_bg_color(objects.presets, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_preset_list_color_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj56, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj56, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj57, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 489;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 495;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 501;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 507;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 513;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 519;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 525;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 531;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 537;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 543;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
        }
    }
    {
        lv_obj_set_style_bg_color(objects.scenes, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.scenes, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_text_color(objects.obj58, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_scene_delete_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj59, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj59, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_scene_rename_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj60, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj60, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj61, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj62, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 574;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 580;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 586;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 592;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 598;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 604;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 610;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 616;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 622;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 628;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 634;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 640;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 646;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 652;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 658;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 664;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 670;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 676;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 682;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 688;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 3], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
        }
    }
    {
        lv_obj_set_style_bg_color(objects.presets_backup, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.ui_preset_backup_list_page_label, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_preset_backup_delete_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj63, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj63, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_preset_backup_load_dialog, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj64, lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj64, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 709;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 718;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 727;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 736;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 745;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 754;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 763;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 772;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][5]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][2]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 1], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 5], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 6], lv_color_hex(theme_colors[theme_index][0]), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_border_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 7], lv_color_darken(lv_color_hex(theme_colors[theme_index][3]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
        }
    }
    lv_style_set_bg_color(get_style_button_selectable_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_text_color(get_style_button_selectable_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_selectable_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_selectable_purple_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_selectable_red_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_selectable_yellow_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_selectable_green_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_border_color(get_style_button_selectable_green_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_button_selectable_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_button_selectable_blue_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_border_color(get_style_button_selectable_blue_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_button_selectable_purple_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][7]));
    lv_style_set_bg_color(get_style_button_selectable_purple_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][7]));
    lv_style_set_border_color(get_style_button_selectable_purple_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][7]));
    lv_style_set_bg_color(get_style_button_selectable_red_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][8]));
    lv_style_set_bg_color(get_style_button_selectable_red_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][8]));
    lv_style_set_border_color(get_style_button_selectable_red_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][8]));
    lv_style_set_bg_color(get_style_button_selectable_yellow_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_bg_color(get_style_button_selectable_yellow_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_border_color(get_style_button_selectable_yellow_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_bg_color(get_style_button_basic_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_text_color(get_style_button_basic_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_secondary_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_highlighted_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_highlighted_yellow_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_highlighted_purple_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_highlighted_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_highlighted_red_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_basic_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_secondary_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_green_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_yellow_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_purple_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_blue_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_red_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_secondary_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_button_highlighted_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_border_color(get_style_button_highlighted_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_button_highlighted_yellow_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_border_color(get_style_button_highlighted_yellow_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][4]));
    lv_style_set_bg_color(get_style_button_highlighted_purple_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][7]));
    lv_style_set_border_color(get_style_button_highlighted_purple_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][7]));
    lv_style_set_bg_color(get_style_button_highlighted_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_border_color(get_style_button_highlighted_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_button_highlighted_red_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][8]));
    lv_style_set_border_color(get_style_button_highlighted_red_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][8]));
    lv_style_set_border_color(get_style_button_chain_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_chain_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_chain_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_tab_settings_old_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_tab_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_container_preset_list_cell_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_text_color(get_style_container_preset_list_cell_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_container_preset_list_cell_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_text_color(get_style_container_preset_list_cell_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_switch_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_switch_blue_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_border_color(get_style_switch_green_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_border_color(get_style_switch_dark_green_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_border_color(get_style_switch_dark_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_switch_green_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_switch_dark_green_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_switch_dark_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_switch_dark_green_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_border_color(get_style_switch_blue_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_border_color(get_style_switch_dark_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_switch_blue_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_switch_dark_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][6]));
    lv_style_set_bg_color(get_style_switch_dark_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_bar_sub_settings_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_bar_sub_settings_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_text_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_darken(lv_color_hex(theme_colors[theme_index][5]), 191));
    lv_style_set_border_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_container_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_container_sub_settings_2_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_dropdown_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_dropdown_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_text_color(get_style_dropdown_list_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_dropdown_list_sub_settings_SELECTED_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_SELECTED_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_SELECTED_CHECKED(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_text_color(get_style_dropdown_list_sub_settings_SELECTED_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_textarea_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_border_color(get_style_textarea_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_text_color(get_style_textarea_settings_TEXTAREA_PLACEHOLDER_DEFAULT(), lv_color_hex(theme_colors[theme_index][9]));
    lv_style_set_border_color(get_style_checkbox_settings_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_bg_color(get_style_checkbox_settings_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_checkbox_settings_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][5]));
    lv_style_set_text_color(get_style_checkbox_settings_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_button_settings_color_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_border_color(get_style_button_settings_color_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_outline_color(get_style_button_settings_color_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_text_color(get_style_button_settings_color_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_keyboard_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_keyboard_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][9]));
    lv_style_set_bg_color(get_style_keyboard_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_obj_invalidate(objects.screen1);
    lv_obj_invalidate(objects.settings);
    lv_obj_invalidate(objects.presets);
    lv_obj_invalidate(objects.scenes);
    lv_obj_invalidate(objects.presets_backup);
}
uint32_t theme_colors[4][20] = {
    { 0xffffffff, 0xff000000, 0xff292c28, 0xff191c18, 0xffffed27, 0xff80f576, 0xff0075dc, 0xff8b3aff, 0xffff0000, 0xff505050, 0xff6f6f6f, 0xff9b4ef9, 0xff664ef9, 0xffcc4891, 0xffe83f3b, 0xffeb5e22, 0xffa49e96, 0xffe3a929, 0xff72ac3a, 0xff006ff3 },
    { 0xffffffff, 0xff000000, 0xff1e1e1e, 0xff121212, 0xffffed27, 0xff45f862, 0xff1a3af8, 0xff8b3aff, 0xffff2727, 0xff525252, 0xff616161, 0xff6954ff, 0xff000000, 0xffff02c2, 0xffff2727, 0xffff7000, 0xff959595, 0xffffd236, 0xff45f862, 0xff0a74e0 },
    { 0xffffffff, 0xff000000, 0xff2c2c2e, 0xff1c1c1e, 0xffffd600, 0xff30d158, 0xff0091ff, 0xffdb34f2, 0xffff4245, 0xff48484a, 0xff636366, 0xff5e55f5, 0xff000000, 0xffdb34f2, 0xffff4245, 0xffff9230, 0xff8e8e93, 0xffffd600, 0xff30d158, 0xff0091ff },
    { 0xffffffff, 0xff000000, 0xff303131, 0xff1e2028, 0xfffff943, 0xff41b645, 0xff4155d1, 0xffa167e6, 0xffdb2c38, 0xff55747c, 0xff67b7a4, 0xff786dc4, 0xff000000, 0xffb21889, 0xffdb2c38, 0xffd25f1f, 0xff92a1b1, 0xffd0c400, 0xff83c057, 0xff00a0be },
};

//
//
//

void create_screens() {

// Set default LVGL theme
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    // Initialize screens
    // Create screens
    create_screen_screen1();
    create_screen_settings();
    create_screen_presets();
    create_screen_scenes();
    create_screen_presets_backup();
}