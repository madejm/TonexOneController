
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

esp_err_t fx_handler_helper_get_values(uint16_t *param, tExternalFootswitchEffectConfig config, uint8_t *type, float *current_value, float *new_value, uint8_t *CC)
{
    tTonexParameter *param_ptr;
    
    if (tonex_params_get_locked_access(&param_ptr) != ESP_OK)
    {
        return ESP_FAIL;
    }

    *CC = config.CC;
    
    if (*param == TONEX_PARAM_DELAY_DIGITAL_TS && param_ptr[TONEX_PARAM_DELAY_MODEL].Value == 1) {
        // tape delay is selected, change param to tape ts
        *param = TONEX_PARAM_DELAY_TAPE_TS;
        *CC = 92;
    } else if (*param == TONEX_PARAM_DELAY_TAPE_TS && param_ptr[TONEX_PARAM_DELAY_MODEL].Value == 0) {
        // digital delay is selected, change param to digital ts
        *param = TONEX_PARAM_DELAY_DIGITAL_TS;
        *CC = 5;
    }

    tTonexParameter param_entry = param_ptr[*param];
    *type = param_entry.Type;
    *current_value = param_entry.Value;

    // is the parameter a boolean type?
    switch (*type) {
        case TONEX_PARAM_TYPE_SWITCH: {
            // toggle the current value
            if (param_entry.Value == 0)
            {
                *new_value = 1;
            }
            else
            {
                *new_value = 0;
            }

            tonex_params_release_locked_access();
            return ESP_OK;
        } break;
        
        case TONEX_PARAM_TYPE_SELECT: {
            // save current value before we release the locked access
            // select params are really integers saved as floats
            uint8_t current_select_val = (uint8_t)param_entry.Value;

            // release access now as midi helper needs the mutex
            tonex_params_release_locked_access();

            if (current_select_val == config.Value_1)
            {
                *new_value = (float)config.Value_2;
            }
            else
            {
                *new_value = (float)config.Value_1;
            }
            return ESP_OK;
        } break;

        case TONEX_PARAM_TYPE_RANGE: {
            // save current value before we release the locked access
            float current_param_value = param_entry.Value;

            // release access now as midi helper needs the mutex
            tonex_params_release_locked_access();

            // flip between value 1 and value 2
            // get value 1 (Midi 0..127) scaled back to a float to it can be compared with the current param value (a float)
            float value_1 = midi_helper_scale_midi_to_float(*param, config.Value_1);

            // note here: scaling Midi to float may result in rounding errors. This check is to make sure
            // we can find the current value without missing it due to slight difference
            float param_diff = fabs(current_param_value - value_1);

            // debug
            //ESP_LOGI(TAG, "Footswitch FX Param difference %f", param_diff);    

            if (param_diff < 0.1f)
            {
                *new_value = config.Value_2;
            }
            else
            {
                *new_value = config.Value_1;
            }
            return ESP_OK;
        } break;

        default: {
            tonex_params_release_locked_access();
            ESP_LOGI(TAG, "Footswitch FX Unknown param type");
            *new_value = 0.0f;
            return ESP_FAIL;
        } break;
    }                                  

    return ESP_FAIL;                                                                
}

void fx_handler_helper_update_parameter(uint16_t param, uint8_t type, float new_value, uint8_t CC)
{
    switch (type) {
        case TONEX_PARAM_TYPE_SWITCH: {
            usb_modify_parameter(param, new_value);
        } break;

        case TONEX_PARAM_TYPE_SELECT:
        case TONEX_PARAM_TYPE_RANGE: {
            midi_helper_adjust_param_via_midi(CC, new_value);
        } break;
    }
}