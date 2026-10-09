#include "display_tap_tempo.h"
#include <stdio.h>
#include "control.h"
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

static lv_anim_t *beat_animation;
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

static void beat_animation_cb(void *obj, int32_t value)
{
    (void)obj;
    uint8_t indicator = (uint32_t)value / 256;
    if (dialog_open && indicator != current_indicator) {
        current_indicator = indicator;
        set_indicator(current_indicator);
    }
#if CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR
    if (control_get_config_item_int(CONFIG_ITEM_DISABLE_BPM_FLASHER) != 0) {
        lv_obj_clear_state(objects.ui_bpm_indicator, LV_STATE_CHECKED);
        lv_obj_add_flag(objects.ui_bpm_indicator, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_clear_flag(objects.ui_bpm_indicator, LV_OBJ_FLAG_HIDDEN);
        if (((uint32_t)value % 256) < 128) {
            lv_obj_add_state(objects.ui_bpm_indicator, LV_STATE_CHECKED);
        } else {
            lv_obj_clear_state(objects.ui_bpm_indicator, LV_STATE_CHECKED);
        }
    }
#endif
}

static void stop_indicator_animation(void)
{
    // The shared clock keeps the main indicator running while the dialog is hidden.
}

void display_tap_tempo_set_beat_period(uint32_t period_ms)
{
    if (period_ms == 0) return;
    uint32_t duration = period_ms * 4;
    if (beat_animation != NULL) {
        if (beat_animation->time != duration) {
            beat_animation->act_time = (int32_t)(
                (int64_t)beat_animation->act_time * duration / beat_animation->time);
            lv_anim_set_time(beat_animation, duration);
        }
        return;
    }
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, &current_indicator);
    lv_anim_set_exec_cb(&anim, beat_animation_cb);
    lv_anim_set_values(&anim, 0, 1023);
    lv_anim_set_time(&anim, duration);
    lv_anim_set_path_cb(&anim, lv_anim_path_linear);
    lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE);
    beat_animation = lv_anim_start(&anim);
}

static void start_indicator_animation(void)
{
    display_tap_tempo_set_beat_period(tap_tempo_period_ms());
    current_indicator = beat_animation != NULL ? (uint32_t)beat_animation->current_value / 256 : 0;
    set_indicator(current_indicator);
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

    display_tap_tempo_set_beat_period(tap_tempo_period_ms());
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
