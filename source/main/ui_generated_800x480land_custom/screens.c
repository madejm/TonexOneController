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
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_GESTURE_BUBBLE|LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_rounded(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xa7ff00), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_add_event_cb(obj, action_usb, LV_EVENT_PRESSED, (void *)0);
                                    add_style_button_selectable(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffed27), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xffed27), LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xffed27), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                    lv_obj_add_event_cb(obj, action_wifi, LV_EVENT_PRESSED, (void *)0);
                                    add_style_button_selectable(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x8b3aff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x8b3aff), LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0x8b3aff), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                    add_style_button_selectable(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                    add_style_button_selectable(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_CHECKED);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0x275dff), LV_PART_MAIN | LV_STATE_CHECKED);
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
                            lv_obj_set_style_pad_row(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // ui_BPMTitleLabel_1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_bpm_title_label_1 = obj;
                                    lv_obj_set_pos(obj, 0, 64);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0x505050), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "BPM");
                                }
                                {
                                    // ui_BPMValueLabel
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.ui_bpm_value_label = obj;
                                    lv_obj_set_pos(obj, 75, 64);
                                    lv_obj_set_size(obj, 65, LV_SIZE_CONTENT);
                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_SCROLLED);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_32, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text_static(obj, "120");
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
                                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xd1a60c), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xd1b44d), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_radius(obj, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
                                        }
                                    }
                                }
                            }
                        }
                        {
                            // ui_SettingsButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_settings_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                            lv_obj_add_event_cb(obj, action_show_settings_page, LV_EVENT_PRESSED, (void *)0);
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
                            lv_obj_add_event_cb(obj, action_alt_button_clicked, LV_EVENT_PRESSED, (void *)0);
                            add_style_button_selectable(obj);
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton7
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button7 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs7_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs7_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_effect(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel7
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label7 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 132);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel7Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label7_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel7On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label7_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall7
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small7 = obj;
                                                    lv_obj_set_pos(obj, 2200, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall7
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small7 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton8
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button8 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs8_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs8_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_effect(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel8
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label8 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 132);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel8Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label8_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel8On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label8_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall8
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small8 = obj;
                                                    lv_obj_set_pos(obj, 2200, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall8
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small8 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton6
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button6 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs6_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs6_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_effect(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel6
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label6 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 132);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_label_set_text(obj, "↑");
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
                                                            add_style_container_effect_on_off(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel6Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label6_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel6On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label6_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall6
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small6 = obj;
                                                    lv_obj_set_pos(obj, 2200, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall6
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small6 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton1
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button1 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs1_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs1_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_preset(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel1
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label1 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 116);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel1Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label1_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel1On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label1_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetIndex1
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_preset_index1 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                            add_style_label_preset_index(obj);
                                                            lv_label_set_text_static(obj, "1A");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall1
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small1 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall1
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small1 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton2
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button2 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs2_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs2_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_preset(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel2
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label2 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 116);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel2Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label2_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel2On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label2_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetIndex2
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_preset_index2 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                            add_style_label_preset_index(obj);
                                                            lv_label_set_text_static(obj, "1B");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall2
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small2 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall2
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small2 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton3
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button3 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs3_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs3_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_preset(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel3
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label3 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 116);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel3Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label3_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel3On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label3_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetIndex3
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_preset_index3 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                            add_style_label_preset_index(obj);
                                                            lv_label_set_text_static(obj, "1C");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall3
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small3 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall3
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small3 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton4
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button4 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs4_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs4_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_preset(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel4
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label4 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 116);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text(obj, "...");
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
                                                            add_style_container_effect_on_off(obj);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_BOTTOM_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel4Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label4_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel4On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label4_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                        {
                                                            // ui_PresetIndex4
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_preset_index4 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                            add_style_label_preset_index(obj);
                                                            lv_label_set_text_static(obj, "1D");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall4
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small4 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall4
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small4 = obj;
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
                                            add_style_container_preset(obj);
                                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            {
                                                lv_obj_t *parent_obj = obj;
                                                {
                                                    // ui_EffectButton5
                                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                                    objects.ui_effect_button5 = obj;
                                                    lv_obj_set_pos(obj, 0, 0);
                                                    lv_obj_set_size(obj, LV_PCT(100), 188);
                                                    lv_obj_add_event_cb(obj, action_fs5_clicked, LV_EVENT_SHORT_CLICKED, (void *)0);
                                                    lv_obj_add_event_cb(obj, action_fs5_clicked, LV_EVENT_LONG_PRESSED, (void *)0);
                                                    add_style_button_effect(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabel5
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label5 = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_PCT(100), 132);
                                                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                                                            add_style_label_preset_name(obj);
                                                            lv_label_set_text(obj, "↓");
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
                                                            add_style_container_effect_on_off(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_EffectLabel5Off
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label5_off = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                                {
                                                                    // ui_EffectLabel5On
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_effect_label5_on = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_PCT(100), LV_SIZE_CONTENT);
                                                                    lv_label_set_long_mode(obj, LV_LABEL_LONG_CLIP);
                                                                    lv_label_set_text_static(obj, "...");
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EffectButtonSmall5
                                                    lv_obj_t *obj = lv_obj_create(parent_obj);
                                                    objects.ui_effect_button_small5 = obj;
                                                    lv_obj_set_pos(obj, 2200, 0);
                                                    lv_obj_set_size(obj, 138, LV_SIZE_CONTENT);
                                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE|LV_OBJ_FLAG_SCROLLABLE);
                                                    add_style_container_preset_small(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EffectLabelSmall5
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_effect_label_small5 = obj;
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
                                    lv_obj_add_event_cb(obj, action_open_presets_page, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_font(obj, &ui_font_ibm_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
                                            lv_obj_set_style_align(obj, LV_ALIGN_TOP_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][4]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][6]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][7]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][7]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][8]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                            lv_obj_set_style_line_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][10]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][11]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][11]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
                                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][12]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][12]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
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
    }
    
    tick_screen_screen1();
}

