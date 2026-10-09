#include "preset_backup.h"
#include "tonex_parser.h"
#include "tonex_parser_trees.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "esp_heap_caps.h"
#include "esp_log.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "scenes.h"

#define PRESET_BACKUP_PARTITION "preset_backups"
#define PRESET_BACKUP_NAMESPACE "backups"
#define PRESET_BACKUP_CATALOG_KEY "catalog"
#define PRESET_BACKUP_CATALOG_VERSION 1

typedef struct
{
    bool Used;
    tPresetBackupInfo Info;
} tPresetBackupCatalogEntry;

typedef struct
{
    uint8_t Version;
    uint16_t Count;
    tPresetBackupCatalogEntry Entries[PRESET_BACKUP_MAX_SLOTS];
} tPresetBackupCatalog;

static const char *TAG = "preset_backup";
static tPresetBackupCatalog Catalog;

static esp_err_t OpenStorage(nvs_open_mode_t mode, nvs_handle_t *handle)
{
    return nvs_open_from_partition(PRESET_BACKUP_PARTITION, PRESET_BACKUP_NAMESPACE, mode, handle);
}

static void BackupKey(uint16_t slot, char *key, size_t key_length)
{
    snprintf(key, key_length, "p%03u", slot);
}

static bool CopyTreeString(const uint8_t *full_details, size_t length, tTonexDataFieldName field,
                           char *destination, size_t destination_length)
{
    const char *source;
    size_t source_length;

    if (destination == NULL || destination_length == 0 ||
        !tonex_read_data_str(full_details, length, &TonexPresetDetailsFullTree,
                             field, &source, &source_length)) return false;
    if (source_length >= destination_length) source_length = destination_length - 1;
    memcpy(destination, source, source_length);
    destination[source_length] = 0;
    return true;
}

static void SetModelType(tPresetBackupInfo *info, tTonexModelType model_a_type,
                         bool separate_model_enabled, tTonexModelType model_b_type)
{
    switch (model_a_type)
    {
        case MODEL_TYPE_STOMP:
            if (separate_model_enabled && model_b_type == MODEL_TYPE_IR)          snprintf(info->ModelType, sizeof(info->ModelType), "Stomp+IR");
            else if (separate_model_enabled && model_b_type == MODEL_TYPE_AMPCAB) snprintf(info->ModelType, sizeof(info->ModelType), "Stomp+Cab");
            else                                                                  snprintf(info->ModelType, sizeof(info->ModelType), "Stomp");
            break;

        case MODEL_TYPE_AMP:
            if (separate_model_enabled && model_b_type == MODEL_TYPE_IR)          snprintf(info->ModelType, sizeof(info->ModelType), "Amp+IR");
            else if (separate_model_enabled && model_b_type == MODEL_TYPE_AMPCAB) snprintf(info->ModelType, sizeof(info->ModelType), "Amp+Cab");
            else                                                                  snprintf(info->ModelType, sizeof(info->ModelType), "Amp");
            break;

        case MODEL_TYPE_AMPCAB:
            if (separate_model_enabled && model_b_type == MODEL_TYPE_IR)          snprintf(info->ModelType, sizeof(info->ModelType), "Amp+IR");
            else if (separate_model_enabled)                                      snprintf(info->ModelType, sizeof(info->ModelType), "Amp+Cab");
            else                                                                  snprintf(info->ModelType, sizeof(info->ModelType), "Amp&Cab");
            break;
        default:
            break;
    }
}

static bool ParseInfo(const uint8_t *full_details, size_t length, tPresetBackupInfo *info)
{
    tTonexModelType model_a_type;
    uint8_t separate_model_enabled;
    tTonexModelType model_b_type = MODEL_TYPE_EMPTY;

    if (info == NULL) return false;
    memset(info, 0, sizeof(*info));

    if (!CopyTreeString(full_details, length, TONEX_PRESET_NAME,
                        info->PresetName, sizeof(info->PresetName))) {
        return false;
    }
    if (!CopyTreeString(full_details, length, TONEX_PRESET_METADATA_CHARACTER,
                        info->ModelCharacter, sizeof(info->ModelCharacter))) {
        return false;
    }
    if (!tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                            TONEX_MODEL_A_TYPE, &model_a_type) ||
        !tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                            TONEX_MODEL_SEPARATE_ENABLED, &separate_model_enabled) ||
        !CopyTreeString(full_details, length, TONEX_MODEL_A_NAME,
                        info->ModelAmpName, sizeof(info->ModelAmpName))) {
        return false;
    }

    if (separate_model_enabled)
    {
        if (!tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                                TONEX_MODEL_B_TYPE, &model_b_type)) return false;
        // if (model_b_type == MODEL_TYPE_IR)
        //     snprintf(info->ModelCabName, sizeof(info->ModelCabName), "IR");
        else if (!CopyTreeString(full_details, length, TONEX_MODEL_B_NAME,
                                 info->ModelCabName, sizeof(info->ModelCabName)))
            return false;
    }

    SetModelType(info, model_a_type, separate_model_enabled, model_b_type);
    return true;
}

static esp_err_t SaveCatalog(void)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK) return err;
    err = nvs_set_blob(handle, PRESET_BACKUP_CATALOG_KEY, &Catalog, sizeof(Catalog));
    if (err == ESP_OK) err = nvs_commit(handle);
    nvs_close(handle);
    return err;
}

esp_err_t preset_backup_init(void)
{
    esp_err_t err = nvs_flash_init_partition(PRESET_BACKUP_PARTITION);
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_LOGW(TAG, "Erasing incompatible backup storage");
        err = nvs_flash_erase_partition(PRESET_BACKUP_PARTITION);
        if (err == ESP_OK) err = nvs_flash_init_partition(PRESET_BACKUP_PARTITION);
    }
    if (err != ESP_OK) return err;

    nvs_handle_t handle;
    err = OpenStorage(NVS_READONLY, &handle);
    if (err == ESP_OK)
    {
        size_t size = sizeof(Catalog);
        err = nvs_get_blob(handle, PRESET_BACKUP_CATALOG_KEY, &Catalog, &size);
        nvs_close(handle);
        if (err == ESP_OK && size == sizeof(Catalog) && Catalog.Version == PRESET_BACKUP_CATALOG_VERSION)
            return ESP_OK;
    }

    memset(&Catalog, 0, sizeof(Catalog));
    Catalog.Version = PRESET_BACKUP_CATALOG_VERSION;
    return SaveCatalog();
}

esp_err_t preset_backup_save(const uint8_t *full_details, size_t length, uint16_t *slot)
{
    tPresetBackupInfo info;
    if (full_details == NULL || slot == NULL || length == 0 || length > TONEX_MAX_FULL_PRESET_DATA ||
        !ParseInfo(full_details, length, &info)) return ESP_ERR_INVALID_ARG;

    uint16_t free_slot;
    for (free_slot = 0; free_slot < PRESET_BACKUP_MAX_SLOTS && Catalog.Entries[free_slot].Used; free_slot++);
    if (free_slot == PRESET_BACKUP_MAX_SLOTS) return ESP_ERR_NO_MEM;

    char key[8];
    BackupKey(free_slot, key, sizeof(key));
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK) return err;
    err = nvs_set_blob(handle, key, full_details, length);
    if (err == ESP_OK) err = nvs_commit(handle);
    nvs_close(handle);
    if (err != ESP_OK) return err;

    Catalog.Entries[free_slot].Used = true;
    Catalog.Entries[free_slot].Info = info;
    Catalog.Count++;
    err = SaveCatalog();
    if (err == ESP_OK) *slot = free_slot;
    return err;
}

esp_err_t preset_backup_update(uint16_t slot, const uint8_t *full_details, size_t length)
{
    tPresetBackupInfo info;
    if (slot >= PRESET_BACKUP_MAX_SLOTS || !Catalog.Entries[slot].Used ||
        full_details == NULL || length == 0 || length > TONEX_MAX_FULL_PRESET_DATA ||
        !ParseInfo(full_details, length, &info)) return ESP_ERR_INVALID_ARG;

    tPresetBackupCatalog *updated = heap_caps_malloc(sizeof(*updated), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (updated == NULL) updated = malloc(sizeof(*updated));
    if (updated == NULL) return ESP_ERR_NO_MEM;
    *updated = Catalog;
    updated->Entries[slot].Info = info;

    char key[8];
    BackupKey(slot, key, sizeof(key));
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err == ESP_OK)
    {
        err = nvs_set_blob(handle, key, full_details, length);
        if (err == ESP_OK)
            err = nvs_set_blob(handle, PRESET_BACKUP_CATALOG_KEY, updated, sizeof(*updated));
        if (err == ESP_OK) err = nvs_commit(handle);
        nvs_close(handle);
    }
    if (err == ESP_OK) Catalog = *updated;
    free(updated);
    return err;
}

esp_err_t preset_backup_load(uint16_t slot, uint8_t **full_details, size_t *length)
{
    if (full_details == NULL || length == NULL || slot >= PRESET_BACKUP_MAX_SLOTS || !Catalog.Entries[slot].Used)
        return ESP_ERR_INVALID_ARG;

    char key[8];
    BackupKey(slot, key, sizeof(key));
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READONLY, &handle);
    if (err != ESP_OK) return err;
    size_t data_length = 0;
    err = nvs_get_blob(handle, key, NULL, &data_length);
    if (err != ESP_OK || data_length == 0 || data_length > TONEX_MAX_FULL_PRESET_DATA)
    {
        nvs_close(handle);
        return err != ESP_OK ? err : ESP_ERR_INVALID_SIZE;
    }
    uint8_t *data = heap_caps_malloc(data_length, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (data == NULL) data = malloc(data_length);
    if (data == NULL)
    {
        nvs_close(handle);
        return ESP_ERR_NO_MEM;
    }
    err = nvs_get_blob(handle, key, data, &data_length);
    nvs_close(handle);
    if (err != ESP_OK)
    {
        free(data);
        return err;
    }
    *full_details = data;
    *length = data_length;
    return ESP_OK;
}

esp_err_t preset_backup_load_to_tonex(uint16_t slot, uint8_t destination_slot,
                                      bool keep_parameters, uint32_t *id)
{
    uint8_t *full_details;
    size_t length;
    esp_err_t err = preset_backup_load(slot, &full_details, &length);
    if (err != ESP_OK) return err;

    err = usb_tonex_one_import_preset(full_details, length, destination_slot, keep_parameters, id);
    if (err != ESP_OK) free(full_details);
    return err;
}

esp_err_t preset_backup_delete(uint16_t slot)
{
    if (slot >= PRESET_BACKUP_MAX_SLOTS || !Catalog.Entries[slot].Used)
        return ESP_ERR_INVALID_ARG;

    tPresetBackupCatalog *updated_catalog = heap_caps_malloc(sizeof(*updated_catalog),
                                                              MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (updated_catalog == NULL) updated_catalog = malloc(sizeof(*updated_catalog));
    if (updated_catalog == NULL) return ESP_ERR_NO_MEM;

    *updated_catalog = Catalog;
    updated_catalog->Entries[slot].Used = false;
    updated_catalog->Count--;

    char key[8];
    BackupKey(slot, key, sizeof(key));
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        free(updated_catalog);
        return err;
    }
    err = nvs_erase_key(handle, key);
    if (err == ESP_OK)
        err = nvs_set_blob(handle, PRESET_BACKUP_CATALOG_KEY, updated_catalog, sizeof(*updated_catalog));
    if (err == ESP_OK) err = nvs_commit(handle);
    nvs_close(handle);
    if (err == ESP_OK) Catalog = *updated_catalog;
    free(updated_catalog);
    return err;
}

uint16_t preset_backup_get_count(void)
{
    return Catalog.Count;
}

bool preset_backup_get_info(uint16_t index, tPresetBackupInfo *info)
{
    uint16_t slot;
    if (info == NULL || !preset_backup_get_slot(index, &slot)) return false;
    *info = Catalog.Entries[slot].Info;
    return true;
}

bool preset_backup_get_slot(uint16_t index, uint16_t *slot)
{
    uint16_t found = 0;
    if (slot == NULL) return false;
    for (uint16_t physical_slot = 0; physical_slot < PRESET_BACKUP_MAX_SLOTS; physical_slot++)
    {
        if (!Catalog.Entries[physical_slot].Used) continue;
        if (found++ == index)
        {
            *slot = physical_slot;
            return true;
        }
    }
    return false;
}

preset_backup_err_t preset_backup_load_preset_to_tonex(
    uint16_t backupIndex, 
    uint8_t presetIndex,
    lv_timer_cb_t timer_xcb
) {
    tScene *scene = scenes_get_current();
    if (scene == NULL || presetIndex >= MAX_SUPPORTED_PRESETS)
    {
        ESP_LOGE(TAG, "Cannot resolve destination preset %d", presetIndex);
        return PRESET_BACKUP_LOAD_ERR_WRONG_PRESET_INDEX;
    }
    uint8_t destination_preset = scene->PresetOrder[presetIndex];

    uint16_t backup_slot;
    if (!preset_backup_get_slot(backupIndex, &backup_slot))
    {
        ESP_LOGW(TAG, "Selected backup %d no longer exists", backupIndex);
        return PRESET_BACKUP_LOAD_ERR_NO_BACKUP;
    }

    uint32_t transfer_id;
    esp_err_t err = preset_backup_load_to_tonex(backup_slot, destination_preset,
                                                false, &transfer_id);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to load backup %u into preset %u (%s)", backup_slot,
                 destination_preset, esp_err_to_name(err));
        
        return PRESET_BACKUP_LOAD_ERR_FAILED;
    }
    else
    {
        ESP_LOGI(TAG, "Loading backup %u into preset %u (transfer %" PRIu32 ")", backup_slot,
                 destination_preset, transfer_id);

        if (timer_xcb != NULL)
        {
            lv_timer_t *timer = lv_timer_create(timer_xcb, 50, NULL);
            if (timer == NULL)
            {
                ESP_LOGE(TAG, "Failed to create preset backup load timer");
            }
            else
            {
                timer->user_data = (void *)(uintptr_t)transfer_id;
            }
        }

        return PRESET_BACKUP_OK;
    }
}