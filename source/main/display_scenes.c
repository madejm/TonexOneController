#include "display_scenes.h"
#include "esp_log.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
#endif
#include "display_helpers.h"
#include "display.h"
#include "display_preset_list.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "usb_tonex.h"
#include "control.h"
#include "scenes.h"
#include "wifi_config.h"
#include "tonex_params.h"

// static const char *TAG = "app_display_scenes";

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#define OPTION_RENAME "Rename"
#define OPTION_DELETE "Delete"

static int16_t updatingScene = -1;

static void updateSceneElementName(
    uint8_t index,
    const char *name
) {
    lv_obj_t *obj;
    switch (index) {
        case 0:  obj = objects.ui_scene_list_element_0__label;  break;
        case 1:  obj = objects.ui_scene_list_element_1__label;  break;
        case 2:  obj = objects.ui_scene_list_element_2__label;  break;
        case 3:  obj = objects.ui_scene_list_element_3__label;  break;
        case 4:  obj = objects.ui_scene_list_element_4__label;  break;
        case 5:  obj = objects.ui_scene_list_element_5__label;  break;
        case 6:  obj = objects.ui_scene_list_element_6__label;  break;
        case 7:  obj = objects.ui_scene_list_element_7__label;  break;
        case 8:  obj = objects.ui_scene_list_element_8__label;  break;
        case 9:  obj = objects.ui_scene_list_element_9__label;  break;
        case 10: obj = objects.ui_scene_list_element_10__label; break;
        case 11: obj = objects.ui_scene_list_element_11__label; break;
        case 12: obj = objects.ui_scene_list_element_12__label; break;
        case 13: obj = objects.ui_scene_list_element_13__label; break;
        case 14: obj = objects.ui_scene_list_element_14__label; break;
        case 15: obj = objects.ui_scene_list_element_15__label; break;
        case 16: obj = objects.ui_scene_list_element_16__label; break;
        case 17: obj = objects.ui_scene_list_element_17__label; break;
        case 18: obj = objects.ui_scene_list_element_18__label; break;
        case 19: obj = objects.ui_scene_list_element_19__label; break;
        default: return;
    }

    lv_label_set_text(obj, name);
}

static void updateSceneElementSelected(
    uint8_t index,
    bool selected
) {
    lv_obj_t *obj;
    switch (index) {
        case 0:  obj = objects.ui_scene_list_element_0__button; break;
        case 1:  obj = objects.ui_scene_list_element_1__button; break;
        case 2:  obj = objects.ui_scene_list_element_2__button; break;
        case 3:  obj = objects.ui_scene_list_element_3__button; break;
        case 4:  obj = objects.ui_scene_list_element_4__button; break;
        case 5:  obj = objects.ui_scene_list_element_5__button; break;
        case 6:  obj = objects.ui_scene_list_element_6__button; break;
        case 7:  obj = objects.ui_scene_list_element_7__button; break;
        case 8:  obj = objects.ui_scene_list_element_8__button; break;
        case 9:  obj = objects.ui_scene_list_element_9__button; break;
        case 10: obj = objects.ui_scene_list_element_10__button; break;
        case 11: obj = objects.ui_scene_list_element_11__button; break;
        case 12: obj = objects.ui_scene_list_element_12__button; break;
        case 13: obj = objects.ui_scene_list_element_13__button; break;
        case 14: obj = objects.ui_scene_list_element_14__button; break;
        case 15: obj = objects.ui_scene_list_element_15__button; break;
        case 16: obj = objects.ui_scene_list_element_16__button; break;
        case 17: obj = objects.ui_scene_list_element_17__button; break;
        case 18: obj = objects.ui_scene_list_element_18__button; break;
        case 19: obj = objects.ui_scene_list_element_19__button; break;
        default: return;
    }

    lv_obj_set_checked(obj, selected);
}

static void updateSceneElementVisible(
    uint8_t index,
    bool visible
) {
    lv_obj_t *obj;
    switch (index) {
        case 0:  obj = objects.ui_scene_list_element_0;  break;
        case 1:  obj = objects.ui_scene_list_element_1;  break;
        case 2:  obj = objects.ui_scene_list_element_2;  break;
        case 3:  obj = objects.ui_scene_list_element_3;  break;
        case 4:  obj = objects.ui_scene_list_element_4;  break;
        case 5:  obj = objects.ui_scene_list_element_5;  break;
        case 6:  obj = objects.ui_scene_list_element_6;  break;
        case 7:  obj = objects.ui_scene_list_element_7;  break;
        case 8:  obj = objects.ui_scene_list_element_8;  break;
        case 9:  obj = objects.ui_scene_list_element_9;  break;
        case 10: obj = objects.ui_scene_list_element_10; break;
        case 11: obj = objects.ui_scene_list_element_11; break;
        case 12: obj = objects.ui_scene_list_element_12; break;
        case 13: obj = objects.ui_scene_list_element_13; break;
        case 14: obj = objects.ui_scene_list_element_14; break;
        case 15: obj = objects.ui_scene_list_element_15; break;
        case 16: obj = objects.ui_scene_list_element_16; break;
        case 17: obj = objects.ui_scene_list_element_17; break;
        case 18: obj = objects.ui_scene_list_element_18; break;
        case 19: obj = objects.ui_scene_list_element_19; break;
        default: return;
    }

    if (visible) {
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
    }
}

static void populateSceneElementOptions(
    uint8_t index,
    uint8_t scenesCount
) {
    lv_obj_t *obj;
    switch (index) {
        case 0:  obj = objects.ui_scene_list_element_0__options;  break;
        case 1:  obj = objects.ui_scene_list_element_1__options;  break;
        case 2:  obj = objects.ui_scene_list_element_2__options;  break;
        case 3:  obj = objects.ui_scene_list_element_3__options;  break;
        case 4:  obj = objects.ui_scene_list_element_4__options;  break;
        case 5:  obj = objects.ui_scene_list_element_5__options;  break;
        case 6:  obj = objects.ui_scene_list_element_6__options;  break;
        case 7:  obj = objects.ui_scene_list_element_7__options;  break;
        case 8:  obj = objects.ui_scene_list_element_8__options;  break;
        case 9:  obj = objects.ui_scene_list_element_9__options;  break;
        case 10: obj = objects.ui_scene_list_element_10__options; break;
        case 11: obj = objects.ui_scene_list_element_11__options; break;
        case 12: obj = objects.ui_scene_list_element_12__options; break;
        case 13: obj = objects.ui_scene_list_element_13__options; break;
        case 14: obj = objects.ui_scene_list_element_14__options; break;
        case 15: obj = objects.ui_scene_list_element_15__options; break;
        case 16: obj = objects.ui_scene_list_element_16__options; break;
        case 17: obj = objects.ui_scene_list_element_17__options; break;
        case 18: obj = objects.ui_scene_list_element_18__options; break;
        case 19: obj = objects.ui_scene_list_element_19__options; break;
        default: return;
    }

    if (scenesCount > 1) {
        lv_dropdown_set_options(obj, OPTION_RENAME "\n" OPTION_DELETE);
    } else {
        lv_dropdown_set_options(obj, OPTION_RENAME);
    }
}

// static void updateScenesListSelected()
// {
//     uint8_t scenesCount = scenes_get_count();
//     uint8_t selectedScene = scenes_get_selected();

//     for (uint8_t index = 0; index < MAX_SCENES; index++)
//     {
//         bool visible = index < scenesCount;

//         if (visible) {
//             updateSceneElementSelected(index, index == selectedScene);
//         }
//     }
// }

