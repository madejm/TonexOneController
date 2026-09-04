#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_heap_caps.h"
#include "esp_log.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "scenes.h"

#define NVS_SCENES_PARTITION                "scenes"
#define NVS_SCENES_NAMESPACE                "scenes"
#define NVS_SCENES_CATALOG                  "catalog"
#define NVS_SCENE_KEY_FORMAT                "scene%02u"
#define SCENES_STORAGE_VERSION              1
#define SCENE_STORAGE_ID_INVALID            UINT8_MAX

typedef struct
{
    uint8_t StorageId;
    char Name[MAX_SCENE_NAME];
} tSceneCatalogEntry;

typedef struct
{
    uint32_t Version;
    tScenesConfig Config;
    tSceneCatalogEntry Scenes[MAX_SCENES];
} tScenesCatalog;

static const char *TAG = "app_scenes";
static tScenesCatalog ScenesCatalog;
static tScene *CurrentScene;
static uint8_t CurrentSceneStorageId = SCENE_STORAGE_ID_INVALID;
static bool CurrentSceneNeedsSave;
static bool ScenesLoaded;

static esp_err_t OpenStorage(nvs_open_mode_t mode, nvs_handle_t *handle)
{
    return nvs_open_from_partition(NVS_SCENES_PARTITION, NVS_SCENES_NAMESPACE, mode, handle);
}

static void SceneKey(uint8_t storage_id, char *key, size_t key_length)
{
    snprintf(key, key_length, NVS_SCENE_KEY_FORMAT, storage_id);
}

static void SetDefaultScenePayload(tScene *scene)
{
    memset(scene, 0, sizeof(*scene));
    for (uint8_t index = 0; index < MAX_SUPPORTED_PRESETS; index++)
    {
        scene->PresetOrder[index] = index;
    }
}

static void SetDefaults(void)
{
    memset(&ScenesCatalog, 0, sizeof(ScenesCatalog));
    ScenesCatalog.Version = SCENES_STORAGE_VERSION;
    ScenesCatalog.Config.ScenesCount = 1;
    ScenesCatalog.Config.SelectedScene = 0;
    ScenesCatalog.Scenes[0].StorageId = 0;
    snprintf(ScenesCatalog.Scenes[0].Name, sizeof(ScenesCatalog.Scenes[0].Name), "Scene 1");

    SetDefaultScenePayload(CurrentScene);
    CurrentSceneStorageId = 0;
    CurrentSceneNeedsSave = false;
}

static esp_err_t SaveScene(uint8_t storage_id, const tScene *scene)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        return err;
    }

    char key[16];
    SceneKey(storage_id, key, sizeof(key));
    err = nvs_set_blob(handle, key, scene, sizeof(*scene));
    if (err == ESP_OK)
    {
        err = nvs_commit(handle);
    }
    nvs_close(handle);

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to save scene %u (%s)", storage_id, esp_err_to_name(err));
    }
    return err;
}

static esp_err_t LoadScene(uint8_t storage_id, tScene *scene)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READONLY, &handle);
    if (err != ESP_OK)
    {
        return err;
    }

    char key[16];
    size_t required_size = sizeof(*scene);
    SceneKey(storage_id, key, sizeof(key));
    err = nvs_get_blob(handle, key, scene, &required_size);
    nvs_close(handle);

    if ((err == ESP_OK) && (required_size != sizeof(*scene)))
    {
        err = ESP_ERR_NVS_INVALID_LENGTH;
    }
    return err;
}

static esp_err_t EraseScene(uint8_t storage_id)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        return err;
    }

    char key[16];
    SceneKey(storage_id, key, sizeof(key));
    err = nvs_erase_key(handle, key);
    if ((err == ESP_OK) || (err == ESP_ERR_NVS_NOT_FOUND))
    {
        err = nvs_commit(handle);
    }
    nvs_close(handle);
    return err;
}

static esp_err_t SaveCatalog(void)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        return err;
    }

    ScenesCatalog.Version = SCENES_STORAGE_VERSION;
    err = nvs_set_blob(handle, NVS_SCENES_CATALOG, &ScenesCatalog, sizeof(ScenesCatalog));
    if (err == ESP_OK)
    {
        err = nvs_commit(handle);
    }
    nvs_close(handle);

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to save scenes catalog (%s)", esp_err_to_name(err));
    }
    return err;
}

static bool CatalogIsValid(void)
{
    if ((ScenesCatalog.Version != SCENES_STORAGE_VERSION)
     || (ScenesCatalog.Config.ScenesCount == 0)
     || (ScenesCatalog.Config.ScenesCount > MAX_SCENES)
     || (ScenesCatalog.Config.SelectedScene >= ScenesCatalog.Config.ScenesCount))
    {
        return false;
    }

    bool used_ids[MAX_SCENES] = { false };
    for (uint8_t index = 0; index < ScenesCatalog.Config.ScenesCount; index++)
    {
        uint8_t storage_id = ScenesCatalog.Scenes[index].StorageId;
        if ((storage_id >= MAX_SCENES) || used_ids[storage_id])
        {
            return false;
        }
        used_ids[storage_id] = true;
        ScenesCatalog.Scenes[index].Name[MAX_SCENE_NAME - 1] = 0;
    }
    return true;
}

static esp_err_t InitStorage(void)
{
    esp_err_t err = nvs_flash_init_partition(NVS_SCENES_PARTITION);
    if ((err == ESP_ERR_NVS_NO_FREE_PAGES) || (err == ESP_ERR_NVS_NEW_VERSION_FOUND))
    {
        ESP_ERROR_CHECK(nvs_flash_erase_partition(NVS_SCENES_PARTITION));
        err = nvs_flash_init_partition(NVS_SCENES_PARTITION);
    }

    return err;
}

static esp_err_t LoadData(void)
{
    nvs_handle_t handle;
    esp_err_t err = OpenStorage(NVS_READONLY, &handle);
    if (err == ESP_OK)
    {
        size_t required_size = sizeof(ScenesCatalog);
        err = nvs_get_blob(handle, NVS_SCENES_CATALOG, &ScenesCatalog, &required_size);
        nvs_close(handle);
        if ((err == ESP_OK) && (required_size != sizeof(ScenesCatalog)))
        {
            err = ESP_ERR_NVS_INVALID_LENGTH;
        }
    }

    if ((err != ESP_OK) || !CatalogIsValid())
    {
        ESP_LOGW(TAG, "No valid scenes catalog; creating defaults");
        SetDefaults();
        err = SaveScene(CurrentSceneStorageId, CurrentScene);
        if (err == ESP_OK)
        {
            err = SaveCatalog();
        }
        ScenesLoaded = true;
        return err;
    }

    CurrentSceneStorageId = ScenesCatalog.Scenes[ScenesCatalog.Config.SelectedScene].StorageId;
    err = LoadScene(CurrentSceneStorageId, CurrentScene);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to load selected scene %u (%s)", CurrentSceneStorageId, esp_err_to_name(err));
        SetDefaultScenePayload(CurrentScene);
        err = SaveScene(CurrentSceneStorageId, CurrentScene);
    }

    for (uint8_t index = 0; index < MAX_SUPPORTED_PRESETS; index++)
    {
        if (CurrentScene->PresetOrder[index] >= MAX_SUPPORTED_PRESETS)
        {
            ESP_LOGW(TAG, "Repairing active scene preset layout");
            SetDefaultScenePayload(CurrentScene);
            err = SaveScene(CurrentSceneStorageId, CurrentScene);
            break;
        }
    }

    CurrentSceneNeedsSave = false;
    ScenesLoaded = true;
    return err;
}

esp_err_t scenes_init(void)
{
    CurrentScene = heap_caps_calloc(1, sizeof(*CurrentScene), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (CurrentScene == NULL)
    {
        ESP_LOGE(TAG, "Failed to allocate current scene in PSRAM (%u bytes)", sizeof(*CurrentScene));
        return ESP_ERR_NO_MEM;
    }

    SetDefaults();
    esp_err_t err = InitStorage();
    if (err != ESP_OK)
    {
        return err;
    }
    return LoadData();
}

esp_err_t scenes_save(void)
{
    if (!ScenesLoaded)
    {
        return ESP_ERR_INVALID_STATE;
    }

    esp_err_t err = ESP_OK;
    if ((CurrentSceneStorageId != SCENE_STORAGE_ID_INVALID) && CurrentSceneNeedsSave)
    {
        err = SaveScene(CurrentSceneStorageId, CurrentScene);
        if (err == ESP_OK)
        {
            CurrentSceneNeedsSave = false;
        }
    }

    esp_err_t catalog_err = SaveCatalog();
    return (err != ESP_OK) ? err : catalog_err;
}

// FNV-1a hash
uint32_t scenes_hash_preset_params(const float preset_params[TONEX_PARAM_LAST])
{
    uint32_t hash = 2166136261u;

    for (uint16_t index = 0; index < TONEX_PARAM_LAST; index++)
    {
        uint32_t value_bits;
        memcpy(&value_bits, &preset_params[index], sizeof(value_bits));

        for (uint8_t byte = 0; byte < sizeof(value_bits); byte++)
        {
            hash ^= (value_bits >> (byte * 8)) & 0xFFu;
            hash *= 16777619u;
        }
    }

    return hash;
}

esp_err_t scenes_save_preset_params(uint8_t preset_index, const float preset_params[TONEX_PARAM_LAST])
{
    if ((CurrentScene == NULL) || (preset_params == NULL) || (preset_index >= MAX_SUPPORTED_PRESETS))
    {
        return ESP_ERR_INVALID_ARG;
    }

    tScenePreset *scene_preset = &CurrentScene->Presets[preset_index];
    memcpy(scene_preset->PresetParams, preset_params, sizeof(scene_preset->PresetParams));
    scene_preset->PresetParamsHash = scenes_hash_preset_params(scene_preset->PresetParams);
    scene_preset->Modified = false;
    CurrentSceneNeedsSave = true;

    esp_err_t err = scenes_save();
    if (err != ESP_OK)
    {
        scene_preset->Modified = true;
    }
    return err;
}

tScene *scenes_get_current(void)
{
    return CurrentScene;
}

const char *scenes_get_name(uint8_t index)
{
    if (index >= ScenesCatalog.Config.ScenesCount)
    {
        return NULL;
    }
    return ScenesCatalog.Scenes[index].Name;
}

uint8_t scenes_get_selected(void)
{
    return ScenesCatalog.Config.SelectedScene;
}

uint8_t scenes_get_count(void)
{
    return ScenesCatalog.Config.ScenesCount;
}

bool scenes_select(uint8_t index)
{
    if (index >= ScenesCatalog.Config.ScenesCount)
    {
        return false;
    }

    uint8_t storage_id = ScenesCatalog.Scenes[index].StorageId;
    if (storage_id != CurrentSceneStorageId)
    {
        if (LoadScene(storage_id, CurrentScene) != ESP_OK)
        {
            ESP_LOGE(TAG, "Failed to load scene %u", storage_id);
            return false;
        }
        CurrentSceneStorageId = storage_id;
        CurrentSceneNeedsSave = false;
    }

    ScenesCatalog.Config.SelectedScene = index;
    return true;
}

bool scenes_create(void)
{
    if (ScenesCatalog.Config.ScenesCount >= MAX_SCENES)
    {
        return false;
    }

    bool used_ids[MAX_SCENES] = { false };
    for (uint8_t index = 0; index < ScenesCatalog.Config.ScenesCount; index++)
    {
        if (ScenesCatalog.Scenes[index].StorageId < MAX_SCENES)
        {
            used_ids[ScenesCatalog.Scenes[index].StorageId] = true;
        }
    }

    uint8_t storage_id = SCENE_STORAGE_ID_INVALID;
    for (uint8_t index = 0; index < MAX_SCENES; index++)
    {
        if (!used_ids[index])
        {
            storage_id = index;
            break;
        }
    }
    if (storage_id == SCENE_STORAGE_ID_INVALID)
    {
        return false;
    }

    tScene *new_scene = heap_caps_malloc(sizeof(*new_scene), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (new_scene == NULL)
    {
        ESP_LOGE(TAG, "Failed to allocate new scene copy in PSRAM");
        return false;
    }
    memcpy(new_scene, CurrentScene, sizeof(*new_scene));
    for (uint8_t preset = 0; preset < MAX_SUPPORTED_PRESETS; preset++)
    {
        new_scene->Presets[preset].Modified = false;
    }

    esp_err_t err = SaveScene(storage_id, new_scene);
    heap_caps_free(new_scene);
    if (err != ESP_OK)
    {
        return false;
    }

    uint8_t new_index = ScenesCatalog.Config.ScenesCount;
    ScenesCatalog.Scenes[new_index].StorageId = storage_id;
    snprintf(ScenesCatalog.Scenes[new_index].Name, sizeof(ScenesCatalog.Scenes[new_index].Name), "Scene %u", new_index + 1);
    ScenesCatalog.Config.ScenesCount++;

    if (SaveCatalog() != ESP_OK)
    {
        ScenesCatalog.Config.ScenesCount--;
        memset(&ScenesCatalog.Scenes[new_index], 0, sizeof(ScenesCatalog.Scenes[new_index]));
        EraseScene(storage_id);
        return false;
    }
    return true;
}

void scenes_delete(uint8_t index)
{
    uint8_t scenes_count = ScenesCatalog.Config.ScenesCount;
    if ((scenes_count <= 1) || (index >= scenes_count))
    {
        return;
    }

    uint8_t deleted_storage_id = ScenesCatalog.Scenes[index].StorageId;
    uint8_t selected_scene = ScenesCatalog.Config.SelectedScene;

    if (selected_scene == index)
    {
        uint8_t replacement_source_index = (index < scenes_count - 1) ? (index + 1) : (index - 1);
        uint8_t replacement_storage_id = ScenesCatalog.Scenes[replacement_source_index].StorageId;
        if (LoadScene(replacement_storage_id, CurrentScene) != ESP_OK)
        {
            ESP_LOGE(TAG, "Failed to load replacement for deleted scene");
            return;
        }
        CurrentSceneStorageId = replacement_storage_id;
        CurrentSceneNeedsSave = false;
    }

    for (uint8_t scene = index; scene < scenes_count - 1; scene++)
    {
        ScenesCatalog.Scenes[scene] = ScenesCatalog.Scenes[scene + 1];
    }
    memset(&ScenesCatalog.Scenes[scenes_count - 1], 0, sizeof(ScenesCatalog.Scenes[scenes_count - 1]));
    ScenesCatalog.Config.ScenesCount--;

    if (selected_scene == index)
    {
        ScenesCatalog.Config.SelectedScene = (index < ScenesCatalog.Config.ScenesCount) ? index : (index - 1);
    }
    else if (selected_scene > index)
    {
        ScenesCatalog.Config.SelectedScene--;
    }

    if (SaveCatalog() == ESP_OK)
    {
        EraseScene(deleted_storage_id);
    }
}

void scenes_set_name(uint8_t index, const char *name)
{
    if ((index >= ScenesCatalog.Config.ScenesCount) || (name == NULL))
    {
        return;
    }
    snprintf(ScenesCatalog.Scenes[index].Name, sizeof(ScenesCatalog.Scenes[index].Name), "%s", name);
}

void scenes_set_preset_order(const uint8_t *order, uint8_t count)
{
    if ((order == NULL) || (CurrentScene == NULL))
    {
        return;
    }

    if (count > MAX_SUPPORTED_PRESETS)
    {
        count = MAX_SUPPORTED_PRESETS;
    }
    memcpy(CurrentScene->PresetOrder, order, count);
    CurrentSceneNeedsSave = true;
}

uint8_t *scenes_get_preset_order(void)
{
    return (CurrentScene != NULL) ? CurrentScene->PresetOrder : NULL;
}