void tick_screen_screen1() {
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_get_tab_btns(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 8, LV_PART_ITEMS | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_bg_opa(obj, 50, LV_PART_ITEMS | LV_STATE_CHECKED);
                    lv_obj_set_style_pad_right(obj, 80, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_NoiseGateSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_noise_gate_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_NoiseGatePostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_noise_gate_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                            lv_obj_add_event_cb(obj, action_settings_copy_gate, LV_EVENT_PRESSED, (void *)0);
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
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Threshold");
                                                }
                                                {
                                                    // ui_NoiseGateThresholdSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_noise_gate_threshold_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_NoiseGateThresholdValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_noise_gate_threshold_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                                    objects.obj6 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Release");
                                                }
                                                {
                                                    // ui_NoiseGateReleaseSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_noise_gate_release_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_NoiseGateReleaseValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_noise_gate_release_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "ms");
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
                                                    objects.obj7 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Depth");
                                                }
                                                {
                                                    // ui_NoiseGateDepthSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_noise_gate_depth_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_NoiseGateDepthValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_noise_gate_depth_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_CompressorEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_compressor_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_CompressorPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_compressor_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                            lv_obj_add_event_cb(obj, action_settings_copy_compressor, LV_EVENT_PRESSED, (void *)0);
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
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Threshold");
                                                }
                                                {
                                                    // ui_CompressorThresholdSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_compressor_threshold_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CompressorThresholdValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_compressor_threshold_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                                    objects.obj11 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Gain");
                                                }
                                                {
                                                    // ui_CompressorGainSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_compressor_gain_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CompressorGainValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_compressor_gain_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                                    objects.obj12 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Attack");
                                                }
                                                {
                                                    // ui_CompressorAttackSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_compressor_attack_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_CompressorAttackValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_compressor_attack_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "ms");
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_AmpEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_amp_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj14 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_add_event_cb(obj, action_settings_copy_amp, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    objects.obj15 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Gain");
                                                }
                                                {
                                                    // ui_AmplifierGainSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_amplifier_gain_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_AmplifierGainValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_amplifier_gain_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                                    objects.obj16 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Volume");
                                                }
                                                {
                                                    // ui_AmplifierVolumeSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_amplifier_volume_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_AmplifierVolumeValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_amplifier_volume_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
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
                            lv_obj_set_style_line_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_arc_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_t *obj = lv_tabview_create(parent_obj, LV_DIR_TOP, 44);
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
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_amplifier_depth_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_AmplifierDepthValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_amplifier_depth_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
                                                        }
                                                    }
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
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_bass_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 100);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQBassFreqValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_bass_freq_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Hz");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EQBassSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_bass_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQBassValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_bass_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
                                                        }
                                                    }
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
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_mid_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 100);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQMidFreqValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_mid_freq_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Hz");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EQMidQSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_mid_qslider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 50);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQMidQValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_mid_qvalue = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Q");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EQMidSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_mid_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQMidValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_mid_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
                                                        }
                                                    }
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
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_treble_freq_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 100);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQTrebleFreqValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_treble_freq_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Hz");
                                                        }
                                                    }
                                                }
                                                {
                                                    // ui_EQTrebleSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_eq_treble_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_EQTrebleValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_eq_treble_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
                                                        }
                                                    }
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
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_amplifier_presense_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_AmplifierPresenseValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_amplifier_presense_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            add_style_label_arc_value(obj);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                    lv_obj_set_style_pad_row(obj, 14, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    {
                                        lv_obj_t *parent_obj = obj;
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 45);
                                            lv_obj_add_event_cb(obj, action_settings_copy_eq, LV_EVENT_PRESSED, (void *)0);
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
                                            lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj17 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_ModulationEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj18 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_ModulationPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Sync");
                                                }
                                                {
                                                    // ui_ModulationSyncSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_modulation_sync_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj20 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_add_event_cb(obj, action_settings_copy_modulation, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                            lv_obj_t *obj = lv_arc_create(parent_obj);
                                                            objects.ui_modulation_param1_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_arc_set_value(obj, 0);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_arc_settings(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_ModulationParam1Value
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_modulation_param1_value = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "0");
                                                                }
                                                                {
                                                                    // ui_ModulationParam1Unit
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_modulation_param1_unit = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_label_set_text_static(obj, "u");
                                                                }
                                                            }
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 2");
                                                }
                                                {
                                                    // ui_ModulationParam2Slider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_modulation_param2_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ModulationParam2Value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param2_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            // ui_ModulationParam2Unit
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param2_unit = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "u");
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
                                                    // ui_ModulationParam3Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param3_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 3");
                                                }
                                                {
                                                    // ui_ModulationParam3Slider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_modulation_param3_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ModulationParam3Value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param3_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            // ui_ModulationParam3Unit
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param3_unit = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "u");
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
                                                    // ui_ModulationParam4Label
                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                    objects.ui_modulation_param4_label = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Param 4");
                                                }
                                                {
                                                    // ui_ModulationParam4Slider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_modulation_param4_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ModulationParam4Value
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param4_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            // ui_ModulationParam4Unit
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_modulation_param4_unit = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "u");
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
                                                    objects.obj21 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_DelayEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj22 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_DelayPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj23 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Sync");
                                                }
                                                {
                                                    // ui_DelaySyncSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_sync_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Ping-Pong");
                                                }
                                                {
                                                    // ui_DelayPingPongSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_delay_ping_pong_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    objects.obj25 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_add_event_cb(obj, action_settings_copy_delay, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    objects.obj26 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                            lv_obj_t *obj = lv_arc_create(parent_obj);
                                                            objects.ui_delay_ts_slider = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, 150, 150);
                                                            lv_arc_set_value(obj, 0);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_arc_settings(obj);
                                                            {
                                                                lv_obj_t *parent_obj = obj;
                                                                {
                                                                    // ui_DelayTSValue
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    objects.ui_delay_ts_value = obj;
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                                    lv_label_set_text_static(obj, "0");
                                                                }
                                                                {
                                                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                                                    lv_obj_set_pos(obj, 0, 0);
                                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                                    lv_label_set_text_static(obj, "ms");
                                                                }
                                                            }
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
                                                    objects.obj27 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Feedback");
                                                }
                                                {
                                                    // ui_DelayFeedbackSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_delay_feedback_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_DelayFeedbackValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_delay_feedback_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "%");
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
                                                    objects.obj28 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mix");
                                                }
                                                {
                                                    // ui_DelayMixSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_delay_mix_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_DelayMixValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_delay_mix_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "%");
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
                                                    objects.obj29 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Enable");
                                                }
                                                {
                                                    // ui_ReverbEnableSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_reverb_enable_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Post");
                                                }
                                                {
                                                    // ui_ReverbPostSwitch
                                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                                    objects.ui_reverb_post_switch = obj;
                                                    lv_obj_set_pos(obj, 168, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_switch_dark(obj);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    lv_obj_add_event_cb(obj, action_settings_copy_reverb, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_add_event_cb(obj, action_settings_paste, LV_EVENT_PRESSED, (void *)0);
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Time");
                                                }
                                                {
                                                    // ui_ReverbTimeSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_reverb_time_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ReverbTimeValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_reverb_time_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "s");
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
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Pre-Delay");
                                                }
                                                {
                                                    // ui_ReverbPredelaySlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_reverb_predelay_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ReverbPredelayValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_reverb_predelay_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "ms");
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
                                                    objects.obj34 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Color");
                                                }
                                                {
                                                    // ui_ReverbColorSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_reverb_color_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ReverbColorValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_reverb_color_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
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
                                                    objects.obj35 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Mix");
                                                }
                                                {
                                                    // ui_ReverbMixSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_reverb_mix_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_ReverbMixValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_reverb_mix_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "%");
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
                                                            objects.obj36 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Cab Bypass");
                                                        }
                                                        {
                                                            // ui_CabBypassSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_cab_bypass_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark(obj);
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
                                                            objects.obj37 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Direct Monitor");
                                                        }
                                                        {
                                                            // ui_DirectMonitorSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_direct_monitor_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark(obj);
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
                                                            objects.obj38 = obj;
                                                            lv_obj_set_pos(obj, 13, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                            lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "Tempo Per Preset");
                                                        }
                                                        {
                                                            // ui_TempoSourceSwitch
                                                            lv_obj_t *obj = lv_switch_create(parent_obj);
                                                            objects.ui_tempo_source_switch = obj;
                                                            lv_obj_set_pos(obj, 168, -148);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                            add_style_switch_dark(obj);
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
                                                    objects.obj39 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "BPM");
                                                }
                                                {
                                                    // ui_BPMSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_bpm_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_BPMValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_bpm_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
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
                                                    objects.obj40 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Input Trim");
                                                }
                                                {
                                                    // ui_InputTrimSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_input_trim_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_InputTrimValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_input_trim_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "dB");
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
                                                    objects.obj41 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Tuning Ref");
                                                }
                                                {
                                                    // ui_TuningReferenceSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_tuning_reference_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_TuningReferenceValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_tuning_reference_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_label_set_text_static(obj, "Hz");
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
                                                    objects.obj42 = obj;
                                                    lv_obj_set_pos(obj, 13, -92);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_label_set_text_static(obj, "Master Volume");
                                                }
                                                {
                                                    // ui_VolumeSlider
                                                    lv_obj_t *obj = lv_arc_create(parent_obj);
                                                    objects.ui_volume_slider = obj;
                                                    lv_obj_set_pos(obj, 409, 251);
                                                    lv_obj_set_size(obj, 150, 150);
                                                    lv_arc_set_value(obj, 0);
                                                    lv_obj_add_event_cb(obj, action_parameter_changed, LV_EVENT_RELEASED, (void *)0);
                                                    add_style_arc_settings(obj);
                                                    {
                                                        lv_obj_t *parent_obj = obj;
                                                        {
                                                            // ui_VolumeValue
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            objects.ui_volume_value = obj;
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                                            lv_label_set_text_static(obj, "0");
                                                        }
                                                        {
                                                            lv_obj_t *obj = lv_label_create(parent_obj);
                                                            lv_obj_set_pos(obj, 0, 0);
                                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
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
                                                    objects.obj43 = obj;
                                                    lv_obj_set_pos(obj, 13, -148);
                                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                    add_style_switch_dark(obj);
                                                }
                                            }
                                        }
                                        {
                                            lv_obj_t *obj = lv_btn_create(parent_obj);
                                            lv_obj_set_pos(obj, 0, 0);
                                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                            lv_obj_add_event_cb(obj, action_save_wifi_settings, LV_EVENT_PRESSED, (void *)0);
                                            add_style_button_highlighted(obj);
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
                                    // ui_USBRebootButton
                                    lv_obj_t *obj = lv_btn_create(parent_obj);
                                    objects.ui_usb_reboot_button = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_usb_reboot, LV_EVENT_PRESSED, (void *)0);
                                    add_style_button_highlighted(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_add_event_cb(obj, action_usb_flash, LV_EVENT_PRESSED, (void *)0);
                                    add_style_button_highlighted(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    objects.obj44 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    static lv_point_t line_points[] = {
                        { 0, 0 },
                        { 0, 40 }
                    };
                    lv_line_set_points(obj, line_points, 2);
                    lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_line_rounded(obj, true, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 732, 0);
                    lv_obj_set_size(obj, 68, 50);
                    lv_obj_add_event_cb(obj, action_close_settings_page, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj45 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 686, 423);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(0x81562e), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0x2a2a2a), LV_PART_MAIN | LV_STATE_DEFAULT);
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
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_border_color(obj, lv_color_hex(0x81562e), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x2a2a2a), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xd1a60c), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    }
    lv_keyboard_set_textarea(objects.ui_controller_dialog_keyboard, objects.ui_controller_dialog_entry);
    lv_keyboard_set_textarea(objects.ui_settings_keyboard, objects.ui_settings_text_entry);
    
    tick_screen_settings();
}