static void updateScenesList()
{
    uint8_t scenesCount = scenes_get_count();
    uint8_t selectedScene = scenes_get_selected();

    for (uint8_t index = 0; index < 20; index++)
    {
        bool visible = index < scenesCount;
        updateSceneElementVisible(index, visible);
        populateSceneElementOptions(index, scenesCount);

        if (visible) {
            updateSceneElementSelected(index, index == selectedScene);
            
            const char *name = scenes_get_name(index);
            if (name != NULL) {
                updateSceneElementName(index, name);
            }
        }
    }

    lv_obj_set_disabled(objects.ui_new_scene_button, scenesCount == MAX_SCENES);
}

void action_open_scenes_page(lv_event_t * e)
{
    updatingScene = -1;

    updateScenesList();

    lv_obj_add_flag(objects.ui_scene_rename_dialog, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
    lv_scr_load_anim(objects.scenes, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_close_scenes_page(lv_event_t *e)
{
    lv_scr_load_anim(objects.presets, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void action_new_scene(lv_event_t *e)
{
    if (scenes_create())
    {
        updateScenesList();
    }
}

void selectScene(uint8_t index)
{
    scenes_select(index);
    control_refresh_preset_order();

    // updatePresetListSelection();
    // updatePresetListColors();
    // updatePresetListNames();

    scenes_save();

    bool syncPresets = lv_obj_has_state(objects.ui_scenes_sync_presets_switch, LV_STATE_CHECKED);

    if (syncPresets && usb_get_connected_modeller_type() == AMP_MODELLER_TONEX_ONE)
    {
        usb_sync_scene_presets();
    }
    
    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

void sceneOptionsSelected(uint8_t index, const char *option)
{
    uint8_t scenesCount = scenes_get_count();

    if (index >= scenesCount) {
        return;
    }
    if (updatingScene > -1) {
        return;
    }
    const char *name = scenes_get_name(index);

    if (name == NULL) {
        return;
    }
    
    str_switch(option)
    {
        str_case(OPTION_RENAME)
        {
            updatingScene = index;

            lv_textarea_set_text(objects.ui_scene_rename_dialog_textarea, name);
            lv_obj_add_state(objects.ui_scene_rename_dialog_textarea, LV_STATE_FOCUSED);

            if (strlen(name) == 0) {
                lv_keyboard_set_mode(objects.ui_scene_rename_dialog_keyboard, LV_KEYBOARD_MODE_TEXT_UPPER);
            } else {
                lv_keyboard_set_mode(objects.ui_scene_rename_dialog_keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            
            lv_obj_clear_flag(objects.ui_scene_rename_dialog, LV_OBJ_FLAG_HIDDEN);
        }
        
        str_case(OPTION_DELETE)
        {
            if (scenesCount <= 1) {
                return;
            }
            updatingScene = index;
            
            lv_label_set_text(objects.ui_scene_delete_dialog_name, name);
            lv_obj_clear_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
        }
    }
}

void action_scene_rename_dialog_close(lv_event_t * e)
{
    updatingScene = -1;
    lv_obj_add_flag(objects.ui_scene_rename_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_scene_rename_dialog_keyboard_ok(lv_event_t * e)
{
    if (updatingScene > -1) {
        char *name = (char *)lv_textarea_get_text(objects.ui_scene_rename_dialog_textarea);
        scenes_set_name(updatingScene, name);
        scenes_save();

        updateSceneElementName(updatingScene, name);
    }

    updatingScene = -1;
    lv_obj_add_flag(objects.ui_scene_rename_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_scene_delete_dialog_cancel(lv_event_t *e) {
    updatingScene = -1;
    lv_obj_add_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_scene_delete_dialog_delete(lv_event_t *e) {
    if (updatingScene > -1) {
        bool deleting_selected_scene = updatingScene == scenes_get_selected();
        uint8_t scenes_count = scenes_get_count();
        scenes_delete(updatingScene);

        if (deleting_selected_scene && scenes_get_count() < scenes_count)
        {
            selectScene(0);
        }
        else
        {
            updateScenesList();
        }
    }

    updatingScene = -1;
    lv_obj_add_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
}
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM