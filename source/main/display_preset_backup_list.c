#include "display_preset_backup_list.h"
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

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
static const char *TAG = "app_display_preset_backup_list";

#define OPTION_DELETE       "Delete"
#define ALL_OPTIONS         OPTION_DELETE

static int16_t preset_backup_list_edit_index = -1;
static int16_t preset_backup_list_load_preset_index = -1;

#define PRESET_BACKUP_LIST_PRESETS_PER_PAGE 8
static uint8_t preset_backup_list_page = 0;

static lv_obj_t * preset_backup_cells(uint8_t index)
{
    switch (index) {
        case 0: return objects.ui_preset_backup_list_element_0;
        case 1: return objects.ui_preset_backup_list_element_1;
        case 2: return objects.ui_preset_backup_list_element_2;
        case 3: return objects.ui_preset_backup_list_element_3;
        case 4: return objects.ui_preset_backup_list_element_4;
        case 5: return objects.ui_preset_backup_list_element_5;
        case 6: return objects.ui_preset_backup_list_element_6;
        case 7: return objects.ui_preset_backup_list_element_7;
        default: return NULL;
    }
}

static lv_obj_t * preset_backup_names(uint8_t index)
{
    switch (index) {
        case 0: return objects.ui_preset_backup_list_element_0__name_label;
        case 1: return objects.ui_preset_backup_list_element_1__name_label;
        case 2: return objects.ui_preset_backup_list_element_2__name_label;
        case 3: return objects.ui_preset_backup_list_element_3__name_label;
        case 4: return objects.ui_preset_backup_list_element_4__name_label;
        case 5: return objects.ui_preset_backup_list_element_5__name_label;
        case 6: return objects.ui_preset_backup_list_element_6__name_label;
        case 7: return objects.ui_preset_backup_list_element_7__name_label;
        default: return NULL;
    }
}

static lv_obj_t * preset_backup_details(uint8_t index, uint8_t detail)
{
    #define DETAILS_SWITCH(detail, element) \
        switch (detail) { \
            case 0: return element ## 1; \
            case 1: return element ## 2; \
            case 2: return element ## 3; \
            case 3: return element ## 4; \
            default: return NULL; \
        }

    switch (index) {
        case 0: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_0__label)
        case 1: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_1__label)
        case 2: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_2__label)
        case 3: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_3__label)
        case 4: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_4__label)
        case 5: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_5__label)
        case 6: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_6__label)
        case 7: DETAILS_SWITCH(detail, objects.ui_preset_backup_list_element_7__label)
        default: return NULL;
    }
}

static uint16_t preset_backup_list_pages()
{
    uint16_t count = preset_backup_get_count();
    return count == 0 ? 1 : (count + PRESET_BACKUP_LIST_PRESETS_PER_PAGE - 1) / PRESET_BACKUP_LIST_PRESETS_PER_PAGE;
}

static bool selected_preset_backup_info(tPresetBackupInfo *info)
{
    return preset_backup_list_edit_index >= 0 &&
           preset_backup_get_info(preset_backup_list_edit_index, info);
}

// ====== UPDATES ======

static void updatePresetBackupList()
{
    uint16_t pages = preset_backup_list_pages();
    uint16_t start;
    char page_text[16];

    if (preset_backup_list_page >= pages) preset_backup_list_page = pages - 1;
    start = preset_backup_list_page * PRESET_BACKUP_LIST_PRESETS_PER_PAGE;
    snprintf(page_text, sizeof(page_text), "Page %u/%u", preset_backup_list_page + 1, pages);
    lv_label_set_text(objects.ui_preset_backup_list_page_label, page_text);

    for (uint8_t cell = 0; cell < PRESET_BACKUP_LIST_PRESETS_PER_PAGE; cell++)
    {
        tPresetBackupInfo info;
        if (!preset_backup_get_info(start + cell, &info))
        {
            lv_obj_add_flag(preset_backup_cells(cell), LV_OBJ_FLAG_HIDDEN);
            continue;
        }

        const char *details[] = {info.ModelCharacter, info.ModelType, info.ModelAmpName, info.ModelCabName};
        lv_obj_clear_flag(preset_backup_cells(cell), LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(preset_backup_names(cell), info.PresetName);
        for (uint8_t detail = 0; detail < 4; detail++)
        {
            const char *text = details[detail];
            lv_obj_t *label = preset_backup_details(cell, detail);

            switch (detail) {
                case 0: {
                    int colorId;
                    str_switch(text) {
                        str_case("CLEAN")   colorId = COLOR_ID_HIGHLIGHT_BLUE;   text = "Clean";
                        str_case("DRIVE")   colorId = COLOR_ID_HIGHLIGHT_YELLOW; text = "Drive";
                        str_case("HI-GAIN") colorId = COLOR_ID_HIGHLIGHT_RED;    text = "Hi-Gain";
                        str_case("FUZZY")   colorId = COLOR_ID_HIGHLIGHT_PURPLE; text = "Fuzz";
                        str_default         colorId = COLOR_ID_HIGHLIGHT_GREEN;  text = "Other";
                    }
                    lv_obj_set_style_text_color(label, lv_color_hex(theme_colors[active_theme_index][colorId]), LV_PART_MAIN | LV_STATE_DEFAULT);
                } break;

                case 1: {
                    int colorId;
                    str_switch(text) {
                        str_case_contains("Stomp") colorId = COLOR_ID_HIGHLIGHT_GREEN;
                        str_case_contains("Cab")   colorId = COLOR_ID_HIGHLIGHT_RED;
                        str_case_contains("IR")    colorId = COLOR_ID_HIGHLIGHT_BLUE;
                        str_case_contains("Amp")   colorId = COLOR_ID_HIGHLIGHT_YELLOW;
                        str_default                colorId = COLOR_ID_DEFAULT_GRAY;
                    }
                    lv_obj_set_style_text_color(label, lv_color_hex(theme_colors[active_theme_index][colorId]), LV_PART_MAIN | LV_STATE_DEFAULT);
                } break;
            }

            lv_label_set_text(label, text);

            if (text[0] == 0)
                lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
            else
                lv_obj_clear_flag(label, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

static void updatePresetBackupListOptions()
{
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_0__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_1__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_2__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_3__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_4__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_5__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_6__options, ALL_OPTIONS);
    lv_dropdown_set_options(objects.ui_preset_backup_list_element_7__options, ALL_OPTIONS);
}

// ====== ACTIONS ======

static void openPresetsBackupPage()
{
    preset_backup_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_backup_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_backup_delete_dialog, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_backup_load_dialog, LV_OBJ_FLAG_HIDDEN);

    updatePresetBackupList();
    updatePresetBackupListOptions();

    lv_scr_load_anim(objects.presets_backup, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_open_presets_backup_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_open_presets_backup_page");

    preset_backup_list_load_preset_index = -1;

    openPresetsBackupPage();

    lv_obj_add_flag(objects.ui_preset_backup_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(objects.ui_preset_backup_list_close_button, LV_OBJ_FLAG_HIDDEN);
}

void openPresetsBackupPageLoad(uint8_t presetIndex)
{
    ESP_LOGI(TAG, "openPresetsBackupPageLoad %u", presetIndex);

    preset_backup_list_load_preset_index = presetIndex;

    openPresetsBackupPage();

    lv_obj_clear_flag(objects.ui_preset_backup_list_cancel_button, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_preset_backup_list_close_button, LV_OBJ_FLAG_HIDDEN);
}

void action_close_presets_backup_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_close_presets_backup_page");

    lv_scr_load_anim(objects.presets, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void selectPresetListBackupPreset(uint8_t buttonIndex)
{
    ESP_LOGI(TAG, "selectPresetListBackupPreset %u", buttonIndex);

    if (preset_backup_list_load_preset_index <= -1) {
        return;
    }

    preset_backup_list_edit_index = preset_backup_list_page * PRESET_BACKUP_LIST_PRESETS_PER_PAGE + buttonIndex;

    tPresetBackupInfo backup_info;
    tScene *scene = scenes_get_current();
    if (!selected_preset_backup_info(&backup_info) || scene == NULL ||
        preset_backup_list_load_preset_index >= MAX_SUPPORTED_PRESETS)
    {
        preset_backup_list_edit_index = -1;
        return;
    }

    uint8_t destination_preset = scene->PresetOrder[preset_backup_list_load_preset_index];
    char old_preset_name[MAX_PRESET_NAME_LENGTH];
    control_get_preset_name(destination_preset, old_preset_name);
    lv_label_set_text(objects.ui_preset_backup_load_dialog_name, backup_info.PresetName);
    lv_label_set_text(objects.ui_preset_backup_load_dialog_old_name, old_preset_name);

    lv_obj_clear_flag(objects.ui_preset_backup_load_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_preset_backup_list_previous(lv_event_t * e)
{
    uint16_t pages = preset_backup_list_pages();
    preset_backup_list_page = preset_backup_list_page == 0 ? pages - 1 : preset_backup_list_page - 1;
    updatePresetBackupList();
}

void action_preset_backup_list_next(lv_event_t * e)
{
    uint16_t pages = preset_backup_list_pages();
    preset_backup_list_page = preset_backup_list_page + 1 == pages ? 0 : preset_backup_list_page + 1;
    updatePresetBackupList();
}

void presetBackupOptionsSelected(uint8_t buttonIndex, const char *option)
{
    ESP_LOGI(TAG, "presetBackupOptionsSelected %u, %s", buttonIndex, option);

    if (preset_backup_list_edit_index > -1) {
        return;
    }

    preset_backup_list_edit_index = preset_backup_list_page * PRESET_BACKUP_LIST_PRESETS_PER_PAGE + buttonIndex;

    str_switch(option)
    {
        str_case(OPTION_DELETE)
        {
            tPresetBackupInfo backup_info;
            if (!selected_preset_backup_info(&backup_info))
            {
                preset_backup_list_edit_index = -1;
                return;
            }
            lv_label_set_text(objects.ui_preset_backup_delete_dialog_name, backup_info.PresetName);
            lv_obj_clear_flag(objects.ui_preset_backup_delete_dialog, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void action_preset_backup_list_cancel(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_backup_list_cancel");

    lv_scr_load_anim(objects.presets, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_preset_backup_load_dialog_load(lv_event_t * e)
{
    lv_obj_add_flag(objects.ui_preset_backup_load_dialog, LV_OBJ_FLAG_HIDDEN);

    if (preset_backup_list_edit_index <= -1) {
        return;
    }
    if (preset_backup_list_load_preset_index <= -1) {
        return;
    }

    tScene *scene = scenes_get_current();
    if (scene == NULL || preset_backup_list_load_preset_index >= MAX_SUPPORTED_PRESETS)
    {
        ESP_LOGE(TAG, "Cannot resolve destination preset %d", preset_backup_list_load_preset_index);
        preset_backup_list_edit_index = -1;
        return;
    }
    uint8_t destination_preset = scene->PresetOrder[preset_backup_list_load_preset_index];

    uint16_t backup_slot;
    if (!preset_backup_get_slot(preset_backup_list_edit_index, &backup_slot))
    {
        ESP_LOGW(TAG, "Selected backup %d no longer exists", preset_backup_list_edit_index);
        preset_backup_list_edit_index = -1;
        updatePresetBackupList();
        return;
    }

    uint32_t transfer_id;
    esp_err_t err = preset_backup_load_to_tonex(backup_slot, destination_preset,
                                                false, &transfer_id);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to load backup %u into preset %u (%s)", backup_slot,
                 destination_preset, esp_err_to_name(err));
    }
    else
    {
        ESP_LOGI(TAG, "Loading backup %u into preset %u (transfer %" PRIu32 ")", backup_slot,
                 destination_preset, transfer_id);
    }
    preset_backup_list_edit_index = -1;
}

void action_preset_backup_load_dialog_cancel(lv_event_t * e)
{
    preset_backup_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_backup_load_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_preset_backup_delete_dialog_delete(lv_event_t * e)
{
    lv_obj_add_flag(objects.ui_preset_backup_delete_dialog, LV_OBJ_FLAG_HIDDEN);

    if (preset_backup_list_edit_index <= -1) {
        return;
    }

    uint16_t backup_slot;
    if (!preset_backup_get_slot(preset_backup_list_edit_index, &backup_slot))
    {
        ESP_LOGW(TAG, "Selected backup %d no longer exists", preset_backup_list_edit_index);
    }
    else
    {
        esp_err_t err = preset_backup_delete(backup_slot);
        if (err != ESP_OK)
        {
            ESP_LOGE(TAG, "Failed to delete backup %u (%s)", backup_slot, esp_err_to_name(err));
        }
        else
        {
            ESP_LOGI(TAG, "Deleted backup %u", backup_slot);
        }
    }

    preset_backup_list_edit_index = -1;
    updatePresetBackupList();
}

void action_preset_backup_delete_dialog_cancel(lv_event_t * e)
{
    preset_backup_list_edit_index = -1;
    lv_obj_add_flag(objects.ui_preset_backup_delete_dialog, LV_OBJ_FLAG_HIDDEN);
}
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