void tick_screen_settings() {
}

void create_screen_presets() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.presets = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 170, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_previous, LV_EVENT_PRESSED, (void *)0);
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
                            // ui_PresetListCancelButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_list_cancel_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_cancel, LV_EVENT_PRESSED, (void *)0);
                            add_style_button_highlighted(obj);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                            // ui_PresetListScenesButton
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            objects.ui_preset_list_scenes_button = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                            lv_obj_add_event_cb(obj, action_open_scenes_page, LV_EVENT_PRESSED, (void *)0);
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
                            lv_obj_t *obj = lv_btn_create(parent_obj);
                            lv_obj_set_pos(obj, 562, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_next, LV_EVENT_PRESSED, (void *)0);
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
                            lv_obj_add_event_cb(obj, action_close_presets_page, LV_EVENT_PRESSED, (void *)0);
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
                                    create_user_widget_preset_button(obj, 269);
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
                                    create_user_widget_preset_button(obj, 275);
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
                                    create_user_widget_preset_button(obj, 281);
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
                                    create_user_widget_preset_button(obj, 287);
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
                                    create_user_widget_preset_button(obj, 293);
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
                                    create_user_widget_preset_button(obj, 299);
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
                                    create_user_widget_preset_button(obj, 305);
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
                                    create_user_widget_preset_button(obj, 311);
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
                                    create_user_widget_preset_button(obj, 317);
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
                                    create_user_widget_preset_button(obj, 323);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj46 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)0);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)1);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)2);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)3);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)4);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)5);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)6);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)7);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)8);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)9);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)10);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)11);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)12);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)13);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)14);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)15);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)16);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)17);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)18);
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
                                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)19);
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
                                            lv_obj_add_event_cb(obj, action_preset_list_color, LV_EVENT_PRESSED, (void *)20);
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
                            objects.obj47 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_preset_list_dialog_close, LV_EVENT_PRESSED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    tick_user_widget_preset_button(269);
    tick_user_widget_preset_button(275);
    tick_user_widget_preset_button(281);
    tick_user_widget_preset_button(287);
    tick_user_widget_preset_button(293);
    tick_user_widget_preset_button(299);
    tick_user_widget_preset_button(305);
    tick_user_widget_preset_button(311);
    tick_user_widget_preset_button(317);
    tick_user_widget_preset_button(323);
}

