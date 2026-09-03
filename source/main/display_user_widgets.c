#include "display_user_widgets.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
#endif
#include "display_helpers.h"
#include "display.h"
#include "display_preset_list.h"
#include "display_scenes.h"

void action_preset_button(lv_event_t * e)
{
    lv_obj_t *button = lv_event_get_target(e);
    if      (button == objects.ui_preset_list_element_0__button) { selectPresetListPreset(0); }
    else if (button == objects.ui_preset_list_element_1__button) { selectPresetListPreset(1); }
    else if (button == objects.ui_preset_list_element_2__button) { selectPresetListPreset(2); }
    else if (button == objects.ui_preset_list_element_3__button) { selectPresetListPreset(3); }
    else if (button == objects.ui_preset_list_element_4__button) { selectPresetListPreset(4); }
    else if (button == objects.ui_preset_list_element_5__button) { selectPresetListPreset(5); }
    else if (button == objects.ui_preset_list_element_6__button) { selectPresetListPreset(6); }
    else if (button == objects.ui_preset_list_element_7__button) { selectPresetListPreset(7); }
    else if (button == objects.ui_preset_list_element_8__button) { selectPresetListPreset(8); }
    else if (button == objects.ui_preset_list_element_9__button) { selectPresetListPreset(9); }

    else if (button == objects.ui_scene_list_element_0__button)  { selectScene(0); }
    else if (button == objects.ui_scene_list_element_1__button)  { selectScene(1); }
    else if (button == objects.ui_scene_list_element_2__button)  { selectScene(2); }
    else if (button == objects.ui_scene_list_element_3__button)  { selectScene(3); }
    else if (button == objects.ui_scene_list_element_4__button)  { selectScene(4); }
    else if (button == objects.ui_scene_list_element_5__button)  { selectScene(5); }
    else if (button == objects.ui_scene_list_element_6__button)  { selectScene(6); }
    else if (button == objects.ui_scene_list_element_7__button)  { selectScene(7); }
    else if (button == objects.ui_scene_list_element_8__button)  { selectScene(8); }
    else if (button == objects.ui_scene_list_element_9__button)  { selectScene(9); }
    else if (button == objects.ui_scene_list_element_10__button) { selectScene(10); }
    else if (button == objects.ui_scene_list_element_11__button) { selectScene(11); }
    else if (button == objects.ui_scene_list_element_12__button) { selectScene(12); }
    else if (button == objects.ui_scene_list_element_13__button) { selectScene(13); }
    else if (button == objects.ui_scene_list_element_14__button) { selectScene(14); }
    else if (button == objects.ui_scene_list_element_15__button) { selectScene(15); }
    else if (button == objects.ui_scene_list_element_16__button) { selectScene(16); }
    else if (button == objects.ui_scene_list_element_17__button) { selectScene(17); }
    else if (button == objects.ui_scene_list_element_18__button) { selectScene(18); }
    else if (button == objects.ui_scene_list_element_19__button) { selectScene(19); }
    
    else {
        return;
    }
}

void action_preset_button_options(lv_event_t * e)
{
    lv_obj_t *dropdown = lv_event_get_target(e);
    uint16_t option = lv_dropdown_get_selected(dropdown);
    if      (dropdown == objects.ui_preset_list_element_0__options) { presetOptionsSelected(0, option); }
    else if (dropdown == objects.ui_preset_list_element_1__options) { presetOptionsSelected(1, option); }
    else if (dropdown == objects.ui_preset_list_element_2__options) { presetOptionsSelected(2, option); }
    else if (dropdown == objects.ui_preset_list_element_3__options) { presetOptionsSelected(3, option); }
    else if (dropdown == objects.ui_preset_list_element_4__options) { presetOptionsSelected(4, option); }
    else if (dropdown == objects.ui_preset_list_element_5__options) { presetOptionsSelected(5, option); }
    else if (dropdown == objects.ui_preset_list_element_6__options) { presetOptionsSelected(6, option); }
    else if (dropdown == objects.ui_preset_list_element_7__options) { presetOptionsSelected(7, option); }
    else if (dropdown == objects.ui_preset_list_element_8__options) { presetOptionsSelected(8, option); }
    else if (dropdown == objects.ui_preset_list_element_9__options) { presetOptionsSelected(9, option); }

    else if (dropdown == objects.ui_scene_list_element_0__options)  { sceneOptionsSelected(0, option); }
    else if (dropdown == objects.ui_scene_list_element_1__options)  { sceneOptionsSelected(1, option); }
    else if (dropdown == objects.ui_scene_list_element_2__options)  { sceneOptionsSelected(2, option); }
    else if (dropdown == objects.ui_scene_list_element_3__options)  { sceneOptionsSelected(3, option); }
    else if (dropdown == objects.ui_scene_list_element_4__options)  { sceneOptionsSelected(4, option); }
    else if (dropdown == objects.ui_scene_list_element_5__options)  { sceneOptionsSelected(5, option); }
    else if (dropdown == objects.ui_scene_list_element_6__options)  { sceneOptionsSelected(6, option); }
    else if (dropdown == objects.ui_scene_list_element_7__options)  { sceneOptionsSelected(7, option); }
    else if (dropdown == objects.ui_scene_list_element_8__options)  { sceneOptionsSelected(8, option); }
    else if (dropdown == objects.ui_scene_list_element_9__options)  { sceneOptionsSelected(9, option); }
    else if (dropdown == objects.ui_scene_list_element_10__options) { sceneOptionsSelected(10, option); }
    else if (dropdown == objects.ui_scene_list_element_11__options) { sceneOptionsSelected(11, option); }
    else if (dropdown == objects.ui_scene_list_element_12__options) { sceneOptionsSelected(12, option); }
    else if (dropdown == objects.ui_scene_list_element_13__options) { sceneOptionsSelected(13, option); }
    else if (dropdown == objects.ui_scene_list_element_14__options) { sceneOptionsSelected(14, option); }
    else if (dropdown == objects.ui_scene_list_element_15__options) { sceneOptionsSelected(15, option); }
    else if (dropdown == objects.ui_scene_list_element_16__options) { sceneOptionsSelected(16, option); }
    else if (dropdown == objects.ui_scene_list_element_17__options) { sceneOptionsSelected(17, option); }
    else if (dropdown == objects.ui_scene_list_element_18__options) { sceneOptionsSelected(18, option); }
    else if (dropdown == objects.ui_scene_list_element_19__options) { sceneOptionsSelected(19, option); }

    else {
        return;
    }
}
