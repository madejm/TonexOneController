#include "display_settings.h"
#include "esp_log.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
    #include "styles.h"
#endif
#include "display_helpers.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "usb_tonex.h"
#include "control.h"
#include "wifi_config.h"
#include "tonex_params.h"
#include "display.h"
#include "nvs_flash.h"
#include "esp_log.h"

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
static const char *TAG = "display_settings";

#define THEME_STORAGE   "theme_storage"
#define THEME_ID_KEY    "theme_id"

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
void action_settings_copy_cab(lv_event_t *e)
{
    usb_copy_settings(CLIPBOARD_CAB);
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

void action_usb_host_changed(lv_event_t * e)
{
    bool usbHost = lv_obj_has_state(objects.ui_usb_host_switch, LV_STATE_CHECKED);

    if (usbHost)
    {
        remove_style_button_selectable_red(objects.ui_usb_button);
        add_style_button_selectable_yellow(objects.ui_usb_button);
    }
    else
    {
        remove_style_button_selectable_yellow(objects.ui_usb_button);
        add_style_button_selectable_red(objects.ui_usb_button);
    }

    usb_set_host_enabled(usbHost);
}

void updateSettingsClipboard(Clipboard_t type)
{
    lv_obj_set_disabled(objects.ui_settings_paste_gate, type != CLIPBOARD_GATE);
    lv_obj_set_disabled(objects.ui_settings_paste_compressor, type != CLIPBOARD_COMPRESSOR);
    lv_obj_set_disabled(objects.ui_settings_paste_amp, type != CLIPBOARD_AMP);
    lv_obj_set_disabled(objects.ui_settings_paste_cab, type != CLIPBOARD_CAB);
    lv_obj_set_disabled(objects.ui_settings_paste_eq, type != CLIPBOARD_EQ);
    lv_obj_set_disabled(objects.ui_settings_paste_modulation, type != CLIPBOARD_MODULATION);
    lv_obj_set_disabled(objects.ui_settings_paste_delay, type != CLIPBOARD_DELAY);
    lv_obj_set_disabled(objects.ui_settings_paste_reverb, type != CLIPBOARD_REVERB);
}

lv_color_t eq_color_depth() {
    return lv_color_hex(theme_colors[active_theme_index][COLOR_ID_MODULATION]);
}

lv_color_t eq_color_bass() {
    return lv_color_hex(theme_colors[active_theme_index][COLOR_ID_CABINET]);
}

lv_color_t eq_color_mid() {
    return lv_color_hex(theme_colors[active_theme_index][COLOR_ID_DELAY]);
}

lv_color_t eq_color_treble() {
    return lv_color_hex(theme_colors[active_theme_index][COLOR_ID_REVERB]);
}

lv_color_t eq_color_presence() {
    return lv_color_hex(theme_colors[active_theme_index][COLOR_ID_NOISE_GATE]);
}

void updateEQColors()
{
    lv_obj_set_style_arc_color(objects.ui_amplifier_depth_slider__arc,    eq_color_depth(),    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_bass_freq_slider__arc,       eq_color_bass(),     LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_bass_slider__arc,            eq_color_bass(),     LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_mid_freq_slider__arc,        eq_color_mid(),      LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_mid_qslider__arc,            eq_color_mid(),      LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_mid_slider__arc,             eq_color_mid(),      LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_treble_freq_slider__arc,     eq_color_treble(),   LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_eq_treble_slider__arc,          eq_color_treble(),   LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(objects.ui_amplifier_presense_slider__arc, eq_color_presence(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
}

typedef enum {
    EQ_TAB_DEPTH,
    EQ_TAB_BASS,
    EQ_TAB_MID,
    EQ_TAB_TREBLE,
    EQ_TAB_PRESENCE
} EQTabs_t;

#define RECOLOR_TAB_BTN(dsc, col) \
    { \
        dsc->rect_dsc->bg_color = lv_color_darken(col, 191); \
        dsc->rect_dsc->border_color = col; \
        dsc->label_dsc->color = col; \
    }

static void tab_btn_draw_cb(lv_event_t *e)
{
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_draw_part_dsc(e);

    if(dsc->part != LV_PART_ITEMS) {
        return;
    }
    if(!(dsc->draw_area && dsc->rect_dsc)) {
        return;
    }

    lv_obj_t *btns = lv_event_get_target(e);

    if(!lv_btnmatrix_has_btn_ctrl(
        btns,
        dsc->id,
        LV_BTNMATRIX_CTRL_CHECKED
    )) {
        return;
    }

    switch(dsc->id) {
        case EQ_TAB_DEPTH:
            RECOLOR_TAB_BTN(dsc, eq_color_depth());
            break;
        case EQ_TAB_BASS:
            RECOLOR_TAB_BTN(dsc, eq_color_bass());
            break;
        case EQ_TAB_MID:
            RECOLOR_TAB_BTN(dsc, eq_color_mid());
            break;
        case EQ_TAB_TREBLE:
            RECOLOR_TAB_BTN(dsc, eq_color_treble());
            break;
        case EQ_TAB_PRESENCE:
            RECOLOR_TAB_BTN(dsc, eq_color_presence());
            break;
    }
}

void customize_ui_settings()
{
    lv_obj_t *tab_btns = lv_tabview_get_tab_btns(objects.ui_settings_eq_tabview);
    lv_obj_add_event_cb(
        tab_btns,
        tab_btn_draw_cb,
        LV_EVENT_DRAW_PART_BEGIN,
        NULL
    );

    #if USB_DEBUG
    remove_style_button_selectable_yellow(objects.ui_usb_button);
    add_style_button_selectable_red(objects.ui_usb_button);
    #endif
}

static void setTheme(uint32_t themeId)
{
    if (active_theme_index == themeId) {
        return;
    }

    uint32_t themesCount = sizeof(theme_colors) / sizeof(theme_colors[0]);

    if (themeId >= themesCount) {
        return;
    }

    change_color_theme(themeId);
    updateFSButtons();
    updateEQColors();
}

void action_theme_changed(lv_event_t * e)
{
    uint32_t themeId = lv_dropdown_get_selected(objects.ui_theme_dropdown);
    setTheme(themeId);

    nvs_handle_t handle;
    esp_err_t err = nvs_open(THEME_STORAGE, NVS_READWRITE, &handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to open theme storage READWRITE (%s)", esp_err_to_name(err));
        return;
    }

    err = nvs_set_u32(handle, THEME_ID_KEY, themeId);
    if (err == ESP_OK)
    {
        err = nvs_commit(handle);
    }
    nvs_close(handle);

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to save theme %u (%s)", themeId, esp_err_to_name(err));
    }
}

void loadSavedTheme()
{
    nvs_handle_t handle;
    esp_err_t err = nvs_open(THEME_STORAGE, NVS_READONLY, &handle);
    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to open theme storage READONLY (%s)", esp_err_to_name(err));
        return;
    }

    uint32_t themeId;
    err = nvs_get_u32(handle, THEME_ID_KEY, &themeId);
    nvs_close(handle);

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Failed to load theme %u (%s)", themeId, esp_err_to_name(err));
        return;
    }

    setTheme(themeId);
    lv_dropdown_set_selected(objects.ui_theme_dropdown, themeId);
}
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
