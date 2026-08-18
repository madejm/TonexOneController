
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#include "screens.h"
#include "display_helpers.h"
#include "eq_canvas.h"

typedef struct {
    lv_obj_t * arc;
    lv_obj_t * label;
    const char *format;
    float multiplier;
    float defaultValue;
} drag_data_t;

static void label_set_value(drag_data_t * data, int32_t value)
{
    char buf[20];
    sprintf(buf, data->format, ((float)value) / data->multiplier);
    lv_label_set_text(data->label, buf);
}

static int32_t arc_drag_accumulator = 0;
static void arc_drag_cb(lv_event_t * e)
{
    if(lv_event_get_code(e) == LV_EVENT_PRESSED) {
        arc_drag_accumulator = 0;
        return;
    }

    drag_data_t * data = lv_event_get_user_data(e);
    lv_obj_t * arc = data->arc;

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
        int32_t value = lv_arc_get_value(arc) + delta;
        lv_arc_set_value(arc, value);
        label_set_value(data, value);
        lv_event_send(arc, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void drag_released_cb(lv_event_t * e)
{
    lv_obj_t * arc = lv_event_get_user_data(e);

    lv_event_send(arc, LV_EVENT_RELEASED, NULL);
}

static void arc_reset_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);

    lv_arc_set_value(data->arc, (int16_t)(data->defaultValue * data->multiplier));
    label_set_value(data,       (int16_t)(data->defaultValue * data->multiplier));
    lv_event_send(data->arc, LV_EVENT_VALUE_CHANGED, NULL);
}

static void drag_delete_cb(lv_event_t *e)
{
    drag_data_t *data = lv_event_get_user_data(e);
    lv_mem_free(data);
}

static void lv_helper_create_arc_gesture(
    lv_obj_t *arc,
    lv_obj_t *label,
    const char *format,
    float multiplier,
    float defaultValue
) {
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

    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->arc = arc;
    data->label = label;
    data->format = format;
    data->multiplier = multiplier;
    data->defaultValue = defaultValue;

    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSED, data);
    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSING, data);
    lv_obj_add_event_cb(drag, drag_delete_cb, LV_EVENT_DELETE, data);
    lv_obj_add_event_cb(drag, arc_reset_cb, LV_EVENT_LONG_PRESSED, data);
    lv_obj_add_event_cb(drag, drag_released_cb, LV_EVENT_RELEASED, arc);
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
void customize_ui() {
    lv_helper_create_arc_gesture(objects.ui_noise_gate_threshold_slider, objects.ui_noise_gate_threshold_value, "%1.0f", 1.0f, -100);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_release_slider,   objects.ui_noise_gate_release_value,   "%1.0f", 1.0f, 20);
    lv_helper_create_arc_gesture(objects.ui_noise_gate_depth_slider,     objects.ui_noise_gate_depth_value,     "%1.0f", 1.0f, 60);

    lv_helper_create_arc_gesture(objects.ui_compressor_threshold_slider, objects.ui_compressor_threshold_value, "%1.1f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_compressor_gain_slider,      objects.ui_compressor_gain_value,      "%1.0f", 1.0f, -8);
    lv_helper_create_arc_gesture(objects.ui_compressor_attack_slider,    objects.ui_compressor_attack_value,    "%1.0f", 1.0f, 5);

    lv_helper_create_arc_gesture(objects.ui_amplifier_gain_slider,       objects.ui_amplifier_gain_value,       "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_volume_slider,     objects.ui_amplifier_volume_value,     "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_depth_slider,      objects.ui_amplifier_depth_value,      "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_amplifier_presense_slider,   objects.ui_amplifier_presense_value,   "%1.1f", 10.0f, 5);

    lv_helper_create_arc_gesture(objects.ui_eq_bass_freq_slider,         objects.ui_eq_bass_freq_value,         "%1.0f", 1.0f,  300);
    lv_helper_create_arc_gesture(objects.ui_eq_bass_slider,              objects.ui_eq_bass_value,              "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_freq_slider,          objects.ui_eq_mid_freq_value,          "%1.0f", 1.0f,  750);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_qslider,              objects.ui_eq_mid_qvalue,              "%1.1f", 10.0f, 0.7);
    lv_helper_create_arc_gesture(objects.ui_eq_mid_slider,               objects.ui_eq_mid_value,               "%1.1f", 10.0f, 5);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_freq_slider,       objects.ui_eq_treble_freq_value,       "%1.0f", 1.0f,  2000);
    lv_helper_create_arc_gesture(objects.ui_eq_treble_slider,            objects.ui_eq_treble_value,            "%1.1f", 10.0f, 5);

    lv_helper_create_arc_gesture(objects.ui_bpm_slider,                  objects.ui_bpm_value,                  "%1.0f", 1.0f, 120);
    lv_helper_create_arc_gesture(objects.ui_input_trim_slider,           objects.ui_input_trim_value,           "%1.0f", 1.0f, 0);
    lv_helper_create_arc_gesture(objects.ui_tuning_reference_slider,     objects.ui_tuning_reference_value,     "%1.0f", 1.0f, 440);
    lv_helper_create_arc_gesture(objects.ui_volume_slider,               objects.ui_volume_value,               "%1.0f", 1.0f, 5);

    eq_canvas_setup();
}
#endif