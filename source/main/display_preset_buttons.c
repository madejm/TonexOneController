#include "display_preset_buttons.h"
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
#include "scenes.h"
#include "wifi_config.h"
#include "tonex_params.h"
#include "display_scenes.h"
#include "display.h"
#include "fx_handler_helper.h"
#include "midi_helper.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

// ===== ACTIONS =====


// ===== UPDATES =====

void display_preset_buttons_clicked(uint32_t buttonIndex, bool longPress)
{
    bool alt = display_get_alt_Mode() != longPress;

    if (!alt) {
        switch (buttonIndex)
        {
            case 0:
            case 1:
            case 2:
            case 3:
                control_request_preset_in_bank_index(buttonIndex);
                return;
            case 4:
                control_request_bank_down();
                return;
            case 5:
                control_request_bank_up();
                return;
        }
    }

    for (uint32_t item = 0; item < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; item ++)
    {
        tExternalFootswitchEffectConfig config;
        
        control_get_config_item_external_fs_config(item, alt, &config);

        if (config.Switch != buttonIndex) {
            continue;
        }

        TonexParameter_t param = midi_helper_get_param_for_change_num(config.CC, config.Value_1, config.Value_2);

        if (param == TONEX_UNKNOWN) {
            return;
        }

        ParamType_t type;
        FxSelectedValueIndex_t selectedValueIndex;
        uint8_t CC;

        if (fx_handler_helper_get_values(&param, config, &type, &selectedValueIndex, &CC) != ESP_OK) {
            return;
        }

        fx_handler_helper_update_parameter(param, config, type, selectedValueIndex, CC);
        return;
    }
}

void display_preset_buttons_updatePresetNumberLabel(uint8_t ui_PresetIndex)
{
    const char *letter = "";
    switch (ui_PresetIndex % 4) {
        case 0: letter = "A"; break;
        case 1: letter = "B"; break;
        case 2: letter = "C"; break;
        case 3: letter = "D"; break;
        default: break;
    }
    
    lv_label_set_text(objects.ui_preset_letter_label, letter);

    char buff[3];
    sprintf(buff, "%d", (ui_PresetIndex / 4) + 1);
    lv_label_set_text(objects.ui_preset_number_label, buff);
}

static void setFSSmallButton(
    uint32_t buttonIndex,
    lv_color_t color,
    FxSelectedValueIndex_t selectedValueIndex,
    const char *title,
    const char *value1,
    const char *value2,
    bool visible
) {
    lv_obj_t *smallButton;
    lv_obj_t *smallLabel;

    switch (buttonIndex) {
        case 0:
            smallButton = objects.ui_preset_button_1__button_small;
            smallLabel =  objects.ui_preset_button_1__label_small;
            break;
        case 1:
            smallButton = objects.ui_preset_button_2__button_small;
            smallLabel =  objects.ui_preset_button_2__label_small;
            break;
        case 2:
            smallButton = objects.ui_preset_button_3__button_small;
            smallLabel =  objects.ui_preset_button_3__label_small;
            break;
        case 3:
            smallButton = objects.ui_preset_button_4__button_small;
            smallLabel =  objects.ui_preset_button_4__label_small;
            break;
        case 4:
            smallButton = objects.ui_preset_button_5__button_small;
            smallLabel =  objects.ui_preset_button_5__label_small;
            break;
        case 5:
            smallButton = objects.ui_preset_button_6__button_small;
            smallLabel =  objects.ui_preset_button_6__label_small;
            break;
        case 6:
            smallButton = objects.ui_preset_button_7__button_small;
            smallLabel =  objects.ui_preset_button_7__label_small;
            break;
        case 7:
            smallButton = objects.ui_preset_button_8__button_small;
            smallLabel =  objects.ui_preset_button_8__label_small;
            break;
        default:
            return;
    }

    if (visible) {
        lv_obj_set_style_opa(smallButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
        lv_obj_set_style_opa(smallButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        return;
    }

    lv_obj_set_style_bg_color(smallButton, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(smallButton, color, LV_PART_MAIN | LV_STATE_CHECKED);

    char buffer[MAX_UI_TEXT];
    sprintf(buffer, "%s", title);

    switch (selectedValueIndex) {
        case FX_SELECTED_VALUE_NONE: {
            lv_obj_clear_state(smallButton, LV_STATE_CHECKED);

            if (value1 != NULL) {
                sprintf(buffer + strlen(buffer), " ?");
            }
        } break;

        case FX_SELECTED_VALUE_1: {
            lv_obj_clear_state(smallButton, LV_STATE_CHECKED);

            if (value1 != NULL) {
                sprintf(buffer + strlen(buffer), " %s", value1);
            }
        } break;

        case FX_SELECTED_VALUE_2: {
            lv_obj_add_state(smallButton, LV_STATE_CHECKED);

            if (value2 != NULL) {
                sprintf(buffer + strlen(buffer), " %s", value2);
            }
        } break;
    }

    lv_label_set_text(smallLabel, buffer);
}

static void setFSBigButton(
    uint32_t buttonIndex,
    lv_color_t color,
    FxSelectedValueIndex_t selectedValueIndex,
    const char *title,
    const char *index,
    const char *value1,
    const char *value2,
    const lv_img_dsc_t *image,
    bool visible
) {
    lv_obj_t *button;
    lv_obj_t *nameLabel;
    lv_obj_t *indexLabel;
    lv_obj_t *onLabel;
    lv_obj_t *offLabel;
    lv_obj_t *iconButton;
    lv_obj_t *iconImage;

    switch (buttonIndex) {
        case 0:
            button =      objects.ui_preset_button_1__button;
            nameLabel =   objects.ui_preset_button_1__label;
            indexLabel =  objects.ui_preset_button_1__index;
            onLabel =     objects.ui_preset_button_1__label_on;
            offLabel =    objects.ui_preset_button_1__label_off;
            iconButton =  objects.ui_preset_button_1__icon_button;
            iconImage =   objects.ui_preset_button_1__icon_image;
            break;
        case 1:
            button =      objects.ui_preset_button_2__button;
            nameLabel =   objects.ui_preset_button_2__label;
            indexLabel =  objects.ui_preset_button_2__index;
            onLabel =     objects.ui_preset_button_2__label_on;
            offLabel =    objects.ui_preset_button_2__label_off;
            iconButton =  objects.ui_preset_button_2__icon_button;
            iconImage =   objects.ui_preset_button_2__icon_image;
            break;
        case 2:
            button =      objects.ui_preset_button_3__button;
            nameLabel =   objects.ui_preset_button_3__label;
            indexLabel =  objects.ui_preset_button_3__index;
            onLabel =     objects.ui_preset_button_3__label_on;
            offLabel =    objects.ui_preset_button_3__label_off;
            iconButton =  objects.ui_preset_button_3__icon_button;
            iconImage =   objects.ui_preset_button_3__icon_image;
            break;
        case 3:
            button =      objects.ui_preset_button_4__button;
            nameLabel =   objects.ui_preset_button_4__label;
            indexLabel =  objects.ui_preset_button_4__index;
            onLabel =     objects.ui_preset_button_4__label_on;
            offLabel =    objects.ui_preset_button_4__label_off;
            iconButton =  objects.ui_preset_button_4__icon_button;
            iconImage =   objects.ui_preset_button_4__icon_image;
            break;
        case 4:
            button =      objects.ui_preset_button_5__button;
            nameLabel =   objects.ui_preset_button_5__label;
            indexLabel =  objects.ui_preset_button_5__index;
            onLabel =     objects.ui_preset_button_5__label_on;
            offLabel =    objects.ui_preset_button_5__label_off;
            iconButton =  objects.ui_preset_button_5__icon_button;
            iconImage =   objects.ui_preset_button_5__icon_image;
            break;
        case 5:
            button =      objects.ui_preset_button_6__button;
            nameLabel =   objects.ui_preset_button_6__label;
            indexLabel =  objects.ui_preset_button_6__index;
            onLabel =     objects.ui_preset_button_6__label_on;
            offLabel =    objects.ui_preset_button_6__label_off;
            iconButton =  objects.ui_preset_button_6__icon_button;
            iconImage =   objects.ui_preset_button_6__icon_image;
            break;
        case 6:
            button =      objects.ui_preset_button_7__button;
            nameLabel =   objects.ui_preset_button_7__label;
            indexLabel =  objects.ui_preset_button_7__index;
            onLabel =     objects.ui_preset_button_7__label_on;
            offLabel =    objects.ui_preset_button_7__label_off;
            iconButton =  objects.ui_preset_button_7__icon_button;
            iconImage =   objects.ui_preset_button_7__icon_image;
            break;
        case 7:
            button =      objects.ui_preset_button_8__button;
            nameLabel =   objects.ui_preset_button_8__label;
            indexLabel =  objects.ui_preset_button_8__index;
            onLabel =     objects.ui_preset_button_8__label_on;
            offLabel =    objects.ui_preset_button_8__label_off;
            iconButton =  objects.ui_preset_button_8__icon_button;
            iconImage =   objects.ui_preset_button_8__icon_image;
            break;
        default:
            return;
    }

    if (visible) {
        lv_obj_set_style_opa(button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(button, LV_OBJ_FLAG_CLICKABLE);
    } else {
        lv_obj_set_style_opa(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(button, LV_OBJ_FLAG_CLICKABLE);
        return;
    }

    lv_label_set_text(nameLabel, title);
    lv_obj_set_style_bg_color(button, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(button, color, LV_PART_MAIN | LV_STATE_CHECKED);

    if (selectedValueIndex == FX_SELECTED_VALUE_2) {
        lv_obj_add_state(button, LV_STATE_CHECKED);
        lv_obj_add_state(indexLabel, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(button, LV_STATE_CHECKED);
        lv_obj_clear_state(indexLabel, LV_STATE_CHECKED);
    }

    if (index != NULL) {
        lv_label_set_text(indexLabel, index);
        lv_obj_set_style_text_color(indexLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(indexLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(indexLabel, LV_OBJ_FLAG_HIDDEN);
    }

    if (value1 != NULL) {
        lv_label_set_text(offLabel, value1);
        lv_obj_clear_flag(offLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(offLabel, LV_OBJ_FLAG_HIDDEN);
    }

    if (value2 != NULL) {
        lv_label_set_text(onLabel, value2);
        lv_obj_clear_flag(onLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(onLabel, LV_OBJ_FLAG_HIDDEN);
    }

    switch (selectedValueIndex) {
        case FX_SELECTED_VALUE_NONE: {
            lv_obj_set_style_opa(offLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;

        case FX_SELECTED_VALUE_1: {
            lv_obj_set_style_opa(offLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;

        case FX_SELECTED_VALUE_2: {
            // lv_obj_set_style_opa(offLabel, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(offLabel, 152, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            // lv_obj_set_style_text_color(onLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;
    }

    if (image == NULL) {
        lv_obj_add_flag(iconButton, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_clear_flag(iconButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_bg_color(iconButton, lv_color_darken(color, 204), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(iconButton, color, LV_PART_MAIN | LV_STATE_CHECKED);
        lv_img_set_src(iconImage, image);
    }
}

void display_preset_buttons_updateFSButtons(
    bool ui_AltMode,
    uint8_t ui_PresetIndex,
    uint8_t ui_BankIndex
) {
    char buffer1[MAX_UI_TEXT];
    char buffer2[MAX_UI_TEXT];

    for (uint32_t buttonIndex = 0; buttonIndex < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; buttonIndex++)
    {
        for (int s = 0; s <= 1; s++)
        {
            bool small = s ? true : false;
            bool didSet = false;
            
            // if
            // small == false, ui_AltMode == false
            // or
            // small == true,  ui_AltMode == true
            bool alt = small == ui_AltMode;

            if (alt && buttonIndex < 6) {
                FxSelectedValueIndex_t selectedValueIndex = FX_SELECTED_VALUE_NONE;
                uint32_t color;
                char *name = NULL;
                const char *presetIndex = NULL;

                if (buttonIndex < 4) {
                    bool isInCurrentBank = (ui_PresetIndex/4) == ui_BankIndex;
                    uint16_t selectedPresetButtonIndex = ui_PresetIndex % 4;
                    bool selected = isInCurrentBank && selectedPresetButtonIndex == buttonIndex;
                    
                    uint8_t presetIndexValue = ui_BankIndex * 4 + buttonIndex;
                //     // selectedValueIndex = control_get_current_preset_index() == presetIndexValue ? FX_SELECTED_VALUE_2 : FX_SELECTED_VALUE_1;
                    selectedValueIndex = selected ? FX_SELECTED_VALUE_2 : FX_SELECTED_VALUE_1;
                    
                    const char *indexFormat = "%d";
                    switch (buttonIndex) {
                        case 0: indexFormat = "%dA"; break;
                        case 1: indexFormat = "%dB"; break;
                        case 2: indexFormat = "%dC"; break;
                        case 3: indexFormat = "%dD"; break;
                        default: break;
                    }
                    sprintf(buffer1, indexFormat, ui_BankIndex + 1);
                    presetIndex = buffer1;

                    control_get_preset_name(presetIndexValue, buffer2);
                    name = buffer2;

                    color = get_preset_color(presetIndexValue);
                } else {
                    name = buttonIndex == 4 ? "↓" : "↑";
                    color = theme_colors[THEME_ID_DEFAULT][COLOR_ID_DEFAULT_GRAY];
                }

                if (small) {
                    setFSSmallButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, NULL, NULL, true);
                } else {
                    setFSBigButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, presetIndex, NULL, NULL, NULL, true);
                }

                didSet = true;
            } else {
                for (uint32_t item = 0; item < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; item++)
                {
                    tExternalFootswitchEffectConfig config;
                    
                    control_get_config_item_external_fs_config(item, !alt, &config);

                    if (config.Switch != buttonIndex) {
                        continue;
                    }

                    TonexParameter_t param = midi_helper_get_param_for_change_num(config.CC, config.Value_1, config.Value_2);

                    if (param == TONEX_UNKNOWN) {
                        break;
                    }
                    
                    ParamType_t type;
                    FxSelectedValueIndex_t selectedValueIndex;
                    MidiValue_t CC;

                    if (fx_handler_helper_get_values(&param, config, &type, &selectedValueIndex, &CC) != ESP_OK) {
                        break;
                    }

                    tModellerParameter *param_ptr;

                    if (tonex_params_get_locked_access(&param_ptr) != ESP_OK) {
                        break;
                    }

                    tModellerParameter param_entry = param_ptr[param];
                    // // float paramValue = param_entry.Value;
                    uint32_t color = 0x000000;
                    const char *name = NULL;
                    const char *value1 = NULL;
                    const char *value2 = NULL;
                    const lv_img_dsc_t *image = NULL;

                    tonex_params_get_ui_style(
                        param,
                        config.Value_1,
                        config.Value_2,
                        small,
                        &color,
                        &name,
                        &value1,
                        &value2,
                        &image,
                        param_ptr
                    );
                    tonex_params_release_locked_access();

                    switch (type) {
                        case MODELLER_PARAM_TYPE_SWITCH:
                        case MODELLER_PARAM_TYPE_SELECT:
                            break;

                        case MODELLER_PARAM_TYPE_RANGE: {
                            switch (param) {
                                case TONEX_GLOBAL_BPM:
                                    break;

                                default: {
                                    float value_1 = midi_helper_scale_midi_to_float(param, config.Value_1);
                                    float value_2 = midi_helper_scale_midi_to_float(param, config.Value_2);
                                    const char *format = (param_entry.Max - param_entry.Min) > 10.0f ? "%.0f" : "%.1f";
                                    
                                    sprintf(buffer1, format, value_1);
                                    sprintf(buffer2, format, value_2);

                                    if (value1 != NULL) {
                                        strncat(buffer1, value1, sizeof(buffer1) - strlen(buffer1) - 1);
                                        strncat(buffer2, value1, sizeof(buffer2) - strlen(buffer2) - 1);
                                    }
                                    
                                    value1 = buffer1;
                                    value2 = buffer2;
                                } break;
                            }
                        } break;
                    }

                    if (small) {
                        setFSSmallButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, value1, value2, true);
                    } else {
                        setFSBigButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, NULL, value1, value2, image, true);
                    }

                    // done, break for loop and go to next buttonIndex
                    didSet = true;
                    break;
                }
            }

            if (!didSet) {
                if (small) {
                    setFSSmallButton(buttonIndex, lv_color_hex(0), FX_SELECTED_VALUE_NONE, NULL, NULL, NULL, false);
                } else {
                    setFSBigButton(buttonIndex, lv_color_hex(0), FX_SELECTED_VALUE_NONE, NULL, NULL, NULL, NULL, NULL, false);
                }
            }
        }
    }

    uint32_t presetColor = get_preset_color(ui_PresetIndex);
    lv_obj_set_style_text_color(objects.ui_preset_letter_label, lv_color_hex(presetColor), LV_PART_MAIN | LV_STATE_DEFAULT);
}
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI