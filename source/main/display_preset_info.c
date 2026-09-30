#include "display_preset_info.h"
#include <inttypes.h>
#include "esp_log.h"
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
            updateInfo(full_details, length);
            lv_scr_load_anim(objects.preset_info, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
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

void openPresetInfoPagePreset(uint8_t presetIndex, display_preset_info_close_cb_t close_action)
{
    close_callback = close_action;

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

    uint8_t *full_details;
    size_t length;
    esp_err_t err = preset_backup_load(slot, &full_details, &length);
    if (err != ESP_OK) return;

    updateInfo(full_details, length);

    free(full_details);

    lv_scr_load_anim(objects.preset_info, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_preset_info_close(lv_event_t *e)
{
    close_callback(NULL);
}

#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
