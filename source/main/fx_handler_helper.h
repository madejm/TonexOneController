
#ifndef _FX_HANDLER_HELPER_H
#define _FX_HANDLER_HELPER_H

#include "control.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t fx_handler_helper_get_values(uint16_t *param, tExternalFootswitchEffectConfig config, uint8_t *type, float *current_value, float *new_value, uint8_t *CC);
void fx_handler_helper_update_parameter(uint16_t param, uint8_t type, float new_value, uint8_t CC);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif