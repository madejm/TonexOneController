#include "display_preset_list.h"
#include "esp_log.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
#endif
#include "display_helpers.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "usb_tonex.h"
#include "control.h"
#include "wifi_config.h"
#include "tonex_params.h"
#include "display_scenes.h"

static const char *TAG = "app_display_preset_list";

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
typedef enum
{
    PRESET_LIST_INSERT_MODE_INSERT,
    PRESET_LIST_INSERT_MODE_SWAP
} PresetListInsertMode_t;

static PresetListInsertMode_t preset_list_insert_mode = PRESET_LIST_INSERT_MODE_INSERT;
static int16_t preset_list_edit_index = -1;

#define PRESET_LIST_PRESETS_PER_PAGE 10
static uint8_t preset_list_page = 0;
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

// ====== UPDATES ======

void updatePresetListSelection()
{
    uint8_t pageStart = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;
    uint8_t selectedPreset;

    if (preset_list_edit_index > -1) {
        selectedPreset = preset_list_edit_index;
    } else {
        selectedPreset = control_get_current_preset_mapped_index();
    }

    lv_obj_set_checked(objects.ui_preset_list_element_0__button, selectedPreset == (pageStart + 0));
    lv_obj_set_checked(objects.ui_preset_list_element_1__button, selectedPreset == (pageStart + 1));
    lv_obj_set_checked(objects.ui_preset_list_element_2__button, selectedPreset == (pageStart + 2));
    lv_obj_set_checked(objects.ui_preset_list_element_3__button, selectedPreset == (pageStart + 3));
    lv_obj_set_checked(objects.ui_preset_list_element_4__button, selectedPreset == (pageStart + 4));
    lv_obj_set_checked(objects.ui_preset_list_element_5__button, selectedPreset == (pageStart + 5));
    lv_obj_set_checked(objects.ui_preset_list_element_6__button, selectedPreset == (pageStart + 6));
    lv_obj_set_checked(objects.ui_preset_list_element_7__button, selectedPreset == (pageStart + 7));
    lv_obj_set_checked(objects.ui_preset_list_element_8__button, selectedPreset == (pageStart + 8));
    lv_obj_set_checked(objects.ui_preset_list_element_9__button, selectedPreset == (pageStart + 9));
}

static inline void lv_label_set_preset_name(lv_obj_t* label, uint8_t index)
{
    char name[MAX_PRESET_NAME_LENGTH];
    char text[MAX_PRESET_NAME_LENGTH + 8];
    control_get_preset_name(index, name);
    snprintf(text, sizeof(text), "%u: %s", index + usb_get_first_preset_index_for_connected_modeller(), name);
    lv_label_set_text(label, text);
}

static inline void lv_panel_set_preset_color(lv_obj_t* colorPanel, uint8_t index)
{
    uint32_t color = get_preset_color(index);
    lv_obj_set_style_outline_color(colorPanel, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(colorPanel, LV_OBJ_FLAG_HIDDEN);
}

void updatePresetListColors()
{
    uint8_t pageStart = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;

    lv_panel_set_preset_color(objects.ui_preset_list_element_0__color, pageStart + 0);
    lv_panel_set_preset_color(objects.ui_preset_list_element_1__color, pageStart + 1);
    lv_panel_set_preset_color(objects.ui_preset_list_element_2__color, pageStart + 2);
    lv_panel_set_preset_color(objects.ui_preset_list_element_3__color, pageStart + 3);
    lv_panel_set_preset_color(objects.ui_preset_list_element_4__color, pageStart + 4);
    lv_panel_set_preset_color(objects.ui_preset_list_element_5__color, pageStart + 5);
    lv_panel_set_preset_color(objects.ui_preset_list_element_6__color, pageStart + 6);
    lv_panel_set_preset_color(objects.ui_preset_list_element_7__color, pageStart + 7);
    lv_panel_set_preset_color(objects.ui_preset_list_element_8__color, pageStart + 8);
    lv_panel_set_preset_color(objects.ui_preset_list_element_9__color, pageStart + 9);
}

void updatePresetListNames()
{
    uint8_t pageStart = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;

    lv_label_set_preset_name(objects.ui_preset_list_element_0__label, pageStart + 0);
    lv_label_set_preset_name(objects.ui_preset_list_element_1__label, pageStart + 1);
    lv_label_set_preset_name(objects.ui_preset_list_element_2__label, pageStart + 2);
    lv_label_set_preset_name(objects.ui_preset_list_element_3__label, pageStart + 3);
    lv_label_set_preset_name(objects.ui_preset_list_element_4__label, pageStart + 4);
    lv_label_set_preset_name(objects.ui_preset_list_element_5__label, pageStart + 5);
    lv_label_set_preset_name(objects.ui_preset_list_element_6__label, pageStart + 6);
    lv_label_set_preset_name(objects.ui_preset_list_element_7__label, pageStart + 7);
    lv_label_set_preset_name(objects.ui_preset_list_element_8__label, pageStart + 8);
    lv_label_set_preset_name(objects.ui_preset_list_element_9__label, pageStart + 9);
    
    updatePresetListColors();
}

// ====== ACTIONS ======

void action_open_presets_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_open_presets_page");

    preset_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_list_color_dialog, LV_OBJ_FLAG_HIDDEN);

    updatePresetListSelection();
    updatePresetListNames();

    const char *options = "Insert before...\nSwap with...\nChange color";
    lv_dropdown_set_options(objects.ui_preset_list_element_0__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_1__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_2__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_3__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_4__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_5__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_6__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_7__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_8__options, options);
    lv_dropdown_set_options(objects.ui_preset_list_element_9__options, options);

    lv_scr_load_anim(objects.presets, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_close_presets_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_close_presets_page");

    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void selectPresetListPreset(uint8_t buttonIndex)
{
    ESP_LOGI(TAG, "action_preset_list_select");

    uint8_t preset_index = buttonIndex + preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;

    if (preset_list_edit_index > -1) {
        uint8_t newPresetOrder[MAX_SUPPORTED_PRESETS];
        memcpy(newPresetOrder, control_get_preset_order(), MAX_SUPPORTED_PRESETS);
        
        switch (preset_list_insert_mode)
        {
            case PRESET_LIST_INSERT_MODE_INSERT:
            {
                uint8_t movedValue = newPresetOrder[preset_list_edit_index];

                if (preset_list_edit_index < preset_index)
                {
                    // Shift left
                    for (uint8_t i = preset_list_edit_index; i < preset_index; i++)
                    {
                        newPresetOrder[i] = newPresetOrder[i + 1];
                    }
                }
                else if (preset_list_edit_index > preset_index)
                {
                    // Shift right
                    for (uint8_t i = preset_list_edit_index; i > preset_index; i--)
                    {
                        newPresetOrder[i] = newPresetOrder[i - 1];
                    }
                }
                newPresetOrder[preset_index] = movedValue;
            } break;

            case PRESET_LIST_INSERT_MODE_SWAP:
            {
                uint8_t temp = newPresetOrder[preset_list_edit_index];
                newPresetOrder[preset_list_edit_index] = newPresetOrder[preset_index];
                newPresetOrder[preset_index] = temp;
            } break;

            default:
                break;
        }

        control_set_preset_order(newPresetOrder);
        control_save_user_data(0);
        wifi_request_sync(WIFI_SYNC_TYPE_CONFIG, NULL, NULL);
        
        preset_list_edit_index = -1;
        lv_obj_add_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);

        updatePresetListSelection();
        updatePresetListNames();
    } else {
        lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
        control_request_preset_index(preset_index);
    }
}

void action_preset_list_previous(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_previous");

    if (preset_list_page == 0) {
        preset_list_page = usb_get_max_presets_for_connected_modeller() / PRESET_LIST_PRESETS_PER_PAGE - 1;
    } else {
        preset_list_page -= 1;
    }
    updatePresetListSelection();
    updatePresetListNames();
}

void action_preset_list_next(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_next");

    if (preset_list_page == (usb_get_max_presets_for_connected_modeller() / PRESET_LIST_PRESETS_PER_PAGE - 1)) {
        preset_list_page = 0;
    } else {
        preset_list_page += 1;
    }
    updatePresetListSelection();
    updatePresetListNames();
}

static void setDialogColorButton(int index, uint32_t rawColor)
{
    if (index >= TONEX_COLORS_COUNT) {
        return;
    }

    lv_obj_t * button;

    switch (index) {
        case 0: button = objects.ui_preset_list_color0; break;
        case 1: button = objects.ui_preset_list_color1; break;
        case 2: button = objects.ui_preset_list_color2; break;
        case 3: button = objects.ui_preset_list_color3; break;
        case 4: button = objects.ui_preset_list_color4; break;
        case 5: button = objects.ui_preset_list_color5; break;
        case 6: button = objects.ui_preset_list_color6; break;
        case 7: button = objects.ui_preset_list_color7; break;
        case 8: button = objects.ui_preset_list_color8; break;
        case 9: button = objects.ui_preset_list_color9; break;
        case 10: button = objects.ui_preset_list_color10; break;
        case 11: button = objects.ui_preset_list_color11; break;
        case 12: button = objects.ui_preset_list_color12; break;
        case 13: button = objects.ui_preset_list_color13; break;
        case 14: button = objects.ui_preset_list_color14; break;
        case 15: button = objects.ui_preset_list_color15; break;
        case 16: button = objects.ui_preset_list_color16; break;
        case 17: button = objects.ui_preset_list_color17; break;
        case 18: button = objects.ui_preset_list_color18; break;
        case 19: button = objects.ui_preset_list_color19; break;
        case 20: button = objects.ui_preset_list_color20; break;
        default: return;
    }

    lv_color_t bgColor = lv_obj_get_style_bg_color(button, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(button, bgColor, LV_PART_MAIN | LV_STATE_CHECKED);

    const tTonexPresetColorMapping mapping = TonexColorMap[index];

    lv_obj_set_checked(button, mapping.rawColor == rawColor);
}

void presetOptionsSelected(uint8_t buttonIndex, uint16_t option)
{
    if (preset_list_edit_index > -1) {
        return;
    }

    preset_list_edit_index = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE + buttonIndex;

    switch (option) {
        case 0:
        case 1: {
            preset_list_insert_mode = option == 0 ? PRESET_LIST_INSERT_MODE_INSERT : PRESET_LIST_INSERT_MODE_SWAP;

            lv_obj_clear_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
            updatePresetListSelection();
        } break;

        case 2: {
            lv_label_set_preset_name(objects.ui_preset_list_color_dialog_name, preset_list_edit_index);

            uint32_t rawColor = get_preset_color_raw(preset_list_edit_index);

            for (int i = 0; i <= 20; i++) {
                setDialogColorButton(i, rawColor);
            }

            lv_obj_clear_flag(objects.ui_preset_list_color_dialog, LV_OBJ_FLAG_HIDDEN);
        } break;
    }
}

void action_preset_list_color(lv_event_t * e)
{
    if (preset_list_edit_index < 0 || preset_list_edit_index >= TONEX_COLORS_COUNT) {
        return;
    }

    uint8_t colorIndex = (uint8_t)(intptr_t)lv_event_get_user_data(e);
    const tTonexPresetColorMapping mapping = TonexColorMap[colorIndex];
    
    uint8_t *preset_order = control_get_preset_order();
    uint8_t preset_index = preset_order[preset_list_edit_index];
    usb_set_preset_color(preset_index, mapping.rawColor);

    preset_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_list_color_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_preset_list_dialog_close(lv_event_t * e)
{
    preset_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_list_color_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_preset_list_cancel(lv_event_t * e)
{
    preset_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_list_cancel_button, LV_OBJ_FLAG_HIDDEN);

    updatePresetListSelection();
}
