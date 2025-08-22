
#ifndef _FX_HANDLER_HELPER_H
#define _FX_HANDLER_HELPER_H

#include "control.h"
#include "tonex_params.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t fx_handler_helper_get_values(TonexParameter_t *param, tExternalFootswitchEffectConfig config, ParamType_t *type, FxSelectedValueIndex_t *selected_value_index, uint8_t *CC);
void fx_handler_helper_update_parameter(TonexParameter_t param, tExternalFootswitchEffectConfig config, ParamType_t type, FxSelectedValueIndex_t selected_value_index, uint8_t CC);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif