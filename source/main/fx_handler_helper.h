
#ifndef _FX_HANDLER_HELPER_H
#define _FX_HANDLER_HELPER_H

#include "control.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    FX_SELECTED_VALUE_NONE,
    FX_SELECTED_VALUE_1,
    FX_SELECTED_VALUE_2
} FxSelectedValueIndex_t;

esp_err_t fx_handler_helper_get_values(uint16_t *param, tExternalFootswitchEffectConfig config, uint8_t *type, FxSelectedValueIndex_t *selected_value_index, uint8_t *CC);
void fx_handler_helper_update_parameter(uint16_t param, tExternalFootswitchEffectConfig config, uint8_t type, FxSelectedValueIndex_t selected_value_index, uint8_t CC);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif