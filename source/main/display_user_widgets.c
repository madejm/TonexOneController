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
#include "display_preset_buttons.h"

#define ptr_switch(x)   const void *_p=x; if (0)
#define ptr_case(y)     } else if (_p == y) {
#define ptr_default     } else {

void action_preset_button(lv_event_t * e)
{
    lv_obj_t *button = lv_event_get_target(e);
    bool longPress = e->code == LV_EVENT_LONG_PRESSED;

    ptr_switch(button) {
        ptr_case(objects.ui_preset_button_1__button) { display_preset_buttons_clicked(0, longPress); }
        ptr_case(objects.ui_preset_button_2__button) { display_preset_buttons_clicked(1, longPress); }
        ptr_case(objects.ui_preset_button_3__button) { display_preset_buttons_clicked(2, longPress); }
        ptr_case(objects.ui_preset_button_4__button) { display_preset_buttons_clicked(3, longPress); }
        ptr_case(objects.ui_preset_button_5__button) { display_preset_buttons_clicked(4, longPress); }
        ptr_case(objects.ui_preset_button_6__button) { display_preset_buttons_clicked(5, longPress); }
        ptr_case(objects.ui_preset_button_7__button) { display_preset_buttons_clicked(6, longPress); }
        ptr_case(objects.ui_preset_button_8__button) { display_preset_buttons_clicked(7, longPress); }
    }
}

void action_preset_list_button(lv_event_t * e)
{
    lv_obj_t *button = lv_event_get_target(e);
    ptr_switch(button) {
        ptr_case(objects.ui_preset_list_element_0__button) { selectPresetListPreset(0); }
        ptr_case(objects.ui_preset_list_element_1__button) { selectPresetListPreset(1); }
        ptr_case(objects.ui_preset_list_element_2__button) { selectPresetListPreset(2); }
        ptr_case(objects.ui_preset_list_element_3__button) { selectPresetListPreset(3); }
        ptr_case(objects.ui_preset_list_element_4__button) { selectPresetListPreset(4); }
        ptr_case(objects.ui_preset_list_element_5__button) { selectPresetListPreset(5); }
        ptr_case(objects.ui_preset_list_element_6__button) { selectPresetListPreset(6); }
        ptr_case(objects.ui_preset_list_element_7__button) { selectPresetListPreset(7); }
        ptr_case(objects.ui_preset_list_element_8__button) { selectPresetListPreset(8); }
        ptr_case(objects.ui_preset_list_element_9__button) { selectPresetListPreset(9); }

        ptr_case(objects.ui_scene_list_element_0__button)  { selectScene(0); }
        ptr_case(objects.ui_scene_list_element_1__button)  { selectScene(1); }
        ptr_case(objects.ui_scene_list_element_2__button)  { selectScene(2); }
        ptr_case(objects.ui_scene_list_element_3__button)  { selectScene(3); }
        ptr_case(objects.ui_scene_list_element_4__button)  { selectScene(4); }
        ptr_case(objects.ui_scene_list_element_5__button)  { selectScene(5); }
        ptr_case(objects.ui_scene_list_element_6__button)  { selectScene(6); }
        ptr_case(objects.ui_scene_list_element_7__button)  { selectScene(7); }
        ptr_case(objects.ui_scene_list_element_8__button)  { selectScene(8); }
        ptr_case(objects.ui_scene_list_element_9__button)  { selectScene(9); }
        ptr_case(objects.ui_scene_list_element_10__button) { selectScene(10); }
        ptr_case(objects.ui_scene_list_element_11__button) { selectScene(11); }
        ptr_case(objects.ui_scene_list_element_12__button) { selectScene(12); }
        ptr_case(objects.ui_scene_list_element_13__button) { selectScene(13); }
        ptr_case(objects.ui_scene_list_element_14__button) { selectScene(14); }
        ptr_case(objects.ui_scene_list_element_15__button) { selectScene(15); }
        ptr_case(objects.ui_scene_list_element_16__button) { selectScene(16); }
        ptr_case(objects.ui_scene_list_element_17__button) { selectScene(17); }
        ptr_case(objects.ui_scene_list_element_18__button) { selectScene(18); }
        ptr_case(objects.ui_scene_list_element_19__button) { selectScene(19); }
    }
}

void action_preset_list_button_options(lv_event_t * e)
{
    lv_obj_t *dropdown = lv_event_get_target(e);
    char option[64];
    lv_dropdown_get_selected_str(dropdown, option, sizeof(option));

    ptr_switch(dropdown) {
        ptr_case(objects.ui_preset_list_element_0__options) { presetOptionsSelected(0, option); }
        ptr_case(objects.ui_preset_list_element_1__options) { presetOptionsSelected(1, option); }
        ptr_case(objects.ui_preset_list_element_2__options) { presetOptionsSelected(2, option); }
        ptr_case(objects.ui_preset_list_element_3__options) { presetOptionsSelected(3, option); }
        ptr_case(objects.ui_preset_list_element_4__options) { presetOptionsSelected(4, option); }
        ptr_case(objects.ui_preset_list_element_5__options) { presetOptionsSelected(5, option); }
        ptr_case(objects.ui_preset_list_element_6__options) { presetOptionsSelected(6, option); }
        ptr_case(objects.ui_preset_list_element_7__options) { presetOptionsSelected(7, option); }
        ptr_case(objects.ui_preset_list_element_8__options) { presetOptionsSelected(8, option); }
        ptr_case(objects.ui_preset_list_element_9__options) { presetOptionsSelected(9, option); }

        ptr_case(objects.ui_scene_list_element_0__options)  { sceneOptionsSelected(0, option); }
        ptr_case(objects.ui_scene_list_element_1__options)  { sceneOptionsSelected(1, option); }
        ptr_case(objects.ui_scene_list_element_2__options)  { sceneOptionsSelected(2, option); }
        ptr_case(objects.ui_scene_list_element_3__options)  { sceneOptionsSelected(3, option); }
        ptr_case(objects.ui_scene_list_element_4__options)  { sceneOptionsSelected(4, option); }
        ptr_case(objects.ui_scene_list_element_5__options)  { sceneOptionsSelected(5, option); }
        ptr_case(objects.ui_scene_list_element_6__options)  { sceneOptionsSelected(6, option); }
        ptr_case(objects.ui_scene_list_element_7__options)  { sceneOptionsSelected(7, option); }
        ptr_case(objects.ui_scene_list_element_8__options)  { sceneOptionsSelected(8, option); }
        ptr_case(objects.ui_scene_list_element_9__options)  { sceneOptionsSelected(9, option); }
        ptr_case(objects.ui_scene_list_element_10__options) { sceneOptionsSelected(10, option); }
        ptr_case(objects.ui_scene_list_element_11__options) { sceneOptionsSelected(11, option); }
        ptr_case(objects.ui_scene_list_element_12__options) { sceneOptionsSelected(12, option); }
        ptr_case(objects.ui_scene_list_element_13__options) { sceneOptionsSelected(13, option); }
        ptr_case(objects.ui_scene_list_element_14__options) { sceneOptionsSelected(14, option); }
        ptr_case(objects.ui_scene_list_element_15__options) { sceneOptionsSelected(15, option); }
        ptr_case(objects.ui_scene_list_element_16__options) { sceneOptionsSelected(16, option); }
        ptr_case(objects.ui_scene_list_element_17__options) { sceneOptionsSelected(17, option); }
        ptr_case(objects.ui_scene_list_element_18__options) { sceneOptionsSelected(18, option); }
        ptr_case(objects.ui_scene_list_element_19__options) { sceneOptionsSelected(19, option); }
    }
}

void action_preset_list_button_options_released(lv_event_t * e)
{
    lv_obj_t *dropdown = lv_event_get_target(e);
    if (!lv_dropdown_is_open(dropdown)) {
        return;
    }

    lv_obj_t *list = lv_dropdown_get_list(dropdown);
    lv_obj_update_layout(list);

    lv_area_t bounds;
    lv_obj_get_coords(list, &bounds);

    lv_coord_t screen_width = lv_disp_get_hor_res(lv_obj_get_disp(dropdown));

    lv_coord_t shift = 0;
    if (bounds.x2 >= screen_width) {
        shift = screen_width - 1 - bounds.x2;
    }
    if (bounds.x1 + shift < 0) {
        shift = -bounds.x1;
    }

    if (shift != 0) {
        lv_obj_set_x(list, lv_obj_get_x(list) + shift);
    }
}