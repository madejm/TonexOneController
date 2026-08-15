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
extern const lv_img_dsc_t img_tick;
extern const lv_img_dsc_t img_amp;
extern const lv_img_dsc_t img_reverb;
extern const lv_img_dsc_t img_comp;
extern const lv_img_dsc_t img_cab;
extern const lv_img_dsc_t img_eq;
extern const lv_img_dsc_t img_mod;
extern const lv_img_dsc_t img_delay;
extern const lv_img_dsc_t img_gate;
extern const lv_img_dsc_t img_settings;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[14];

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/