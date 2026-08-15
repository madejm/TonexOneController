#include "images.h"

const ext_img_desc_t images[14] = {
    { "next", &img_next },
    { "next_down", &img_next_down },
    { "previous", &img_previous },
    { "previous_down", &img_previous_down },
    { "tick", &img_tick },
    { "amp", &img_amp },
    { "reverb", &img_reverb },
    { "comp", &img_comp },
    { "cab", &img_cab },
    { "eq", &img_eq },
    { "mod", &img_mod },
    { "delay", &img_delay },
    { "gate", &img_gate },
    { "settings", &img_settings },
};