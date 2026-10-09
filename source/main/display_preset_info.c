#include "display_preset_info.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include "esp_log.h"
#include "esp_heap_caps.h"
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
#include "preset_backup.h"
#include "tonex_parser.h"
#include "tonex_parser_trees.h"
#include "display_preset_list.h"
#include "display_preset_backup_list.h"

static const char *TAG = "display_preset_info";

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

display_preset_info_close_cb_t close_callback;

typedef enum {
    INFO_TYPE_PRESET,
    INFO_TYPE_BACKUP
} InfoType;

static void openPresetInfoPage();
static void labelSetText(lv_obj_t *label, const char *text);
static uint8_t info_index;
static InfoType info_type;
static uint8_t *info_details;
static size_t info_length;
static lv_timer_t *rename_timer;
static char rename_name[PRESET_BACKUP_TEXT_LENGTH];

static void preset_info_rename_timer_cb(lv_timer_t *timer)
{
    usb_tonex_one_import_state_t state = usb_tonex_one_import_status((uint32_t)(uintptr_t)timer->user_data);
    switch (state)
    {
        case TONEX_IMPORT_SENT: {
            const char *stored_name;
            size_t capacity;
            if (tonex_read_data_str(info_details, info_length, &TonexPresetDetailsFullTree,
                                    TONEX_PRESET_NAME, &stored_name, &capacity))
            {
                uint8_t *destination = info_details + ((const uint8_t *)stored_name - info_details);
                memset(destination, 0, capacity);
                memcpy(destination, rename_name, strlen(rename_name));
                destination[capacity] = (uint8_t)strlen(rename_name);
            }
            labelSetText(objects.ui_preset_info_name, rename_name);
        } break;

        case TONEX_IMPORT_FAILED:
        case TONEX_IMPORT_NONE:
            ESP_LOGE(TAG, "Preset rename transfer failed, state: %d", state);
            break;

        default:
            return;
    }
    
    rename_timer = NULL;
    lv_timer_del(timer);
}

// ====== UPDATES ======

static void labelSetText(lv_obj_t *label, const char *text)
{
    if (text[0] == 0) {
        lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_clear_flag(label, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(label, text);
    }
}

static void spanSetHeader(lv_obj_t *spangroup, const char *text)
{
    lv_span_t *span = lv_spangroup_get_child(spangroup, 0);
    lv_span_set_text(span, text);
}

static bool spanSetText(lv_obj_t *spangroup, const char *text)
{
    if (text[0] == 0) {
        lv_obj_add_flag(spangroup, LV_OBJ_FLAG_HIDDEN);
        return false;
    } else {
        lv_obj_clear_flag(spangroup, LV_OBJ_FLAG_HIDDEN);
        lv_span_t *span = lv_spangroup_get_child(spangroup, -1);
        lv_span_set_text(span, text);
        lv_spangroup_refr_mode(spangroup);
        return true;
    }
}

static void CopyTreeString(const uint8_t *full_details, size_t length,
                           char *destination, size_t destination_length,
                           tTonexDataFieldName field)
{
    const char *source;
    size_t source_length;

    if (destination == NULL || destination_length == 0 ||
        !tonex_read_data_str(full_details, length, &TonexPresetDetailsFullTree,
                             field, &source, &source_length)) {
        destination[0] = 0;
        return;
    }
    if (strcmp(source, "None") == 0) {
        destination[0] = 0;
    } else {
        if (source_length >= destination_length) source_length = destination_length - 1;
        memcpy(destination, source, source_length);
        destination[source_length] = 0;
    }
}

static void updateInfo(const uint8_t *full_details, size_t length)
{
    tTonexModelType model_a_type = MODEL_TYPE_EMPTY;
    uint8_t separate_model_enabled = false;
    tTonexModelType model_b_type = MODEL_TYPE_EMPTY;
    char buf[65];

    tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                       TONEX_MODEL_A_TYPE, &model_a_type);
    tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                       TONEX_MODEL_SEPARATE_ENABLED, &separate_model_enabled);

    if (separate_model_enabled) {
        tonex_read_data_u8(full_details, length, &TonexPresetDetailsFullTree,
                           TONEX_MODEL_B_TYPE, &model_b_type);
    }

    switch (model_a_type)
    {
        case MODEL_TYPE_STOMP:
            spanSetHeader(objects.ui_preset_info_amp, "Stomp ");
            break;

        case MODEL_TYPE_AMP:
            spanSetHeader(objects.ui_preset_info_amp, "Amp ");
            break;

        case MODEL_TYPE_AMPCAB:
            spanSetHeader(objects.ui_preset_info_amp, separate_model_enabled ? "Amp " : "Amp & Cab ");
            break;
        default:
            break;
    }

    if (separate_model_enabled) {
        if (model_b_type == MODEL_TYPE_IR) {
            spanSetText(objects.ui_preset_info_cab, "IR");
        } else {
            CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_MODEL_B_NAME);
            spanSetText(objects.ui_preset_info_cab, buf);
        }
    } else {
        spanSetText(objects.ui_preset_info_cab, "\0");
    }
    
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_NAME);
    labelSetText(objects.ui_preset_info_name, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_AUTHOR);
    spanSetText(objects.ui_preset_info_author, buf);

    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_MODEL_A_METADATA_AUTHOR);
    spanSetText(objects.ui_preset_info_model_author, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_CHARACTER);
    spanSetText(objects.ui_preset_info_character, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_MODEL_A_NAME);
    spanSetText(objects.ui_preset_info_amp, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_MODEL_A_METADATA_DESCRIPTION);
    labelSetText(objects.ui_preset_info_model_description, buf);

    bool song = false;

    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_SONG);
    song |= spanSetText(objects.ui_preset_info_song, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_ARTIST);
    song |= spanSetText(objects.ui_preset_info_artist, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_ALBUM);
    song |= spanSetText(objects.ui_preset_info_album, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_SONG_PART);
    song |= spanSetText(objects.ui_preset_info_part, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_GENRE);
    song |= spanSetText(objects.ui_preset_info_genre, buf);
    
    lv_obj_set_hidden(objects.ui_preset_info_song_section, !song);

    bool instrument = false;

    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_INSTRUMENT);
    instrument |= spanSetText(objects.ui_preset_info_instrument, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_INSTRUMENT_TYPE);
    instrument |= spanSetText(objects.ui_preset_info_instrument_type, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_PICKUP_TYPE);
    instrument |= spanSetText(objects.ui_preset_info_pickup, buf);
    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_PICKUP_POSITION);
    instrument |= spanSetText(objects.ui_preset_info_position, buf);

    lv_obj_set_hidden(objects.ui_preset_info_instrument_section, !instrument);

    CopyTreeString(full_details, length, buf, sizeof(buf), TONEX_PRESET_METADATA_DESCRIPTION);
    labelSetText(objects.ui_preset_info_description, buf);
}

static void preset_info_preset_timer_cb(lv_timer_t *timer)
{
    uint32_t export_id = (uint32_t)(uintptr_t)timer->user_data;
    usb_tonex_one_export_state_t state = usb_tonex_one_export_status(export_id);

    if (state == TONEX_EXPORT_READY)
    {
        uint8_t *full_details = NULL;
        size_t length = 0;
        esp_err_t err = usb_tonex_one_export_take(export_id, &full_details, &length);
        if (err == ESP_OK)
        {
            free(info_details);
            info_details = full_details;
            info_length = length;
            updateInfo(full_details, length);
            openPresetInfoPage();
        }
        else
        {
            ESP_LOGE(TAG, "Failed to collect preset info preset (%s)", esp_err_to_name(err));
        }
        lv_timer_del(timer);
    }
    else if (state == TONEX_EXPORT_FAILED || state == TONEX_EXPORT_NONE)
    {
        ESP_LOGE(TAG, "Preset info failed");
        lv_timer_del(timer);
    }
}

// ====== ACTIONS ======

static void openPresetInfoPage()
{
    lv_obj_add_flag(objects.ui_preset_info_rename_dialog, LV_OBJ_FLAG_HIDDEN);
    lv_scr_load_anim(objects.preset_info, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void openPresetInfoPagePreset(uint8_t presetIndex, display_preset_info_close_cb_t close_action)
{
    close_callback = close_action;
    info_index = presetIndex;
    info_type = INFO_TYPE_PRESET;

    uint32_t export_id;
    lv_timer_t *timer = lv_timer_create(preset_info_preset_timer_cb, 50, NULL);
    if (timer == NULL)
    {
        ESP_LOGE(TAG, "Failed to create preset info timer");
    }
    else
    {
        esp_err_t err = usb_tonex_one_export_preset(presetIndex, &export_id);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "Failed to start preset info for %u (%s)", presetIndex, esp_err_to_name(err));
            lv_timer_del(timer);
        }
        else
        {
            timer->user_data = (void *)(uintptr_t)export_id;
            ESP_LOGI(TAG, "Loading preset info %u", presetIndex);
        }
    }
}

