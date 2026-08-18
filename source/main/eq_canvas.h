#ifndef _EQ_CANVAS_H
#define _EQ_CANVAS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Attach a pixel buffer to ui_eq_canvas and draw its initial response. */
void eq_canvas_setup(void);

/* Gains use the TONEX 0...10 control range (5 is 0 dB). */
void eq_canvas_update_presence_gain(float value);
void eq_canvas_update_depth_gain(float value);
void eq_canvas_update_mid_gain(float value);
void eq_canvas_update_mid_q(float value);
void eq_canvas_update_mid_frequency(float value);
void eq_canvas_update_treble_gain(float value);
void eq_canvas_update_treble_frequency(float value);
void eq_canvas_update_bass_gain(float value);
void eq_canvas_update_bass_frequency(float value);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
