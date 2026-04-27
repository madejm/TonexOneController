
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "esp_err.h"
#include "esp_system.h"
#include "esp_log.h"

#include "usb/usb_host.h"
#include "fx_handler_helper.h"
#include "tonex_params.h"
#include "midi_helper.h"
#include "usb_comms.h"

static const char *TAG = "fx_handler_helper";

esp_err_t fx_handler_helper_get_values(TonexParameter_t *param, tExternalFootswitchEffectConfig config, ParamType_t *type, FxSelectedValueIndex_t *selected_value_index, MidiValue_t *CC)
{
    tModellerParameter *param_ptr;
    
    if (tonex_params_get_locked_access(&param_ptr) != ESP_OK)
    {
        return ESP_FAIL;
    }

    *CC = config.CC;
    
    if (param_ptr[TONEX_PARAM_DELAY_MODEL].Value == 0) {
        // digital delay is selected
        switch (*param) {
            case TONEX_PARAM_DELAY_TAPE_TS:
                // change param to digital ts
                *param = TONEX_PARAM_DELAY_DIGITAL_TS;
                *CC = 5;
                break;
            case TONEX_PARAM_DELAY_TAPE_TIME:
                // change param to digital time
                *param = TONEX_PARAM_DELAY_DIGITAL_TIME;
                *CC = 5;
                break;
            default:
                break;
        }
    }
    else if (param_ptr[TONEX_PARAM_DELAY_MODEL].Value == 1) {
        // tape delay is selected
        switch (*param) {
            case TONEX_PARAM_DELAY_DIGITAL_TS:
                // change param to tape ts
                *param = TONEX_PARAM_DELAY_TAPE_TS;
                *CC = 92;
                break;
            case TONEX_PARAM_DELAY_DIGITAL_TIME:
                // change param to tape time
                *param = TONEX_PARAM_DELAY_TAPE_TIME;
                *CC = 92;
                break;
            default:
                break;
        }
    }

    tModellerParameter param_entry = param_ptr[*param];
    *type = param_entry.Type;

    // is the parameter a boolean type?
    switch (*type) {
        case MODELLER_PARAM_TYPE_SWITCH: {
            // toggle the current value
            if (param_entry.Value == 0)
            {
                *selected_value_index = FX_SELECTED_VALUE_1;
            }
            else
            {
                *selected_value_index = FX_SELECTED_VALUE_2;
            }

            tonex_params_release_locked_access();
            return ESP_OK;
        } break;
        
        case MODELLER_PARAM_TYPE_SELECT: {
            // save current value before we release the locked access
            // select params are really integers saved as floats
            uint8_t current_select_val = (uint8_t)param_entry.Value;

            // release access now as midi helper needs the mutex
            tonex_params_release_locked_access();

            if (current_select_val == config.Value_1)
            {
                *selected_value_index = FX_SELECTED_VALUE_1;
            }
            else if (current_select_val == config.Value_2)
            {
                *selected_value_index = FX_SELECTED_VALUE_2;
            }
            else
            {
                *selected_value_index = FX_SELECTED_VALUE_NONE;
            }
            return ESP_OK;
        } break;

        case MODELLER_PARAM_TYPE_RANGE: {
            // save current value before we release the locked access
            float current_param_value = param_entry.Value;

            // release access now as midi helper needs the mutex
            tonex_params_release_locked_access();

            // flip between value 1 and value 2
            // get value 1 (Midi 0..127) scaled back to a float to it can be compared with the current param value (a float)
            float value_1 = midi_helper_scale_midi_to_float(*param, config.Value_1);

            // note here: scaling Midi to float may result in rounding errors. This check is to make sure
            // we can find the current value without missing it due to slight difference
            float val1_diff = fabs(current_param_value - value_1);

            // debug
            //ESP_LOGI(TAG, "Footswitch FX Param difference %f", param_diff);    

            if (val1_diff < 0.1f)
            {
                *selected_value_index = FX_SELECTED_VALUE_1;
            }
            else
            {
                float value_2 = midi_helper_scale_midi_to_float(*param, config.Value_2);
                float val2_diff = fabs(current_param_value - value_2);

                if (val2_diff < 0.1f)
                {
                    *selected_value_index = FX_SELECTED_VALUE_2;
                }
                else
                {
                    *selected_value_index = FX_SELECTED_VALUE_NONE;
                }
            }
            return ESP_OK;
        } break;

        default: {
            tonex_params_release_locked_access();
            ESP_LOGI(TAG, "Footswitch FX Unknown param type");
            *selected_value_index = FX_SELECTED_VALUE_NONE;
            return ESP_FAIL;
        } break;
    }
}

void fx_handler_helper_update_parameter(TonexParameter_t param, tExternalFootswitchEffectConfig config, ParamType_t type, FxSelectedValueIndex_t selected_value_index, MidiValue_t CC)
{
    float new_value = 0;

    switch (type) {
        case MODELLER_PARAM_TYPE_SWITCH: {
            switch (selected_value_index) {
                case FX_SELECTED_VALUE_NONE:
                case FX_SELECTED_VALUE_2:
                    new_value = 0;
                    break;
                case FX_SELECTED_VALUE_1:
                    new_value = 1;
                    break;
            }

            usb_modify_parameter(param, new_value);
        } break;

        case MODELLER_PARAM_TYPE_SELECT:
        case MODELLER_PARAM_TYPE_RANGE: {
            switch (selected_value_index) {
                case FX_SELECTED_VALUE_NONE:
                case FX_SELECTED_VALUE_2:
                    new_value = config.Value_1;
                    break;
                case FX_SELECTED_VALUE_1:
                    new_value = config.Value_2;
                    break;
            }

            midi_helper_adjust_param_via_midi(CC, new_value);
        } break;
    }

    ESP_LOGI(TAG, "Footswitch FX Param %d changed to %d", (int)param, (int)new_value);
}