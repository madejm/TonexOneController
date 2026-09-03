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
#include "wifi_config.h"
#include "tonex_params.h"

// static const char *TAG = "app_display_scenes";

static int16_t updatingScene = -1;

static void updateSceneElementName(
    uint8_t index,
    char *name
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
    uint8_t index
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

    lv_dropdown_set_options(obj, "Rename\nDelete");
}

// static void updateScenesListSelected()
// {
//     uint8_t scenesCount = control_get_scenes_count();
//     uint8_t selectedScene = control_get_selected_scene();

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
    uint8_t scenesCount = control_get_scenes_count();
    uint8_t selectedScene = control_get_selected_scene();

    for (uint8_t index = 0; index < 20; index++)
    {
        bool visible = index < scenesCount;
        updateSceneElementVisible(index, visible);
        populateSceneElementOptions(index);

        if (visible) {
            updateSceneElementSelected(index, index == selectedScene);
            
            tScene *scene = control_get_scene(index);
            if (scene != NULL) {
                updateSceneElementName(index, scene->Name);
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
    if (control_create_scene())
    {
        control_select_scene(control_get_scenes_count() - 1);
        control_save_user_data(false);

        updateScenesList();
    }
}

void selectScene(uint8_t index)
{
    control_select_scene(index);
    control_refresh_preset_order();

    updatePresetListSelection();
    updatePresetListColors();
    updatePresetListNames();

    control_save_user_data(false);
    
    action_open_presets_page(NULL);
}

void sceneOptionsSelected(uint8_t index, uint16_t option)
{
    uint8_t scenesCount = control_get_scenes_count();

    if (index >= scenesCount) {
        return;
    }
    if (updatingScene > -1) {
        return;
    }
    tScene *scene = control_get_scene(index);

    if (scene == NULL) {
        return;
    }

    switch (option) {
        case 0: {
            updatingScene = index;

            const char *name = scene->Name;
            lv_textarea_set_text(objects.ui_scene_rename_dialog_textarea, name);
            lv_obj_add_state(objects.ui_scene_rename_dialog_textarea, LV_STATE_FOCUSED);

            if (strlen(name) == 0) {
                lv_keyboard_set_mode(objects.ui_scene_rename_dialog_keyboard, LV_KEYBOARD_MODE_TEXT_UPPER);
            } else {
                lv_keyboard_set_mode(objects.ui_scene_rename_dialog_keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            
            lv_obj_clear_flag(objects.ui_scene_rename_dialog, LV_OBJ_FLAG_HIDDEN);
        } break;

        case 1: {
            if (scenesCount <= 1) {
                return;
            }
            updatingScene = index;
            
            const char *name = scene->Name;
            lv_label_set_text(objects.ui_scene_delete_dialog_name, name);
            lv_obj_clear_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
        } break;
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
        control_set_scene_name(updatingScene, name);
        control_save_user_data(false);

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
        control_delete_scene(updatingScene);
        control_save_user_data(false);

        updateScenesList();
    }

    updatingScene = -1;
    lv_obj_add_flag(objects.ui_scene_delete_dialog, LV_OBJ_FLAG_HIDDEN);
}