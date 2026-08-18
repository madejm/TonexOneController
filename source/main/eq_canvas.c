#include "eq_canvas.h"

#include <math.h>
#include <stddef.h>

#include "sdkconfig.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#include "lvgl.h"
#include "ui.h"

#define EQ_MIN_FREQUENCY                 20.0f
#define EQ_MAX_FREQUENCY              20000.0f
#define EQ_MIN_DISPLAY_DB                -9.0f
#define EQ_MAX_DISPLAY_DB                 9.0f
#define EQ_GAIN_MIN_DB                    -6.0f
#define EQ_GAIN_MAX_DB                     6.0f
#define EQ_DEPTH_FREQUENCY                80.0f
#define EQ_DEPTH_Q                         0.6f
#define EQ_BASS_Q                          1.0f
#define EQ_TREBLE_Q                        1.0f
#define EQ_SHELF_HALF_OCTAVES_AT_Q1        0.38f
#define EQ_PRESENCE_START_FREQUENCY      100.0f
#define EQ_PRESENCE_MID_FREQUENCY       2000.0f
#define EQ_PRESENCE_END_FREQUENCY      20000.0f
#define EQ_PRESENCE_MID_GAIN_FRACTION      0.5f

#define EQ_CURVE_SAMPLE_COUNT               64
#define EQ_REDRAW_PERIOD_MS                300

static void *canvas_buffer;
static lv_point_t *curve_points;
static lv_coord_t canvas_width;
static lv_coord_t canvas_height;
static bool redraw_pending;

static struct {
    float presence_gain;
    float depth_gain;
    float mid_gain;
    float mid_q;
    float mid_frequency;
    float treble_gain;
    float treble_frequency;
    float bass_gain;
    float bass_frequency;
} parameters = {
    .presence_gain = 5.0f,
    .depth_gain = 5.0f,
    .mid_gain = 5.0f,
    .mid_q = 0.7f,
    .mid_frequency = 750.0f,
    .treble_gain = 5.0f,
    .treble_frequency = 2000.0f,
    .bass_gain = 5.0f,
    .bass_frequency = 300.0f
};

static void redraw(void);

static bool canvas_is_visible(void)
{
    if (objects.settings == NULL
        || objects.ui_settings_tab_view == NULL
        || objects.ui_eq_tab == NULL
        || lv_scr_act() != objects.settings) {
        return false;
    }

    lv_obj_t *tab_content = lv_tabview_get_content(objects.ui_settings_tab_view);
    uint16_t active_tab = lv_tabview_get_tab_act(objects.ui_settings_tab_view);

    return lv_obj_get_child(tab_content, active_tab) == objects.ui_eq_tab
        && lv_obj_is_visible(objects.ui_eq_tab);
}

static void redraw_timer_cb(lv_timer_t *timer)
{
    LV_UNUSED(timer);

    if (!redraw_pending || !canvas_is_visible()) {
        return;
    }

    redraw_pending = false;
    redraw();
}

static void request_redraw(void)
{
    redraw_pending = true;
}

static float clampf(float value, float lower, float upper)
{
    return fminf(fmaxf(value, lower), upper);
}

static float control_to_db(float value)
{
    float fraction = clampf(value, 0.0f, 10.0f) / 10.0f;
    return EQ_GAIN_MIN_DB + fraction * (EQ_GAIN_MAX_DB - EQ_GAIN_MIN_DB);
}

static float bell_half_bandwidth_octaves(float q)
{
    float clamped_q = clampf(q, 0.2f, 3.0f);
    return clampf(0.62f / sqrtf(clamped_q), 0.28f, 1.65f);
}

static float bell_response(float frequency, float center, float q, float gain_db)
{
    float octaves_from_center = log2f(fmaxf(frequency, 1.0f) / fmaxf(center, 1.0f));
    float width = fmaxf(0.16f, bell_half_bandwidth_octaves(q) / sqrtf(2.0f * logf(2.0f)));
    float normalized = octaves_from_center / width;
    float weight = expf(-0.5f * normalized * normalized);
    return gain_db * weight;
}

static float shelf_response(float frequency, float cutoff, float q, float gain_db, bool inverted)
{
    float clamped_q = fmaxf(0.05f, q);
    float half_octaves = clampf(EQ_SHELF_HALF_OCTAVES_AT_Q1 / sqrtf(clamped_q), 0.18f, 1.10f);
    float slope = logf(4.0f) / half_octaves;
    float octaves_from_cutoff = log2f(fmaxf(frequency, 1.0f) / fmaxf(cutoff, 1.0f));
    float rising = 1.0f / (1.0f + expf(-slope * octaves_from_cutoff));
    return gain_db * (inverted ? 1.0f - rising : rising);
}

static float cubic_hermite(
    float value,
    float start,
    float end,
    float start_slope,
    float end_slope,
    float interval
)
{
    float t = clampf(value, 0.0f, 1.0f);
    float t2 = t * t;
    float t3 = t2 * t;
    return (2.0f * t3 - 3.0f * t2 + 1.0f) * start
        + (t3 - 2.0f * t2 + t) * interval * start_slope
        + (-2.0f * t3 + 3.0f * t2) * end
        + (t3 - t2) * interval * end_slope;
}

static float presence_response(float frequency, float gain_db)
{
    float start = log10f(EQ_PRESENCE_START_FREQUENCY);
    float middle = log10f(EQ_PRESENCE_MID_FREQUENCY);
    float end = log10f(EQ_PRESENCE_END_FREQUENCY);
    float position = clampf((log10f(fmaxf(frequency, 1.0f)) - start) / (end - start), 0.0f, 1.0f);
    float middle_position = clampf((middle - start) / (end - start), 0.05f, 0.95f);
    float lower_slope = EQ_PRESENCE_MID_GAIN_FRACTION / middle_position;
    float upper_slope = (1.0f - EQ_PRESENCE_MID_GAIN_FRACTION) / (1.0f - middle_position);
    float middle_slope = (lower_slope + upper_slope) * 0.5f;

    if (position <= middle_position) {
        return gain_db * cubic_hermite(
            position / middle_position,
            0.0f,
            EQ_PRESENCE_MID_GAIN_FRACTION,
            0.0f,
            middle_slope,
            middle_position
        );
    }

    float upper_interval = 1.0f - middle_position;
    return gain_db * cubic_hermite(
        (position - middle_position) / upper_interval,
        EQ_PRESENCE_MID_GAIN_FRACTION,
        1.0f,
        middle_slope,
        0.0f,
        upper_interval
    );
}

static float frequency_for_fraction(float fraction)
{
    float min_log = log10f(EQ_MIN_FREQUENCY);
    float max_log = log10f(EQ_MAX_FREQUENCY);
    return powf(10.0f, min_log + clampf(fraction, 0.0f, 1.0f) * (max_log - min_log));
}

static lv_coord_t x_for_frequency(float frequency, lv_coord_t plot_x, lv_coord_t plot_width)
{
    float fraction = (log10f(clampf(frequency, EQ_MIN_FREQUENCY, EQ_MAX_FREQUENCY))
        - log10f(EQ_MIN_FREQUENCY))
        / (log10f(EQ_MAX_FREQUENCY) - log10f(EQ_MIN_FREQUENCY));
    return plot_x + (lv_coord_t)lroundf(fraction * (float)(plot_width - 1));
}

static lv_coord_t y_for_db(float db, lv_coord_t plot_y, lv_coord_t plot_height)
{
    float clamped_db = clampf(db, EQ_MIN_DISPLAY_DB, EQ_MAX_DISPLAY_DB);
    float fraction = (EQ_MAX_DISPLAY_DB - clamped_db) / (EQ_MAX_DISPLAY_DB - EQ_MIN_DISPLAY_DB);
    return plot_y + (lv_coord_t)lroundf(fraction * (float)(plot_height - 1));
}

static void draw_grid(lv_coord_t plot_x, lv_coord_t plot_y, lv_coord_t plot_width, lv_coord_t plot_height)
{
    static const float grid_frequencies[] = {
        20.0f, 50.0f, 100.0f, 200.0f, 500.0f,
        1000.0f, 2000.0f, 5000.0f, 10000.0f, 20000.0f
    };
    static const float grid_db[] = {-6.0f, -3.0f, 0.0f, 3.0f, 6.0f};
    lv_draw_line_dsc_t line;
    lv_point_t points[2];

    lv_draw_line_dsc_init(&line);
    line.color = lv_obj_get_style_line_color(objects.ui_eq_canvas, LV_PART_MAIN);
    line.opa = lv_obj_get_style_line_opa(objects.ui_eq_canvas, LV_PART_MAIN);
    line.width = lv_obj_get_style_line_width(objects.ui_eq_canvas, LV_PART_MAIN);

    for (size_t i = 0; i < sizeof(grid_frequencies) / sizeof(grid_frequencies[0]); ++i) {
        lv_coord_t x = x_for_frequency(grid_frequencies[i], plot_x, plot_width);
        points[0] = (lv_point_t){x, plot_y};
        points[1] = (lv_point_t){x, plot_y + plot_height - 1};
        lv_canvas_draw_line(objects.ui_eq_canvas, points, 2, &line);
    }

    for (size_t i = 0; i < sizeof(grid_db) / sizeof(grid_db[0]); ++i) {
        lv_coord_t y = y_for_db(grid_db[i], plot_y, plot_height);
        points[0] = (lv_point_t){plot_x, y};
        points[1] = (lv_point_t){plot_x + plot_width - 1, y};
        lv_canvas_draw_line(objects.ui_eq_canvas, points, 2, &line);
    }
}

void eq_canvas_setup(void)
{
    if (objects.ui_eq_canvas == NULL || canvas_buffer != NULL) {
        return;
    }

    lv_obj_update_layout(objects.ui_eq_canvas);
    canvas_width = lv_obj_get_width(objects.ui_eq_canvas);
    canvas_height = lv_obj_get_height(objects.ui_eq_canvas);

    lv_coord_t horizontal_padding = lv_obj_get_style_pad_left(objects.ui_eq_canvas, LV_PART_MAIN)
        + lv_obj_get_style_pad_right(objects.ui_eq_canvas, LV_PART_MAIN);
    lv_coord_t vertical_padding = lv_obj_get_style_pad_top(objects.ui_eq_canvas, LV_PART_MAIN)
        + lv_obj_get_style_pad_bottom(objects.ui_eq_canvas, LV_PART_MAIN);

    if (canvas_width <= horizontal_padding || canvas_height <= vertical_padding) {
        return;
    }

    canvas_buffer = lv_mem_alloc(LV_CANVAS_BUF_SIZE_TRUE_COLOR_ALPHA(canvas_width, canvas_height));
    curve_points = lv_mem_alloc(EQ_CURVE_SAMPLE_COUNT * sizeof(*curve_points));
    if (canvas_buffer == NULL || curve_points == NULL) {
        if (canvas_buffer != NULL) {
            lv_mem_free(canvas_buffer);
            canvas_buffer = NULL;
        }
        if (curve_points != NULL) {
            lv_mem_free(curve_points);
            curve_points = NULL;
        }
        return;
    }

    lv_canvas_set_buffer(
        objects.ui_eq_canvas,
        canvas_buffer,
        canvas_width,
        canvas_height,
        LV_IMG_CF_TRUE_COLOR_ALPHA
    );
    request_redraw();
    lv_timer_create(redraw_timer_cb, EQ_REDRAW_PERIOD_MS, NULL);
}

static void redraw(void)
{
    if (canvas_buffer == NULL || curve_points == NULL || objects.ui_eq_canvas == NULL) {
        return;
    }

    lv_coord_t plot_x = lv_obj_get_style_pad_left(objects.ui_eq_canvas, LV_PART_MAIN);
    lv_coord_t plot_y = lv_obj_get_style_pad_top(objects.ui_eq_canvas, LV_PART_MAIN);
    lv_coord_t plot_width = canvas_width - plot_x
        - lv_obj_get_style_pad_right(objects.ui_eq_canvas, LV_PART_MAIN);
    lv_coord_t plot_height = canvas_height - plot_y
        - lv_obj_get_style_pad_bottom(objects.ui_eq_canvas, LV_PART_MAIN);

    if (plot_width <= 1 || plot_height <= 1) {
        return;
    }

    lv_canvas_fill_bg(objects.ui_eq_canvas, lv_color_black(), LV_OPA_TRANSP);
    draw_grid(plot_x, plot_y, plot_width, plot_height);

    float presence_db = control_to_db(parameters.presence_gain);
    float depth_db = control_to_db(parameters.depth_gain);
    float mid_db = control_to_db(parameters.mid_gain);
    float treble_db = control_to_db(parameters.treble_gain);
    float bass_db = control_to_db(parameters.bass_gain);
    float clamped_mid_q = clampf(parameters.mid_q, 0.2f, 3.0f);
    float clamped_mid_frequency = clampf(parameters.mid_frequency, 150.0f, 5000.0f);
    float clamped_treble_frequency = clampf(parameters.treble_frequency, 1000.0f, 4000.0f);
    float clamped_bass_frequency = clampf(parameters.bass_frequency, 75.0f, 600.0f);

    uint32_t point_count = plot_width < EQ_CURVE_SAMPLE_COUNT
        ? (uint32_t)plot_width
        : EQ_CURVE_SAMPLE_COUNT;

    for (uint32_t index = 0; index < point_count; ++index) {
        float fraction = point_count > 1 ? (float)index / (float)(point_count - 1) : 0.0f;
        float frequency = frequency_for_fraction(fraction);
        float response_db = bell_response(frequency, EQ_DEPTH_FREQUENCY, EQ_DEPTH_Q, depth_db)
            + shelf_response(frequency, clamped_bass_frequency, EQ_BASS_Q, bass_db, true)
            + bell_response(frequency, clamped_mid_frequency, clamped_mid_q, mid_db)
            + shelf_response(frequency, clamped_treble_frequency, EQ_TREBLE_Q, treble_db, false)
            + presence_response(frequency, presence_db);

        lv_coord_t x = plot_x + (lv_coord_t)lroundf(fraction * (float)(plot_width - 1));
        curve_points[index] = (lv_point_t){x, y_for_db(response_db, plot_y, plot_height)};
    }

    lv_draw_line_dsc_t curve;
    lv_draw_line_dsc_init(&curve);
    curve.color = lv_obj_get_style_arc_color(objects.ui_eq_canvas, LV_PART_MAIN);
    curve.opa = lv_obj_get_style_arc_opa(objects.ui_eq_canvas, LV_PART_MAIN);
    curve.width = lv_obj_get_style_arc_width(objects.ui_eq_canvas, LV_PART_MAIN);
    curve.round_end = false;
    curve.round_start = false;
    lv_canvas_draw_line(objects.ui_eq_canvas, curve_points, point_count, &curve);
}

void eq_canvas_update_presence_gain(float value)
{
    if (parameters.presence_gain == value) {
        return;
    }
    parameters.presence_gain = value;
    request_redraw();
}

void eq_canvas_update_depth_gain(float value)
{
    if (parameters.depth_gain == value) {
        return;
    }
    parameters.depth_gain = value;
    request_redraw();
}

void eq_canvas_update_mid_gain(float value)
{
    if (parameters.mid_gain == value) {
        return;
    }
    parameters.mid_gain = value;
    request_redraw();
}

void eq_canvas_update_mid_q(float value)
{
    if (parameters.mid_q == value) {
        return;
    }
    parameters.mid_q = value;
    request_redraw();
}

void eq_canvas_update_mid_frequency(float value)
{
    if (parameters.mid_frequency == value) {
        return;
    }
    parameters.mid_frequency = value;
    request_redraw();
}

void eq_canvas_update_treble_gain(float value)
{
    if (parameters.treble_gain == value) {
        return;
    }
    parameters.treble_gain = value;
    request_redraw();
}

void eq_canvas_update_treble_frequency(float value)
{
    if (parameters.treble_frequency == value) {
        return;
    }
    parameters.treble_frequency = value;
    request_redraw();
}

void eq_canvas_update_bass_gain(float value)
{
    if (parameters.bass_gain == value) {
        return;
    }
    parameters.bass_gain = value;
    request_redraw();
}

void eq_canvas_update_bass_frequency(float value)
{
    if (parameters.bass_frequency == value) {
        return;
    }
    parameters.bass_frequency = value;
    request_redraw();
}

#else

void eq_canvas_setup(void)
{
}

#define EQ_CANVAS_EMPTY_UPDATE_FUNCTION(function_name) \
    void function_name(float value)                     \
    {                                                   \
        (void)value;                                    \
    }

EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_presence_gain)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_depth_gain)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_mid_gain)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_mid_q)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_mid_frequency)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_treble_gain)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_treble_frequency)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_bass_gain)
EQ_CANVAS_EMPTY_UPDATE_FUNCTION(eq_canvas_update_bass_frequency)

#undef EQ_CANVAS_EMPTY_UPDATE_FUNCTION

#endif
