#ifndef _DISPLAY_TAP_TEMPO_H
#define _DISPLAY_TAP_TEMPO_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "usb_comms.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
void display_tap_tempo_set_bpm(float bpm);
void display_tap_tempo_set_beat_period(uint32_t period_ms);
bool display_tap_tempo_is_open(void);
void display_tap_tempo_footswitch_tapped(void);
void display_tap_tempo_footswitch_changed(float bpm);
void display_tap_tempo_cancel_auto_hide(void);
void display_tap_tempo_set_footswitch_pressed(bool pressed);
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
