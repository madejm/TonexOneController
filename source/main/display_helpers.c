
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#include "screens.h"
#include "display_helpers.h"

static int32_t arc_drag_accumulator = 0;
static void arc_drag_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_user_data(e);

    if(lv_event_get_code(e) == LV_EVENT_PRESSED) {
        arc_drag_accumulator = 0;
        return;
    }

    lv_point_t v;
    lv_indev_get_vect(lv_indev_get_act(), &v);

    int32_t min = lv_arc_get_min_value(arc);
    int32_t max = lv_arc_get_max_value(arc);
    int32_t range = max - min;

    arc_drag_accumulator += v.x * range;
    arc_drag_accumulator -= v.y * range;

    int32_t delta = arc_drag_accumulator / 400;
    arc_drag_accumulator %= 400;

    if(delta) {
        lv_arc_set_value(arc, lv_arc_get_value(arc) + delta);
        lv_event_send(arc, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void drag_released_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_user_data(e);

    lv_event_send(arc, LV_EVENT_RELEASED, NULL);
}

void lv_helper_create_arc_gesture(lv_obj_t *arc)
{
    lv_obj_t * parent = lv_obj_get_parent(arc);

    /* Remember position in parent's child list */
    uint32_t index = lv_obj_get_index(arc);

    /* Remember arc geometry */
    lv_coord_t x = lv_obj_get_x(arc);
    lv_coord_t y = lv_obj_get_y(arc);
    lv_coord_t w = lv_obj_get_width(arc);
    lv_coord_t h = lv_obj_get_height(arc);

    /* Create wrapper in same flex container */
    lv_obj_t * drag = lv_obj_create(parent);

    /* Put wrapper exactly where arc was in child order */
    lv_obj_move_to_index(drag, index);

    /* Wrapper now participates in flex instead of arc */
    lv_obj_set_pos(drag, x, y);
    lv_obj_set_size(drag, w, h);

    lv_obj_set_style_pad_all(drag, 0, 0);
    lv_obj_set_style_border_width(drag, 0, 0);
    lv_obj_set_style_bg_opa(drag, LV_OPA_TRANSP, 0);

    /* Move arc into wrapper */
    lv_obj_set_parent(arc, drag);

    lv_obj_set_pos(arc, 0, 0);
    lv_obj_set_size(arc, LV_PCT(100), LV_PCT(100));

    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSED, arc);
    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSING, arc);
    lv_obj_add_event_cb(drag, drag_released_cb, LV_EVENT_RELEASED, arc);
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui() {
    lv_helper_create_arc_gesture(objects.ui_amplifier_depth_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_bass_freq_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_bass_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_freq_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_qarc);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_freq_arc);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_arc);
    lv_helper_create_arc_gesture(objects.ui_amplifier_presense_arc);
}
#endif