void create_screen_scenes() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.scenes = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, action_scene_rename_dialog_keyboard_ok, LV_EVENT_READY, (void *)0);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_row(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_column(obj, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 60, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                            create_user_widget_preset_button(obj, 354);
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
                            create_user_widget_preset_button(obj, 360);
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
                            create_user_widget_preset_button(obj, 366);
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
                            create_user_widget_preset_button(obj, 372);
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
                            create_user_widget_preset_button(obj, 378);
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
                            create_user_widget_preset_button(obj, 384);
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
                            create_user_widget_preset_button(obj, 390);
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
                            create_user_widget_preset_button(obj, 396);
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
                            create_user_widget_preset_button(obj, 402);
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
                            create_user_widget_preset_button(obj, 408);
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
                            create_user_widget_preset_button(obj, 414);
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
                            create_user_widget_preset_button(obj, 420);
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
                            create_user_widget_preset_button(obj, 426);
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
                            create_user_widget_preset_button(obj, 432);
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
                            create_user_widget_preset_button(obj, 438);
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
                            create_user_widget_preset_button(obj, 444);
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
                            create_user_widget_preset_button(obj, 450);
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
                            create_user_widget_preset_button(obj, 456);
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
                            create_user_widget_preset_button(obj, 462);
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
                            create_user_widget_preset_button(obj, 468);
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
                    lv_obj_add_event_cb(obj, action_new_scene, LV_EVENT_PRESSED, (void *)0);
                    add_style_button_basic(obj);
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
                    lv_obj_t *obj = lv_btn_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 68, 50);
                    lv_obj_add_event_cb(obj, action_close_scenes_page, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj48 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    objects.obj49 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, 50);
                                    lv_obj_add_event_cb(obj, action_scene_delete_dialog_delete, LV_EVENT_PRESSED, (void *)0);
                                    add_style_button_highlighted(obj);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_color(obj, lv_color_hex(0xff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    lv_obj_add_event_cb(obj, action_scene_delete_dialog_cancel, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    objects.obj50 = obj;
                    lv_obj_set_pos(obj, 0, 12);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_border_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                                    objects.obj51 = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
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
                            objects.obj52 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, 68, 50);
                            lv_obj_add_event_cb(obj, action_scene_rename_dialog_close, LV_EVENT_PRESSED, (void *)0);
                            add_style_button_basic(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
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
    tick_user_widget_preset_button(354);
    tick_user_widget_preset_button(360);
    tick_user_widget_preset_button(366);
    tick_user_widget_preset_button(372);
    tick_user_widget_preset_button(378);
    tick_user_widget_preset_button(384);
    tick_user_widget_preset_button(390);
    tick_user_widget_preset_button(396);
    tick_user_widget_preset_button(402);
    tick_user_widget_preset_button(408);
    tick_user_widget_preset_button(414);
    tick_user_widget_preset_button(420);
    tick_user_widget_preset_button(426);
    tick_user_widget_preset_button(432);
    tick_user_widget_preset_button(438);
    tick_user_widget_preset_button(444);
    tick_user_widget_preset_button(450);
    tick_user_widget_preset_button(456);
    tick_user_widget_preset_button(462);
    tick_user_widget_preset_button(468);
}

void create_user_widget_preset_button(lv_obj_t *parent_obj, int startWidgetIndex) {
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
            lv_obj_add_event_cb(obj, action_preset_button, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_min_height(obj, 72, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[active_theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
            lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Color
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_PCT(100));
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    add_style_panel_preset_list_color(obj);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // Label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_PCT(88), LV_SIZE_CONTENT);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_CHECKED);
                    lv_obj_set_style_pad_left(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_align(obj, LV_ALIGN_LEFT_MID, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                            lv_obj_add_event_cb(obj, action_preset_button_options, LV_EVENT_VALUE_CHANGED, (void *)0);
                            lv_obj_set_style_text_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_opa(obj, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_INDICATOR | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_dropdown_get_list(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                    lv_obj_set_style_text_font(obj, &ui_font_ibm_22, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_hex(theme_colors[active_theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_line_space(obj, 34, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_CHECKED);
                                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_SELECTED | LV_STATE_DEFAULT);
                                    lv_obj_set_style_bg_color(obj, lv_color_darken(lv_color_hex(theme_colors[active_theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
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

void tick_user_widget_preset_button(int startWidgetIndex) {
    (void)startWidgetIndex;
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_screen1,
    tick_screen_settings,
    tick_screen_presets,
    tick_screen_scenes,
};
void tick_screen(int screen_index) {
    if (screen_index >= 0 && screen_index < 4) {
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
        lv_obj_set_style_text_color(objects.ui_preset_letter_label, lv_color_hex(theme_colors[theme_index][3]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_icon_gate, lv_color_hex(theme_colors[theme_index][4]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_gate, lv_color_darken(lv_color_hex(theme_colors[theme_index][4]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_comp, lv_color_hex(theme_colors[theme_index][6]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_comp, lv_color_darken(lv_color_hex(theme_colors[theme_index][6]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_amp, lv_color_hex(theme_colors[theme_index][7]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_amp, lv_color_darken(lv_color_hex(theme_colors[theme_index][7]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_cab, lv_color_hex(theme_colors[theme_index][8]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_cab, lv_color_darken(lv_color_hex(theme_colors[theme_index][8]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_eq, lv_color_hex(theme_colors[theme_index][9]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_eq, lv_color_darken(lv_color_hex(theme_colors[theme_index][9]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_mod, lv_color_hex(theme_colors[theme_index][10]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_mod, lv_color_darken(lv_color_hex(theme_colors[theme_index][10]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_delay, lv_color_hex(theme_colors[theme_index][11]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_delay, lv_color_darken(lv_color_hex(theme_colors[theme_index][11]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.ui_icon_reverb, lv_color_hex(theme_colors[theme_index][12]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_icon_reverb, lv_color_darken(lv_color_hex(theme_colors[theme_index][12]), 204), LV_PART_MAIN | LV_STATE_CHECKED);
    }
    {
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][0]), LV_PART_ITEMS | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(objects.obj2, lv_color_hex(theme_colors[theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(objects.obj2, lv_color_hex(theme_colors[theme_index][2]), LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_set_style_arc_color(objects.ui_eq_canvas, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_eq_canvas, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.ui_usb_reboot_button, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.ui_usb_reboot_button, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_line_color(objects.obj44, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
        lv_obj_set_style_border_color(objects.obj46, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj46, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj47, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 269;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 275;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 281;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 287;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 293;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 299;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 305;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 311;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 317;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 323;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
        }
    }
    {
        lv_obj_set_style_border_color(objects.obj48, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj48, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(objects.obj50, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj50, lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(objects.obj52, lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
        {
            int startWidgetIndex;
            (void)startWidgetIndex;
            {
                startWidgetIndex = 354;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 360;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 366;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 372;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 378;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 384;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 390;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 396;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 402;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 408;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 414;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 420;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 426;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 432;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 438;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 444;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 450;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 456;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 462;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
            {
                startWidgetIndex = 468;
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][0]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_text_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_CHECKED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][0]), 64), LV_PART_MAIN | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 0], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_MAIN | LV_STATE_CHECKED | LV_STATE_PRESSED);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_hex(theme_colors[theme_index][1]), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_bg_color(((lv_obj_t **)&objects)[startWidgetIndex + 4], lv_color_darken(lv_color_hex(theme_colors[theme_index][1]), 64), LV_PART_SELECTED | LV_STATE_PRESSED);
            }
        }
    }
    lv_style_set_bg_color(get_style_button_selectable_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_selectable_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_selectable_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_border_color(get_style_button_selectable_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_button_basic_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_basic_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_secondary_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_highlighted_MAIN_PRESSED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_secondary_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_highlighted_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_border_color(get_style_button_highlighted_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_container_preset_small_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_button_preset_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_button_effect_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_arc_color(get_style_arc_settings_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_container_preset_list_cell_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_container_preset_list_cell_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_container_preset_list_cell_MAIN_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_switch_default_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_border_color(get_style_switch_default_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_border_color(get_style_switch_dark_KNOB_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_switch_default_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_switch_dark_KNOB_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_bar_sub_settings_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_border_color(get_style_bar_sub_settings_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_container_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_container_sub_settings_2_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][0]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_dropdown_list_sub_settings_SELECTED_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_SELECTED_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_dropdown_list_sub_settings_SELECTED_CHECKED(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_dropdown_list_sub_settings_SELECTED_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_border_color(get_style_textarea_settings_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_text_color(get_style_textarea_settings_TEXTAREA_PLACEHOLDER_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_border_color(get_style_checkbox_settings_INDICATOR_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_checkbox_settings_INDICATOR_CHECKED(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_outline_color(get_style_panel_preset_list_color_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    lv_style_set_bg_color(get_style_keyboard_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][1]));
    lv_style_set_bg_color(get_style_keyboard_ITEMS_DEFAULT(), lv_color_hex(theme_colors[theme_index][3]));
    lv_style_set_bg_color(get_style_keyboard_ITEMS_CHECKED(), lv_color_hex(theme_colors[theme_index][0]));
    lv_obj_invalidate(objects.screen1);
    lv_obj_invalidate(objects.settings);
    lv_obj_invalidate(objects.presets);
    lv_obj_invalidate(objects.scenes);
}
uint32_t theme_colors[1][13] = {
    { 0xff292c28, 0xff191c18, 0xff80f576, 0xff505050, 0xff9b4ef9, 0xff664ef9, 0xffcc4891, 0xffe83f3b, 0xffeb5e22, 0xffa49e96, 0xffe3a929, 0xff72ac3a, 0xff006ff3 },
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
}