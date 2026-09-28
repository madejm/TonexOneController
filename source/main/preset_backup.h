#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"

#define PRESET_BACKUP_MAX_SLOTS 100
#define PRESET_BACKUP_TEXT_LENGTH 33

typedef struct
{
    char PresetName[PRESET_BACKUP_TEXT_LENGTH];
    char ModelCharacter[PRESET_BACKUP_TEXT_LENGTH];
    char ModelType[PRESET_BACKUP_TEXT_LENGTH];
    char ModelAmpName[PRESET_BACKUP_TEXT_LENGTH];
    char ModelCabName[PRESET_BACKUP_TEXT_LENGTH];
} tPresetBackupInfo;

esp_err_t preset_backup_init(void);
esp_err_t preset_backup_save(const uint8_t *full_details, size_t length, uint16_t *slot);
esp_err_t preset_backup_load(uint16_t slot, uint8_t **full_details, size_t *length);
esp_err_t preset_backup_load_to_tonex(uint16_t slot, uint8_t destination_slot,
                                      bool keep_parameters, uint32_t *id);
esp_err_t preset_backup_delete(uint16_t slot);
uint16_t preset_backup_get_count(void);
bool preset_backup_get_info(uint16_t index, tPresetBackupInfo *info);
bool preset_backup_get_slot(uint16_t index, uint16_t *slot);
