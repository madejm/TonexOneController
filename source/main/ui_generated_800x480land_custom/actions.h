#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_parameter_changed(lv_event_t * e);
extern void action_close_settings_page(lv_event_t * e);
extern void action_show_settings_page(lv_event_t * e);
extern void action_keyboard_ok(lv_event_t * e);
extern void action_preset_description_pressed(lv_event_t * e);
extern void action_effect_icon_clicked(lv_event_t * e);
extern void action_gesture(lv_event_t * e);
extern void action_value_clicked(lv_event_t * e);
extern void action_value_keyboard_ok(lv_event_t * e);
extern void action_alt_button_clicked(lv_event_t * e);
extern void action_preset_button(lv_event_t * e);
extern void action_tap_tempo_clicked(lv_event_t * e);
extern void action_close_presets_page(lv_event_t * e);
extern void action_preset_list_button(lv_event_t * e);
extern void action_open_presets_page(lv_event_t * e);
extern void action_preset_list_previous(lv_event_t * e);
extern void action_preset_list_next(lv_event_t * e);
extern void action_preset_list_button_options(lv_event_t * e);
extern void action_close_controller_page(lv_event_t * e);
extern void action_save_wifi_settings(lv_event_t * e);
extern void action_edit_wifi_ssid_clicked(lv_event_t * e);
extern void action_edit_wifi_password_clicked(lv_event_t * e);
extern void action_edit_mdns_name_clicked(lv_event_t * e);
extern void action_open_controller_page_clicked(lv_event_t * e);
extern void action_controller_keyboard_ok(lv_event_t * e);
extern void action_wifi_password_hidden_clicked(lv_event_t * e);
extern void action_wifi(lv_event_t * e);
extern void action_usb(lv_event_t * e);
extern void action_usb_flash(lv_event_t * e);
extern void action_wi_fi_enabled_changed(lv_event_t * e);
extern void action_preset_list_color(lv_event_t * e);
extern void action_preset_list_dialog_close(lv_event_t * e);
extern void action_preset_list_cancel(lv_event_t * e);
extern void action_usb_reboot(lv_event_t * e);
extern void action_settings_set_as_default(lv_event_t * e);
extern void action_settings_copy(lv_event_t * e);
extern void action_settings_paste(lv_event_t * e);
extern void action_open_scenes_page(lv_event_t * e);
extern void action_close_scenes_page(lv_event_t * e);
extern void action_new_scene(lv_event_t * e);
extern void action_scene_rename_dialog_keyboard_ok(lv_event_t * e);
extern void action_scene_rename_dialog_close(lv_event_t * e);
extern void action_scene_delete_dialog_cancel(lv_event_t * e);
extern void action_scene_delete_dialog_delete(lv_event_t * e);
extern void action_preset_list_button_options_released(lv_event_t * e);
extern void action_settings_load_default(lv_event_t * e);
extern void action_settings_vir_dialog_close(lv_event_t * e);
extern void action_settings_vir_dialog_open(lv_event_t * e);
extern void action_settings_vir_dialog_page_next(lv_event_t * e);
extern void action_settings_vir_dialog_page_previous(lv_event_t * e);
extern void action_theme_changed(lv_event_t * e);
extern void action_preset_backup_list_previous(lv_event_t * e);
extern void action_preset_backup_list_cancel(lv_event_t * e);
extern void action_preset_backup_list_next(lv_event_t * e);
extern void action_close_presets_backup_page(lv_event_t * e);
extern void action_preset_backup_list_button(lv_event_t * e);
extern void action_preset_backup_list_button_options(lv_event_t * e);
extern void action_preset_backup_list_button_options_released(lv_event_t * e);
extern void action_preset_backup_load_dialog_load(lv_event_t * e);
extern void action_preset_backup_load_dialog_cancel(lv_event_t * e);
extern void action_preset_backup_delete_dialog_delete(lv_event_t * e);
extern void action_preset_backup_delete_dialog_cancel(lv_event_t * e);
extern void action_open_presets_backup_page(lv_event_t * e);
extern void action_usb_host_changed(lv_event_t * e);
extern void action_preset_info_close(lv_event_t * e);
extern void action_tap_tempo_open(lv_event_t * e);
extern void action_tap_tempo_close(lv_event_t * e);
extern void action_preset_list_load_dialog_load(lv_event_t * e);
extern void action_preset_list_load_dialog_cancel(lv_event_t * e);
extern void action_preset_info_rename_dialog_close(lv_event_t * e);
extern void action_preset_info_rename_dialog_keyboard_ok(lv_event_t * e);
extern void action_preset_info_rename_preset_name(lv_event_t * e);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/