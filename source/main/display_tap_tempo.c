#include "display_tap_tempo.h"
#include <stdio.h>
#include "esp_log.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
    #include "styles.h"
#endif

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
static const char *TAG = "display_tap_tempo";

#define TAP_TEMPO_AUTO_HIDE_MS 5000

static lv_timer_t *indicator_timer;
static lv_timer_t *auto_hide_timer;
static float current_bpm = 120.0f;
static uint8_t current_indicator;
static bool auto_hide_active;
static volatile bool dialog_open;

static uint32_t tap_tempo_period_ms(void)
{
    if (current_bpm <= 0.0f) {
        return 500;
    }

    return (uint32_t)(60000.0f / current_bpm);
}

static void set_indicator(uint8_t indicator)
{
    lv_obj_t *indicators[] = {
        objects.ui_tap_tempo_dialog_indicator1,
        objects.ui_tap_tempo_dialog_indicator2,
        objects.ui_tap_tempo_dialog_indicator3,
        objects.ui_tap_tempo_dialog_indicator4,
    };

    for (uint8_t i = 0; i < 4; i++) {
        lv_obj_clear_state(indicators[i], LV_STATE_CHECKED);
    }

    lv_obj_add_state(indicators[indicator], LV_STATE_CHECKED);
}

static void indicator_timer_cb(lv_timer_t *timer)
{
    (void)timer;
    current_indicator = (current_indicator + 1) % 4;
    set_indicator(current_indicator);
}

static void stop_indicator_animation(void)
{
    if (indicator_timer != NULL) {
        lv_timer_del(indicator_timer);
        indicator_timer = NULL;
    }
}

static void start_indicator_animation(void)
{
    stop_indicator_animation();
    current_indicator = 0;
    set_indicator(current_indicator);
    indicator_timer = lv_timer_create(indicator_timer_cb, tap_tempo_period_ms(), NULL);
}

static void auto_hide_timer_cb(lv_timer_t *timer)
{
    lv_timer_del(timer);
    auto_hide_timer = NULL;
    auto_hide_active = false;
    dialog_open = false;
    stop_indicator_animation();
    lv_obj_add_flag(objects.ui_tap_tempo_dialog, LV_OBJ_FLAG_HIDDEN);
}

bool display_tap_tempo_is_open(void)
{
    return dialog_open;
}

void display_tap_tempo_set_bpm(float bpm)
{
    if (bpm <= 0.0f) {
        return;
    }

    current_bpm = bpm;

    char bpm_text[8];
    snprintf(bpm_text, sizeof(bpm_text), "%.0f", bpm);
    lv_label_set_text(objects.ui_tap_tempo_dialog_bpm, bpm_text);

    // Changing the timer period retains its phase; it does not restart the animation.
    if (indicator_timer != NULL) {
        lv_timer_set_period(indicator_timer, tap_tempo_period_ms());
    }
}

void display_tap_tempo_cancel_auto_hide(void)
{
    auto_hide_active = false;

    if (auto_hide_timer != NULL) {
        lv_timer_del(auto_hide_timer);
        auto_hide_timer = NULL;
    }
}

void display_tap_tempo_set_footswitch_pressed(bool pressed)
{
    if (pressed) {
        lv_obj_add_state(objects.ui_tap_tempo_dialog_tap_button, LV_STATE_PRESSED);
    } else {
        lv_obj_clear_state(objects.ui_tap_tempo_dialog_tap_button, LV_STATE_PRESSED);
    }
}

void display_tap_tempo_footswitch_tapped(void)
{
    if (lv_obj_has_flag(objects.ui_tap_tempo_dialog, LV_OBJ_FLAG_HIDDEN)) {
        lv_obj_clear_flag(objects.ui_tap_tempo_dialog, LV_OBJ_FLAG_HIDDEN);
        start_indicator_animation();
        auto_hide_active = true;
        dialog_open = true;
    }

    if (auto_hide_active) {
        if (auto_hide_timer == NULL) {
            auto_hide_timer = lv_timer_create(auto_hide_timer_cb, TAP_TEMPO_AUTO_HIDE_MS, NULL);
        } else {
            lv_timer_reset(auto_hide_timer);
        }
    }
}

void display_tap_tempo_footswitch_changed(float bpm)
{
    display_tap_tempo_set_bpm(bpm);
    display_tap_tempo_footswitch_tapped();
}

// ACTIONS

void action_tap_tempo_open(lv_event_t * e)
{
    (void)e;
    display_tap_tempo_cancel_auto_hide();
    lv_obj_clear_flag(objects.ui_tap_tempo_dialog, LV_OBJ_FLAG_HIDDEN);
    start_indicator_animation();
    dialog_open = true;
}

void action_tap_tempo_close(lv_event_t *e)
{
    (void)e;
    display_tap_tempo_cancel_auto_hide();
    stop_indicator_animation();
    lv_obj_add_flag(objects.ui_tap_tempo_dialog, LV_OBJ_FLAG_HIDDEN);
    dialog_open = false;
}

#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
