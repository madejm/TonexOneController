#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "esp_err.h"
#include "tonex_params.h"

#define NVS_SCENES_PARTITION                "scenes"

#define MAX_SUPPORTED_PRESETS                   150
#define MAX_SCENES                              20
#define MAX_SCENE_NAME                          30

typedef struct
{
    float PresetParams[TONEX_PARAM_LAST];
    uint32_t PresetParamsHash;
    bool Modified;
} tScenePreset;

typedef struct
{
    uint8_t PresetOrder[MAX_SUPPORTED_PRESETS];
    tScenePreset Presets[MAX_SUPPORTED_PRESETS];
} tScene;

typedef struct
{
    uint8_t ScenesCount;
    uint8_t SelectedScene;
} tScenesConfig;

esp_err_t scenes_init(void);
esp_err_t scenes_save(void);
uint32_t scenes_hash_preset_params(const float preset_params[TONEX_PARAM_LAST]);
esp_err_t scenes_save_preset_params(uint8_t preset_index, const float preset_params[TONEX_PARAM_LAST]);

tScene *scenes_get_current(void);
const char *scenes_get_name(uint8_t index);
uint8_t scenes_get_selected(void);
uint8_t scenes_get_count(void);

bool scenes_select(uint8_t index);
bool scenes_create(void);
void scenes_delete(uint8_t index);
void scenes_set_name(uint8_t index, const char *name);

void scenes_set_preset_order(const uint8_t *order, uint8_t count);
uint8_t *scenes_get_preset_order(void);
