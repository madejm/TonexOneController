#ifndef _DISPLAY_SCENES_H
#define _DISPLAY_SCENES_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

void selectScene(uint8_t index);
void sceneOptionsSelected(uint8_t index, const char *option);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif