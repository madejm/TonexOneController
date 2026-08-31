#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_next;
extern const lv_img_dsc_t img_next_down;
extern const lv_img_dsc_t img_previous;
extern const lv_img_dsc_t img_previous_down;
extern const lv_img_dsc_t img_eq;
extern const lv_img_dsc_t img_cab;
extern const lv_img_dsc_t img_amp;
extern const lv_img_dsc_t img_comp;
extern const lv_img_dsc_t img_gate;
extern const lv_img_dsc_t img_mod_chorus;
extern const lv_img_dsc_t img_mod_phaser;
extern const lv_img_dsc_t img_mod_flanger;
extern const lv_img_dsc_t img_mod_tremolo;
extern const lv_img_dsc_t img_mod_rotary;
extern const lv_img_dsc_t img_reverb_room;
extern const lv_img_dsc_t img_delay_tape;
extern const lv_img_dsc_t img_delay_digital;
extern const lv_img_dsc_t img_reverb_spring_4;
extern const lv_img_dsc_t img_reverb_spring_3;
extern const lv_img_dsc_t img_reverb_spring_2;
extern const lv_img_dsc_t img_reverb_spring_1;
extern const lv_img_dsc_t img_reverb_plate;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[22];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/