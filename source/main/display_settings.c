#include "display_settings.h"
#include "esp_log.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
#endif
#include "display_helpers.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "usb_tonex.h"
#include "control.h"
#include "wifi_config.h"
#include "tonex_params.h"

void action_settings_copy_gate(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_GATE);
}
void action_settings_copy_compressor(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_COMPRESSOR);
}
void action_settings_copy_amp(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_AMP);
}
void action_settings_copy_eq(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_EQ);
}
void action_settings_copy_modulation(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_MODULATION);
}
void action_settings_copy_delay(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_DELAY);
}
void action_settings_copy_reverb(lv_event_t * e)
{
    usb_copy_settings(CLIPBOARD_REVERB);
}

void action_settings_paste(lv_event_t * e)
{ 
    usb_paste_settings();
}

void updateSettingsClipboard(Clipboard_t type)
{
    lv_obj_set_disabled(objects.ui_settings_paste_gate, type != CLIPBOARD_GATE);
    lv_obj_set_disabled(objects.ui_settings_paste_compressor, type != CLIPBOARD_COMPRESSOR);
    lv_obj_set_disabled(objects.ui_settings_paste_amp, type != CLIPBOARD_AMP);
    lv_obj_set_disabled(objects.ui_settings_paste_eq, type != CLIPBOARD_EQ);
    lv_obj_set_disabled(objects.ui_settings_paste_modulation, type != CLIPBOARD_MODULATION);
    lv_obj_set_disabled(objects.ui_settings_paste_delay, type != CLIPBOARD_DELAY);
    lv_obj_set_disabled(objects.ui_settings_paste_reverb, type != CLIPBOARD_REVERB);
}
