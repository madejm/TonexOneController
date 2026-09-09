#include "display_custom_arc.h"
#include <math.h>
#include "screens.h"
#include "display_helpers.h"
#include "eq_canvas.h"
#include "tonex_params.h"
#include "control.h"
#include "actions.h"

#define CANVAS_ARC_DRAG_UPDATE_PERIOD_MS 750
#define CANVAS_ARC_IDLE_UPDATE_DELAY_MS  150
#define ARC_DOUBLE_TAP_PERIOD_MS          500

#define max(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a > _b ? _a : _b; })

#define min(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
       _a < _b ? _a : _b; })

#define clamp(mi,ma,val) \
    ({ __typeof__ (mi) _mi = (mi); \
       __typeof__ (ma) _ma = (ma); \
       __typeof__ (val) _val = (val); \
       _val < _mi ? _mi : (_val > _ma ? _ma : _val); })

typedef struct {
    lv_obj_t * root;
    lv_obj_t * arc;
    lv_obj_t * label;
    lv_obj_t * content;
    format_data_t format_data;
    format_cb_t format_cb;
    uint32_t last_canvas_update_tick;
    lv_timer_t * canvas_idle_timer;
    uint32_t last_tap_tick;
    bool tap_pending;
    bool tap_candidate;
} drag_data_t;

int16_t lv_custom_arc_get_value(lv_obj_t *arc)
{
    lv_obj_t *realArc = (lv_obj_t *)lv_obj_get_user_data(arc);

    if (realArc != NULL) {
        return lv_arc_get_value(realArc);
    } else {
        return 0;
    }
}

static format_data_t drag_data_get_format(drag_data_t *data)
{
    if (data->format_cb == NULL) {
        return data->format_data;
    } else {
        return data->format_cb(data->label);
    }
}

static void label_set_value(drag_data_t * data, int32_t value, bool notify_canvas)
{
    format_data_t format = drag_data_get_format(data);
    float result = ((float)value) / format.format.multiplier;
    char buf[20];
    sprintf(buf, format.format.format, result);
    lv_label_set_text(data->label, buf);

    UpdateCanvas update_canvas = format.update_canvas;
    if (notify_canvas && update_canvas != NULL) {
        update_canvas(result);
    }
}

static void canvas_idle_timer_cb(lv_timer_t * timer)
{
    drag_data_t * data = timer->user_data;

    lv_timer_pause(timer);
    data->last_canvas_update_tick = lv_tick_get();
    label_set_value(data, lv_arc_get_value(data->arc), true);
}

static int32_t arc_drag_accumulator = 0;
static bool arc_dragging = false;

typedef struct {
    lv_obj_t *parent;
    lv_align_t align;
    lv_coord_t x;
    lv_coord_t y;
} lv_obj_overlay_state_t;

static lv_obj_overlay_state_t overlayState;

static void move_to_top(lv_obj_t *obj)
{
    overlayState.parent = lv_obj_get_parent(obj);
    overlayState.x = lv_obj_get_x(obj);
    overlayState.y = lv_obj_get_y(obj);
    overlayState.align = lv_obj_get_style_align(obj, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_area_t area;
    lv_obj_get_coords(obj, &area);

    lv_obj_set_parent(obj, lv_layer_top());

    lv_obj_set_pos(obj, area.x1, area.y1 - 120);
    lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_move_foreground(obj);
}

static void restore_from_top(lv_obj_t *obj) {
    if (overlayState.parent == NULL) {
        return;
    }
    lv_obj_set_parent(obj, overlayState.parent);
    lv_obj_set_pos(obj, overlayState.x, overlayState.y);
    lv_obj_set_style_align(obj, overlayState.align, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(obj, 0, 0);
}

static void arc_pressed_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);
    data->tap_candidate = true;

    lv_obj_t * content = data->content;
    lv_obj_set_style_bg_opa(content, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    move_to_top(content);
}

static void arc_drag_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);
    lv_obj_t * arc = data->arc;

    lv_point_t v;
    lv_indev_get_vect(lv_indev_get_act(), &v);

    int32_t minValue = lv_arc_get_min_value(arc);
    int32_t maxValue = lv_arc_get_max_value(arc);
    int32_t range = maxValue - minValue;

    arc_drag_accumulator += v.x * range;
    arc_drag_accumulator -= v.y * range;

    int32_t delta = arc_drag_accumulator / 400;
    arc_drag_accumulator %= 400;

    if (delta) {
        uint32_t now = lv_tick_get();
        data->tap_candidate = false;
        data->tap_pending = false;

        if (!arc_dragging) {
            data->last_canvas_update_tick = now;
        }
        arc_dragging = true;

        int32_t rawValue = lv_arc_get_value(arc) + delta;
        // int32_t value = max(minValue, min(rawValue, maxValue));
        int32_t value = clamp(minValue, maxValue, rawValue);
        bool update_canvas = lv_tick_elaps(data->last_canvas_update_tick)
            >= CANVAS_ARC_DRAG_UPDATE_PERIOD_MS;

        if (update_canvas) {
            data->last_canvas_update_tick = now;
        }

        if (data->canvas_idle_timer != NULL) {
            lv_timer_reset(data->canvas_idle_timer);
            lv_timer_resume(data->canvas_idle_timer);
        }

        lv_arc_set_value(arc, value);
        label_set_value(data, value, update_canvas);
        // lv_event_send(data->root, LV_EVENT_VALUE_CHANGED, NULL);
    }
}

static void drag_released_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);

    arc_drag_accumulator = 0;
    arc_dragging = false;
    data->last_canvas_update_tick = 0;

    if (data->canvas_idle_timer != NULL) {
        lv_timer_pause(data->canvas_idle_timer);
    }

    /* Always send the final dragged value to the canvas. */
    label_set_value(data, lv_arc_get_value(data->arc), true);

    lv_obj_t * content = data->content;
    lv_obj_set_style_bg_opa(content, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    restore_from_top(content);

    lv_event_send(data->arc, LV_EVENT_RELEASED, NULL);
    lv_event_send(data->root, LV_EVENT_VALUE_CHANGED, NULL);
}

static void arc_double_tap_cb(lv_event_t * e)
{
    drag_data_t * data = lv_event_get_user_data(e);

    if (!data->tap_candidate) {
        return;
    }

    uint32_t now = lv_tick_get();
    if (!data->tap_pending || lv_tick_elaps(data->last_tap_tick) > ARC_DOUBLE_TAP_PERIOD_MS) {
        data->last_tap_tick = now;
        data->tap_pending = true;
        return;
    }

    data->tap_pending = false;

    format_data_t format = drag_data_get_format(data);
    int16_t value = (int16_t)(format.defaultValue * format.format.multiplier);

    lv_arc_set_value(data->arc, value);
    label_set_value(data, value, true);
    lv_event_send(data->root, LV_EVENT_VALUE_CHANGED, NULL);
}

static void drag_delete_cb(lv_event_t *e)
{
    drag_data_t *data = lv_event_get_user_data(e);

    if (data->canvas_idle_timer != NULL) {
        lv_timer_del(data->canvas_idle_timer);
        data->canvas_idle_timer = NULL;
    }

    lv_mem_free(data);
}

static void add_arc_callbacks(
    lv_obj_t *drag,
    drag_data_t *data
) {
    lv_obj_add_event_cb(data->root, action_parameter_changed, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_add_event_cb(drag, arc_pressed_cb, LV_EVENT_PRESSED, data);
    lv_obj_add_event_cb(drag, arc_drag_cb, LV_EVENT_PRESSING, data);
    lv_obj_add_event_cb(drag, drag_delete_cb, LV_EVENT_DELETE, data);
    lv_obj_add_event_cb(drag, arc_double_tap_cb, LV_EVENT_SHORT_CLICKED, data);
    lv_obj_add_event_cb(drag, drag_released_cb, LV_EVENT_RELEASED, data);
}

static void update_unit(
    lv_obj_t *unitLabel,
    const char *unit
) {
    if (unit == NULL) {
        lv_obj_add_flag(unitLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_label_set_text(unitLabel, unit);
    }
}

void setup_arc_elements(
    lv_obj_t *root,
    lv_obj_t *arc,
    lv_obj_t *label,
    lv_obj_t *unitLabel,
    lv_obj_t *drag,
    lv_obj_t *content,
    TonexParamFormat_t format,
    const char *unit,
    float defaultValue,
    UpdateCanvas update_canvas
) {
    lv_obj_set_user_data(root, arc);

    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->root = root;
    data->arc = arc;
    data->label = label;
    data->content = content;

    data->format_data.format = format;
    data->format_data.defaultValue = defaultValue;
    data->format_data.update_canvas = update_canvas;
    data->format_cb = NULL;
    data->last_canvas_update_tick = 0;
    data->canvas_idle_timer = NULL;
    data->last_tap_tick = 0;
    data->tap_pending = false;
    data->tap_candidate = false;

    if (update_canvas != NULL) {
        data->canvas_idle_timer = lv_timer_create(
            canvas_idle_timer_cb,
            CANVAS_ARC_IDLE_UPDATE_DELAY_MS,
            data
        );
        if (data->canvas_idle_timer != NULL) {
            lv_timer_pause(data->canvas_idle_timer);
        }
    }
    
    update_unit(unitLabel, unit);
    add_arc_callbacks(drag, data);
}

void setup_arc_elements_format_cb(
    lv_obj_t *root,
    lv_obj_t *arc,
    lv_obj_t *label,
    lv_obj_t *unitLabel,
    lv_obj_t *drag,
    lv_obj_t *content,
    format_cb_t format_cb
) {
    lv_obj_set_user_data(root, arc);

    drag_data_t *data = lv_mem_alloc(sizeof(drag_data_t));
    data->root = root;
    data->arc = arc;
    data->label = label;
    data->content = content;

    data->format_data.update_canvas = NULL;
    data->format_cb = format_cb;
    data->last_canvas_update_tick = 0;
    data->canvas_idle_timer = NULL;
    data->last_tap_tick = 0;
    data->tap_pending = false;
    data->tap_candidate = false;

    update_unit(unitLabel, "");
    add_arc_callbacks(drag, data);
}