void openPresetInfoPageBackup(uint8_t slot, display_preset_info_close_cb_t close_action)
{
    close_callback = close_action;
    info_index = slot;
    info_type = INFO_TYPE_BACKUP;

    uint8_t *full_details;
    size_t length;
    esp_err_t err = preset_backup_load(slot, &full_details, &length);
    if (err != ESP_OK)
    {
        return;
    }

    updateInfo(full_details, length);

    free(info_details);
    info_details = full_details;
    info_length = length;

    openPresetInfoPage();
}

void action_preset_info_close(lv_event_t *e)
{
    if (rename_timer != NULL)
    {
        return;
    }
    free(info_details);
    info_details = NULL;
    info_length = 0;
    close_callback(NULL);
}

void action_preset_info_rename_preset_name(lv_event_t * e)
{
    lv_textarea_set_text(
        objects.ui_preset_info_rename_dialog_textarea,
        lv_label_get_text(objects.ui_preset_info_name)
    );
    lv_obj_add_state(objects.ui_preset_info_rename_dialog_textarea, LV_STATE_FOCUSED);

    lv_obj_clear_flag(objects.ui_preset_info_rename_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_preset_info_rename_dialog_keyboard_ok(lv_event_t * e)
{
    if (rename_timer != NULL || info_details == NULL) return;
    const char *name = lv_textarea_get_text(objects.ui_preset_info_rename_dialog_textarea);
    size_t name_length = strlen(name);
    const char *stored_name;
    size_t capacity;
    if (name_length == 0 || name_length >= sizeof(rename_name) ||
        !tonex_read_data_str(info_details, info_length, &TonexPresetDetailsFullTree,
                             TONEX_PRESET_NAME, &stored_name, &capacity) ||
        name_length >= capacity)
    {
        ESP_LOGW(TAG, "Invalid preset name: %s", name);
        return;
    }

    uint8_t *updated = heap_caps_malloc(info_length, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (updated == NULL) updated = malloc(info_length);
    if (updated == NULL)
    {
        ESP_LOGE(TAG, "Failed to allocate renamed preset buffer with length %zu", info_length);
        return;
    }
    memcpy(updated, info_details, info_length);
    size_t offset = (const uint8_t *)stored_name - info_details;
    memset(updated + offset, 0, capacity);
    memcpy(updated + offset, name, name_length);
    // The detail stores its actual string length after the fixed-capacity buffer.
    updated[offset + capacity] = (uint8_t)name_length;
    memcpy(rename_name, name, name_length + 1);

    esp_err_t err = ESP_OK;
    switch (info_type)
    {
        case INFO_TYPE_BACKUP: {
            err = preset_backup_update(info_index, updated, info_length);
            if (err == ESP_OK)
            {
                memcpy(info_details + offset, updated + offset, capacity);
                info_details[offset + capacity] = (uint8_t)name_length;
                labelSetText(objects.ui_preset_info_name, rename_name);
                lv_obj_add_flag(objects.ui_preset_info_rename_dialog, LV_OBJ_FLAG_HIDDEN);
            }
            free(updated);
        } break;

        case INFO_TYPE_PRESET: {
            rename_timer = lv_timer_create(preset_info_rename_timer_cb, 50, NULL);
            if (rename_timer == NULL)
            {
                ESP_LOGE(TAG, "Failed to create rename timer");
                free(updated);
                return;
            }
            uint32_t import_id;
            err = usb_tonex_one_import_preset(updated, info_length, info_index, true, &import_id);
            if (err == ESP_OK)
            {
                rename_timer->user_data = (void *)(uintptr_t)import_id;
                lv_obj_add_flag(objects.ui_preset_info_rename_dialog, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                free(updated);
                lv_timer_del(rename_timer);
                rename_timer = NULL;
            }
        } break;
    }

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to rename preset (%s)", esp_err_to_name(err));
    }
}

void action_preset_info_rename_dialog_close(lv_event_t * e)
{
    if (rename_timer != NULL)
    {
        return;
    }
    lv_obj_add_flag(objects.ui_preset_info_rename_dialog, LV_OBJ_FLAG_HIDDEN);
}
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
