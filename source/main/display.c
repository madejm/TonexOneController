/*
 Copyright (C) 2024  Greg Smith

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include "sdkconfig.h"
#include <math.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "esp_timer.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "lvgl.h"
#include "demos/lv_demos.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_ota_ops.h"
#include "sys/param.h"
#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_mac.h"
#include "esp_crc.h"
#include "esp_now.h"
#include "soc/lldesc.h"
#include "esp_lcd_touch_gt911.h"
#include "esp_lcd_touch_cst816s.h"
#include "esp_lcd_gc9107.h"
#include "esp_lcd_sh8601.h"
#include "esp_intr_alloc.h"
#include "main.h"
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    #include "ui.h"
    #include "images.h"
    #include "actions.h"
#endif
#include "usb/usb_host.h"
#include "usb/cdc_acm_host.h"
#include "esp_partition.h"
#include "usb_comms.h"
#include "usb_tonex_common.h"
#include "usb_tonex_one.h"
#include "usb_tonex.h"
#include "display.h"
#include "display_tonex.h"
#include "display_valeton.h"
#include "CH422G.h"
#include "control.h"
#include "task_priorities.h" 
#include "midi_control.h"
#include "LP5562.h"
#include "tonex_params.h"
#include "platform_common.h"
#include "wifi_config.h"
#include "midi_helper.h"
#include "footswitches.h"
#include "fx_handler_helper.h"
#include "display_helpers.h"
#include "display_preset_list.h"
#include "display_settings.h"
#include "scenes.h"
#include "display_preset_buttons.h"

static const char *TAG = "app_display";

#define DISPLAY_TASK_STACK_SIZE   (6 * 1024)

#if CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR
    //static lv_anim_t *ui_BPMAnimation = NULL;
    //static lv_anim_t PropertyAnimation_0;
    void ui_BPMAnimate(lv_obj_t *TargetObject, uint32_t duration);
#endif

#define DISPLAY_LVGL_TICK_PERIOD_MS     2
#define DISPLAY_LVGL_TASK_MAX_DELAY_MS  500
#define DISPLAY_LVGL_TASK_MIN_DELAY_MS  1
#define BUF_SIZE                        (1024)
#define I2C_MASTER_TIMEOUT_MS           1000
#define MAX_SKIN_IMAGES                 100
#define SKIN_PARTITION_TYPE             0x40
#define SKIN_PARTITION_NAME             "skins"
#define SLIDER_STOP_DELAY               225   // msec

enum UIElements
{
    UI_ELEMENT_USB_STATUS,
    UI_ELEMENT_BT_STATUS,
    UI_ELEMENT_WIFI_STATUS,
    UI_ELEMENT_WIFI_ENABLED,
    UI_ELEMENT_WIFI_CLIENT_CONNECTED,
    UI_ELEMENT_PRESET_NAME,
    UI_ELEMENT_BANK_INDEX,
    UI_ELEMENT_AMP_SKIN,
    UI_ELEMENT_ALT_BUTTON,
    UI_ELEMENT_FS_BUTTONS,
    UI_ELEMENT_PRESET_DESCRIPTION,
    UI_ELEMENT_PARAMETERS,
    UI_ELEMENT_TOAST,
    UI_ELEMENT_PRESET_LIST,
    UI_ELEMENT_SETTINGS_CLIPBOARD,
    UI_ELEMENT_TUNER_FREQ,
    UI_ELEMENT_TUNER_STATE,
    UI_ELEMENT_PROGRESS_BAR,
    UI_ELEMENT_PROGRESS_BAR_HIDE,
    UI_ELEMENT_LOG
};

enum UIAction
{
    UI_ACTION_SET_STATE,
    UI_ACTION_SET_LABEL_TEXT,
    UI_ACTION_SET_ENTRY_TEXT,
    // UI_ACTION_SET_AMP_SKIN_SLOT,
    // UI_ACTION_SET_PRESET_BUTTON_SELECTED,
    UI_ACTION_SET_ALT_BUTTON,
    UI_ACTION_NONE = 0xFF
};

typedef struct 
{
    uint8_t ElementID;
    uint8_t Action;
    uint32_t Value;
    uint16_t State;
    char Text[MAX_UI_TEXT];
} tUIUpdate;

typedef struct 
{
    lv_obj_t *mbox;
    lv_style_t *style_main;
    lv_style_t *style_text;
    
    uint32_t timer;
    uint8_t active;
} msgbox_data_t;

typedef struct __attribute__ ((packed)) 
{
    uint32_t offset;
    uint32_t length;
} tSkinTOC;


static QueueHandle_t ui_update_queue;
static SemaphoreHandle_t I2CMutexHandle;
static SemaphoreHandle_t lvgl_mux = NULL;
static lv_disp_drv_t* disp_drv; 
static msgbox_data_t msgbox_data;

#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
static bool ui_AltMode = false;
static uint8_t ui_PresetIndex = 0;
static uint8_t ui_BankIndex = 0;

static void ui_show_toast(char* contents);

#if CONFIG_TONEX_CONTROLLER_HAS_TOUCH
static uint8_t __attribute__((unused)) touch_data_ready_to_read = 0;
#endif

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
static lv_obj_t* controll_settings_edit_element = NULL;

#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
typedef enum
{
    SKIN_SLOT_MAIN = 0,
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    SKIN_SLOT_PRESET_0,
    SKIN_SLOT_PRESET_1,
    SKIN_SLOT_PRESET_2,
    SKIN_SLOT_PRESET_3,
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    SKIN_SLOT_PRESET_LIST_0,
    SKIN_SLOT_PRESET_LIST_1,
    SKIN_SLOT_PRESET_LIST_2,
    SKIN_SLOT_PRESET_LIST_3,
    SKIN_SLOT_PRESET_LIST_4,
    SKIN_SLOT_PRESET_LIST_5,
    SKIN_SLOT_PRESET_LIST_6,
    SKIN_SLOT_PRESET_LIST_7,
    SKIN_SLOT_PRESET_LIST_8,
    SKIN_SLOT_PRESET_LIST_9,
    
    SKIN_SLOT_MAX
} SkinSlotIndex_t;

#define INVALID_SKIN_INDEX 0xFFFF

static void set_skin_image(lv_obj_t* obj, uint8_t index, SkinSlotIndex_t slot);

typedef struct
{
    uint16_t displayed_index;
    lv_img_dsc_t dsc;
} SkinSlot_t;

static SkinSlot_t skin_slots[SKIN_SLOT_MAX];

static tSkinTOC SkinTOC[MAX_SKIN_IMAGES];
static const esp_partition_t* skin_partition;

static const void* skin_data_map_ptr;
static esp_partition_mmap_handle_t skin_data_map_handle = 0;
#endif // !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
static float current_tuner_ref_freq = 440.0f;
#ifndef clampf
    #define clampf(x, lo, hi)  ((x) < (lo) ? (lo) : ((x) > (hi) ? (hi) : (x)))
#endif
static lv_timer_t* slider_stop_timer = NULL;
static lv_obj_t* last_active_slider = NULL;
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused)) display_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
    int offsetx1;
    int offsetx2;
    int offsety1;
    int offsety2;

    // let platform adjust area
    platform_adjust_display_flush_area((lv_area_t*)area);

    offsetx1 = area->x1;
    offsetx2 = area->x2;
    offsety1 = area->y1;
    offsety2 = area->y2;

#if CONFIG_DISPLAY_AVOID_TEAR_EFFECT_WITH_SEM
    xSemaphoreGive(sem_gui_ready);
    xSemaphoreTake(sem_vsync_end, portMAX_DELAY);
#endif
    // pass the draw buffer to the driver
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
    lv_disp_flush_ready(drv);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
bool __attribute__((unused)) display_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_disp_flush_ready(disp_drv);
    return false;
}
#endif  //CONFIG_TONEX_CONTROLLER_HAS_DISPLAY

#if CONFIG_TONEX_CONTROLLER_HAS_TOUCH

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused)) touch_data_ready(esp_lcd_touch_t *handle)
{
    touch_data_ready_to_read = 1;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused, weak)) display_lvgl_touch_cb(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
    esp_lcd_touch_point_data_t points[1] = {0};
    uint8_t touchpad_cnt = 0;
    bool touchpad_pressed = false;

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_LILYGO_TDISPLAY_S3 || CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_169TOUCH  || CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_19TOUCH
    // CST816 driver has to set interrupt before data is valid to read.
    if (touch_data_ready_to_read)
    {
        if (xSemaphoreTake(I2CMutexHandle, (TickType_t)10) == pdTRUE)
        {
            // Read touch controller data
            if (esp_lcd_touch_read_data(drv->user_data) == ESP_OK)
            {
                // Get coordinates 
                if (esp_lcd_touch_get_data(drv->user_data, points, &touchpad_cnt, 1) == ESP_OK)
                {
                    if (touchpad_cnt > 0)
                    {
                        touchpad_pressed = 1;
                    }
                }
            
                // reset flag
                touch_data_ready_to_read = 0;
            }

            xSemaphoreGive(I2CMutexHandle);
        }
    }

#else

    // poll the driver chip
    if (xSemaphoreTake(I2CMutexHandle, (TickType_t)10) == pdTRUE)
    {
        // Read touch controller data 
        if (esp_lcd_touch_read_data(drv->user_data) == ESP_OK)
        {
            touchpad_cnt = 0;

            // Get coordinates
            if (esp_lcd_touch_get_data(drv->user_data, points, &touchpad_cnt, 1) == ESP_OK)
            {
                if (touchpad_cnt > 0)
                {
                    touchpad_pressed = 1;
                }
            }
        }

        xSemaphoreGive(I2CMutexHandle);
    }
    else
    {
        ESP_LOGE(TAG, "Touch cb mutex timeout");
    }
#endif 

    if (touchpad_pressed && touchpad_cnt > 0) 
    {
        data->point.x = points[0].x;
        data->point.y = points[0].y;

        // allow platform to adjust if needed
        platform_adjust_touch_coords(&data->point.x, &data->point.y);

        data->state = LV_INDEV_STATE_PR;

        // debug
        //ESP_LOGI(TAG, "Touch X:%d Y:%d", (int)data->point.x, (int)data->point.y);
    } 
    else 
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused)) action_gesture(lv_event_t * e)
{
    lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());

    // let platform adjust it
    dir = platform_adjust_gesture(dir);

    // called from LVGL 
    if (dir == LV_DIR_RIGHT)
    {
        ESP_LOGI(TAG, "UI Previous Swipe");      
        control_request_preset_down();      
    }
    else if (dir == LV_DIR_LEFT)
    {
        ESP_LOGI(TAG, "UI Next Swipe");    
        control_request_preset_up();      
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_previous_clicked(lv_event_t * e)
{
    // called from LVGL 
    ESP_LOGI(TAG, "UI Previous Click");      

    control_request_preset_down();      
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_next_clicked(lv_event_t * e)
{
    // called from LVGL 
    ESP_LOGI(TAG, "UI Next Click");    

    control_request_preset_up();        
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

void action_tap_tempo_clicked(lv_event_t * e)
{
    control_trigger_tap_tempo();
}
void action_alt_button_clicked(lv_event_t * e)
{
    footswitches_switch_alt_mode();
}

void action_wifi(lv_event_t * e) {
    lv_tabview_set_act(objects.ui_settings_tab_view, lv_obj_get_index(objects.ui_wi_fi_tab), LV_ANIM_OFF);
    action_show_settings_page(e);
}

void action_usb(lv_event_t * e) {
    lv_tabview_set_act(objects.ui_settings_tab_view, lv_obj_get_index(objects.ui_usb_tab), LV_ANIM_OFF);
    action_show_settings_page(e);
}

void action_usb_reboot(lv_event_t * e) {
    usb_reboot();
}

void action_usb_flash(lv_event_t * e) {
    usb_enter_download_mode();
}

void action_wi_fi_enabled_changed(lv_event_t * e) {
    lv_obj_t *wifi_switch = lv_event_get_target(e);
    wifi_config_set_enabled(lv_obj_has_state(wifi_switch, LV_STATE_CHECKED));
}

bool display_get_alt_Mode()
{
    return ui_AltMode;
}

static void updatePresetNumberLabel()
{
    display_preset_buttons_updatePresetNumberLabel(ui_PresetIndex);
}

void updateFSButtons()
{
    display_preset_buttons_updateFSButtons(
        ui_AltMode,
        ui_PresetIndex,
        ui_BankIndex
    );
}
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused)) action_tuner_pressed(lv_event_t * e)
{
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    char buf[20];
    tModellerParameter* param_ptr;
    
    ESP_LOGI(TAG, "UI tuner pressed");      
    control_request_tuner(1);
    
    // show tuner screen
    lv_scr_load_anim(objects.tuner, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);   

    // grab current tuner ref freq and save it
    if (tonex_params_get_locked_access(&param_ptr) == ESP_OK)
    {
        current_tuner_ref_freq = param_ptr[TONEX_GLOBAL_TUNING_REFERENCE].Value;

        tonex_params_release_locked_access();
    }

    // show reference freq on UI
    sprintf(buf, "%d Hz", (int)round(current_tuner_ref_freq));
    lv_label_set_text(objects.ui_tuner_reference_label, buf);
#endif  //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void __attribute__((unused)) action_tuner_close(lv_event_t * e)
{
    ESP_LOGI(TAG, "UI tuner close");      
    control_request_tuner(0);

    // show main screen
    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}
#else   //CONFIG_TONEX_CONTROLLER_HAS_TOUCH

// Dummy functions so that 1.69 and 1.69 Touch can share the same UI project
void __attribute__((unused)) action_previous_clicked(lv_event_t * e)
{
}

void __attribute__((unused)) action_next_clicked(lv_event_t * e)
{
}

void __attribute__((unused)) action_gesture(lv_event_t * e)
{
}

#endif  //CONFIG_TONEX_CONTROLLER_HAS_TOUCH

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
// we use two semaphores to sync the VSYNC event and the LVGL task, to avoid potential tearing effect
#if CONFIG_DISPLAY_AVOID_TEAR_EFFECT_WITH_SEM
SemaphoreHandle_t sem_vsync_end;
SemaphoreHandle_t sem_gui_ready;
#endif  //CONFIG_DISPLAY_AVOID_TEAR_EFFECT_WITH_SEM

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
bool display_on_vsync_event(esp_lcd_panel_handle_t panel, const esp_lcd_rgb_panel_event_data_t *event_data, void *user_data)
{
    BaseType_t high_task_awoken = pdFALSE;
#if CONFIG_DISPLAY_AVOID_TEAR_EFFECT_WITH_SEM
    if (xSemaphoreTakeFromISR(sem_gui_ready, &high_task_awoken) == pdTRUE) {
        xSemaphoreGiveFromISR(sem_vsync_end, &high_task_awoken);
    }
#endif
    return high_task_awoken == pdTRUE;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void ui_show_settings_tab(lv_event_t * e)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            tonex_show_settings_tab(e);
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            valeton_show_settings_tab(e);
            #endif
        } break;
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_effect_icon_clicked(lv_event_t * e)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            tonex_action_effect_icon_clicked(e);
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            valeton_action_effect_icon_clicked(e);
            #endif
        } break;
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_amp_skin_previous(lv_event_t * e)
{
    control_set_skin_previous();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_amp_skin_next(lv_event_t * e)
{
    control_set_skin_next();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_close_settings_page(lv_event_t * e)
{
    // save preset
    usb_save_preset();

    // close settings screen
    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_show_settings_page(lv_event_t * e)
{

    WiFiMode WiFiMode = control_get_config_item_int(CONFIG_ITEM_WIFI_MODE);
    WiFiTxPower WifiTxPower = control_get_config_item_int(CONFIG_ITEM_WIFI_TX_POWER);

    lv_dropdown_set_selected(objects.ui_wifi_mode_dropdown, WiFiMode);
    lv_dropdown_set_selected(objects.ui_wifi_power_dropdown, WifiTxPower);

    char WifiSSID[MAX_WIFI_SSID_PW];
    char WifiPassword[MAX_WIFI_SSID_PW];
    char MDNSName[MAX_MDNS_NAME];
    
    control_get_config_item_string(CONFIG_ITEM_WIFI_SSID, WifiSSID);
    control_get_config_item_string(CONFIG_ITEM_WIFI_PASSWORD, WifiPassword);
    control_get_config_item_string(CONFIG_ITEM_MDNS_NAME, MDNSName);

    lv_textarea_set_text(objects.ui_wifi_ssid_textarea, WifiSSID);
    lv_textarea_set_text(objects.ui_wifi_password_textarea, WifiPassword);
    lv_textarea_set_text(objects.ui_mdns_name_textarea, MDNSName);

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    if (wifi_config_is_enabled())
    {
        lv_obj_add_state(objects.ui_wi_fi_switch, LV_STATE_CHECKED);
    }
    else
    {
        lv_obj_clear_state(objects.ui_wi_fi_switch, LV_STATE_CHECKED);
    }
#endif

    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            lv_scr_load_anim(objects.settings, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            lv_scr_load_anim(objects.val_settings, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
            #endif
        } break;
    }    
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_enable_skin_edit(lv_event_t * e)
{
    #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    ESP_LOGI(TAG, "UI Skin edit mode");

    lv_obj_clear_flag(objects.ui_left_arrow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(objects.ui_right_arrow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_state(objects.ui_preset_details_text_area, LV_STATE_DISABLED);
    lv_obj_clear_flag(objects.ui_ok_tick, LV_OBJ_FLAG_HIDDEN);
    #endif
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_save_skin_edit(lv_event_t * e)
{
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    ESP_LOGI(TAG, "UI save skin edit");

    // make sure user text is saved
    lv_event_send(objects.ui_entry_keyboard, LV_EVENT_READY, NULL);
    control_save_user_data(0);
    
    lv_obj_add_flag(objects.ui_ok_tick, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_entry_keyboard, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_left_arrow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.ui_right_arrow, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_state(objects.ui_preset_details_text_area, LV_STATE_DISABLED);

#if (CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR)
    if (control_get_config_item_int(CONFIG_ITEM_DISABLE_BPM_FLASHER) == 0)
    {
        lv_obj_clear_flag(objects.ui_bpm_indicator, LV_OBJ_FLAG_HIDDEN);
    }
#endif    
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_description_pressed(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);

    // if(event_code == LV_EVENT_PRESSED) 
    // {
        // lv_keyboard_set_textarea(objects.ui_entry_keyboard,  objects.ui_preset_details_text_area);
    //     lv_obj_clear_flag(objects.ui_entry_keyboard, LV_OBJ_FLAG_HIDDEN);
    // }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_value_clicked(lv_event_t *e) 
{
    ESP_LOGI(TAG, "action_value_clicked");

    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            tonex_value_clicked(e);         
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            valeton_value_clicked(e);
            #endif
        } break;
    }    
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void BTBondsClearRequest(lv_event_t * e)
{
    // request to clear bluetooth bonds
    midi_delete_bluetooth_bonds();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_keyboard_ok(lv_event_t * e)
{
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_READY) 
    {
        // hide keyboard
        lv_obj_add_flag(objects.ui_entry_keyboard, LV_OBJ_FLAG_HIDDEN);

        char* text = (char*)lv_textarea_get_text(objects.ui_preset_details_text_area);

        ESP_LOGI(TAG, "action_keyboard_ok: %s", text);

        control_set_user_text(text);  
    }
#endif
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_value_keyboard_ok(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_READY) 
    {
        ESP_LOGI(TAG, "action_value_keyboard_ok");

        switch (usb_get_connected_modeller_type())
        {
            case AMP_MODELLER_TONEX_ONE:        // fallthrough
            case AMP_MODELLER_TONEX:            // fallthrough
            case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
            case AMP_MODELLER_TONEX_PLUG:
            default:
            {
                tonex_value_changed(e);
            } break;

            case AMP_MODELLER_VALETON_GP5:
            {
                #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
                valeton_value_changed(e);
                #endif
            } break;
        }            
    }    
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void slider_stop_timer_cb(lv_timer_t* timer)
{
    if (last_active_slider == NULL)
    {
        return;
    }

    // send simulated event for this slider
    lv_event_t event;
    lv_memset_00(&event, sizeof(event));
    event.target = last_active_slider;
    event.current_target = last_active_slider;
    event.code = LV_EVENT_RELEASED;
    action_parameter_changed(&event);

    // Clean up
    lv_timer_del(timer);
    slider_stop_timer = NULL;
    last_active_slider = NULL;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_slider_event(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* slider = lv_event_get_target(e);

    if (code == LV_EVENT_VALUE_CHANGED) 
    {
        last_active_slider = slider;

        if (slider_stop_timer) 
        {
            // restart the timer countdown
            lv_timer_reset(slider_stop_timer);
        } 
        else 
        {
            // Create timer to fire after a time delay
            slider_stop_timer = lv_timer_create(slider_stop_timer_cb, SLIDER_STOP_DELAY,  NULL);
        }
    }
    else if (code == LV_EVENT_RELEASED) 
    {
        if (slider_stop_timer && last_active_slider == slider) 
        {
            lv_timer_del(slider_stop_timer);
            slider_stop_timer = NULL;

            // send simulated event for this slider
            lv_event_t event;
            lv_memset_00(&event, sizeof(event));
            event.target = last_active_slider;
            event.current_target = last_active_slider;
            event.code = LV_EVENT_RELEASED;
            action_parameter_changed(&event);

            last_active_slider = NULL;
        }
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_parameter_changed(lv_event_t * e)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            tonex_action_parameter_changed(e);
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            valeton_action_parameter_changed(e);
            #endif
        } break;
    }
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_save_wifi_settings(lv_event_t * e)
{
    ESP_LOGI(TAG, "WiFi Set");
    
    WiFiMode WiFiMode = lv_dropdown_get_selected(objects.ui_wifi_mode_dropdown); // WIFI_MODE_ACCESS_POINT_TIMED
    WiFiTxPower WifiTxPower = lv_dropdown_get_selected(objects.ui_wifi_power_dropdown); // WIFI_TX_POWER_25

    char *WifiSSID = (char*)lv_textarea_get_text(objects.ui_wifi_ssid_textarea);
    char *WifiPassword = (char*)lv_textarea_get_text(objects.ui_wifi_password_textarea);
    char *MDNSName = (char*)lv_textarea_get_text(objects.ui_mdns_name_textarea);

    lv_scr_load_anim(objects.settings, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);

    control_set_config_item_int(CONFIG_ITEM_WIFI_MODE, WiFiMode);
    control_set_config_item_int(CONFIG_ITEM_WIFI_TX_POWER, WifiTxPower);
    control_set_config_item_string(CONFIG_ITEM_WIFI_SSID, WifiSSID);
    control_set_config_item_string(CONFIG_ITEM_WIFI_PASSWORD, WifiPassword);
    control_set_config_item_string(CONFIG_ITEM_MDNS_NAME, MDNSName);

    vTaskDelay(pdMS_TO_TICKS(250));

    // save it and reboot after
    control_save_user_data(1);
}

static void openControllerDialog()
{
    if (controll_settings_edit_element == NULL)
    {
        return;
    }

    const char* text = lv_textarea_get_text(controll_settings_edit_element);
    lv_textarea_set_text(objects.ui_controller_dialog_entry, text);

    lv_obj_clear_flag(objects.ui_controller_dialog, LV_OBJ_FLAG_HIDDEN);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_edit_wifi_ssid_clicked(lv_event_t * e)
{
    controll_settings_edit_element = objects.ui_wifi_ssid_textarea;
    openControllerDialog();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_edit_wifi_password_clicked(lv_event_t * e)
{
    controll_settings_edit_element = objects.ui_wifi_password_textarea;
    openControllerDialog();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_wifi_password_hidden_clicked(lv_event_t * e)
{
    lv_obj_t *checkbox = lv_event_get_target(e);
    bool checked = lv_obj_has_state(checkbox, LV_STATE_CHECKED);
    lv_textarea_set_password_mode(objects.ui_wifi_password_textarea, checked);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_edit_mdns_name_clicked(lv_event_t * e)
{
    controll_settings_edit_element = objects.ui_mdns_name_textarea;
    openControllerDialog();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_controller_keyboard_ok(lv_event_t * e)
{
    if (controll_settings_edit_element != NULL)
    {
        const char* text = lv_textarea_get_text(objects.ui_controller_dialog_entry);
        lv_textarea_set_text(controll_settings_edit_element, text);
        controll_settings_edit_element = NULL;
    }
    lv_obj_add_flag(objects.ui_controller_dialog, LV_OBJ_FLAG_HIDDEN);
}
#endif  //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#endif  //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void __attribute__((unused)) display_increase_lvgl_tick(void *arg)
{
    /* Tell LVGL how many milliseconds has elapsed */
    lv_tick_inc(DISPLAY_LVGL_TICK_PERIOD_MS);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
bool display_lvgl_lock(int timeout_ms)
{
    // Convert timeout in milliseconds to FreeRTOS ticks
    // If `timeout_ms` is set to -1, the program will block until the condition is met
    const TickType_t timeout_ticks = (timeout_ms == -1) ? portMAX_DELAY : pdMS_TO_TICKS(timeout_ms);
    return xSemaphoreTakeRecursive(lvgl_mux, timeout_ticks) == pdTRUE;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void display_lvgl_unlock(void)
{
    xSemaphoreGiveRecursive(lvgl_mux);
}

/****************************************************************************
* NAME:        UI_ShowScreen1IfNeeded
* DESCRIPTION: Returns to the main screen when another screen is active
* PARAMETERS:
* RETURN:      true when a different screen was closed
* NOTES:       Thread-safe API for callers outside the display task
*****************************************************************************/
bool UI_ShowScreen1IfNeeded(void)
{
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    bool screen_changed = false;

    if (display_lvgl_lock(-1))
    {
        lv_obj_t* active_screen = lv_scr_act();

        if ((objects.screen1 != NULL) && (active_screen != objects.screen1))
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
            if (active_screen == objects.settings)
            {
                action_close_settings_page(NULL);
            }
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            else if (active_screen == objects.val_settings)
            {
                action_close_settings_page(NULL);
            }
#endif
            else if (active_screen == objects.presets)
            {
                action_close_presets_page(NULL);
            }
            else
            {
                lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
            }
#else
            lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
#endif
            screen_changed = true;
        }

        display_lvgl_unlock();
    }

    return screen_changed;
#else
    return false;
#endif
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetUSBStatus(uint8_t state)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_USB_STATUS;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = state;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetBTStatus(uint8_t state)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_BT_STATUS;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = state;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetWiFiStatus(uint8_t state)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_WIFI_STATUS;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = state;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
void UI_SetWiFiEnabled(uint8_t state)
{
    tUIUpdate ui_update;

    ui_update.ElementID = UI_ELEMENT_WIFI_ENABLED;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = state;

    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");
    }
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
void UI_SetWiFiClientConnected(uint8_t state)
{
    tUIUpdate ui_update;

    ui_update.ElementID = UI_ELEMENT_WIFI_CLIENT_CONNECTED;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = state;

    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetTunerState(uint8_t state)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_TUNER_STATE;
    ui_update.Action = UI_ACTION_NONE;
    ui_update.Value = state;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI SetTunerState queue send failed!");            
    }
}

static char *log_cache;
static size_t log_cache_count = 0;

static void UI_LogCacheAdd(const char *text)
{
    char *new_cache = realloc(log_cache, (log_cache_count + 1) * MAX_UI_TEXT);
    if (new_cache == NULL)
    {
        ESP_LOGW(TAG, "Unable to cache early UI log message");
        return;
    }

    log_cache = new_cache;
    snprintf(&log_cache[log_cache_count * MAX_UI_TEXT], MAX_UI_TEXT, "%s", text);
    log_cache_count++;
}

void UI_Log(const char *format, ...)
{
    char text[MAX_UI_TEXT];

    va_list args;
    va_start(args, format);
    vsnprintf(text, sizeof(text), format, args);
    va_end(args);

    if (ui_update_queue == NULL)
    {
        UI_LogCacheAdd(text);
        return;
    }

    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_LOG;
    ui_update.Action = UI_ACTION_NONE;
    sprintf(ui_update.Text, text);

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI SetTunerState queue send failed!");            
    }
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
void UI_SetProgressBar(uint8_t progress, char *title)
{
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    tUIUpdate ui_update;

    if (ui_update_queue == NULL)
    {
        ESP_LOGW(TAG, "UI progress bar unavailable");
        return;
    }

    ui_update.ElementID = UI_ELEMENT_PROGRESS_BAR;
    ui_update.Action = UI_ACTION_NONE;
    ui_update.Value = MIN(progress, 100);
    strncpy(ui_update.Text, title, MAX_UI_TEXT - 1);

    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI progress bar queue send failed!");
    }
#endif
}

/****************************************************************************
* NAME:
* DESCRIPTION:
* PARAMETERS:
* RETURN:
* NOTES:
*****************************************************************************/
void UI_HideProgressBar(void)
{
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    tUIUpdate ui_update;

    if (ui_update_queue == NULL)
    {
        return;
    }

    ui_update.ElementID = UI_ELEMENT_PROGRESS_BAR_HIDE;
    ui_update.Action = UI_ACTION_NONE;

    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI progress bar queue send failed!");
    }
#endif
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetPresetLabel(uint16_t index, char* name)
{
    tUIUpdate ui_update;
    bool modified = false;
    tScene *scene = scenes_get_current();
    if ((scene != NULL) && (index < MAX_SUPPORTED_PRESETS))
    {
        uint8_t preset_index = scene->PresetOrder[index];
        modified = scene->Presets[preset_index].Modified;
    }

    // build command
    ui_update.ElementID = UI_ELEMENT_PRESET_NAME;
    ui_update.Action = UI_ACTION_SET_LABEL_TEXT;
    ui_update.Value = index;
    ui_update.State = modified;
    #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    snprintf(ui_update.Text, sizeof(ui_update.Text), "%s%s", name, modified ? "*" : "");
    #else
    sprintf(ui_update.Text, "%d: ", (int)index + usb_get_first_preset_index_for_connected_modeller());
    strncat(ui_update.Text, name, MAX_UI_TEXT - 1);
    #endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetTunerFrequencies(float error, float ref_freq, uint8_t midi_note)
{
    tUIUpdate ui_update;

    // Tuner spams out a huge amount of traffic. Avoid flooding the queue
    uint32_t elements_in_queue = uxQueueMessagesWaiting(ui_update_queue); 

    if (elements_in_queue < 3)
    {
        // build command
        ui_update.ElementID = UI_ELEMENT_TUNER_FREQ;
        ui_update.Action = UI_ACTION_NONE;
        ui_update.Value = (uint32_t)midi_note;

        // put tuner error into string as we don't have floats in the tUIUpdate and adding would waste ram for queue size (yeah OK could use a union I guess...)
        sprintf(ui_update.Text, "%3.2f", error);

        // send to queue
        if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
        {
            ESP_LOGE(TAG, "UI_SetTunerFrequencies queue send failed!");            
        }
    }
    else
    {
        // skip this one and get the next once queue has emptied some more
    }
}


/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
__attribute__((unused)) void UI_ShowToast(char* text)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_TOAST;
    ui_update.Action = UI_ACTION_NONE;
    strncpy(ui_update.Text, text, MAX_UI_TEXT - 1);

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

void UI_SettingsCopied(Clipboard_t type)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_SETTINGS_CLIPBOARD;
    ui_update.Action = UI_ACTION_NONE;
    ui_update.Value = type;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetBankIndex(uint16_t index)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_BANK_INDEX;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.State = index;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetAmpSkin(uint16_t index)
{
    tUIUpdate ui_update;

    // build commands
    ui_update.ElementID = UI_ELEMENT_AMP_SKIN;
    ui_update.Action = UI_ACTION_SET_STATE;
    ui_update.Value = index;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_UpdatePresetList()
{
    tUIUpdate ui_update;
    
    ui_update.ElementID = UI_ELEMENT_PRESET_LIST;
    ui_update.Action = UI_ACTION_NONE;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_UpdateFSButtons()
{
    tUIUpdate ui_update;

    // build commands
    ui_update.ElementID = UI_ELEMENT_FS_BUTTONS;
    ui_update.Action = UI_ACTION_NONE;

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetAltMode(bool altMode)
{
    tUIUpdate ui_update;
    
    ui_update.ElementID = UI_ELEMENT_ALT_BUTTON;
    ui_update.Action = UI_ACTION_SET_ALT_BUTTON;
    ui_update.State = altMode;

    char *value = altMode ? "ON" : "OFF";
    sprintf(ui_update.Text, "ALT");
    strncat(ui_update.Text, ": ", MAX_UI_TEXT - 1);
    strncat(ui_update.Text, value, MAX_UI_TEXT - 1);

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_SetPresetDescription(char* text)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_PRESET_DESCRIPTION;
    ui_update.Action = UI_ACTION_SET_ENTRY_TEXT;
    strncpy(ui_update.Text, text, MAX_UI_TEXT - 1);

    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update queue send failed!");            
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void UI_RefreshParameterValues(void)
{
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    tUIUpdate ui_update;

    // build command
    ui_update.Action = UI_ACTION_NONE;
    ui_update.ElementID = UI_ELEMENT_PARAMETERS;
    
    // send to queue
    if (xQueueSend(ui_update_queue, (void*)&ui_update, 0) != pdPASS)
    {
        ESP_LOGE(TAG, "UI Update parameters send failed!");            
    }
#endif    
}

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void ui_load_skin_toc(void)
{
    // Find the skin partition by name
    skin_partition = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, SKIN_PARTITION_TYPE, SKIN_PARTITION_NAME);
    if (skin_partition == NULL) 
    {
        ESP_LOGE(TAG, "TOC: Could not find partition 'skins'");
        return;
    }

    esp_err_t err = esp_partition_read(skin_partition, 0, (uint8_t*)&SkinTOC, sizeof(SkinTOC));
    if (err != ESP_OK) 
    {
        ESP_LOGE(TAG, "TOC: Failed to read skins partition: %s", esp_err_to_name(err));
        return;
    }
    else
    {
        ESP_LOGI(TAG, "Skin TOC loaded OK");
    }
    
    // debug code to dump the skin TOC
    //for (uint8_t index = 0; index < MAX_SKIN_IMAGES; index++)
    //{
    //    ESP_LOGI(TAG, "TOC: %d, %d %d", (int)index, (int)SkinTOC[index].offset, (int)SkinTOC[index].length);
    //}

    err = esp_partition_mmap(
        skin_partition,
        0,
        skin_partition->size,
        ESP_PARTITION_MMAP_DATA,
        &skin_data_map_ptr,
        &skin_data_map_handle
    );

    if (err != ESP_OK)
    {
        ESP_LOGE(TAG, "Global mmap failed: %s", esp_err_to_name(err));
        return;
    }

    ESP_LOGI(TAG, "Skin partition mapped globally");

    for (int i = 0; i < SKIN_SLOT_MAX; i++)
    {
        skin_slots[i].displayed_index = INVALID_SKIN_INDEX;
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void set_skin_image(lv_obj_t* obj, uint8_t index, SkinSlotIndex_t slot)
{
    if (index >= MAX_SKIN_IMAGES)
    {
        ESP_LOGW(TAG, "Invalid skin index: %d", index);
        return;
    }

    if (SkinTOC[index].length == 0 || skin_partition == NULL)
    {
        ESP_LOGW(TAG, "No data for skin index: %d", index);
        return;
    }

    SkinSlot_t* s = &skin_slots[slot];

    // Skip if already displayed
    if (s->displayed_index == index)
        return;

    const uint8_t* base = (const uint8_t*)skin_data_map_ptr;
    const uint8_t* data_ptr = base + SkinTOC[index].offset;

    memcpy(&s->dsc.header, data_ptr, sizeof(lv_img_header_t));

    s->dsc.data_size = SkinTOC[index].length - sizeof(lv_img_header_t);

    s->dsc.data = data_ptr + sizeof(lv_img_header_t);
    lv_img_set_src(obj, &s->dsc);

    s->displayed_index = index; 
}
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void updateIconOrder(void)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
        case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
        case AMP_MODELLER_TONEX_PLUG:
        default:
        {
            tonex_update_icon_order();
        } break;

        case AMP_MODELLER_VALETON_GP5:
        {
            #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            valeton_update_icon_order();
            #endif
        } break;
    }
}
#endif //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static  __attribute__((unused)) uint8_t update_ui_element(tUIUpdate* update)
{
#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    __attribute__((unused)) char value_string[20];
    lv_obj_t* element_1 = NULL;

    switch (update->ElementID)
    {    
        case UI_ELEMENT_USB_STATUS:
        {
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_usb_button;
            #else
            element_1 = objects.ui_usb_status_fail;
            #endif

            if (update->Value == 1)
            {
                // if enabled, adjust UI to suit modeller
                switch (usb_get_connected_modeller_type())
                {
                    case AMP_MODELLER_TONEX_ONE:        // fallthrough
                    case AMP_MODELLER_TONEX:            // fallthrough
                    case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
                    case AMP_MODELLER_TONEX_PLUG:
                    default:
                    {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
                        lv_obj_clear_flag(objects.ui_bottom_panel_tonex, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(objects.ui_bottom_panel_valeton, LV_OBJ_FLAG_HIDDEN);

                        if (usb_get_connected_modeller_type() == AMP_MODELLER_TONEX_ONE_PLUS)
                        {
                            // unhide Tuner icon
                            lv_obj_clear_flag(objects.ui_tuner_button, LV_OBJ_FLAG_HIDDEN);
                        }

                        lv_label_set_text(objects.ui_project_heading_label, "Tonex Controller"); 
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#else                    
                        // set effect letter to "C" (Compressor)
                        lv_label_set_text(objects.ui_cstatus, "C");
#endif    

                    } break;

                    case AMP_MODELLER_VALETON_GP5:
                    {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM                                                  
                        lv_obj_add_flag(objects.ui_bottom_panel_tonex, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_clear_flag(objects.ui_bottom_panel_valeton, LV_OBJ_FLAG_HIDDEN);

                        // lv_label_set_text(objects.ui_project_heading_label, "Valeton Controller"); 
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#else            
                        // set effect letter to "T" (Distortion)
                        lv_label_set_text(objects.ui_cstatus, "T");
#endif    
                    } break;
                }
            }
        } break;

        case UI_ELEMENT_BT_STATUS:
        {
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_bt_midi_button;
            #else
            element_1 = objects.ui_bt_status_conn;
            #endif
        } break;

        case UI_ELEMENT_WIFI_STATUS:
        {
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            // Power and AP-client state are displayed separately on the custom button.
            element_1 = NULL;
            #else
            element_1 = objects.ui_wi_fi_status_conn;
            #endif
        } break;

        case UI_ELEMENT_WIFI_ENABLED:
        {
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            if (update->Value == 0)
            {
                lv_obj_clear_state(objects.ui_wi_fi_switch, LV_STATE_CHECKED);
            }
            else
            {
                lv_obj_add_state(objects.ui_wi_fi_switch, LV_STATE_CHECKED);
            }

            element_1 = objects.ui_wi_fi_button;
            #endif
        } break;

        case UI_ELEMENT_WIFI_CLIENT_CONNECTED:
        {
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            if (update->Value == 0)
            {
                lv_obj_clear_state(objects.ui_wi_fi_button, LV_STATE_USER_1);
            }
            else
            {
                lv_obj_add_state(objects.ui_wi_fi_button, LV_STATE_USER_1);
            }
            #endif

            element_1 = NULL;
        } break;

        case UI_ELEMENT_PRESET_NAME:
        {
            element_1 = objects.ui_preset_heading_label;
            lv_obj_set_checked(element_1, update->State != 0);
            ui_PresetIndex = update->Value;
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            updatePresetNumberLabel();
            updateFSButtons();
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
        } break;

        case UI_ELEMENT_BANK_INDEX:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_bank_value_label;
#endif
            ui_BankIndex = update->State;
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            updateFSButtons();
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
        } break;

        case UI_ELEMENT_AMP_SKIN:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_skin_image;
#endif            
        } break;

        case UI_ELEMENT_ALT_BUTTON:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_alt_button;
#endif
        } break;

        case UI_ELEMENT_FS_BUTTONS:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            updateFSButtons();
#endif
        } break;

//         case UI_ELEMENT_PRESET_FS6_BUTTON:
//         {
// #if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
//             element_1 = ui_FS6Button;
// #endif            
//         } break;

//         case UI_ELEMENT_PRESET_FS7_BUTTON:
//         {
// #if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
//             element_1 = ui_FS7Button;
// #endif            
//         } break;

//         case UI_ELEMENT_PRESET_FS9_BUTTON:
//         {
// #if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
//             element_1 = ui_FS9Button;
// #endif            
//         } break;

        case UI_ELEMENT_PRESET_DESCRIPTION:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            element_1 = objects.ui_preset_details_text_area;
            return 0;
#endif            
        } break;

        case UI_ELEMENT_PARAMETERS:
        {
            ESP_LOGI(TAG, "Syncing params to UI");

            switch (usb_get_connected_modeller_type())
            {
                case AMP_MODELLER_TONEX_ONE:        // fallthrough
                case AMP_MODELLER_TONEX:            // fallthrough
                case AMP_MODELLER_TONEX_ONE_PLUS:   // fallthrough
                case AMP_MODELLER_TONEX_PLUG:
                default:
                {
                    tonex_update_ui_parameters();
                } break;

                case AMP_MODELLER_VALETON_GP5:
                {
                    #if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
                    valeton_update_ui_parameters();
                    #endif
                } break;
            }

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
            updateIconOrder();
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            updateFSButtons();

            if (lv_scr_act() == objects.presets) {
                updatePresetListColors();
            }
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#endif //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
        } break;

        case UI_ELEMENT_TOAST:
        {
            ui_show_toast(update->Text);
        } break;

        case UI_ELEMENT_SETTINGS_CLIPBOARD:
        {
            updateSettingsClipboard(update->Value);
        } break;

        case UI_ELEMENT_PRESET_LIST:
        {
            if (lv_scr_act() == objects.presets) {
                updatePresetListSelection();
                updatePresetListNames();
                updatePresetListOptions();
            }
        } break;

        case UI_ELEMENT_TUNER_FREQ:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
            int32_t arc_value;
            lv_color_t col;
            char buf[32];
            float tuner_error_cents = (float)atof(update->Text);

            arc_value = (int32_t)clampf(tuner_error_cents, -50.0f, 50.0f);

            // update LCD
            lv_arc_set_value(objects.ui_tuner_arc, arc_value);

            if (fabsf(tuner_error_cents) < 5.0f)
            {
                // green – in tune
                col = lv_color_hex(0x00FF88);      
            }
            else if (fabsf(tuner_error_cents) < 15.0f)
            {
                // orange
                col = lv_color_hex(0xFFAA00);      
            }
            else
            {
                // red
                col = lv_color_hex(0xFF4444);      
            }

            lv_obj_set_style_bg_color(objects.ui_tuner_arc, col, LV_PART_KNOB);

            // show Note
            if ((tuner_error_cents == 0.0f) && (update->Value == 0x80))
            {
                // no note detected
                sprintf(buf, "--");
            }
            else
            {
                control_get_midi_note_name(update->Value, current_tuner_ref_freq, buf, sizeof(buf) - 1);
            }
                            
            const char* current = lv_label_get_text(objects.ui_tuner_note_label);

            // check if note changed
            if (strcmp(current, buf) != 0)
            {
                // update label
                lv_label_set_text(objects.ui_tuner_note_label, buf);
            }
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
        } break;

        case UI_ELEMENT_TUNER_STATE:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI    
            if (usb_get_connected_modeller_type() == AMP_MODELLER_TONEX_ONE_PLUS)
            {
                if (update->Value == 1)
                {
                    // show tuner page
                    action_tuner_pressed(NULL);
                }        
                else 
                { 
                    // hide tuner page
                    action_tuner_close(NULL);
                }
            }
#endif  //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI          
        } break;

        case UI_ELEMENT_PROGRESS_BAR:
        {
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            lv_label_set_text(objects.ui_progress_label, update->Text);
            lv_bar_set_value(objects.ui_progress_bar, update->Value, LV_ANIM_ON);
            lv_obj_clear_flag(objects.ui_progress_dialog, LV_OBJ_FLAG_HIDDEN);
#endif
        } break;

        case UI_ELEMENT_PROGRESS_BAR_HIDE:
        {
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            lv_obj_add_flag(objects.ui_progress_dialog, LV_OBJ_FLAG_HIDDEN);
#endif
        } break;

        case UI_ELEMENT_LOG:
        {
            static char buf[320];
            const char *text = lv_label_get_text(objects.ui_debug_text);
            size_t text_length = strlen(text);
            size_t update_length = strnlen(update->Text, sizeof(update->Text));

            if ((text_length + 1 + update_length) >= sizeof(buf))
            {
                size_t retained_text_length = sizeof(buf) - update_length - 2;
                text += text_length - retained_text_length;
            }

            snprintf(buf, sizeof(buf), "%s\n%s", text, update->Text);
            
            lv_label_set_text(objects.ui_debug_text, buf);
            lv_obj_clear_flag(objects.ui_debug_container, LV_OBJ_FLAG_HIDDEN);
        } break;

        default:
        {
            ESP_LOGE(TAG, "Unknown display elment %d", update->ElementID);     
            return 0;        
        } break;
    }
    
    // check the action
    switch (update->Action)
    {
        case UI_ACTION_SET_STATE:
        {
            // check the element
            #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            if (element_1 == objects.ui_usb_button)
            {
                if (update->Value == 0)
                {
                    lv_obj_clear_state(objects.ui_usb_button, LV_STATE_CHECKED);
                }
                else
                {
                    lv_obj_add_state(objects.ui_usb_button, LV_STATE_CHECKED);
                }
            }
            else if (element_1 == objects.ui_bt_midi_button)
            {
                if (update->Value == 0)
                {
                    lv_obj_clear_state(objects.ui_bt_midi_button, LV_STATE_CHECKED);
                }
                else
                {
                    lv_obj_add_state(objects.ui_bt_midi_button, LV_STATE_CHECKED);
                }
            }
            else if (element_1 == objects.ui_bt_app_button)
            {
                if (update->Value == 0)
                {
                    lv_obj_clear_state(objects.ui_bt_app_button, LV_STATE_CHECKED);
                }
                else
                {
                    lv_obj_add_state(objects.ui_bt_app_button, LV_STATE_CHECKED);
                }
            }
            else if (element_1 == objects.ui_wi_fi_button)
            {
                if (update->Value == 0)
                {
                    lv_obj_clear_state(objects.ui_wi_fi_button, LV_STATE_CHECKED);
                }
                else
                {
                    lv_obj_add_state(objects.ui_wi_fi_button, LV_STATE_CHECKED);
                }
            }
            #else // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            if (element_1 == objects.ui_usb_status_fail)
            {
                if (update->Value == 0)
                {
                    // show the USB disconnected image
                    lv_obj_add_flag(objects.ui_usb_status_ok, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_usb_status_fail, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    // show the USB connected image
                    lv_obj_add_flag(objects.ui_usb_status_fail, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_usb_status_ok, LV_OBJ_FLAG_HIDDEN);
                }
            }
            else if (element_1 == objects.ui_bt_status_conn)
            {
                if (update->Value == 0)
                {
                    // show the BT disconnected image
                    lv_obj_add_flag(objects.ui_bt_status_conn, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_bt_status_disconn, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    // show the BT connected image
                    lv_obj_add_flag(objects.ui_bt_status_disconn, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_bt_status_conn, LV_OBJ_FLAG_HIDDEN);
                }
            }
            else if (element_1 == objects.ui_wi_fi_status_conn)
            {
                if (update->Value == 0)
                {
                    ESP_LOGI(TAG, "Show WiFi disconn");

                    // show the Wifi disconnected image
                    lv_obj_add_flag(objects.ui_wi_fi_status_conn, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_wi_fi_status_disconn, LV_OBJ_FLAG_HIDDEN);
                }
                else
                {
                    ESP_LOGI(TAG, "Show WiFi conn");

                    // show the WiFi connected image
                    lv_obj_add_flag(objects.ui_wi_fi_status_disconn, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(objects.ui_wi_fi_status_conn, LV_OBJ_FLAG_HIDDEN);
                }
            }
            #endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            else if (element_1 == objects.ui_skin_image)
            {
                set_skin_image(objects.ui_skin_image, update->Value, SKIN_SLOT_MAIN);
            }
            else if (element_1 == objects.ui_bank_value_label)
            {
                // set Bank index
                char buf[128];
                sprintf(buf, "%d", (int)round(update->State) + 1);
                lv_label_set_text(objects.ui_bank_value_label, buf);
            }
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
#endif //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI  
        } break;

//         case UI_ACTION_SET_AMP_SKIN_SLOT:
//         {
// #if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
// #endif
//         } break;

//         case UI_ACTION_SET_PRESET_BUTTON_SELECTED:
//         {
// #if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
//             bool selected1 = update->Value & 1;
//             bool selected2 = (update->Value >> 1) & 1;
//             bool selected3 = (update->Value >> 2) & 1;
//             bool selected4 = (update->Value >> 3) & 1;
            
//             lv_obj_set_style_outline_width(ui_PresetButton1, (selected1 ? 4 : 0), LV_PART_MAIN| LV_STATE_DEFAULT);
//             lv_obj_set_style_outline_width(ui_PresetButton2, (selected2 ? 4 : 0), LV_PART_MAIN| LV_STATE_DEFAULT);
//             lv_obj_set_style_outline_width(ui_PresetButton3, (selected3 ? 4 : 0), LV_PART_MAIN| LV_STATE_DEFAULT);
//             lv_obj_set_style_outline_width(ui_PresetButton4, (selected4 ? 4 : 0), LV_PART_MAIN| LV_STATE_DEFAULT);
// #endif   
//         } break;

        case UI_ACTION_SET_ALT_BUTTON:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            ui_AltMode = update->State;

            if (ui_AltMode) {
                lv_obj_add_state(objects.ui_alt_button, LV_STATE_CHECKED);
            } else {
                lv_obj_clear_state(objects.ui_alt_button, LV_STATE_CHECKED);
            }

            updateFSButtons();
#endif   
        } break;

        case UI_ACTION_SET_LABEL_TEXT:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
            lv_label_set_text(element_1, update->Text);

            if (lv_scr_act() == objects.presets) {
                updatePresetListSelection();
            }
#elif CONFIG_TONEX_CONTROLLER_DISPLAY_SMALL
            if (element_1 == objects.ui_preset_heading_label)
            {
                // split up preset into 2 text lines.
                // incoming has "XX: Name"
                char preset_index[16];
                char preset_name[33];

                // get the preset number
                sprintf(preset_index, "%d", atoi(update->Text));
                lv_label_set_text(objects.ui_preset_heading_label, preset_index);

                // get the preset name
                for (uint8_t loop = 0; loop < 4; loop++)
                {
                    if (update->Text[loop] == ':')
                    {
                        strncpy(preset_name, (const char*)&update->Text[loop + 2], sizeof(preset_name) - 1);
                        lv_label_set_text(objects.ui_preset_heading_label2, preset_name);
                        break;
                    }
                }
            }
            else
            {
                lv_label_set_text(element_1, update->Text);
            }
#endif            
        } break;

        case UI_ACTION_SET_ENTRY_TEXT:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
            lv_textarea_set_text(element_1, update->Text);
#endif            
        } break;

        case UI_ACTION_NONE:
        {
            // nothing needed
        } break;

        default:
        {
            ESP_LOGE(TAG, "Unknown display action %d, element %d", (int)update->Action, (int)update->ElementID);
        } break;
    }
#endif 

    return 1;
}

#if CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void ui_anim_hidden_cb(void *obj, int32_t value)
{
    lv_obj_t *target = (lv_obj_t *)obj;

    // Simple threshold: value ≥ 128 → visible, else hidden
    // → gives ~50% duty cycle flash
    if (value >= 128) 
    {
        lv_obj_clear_flag(target, LV_OBJ_FLAG_HIDDEN);
    } 
    else 
    {
        lv_obj_add_flag(target, LV_OBJ_FLAG_HIDDEN);
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void ui_anim_deleted_cb(lv_anim_t *anim) 
{
    if (anim->user_data) 
    {
        lv_mem_free(anim->user_data);
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void ui_BPMAnimate(lv_obj_t *target_obj, uint32_t duration)
{    
    // Delete any existing animations on the target object to avoid conflicts
    lv_anim_del(target_obj, (lv_anim_exec_xcb_t)ui_anim_hidden_cb);

    if (control_get_config_item_int(CONFIG_ITEM_DISABLE_BPM_FLASHER) == 1)
    {
        // disabled, do nothing
        return;
    }
    
    lv_obj_clear_flag(target_obj, LV_OBJ_FLAG_HIDDEN);

    lv_anim_t anim;

    lv_anim_init(&anim);
    lv_anim_set_var(&anim, target_obj);
    lv_anim_set_time(&anim, duration);
    lv_anim_set_user_data(&anim, NULL);
    lv_anim_set_exec_cb(&anim, ui_anim_hidden_cb);
    lv_anim_set_values(&anim, 255, 0); 
    lv_anim_set_path_cb(&anim, lv_anim_path_linear);
    lv_anim_set_delay(&anim, 0);
    lv_anim_set_deleted_cb(&anim, ui_anim_deleted_cb);
    lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_repeat_delay(&anim, 0);
    lv_anim_set_early_apply(&anim, true);

    // Start the animation
    lv_anim_start(&anim);
}
#endif

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void __attribute__((unused)) ui_toast_close(void) 
{
    ESP_LOGI(TAG, "Closing message box");

    // Close and delete the message box
    lv_msgbox_close(msgbox_data.mbox);
    msgbox_data.mbox = NULL;
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void __attribute__((unused)) ui_init_toast(void) 
{
    // Initialize styles
    msgbox_data.style_main = lv_mem_alloc(sizeof(lv_style_t));
    msgbox_data.style_text = lv_mem_alloc(sizeof(lv_style_t));
    if (!msgbox_data.style_main || !msgbox_data.style_text) 
    {
        ESP_LOGE(TAG, "Failed to allocate memory for styles");
        free(msgbox_data.style_main);
        free(msgbox_data.style_text);
        return;
    }

    lv_style_init(msgbox_data.style_main);
    lv_style_set_bg_color(msgbox_data.style_main, lv_color_hex(0x2A2A2A));
    lv_style_set_border_width(msgbox_data.style_main, 6);                 
    lv_style_set_radius(msgbox_data.style_main, 10);                      
    lv_style_set_bg_opa(msgbox_data.style_main, LV_OPA_COVER);            
    lv_style_set_pad_all(msgbox_data.style_main, platform_get_toast_padding());      
    lv_style_set_border_color(msgbox_data.style_main, lv_color_hex(0x563F2A));

    lv_style_init(msgbox_data.style_text);
    lv_style_set_text_color(msgbox_data.style_text, lv_color_hex(0xFFFFFF));

    // font size depends on screen size, let platform tell us
    lv_style_set_text_font(msgbox_data.style_text, platform_get_toast_font()); 
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
static void __attribute__((unused)) ui_show_toast(char* contents) 
{
    if (msgbox_data.mbox != NULL)
    {
        lv_obj_del(msgbox_data.mbox);
        msgbox_data.mbox = NULL;
    }

    // Create message box (no buttons for auto-close)
    static const char *btns[] = {""}; // Empty button list
    msgbox_data.mbox = lv_msgbox_create(NULL, NULL, contents, btns, false);
    if (!msgbox_data.mbox) 
    {
        ESP_LOGE(TAG, "Failed to create message box");
        return;
    }
    
    // Apply styles
    lv_obj_add_style(msgbox_data.mbox, msgbox_data.style_main, LV_PART_MAIN); // Style background
    lv_obj_add_style(lv_msgbox_get_text(msgbox_data.mbox), msgbox_data.style_text, 0);  // Style message

    lv_obj_center(msgbox_data.mbox);

#if CONFIG_TONEX_CONTROLLER_WAVESHARE_169_LANDSCAPE    
    // landscape mode needs rotation applied to match the UI
    // do layout calcs so we can get width/height of the message box
    lv_obj_update_layout(msgbox_data.mbox);

    // Set pivot point to center
    lv_obj_set_style_transform_pivot_x(msgbox_data.mbox, lv_obj_get_width(msgbox_data.mbox) / 2, 0);
    lv_obj_set_style_transform_pivot_y(msgbox_data.mbox, lv_obj_get_height(msgbox_data.mbox) / 2, 0);

    // apply rotation
    lv_obj_set_style_transform_angle(msgbox_data.mbox, -900, 0);
    lv_obj_center(msgbox_data.mbox);
#endif

    // Create timer to close and delete message box after 3 seconds
    msgbox_data.timer = xTaskGetTickCount() + 3000; 
    msgbox_data.active = 1;

    ESP_LOGI(TAG, "Message box created");
}

#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY        
/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void display_task(void *arg)
{
    tUIUpdate ui_update;

    ESP_LOGI(TAG, "Display task start");
 
    while (1) 
    {
        // Lock the mutex due to the LVGL APIs are not thread-safe
        if (display_lvgl_lock(pdMS_TO_TICKS(1000))) 
        {
            lv_task_handler();
            ui_tick();

            // check for any UI update messages
            if (xQueueReceive(ui_update_queue, (void*)&ui_update, 0) == pdPASS)
            {
                // process it
                update_ui_element(&ui_update);
            }

            // handle timed toast messages
            if (msgbox_data.active)
            {
                if (xTaskGetTickCount() >= msgbox_data.timer)
                {
                    // clean up and reset
                    ui_toast_close();
                    msgbox_data.active = 0;
                }
            }

            // Release the mutex
            display_lvgl_unlock();
	    }
        else
        {
            ESP_LOGW(TAG, "Display lock timeout");
        }

        vTaskDelay(pdMS_TO_TICKS(5));
    }
}
#endif //CONFIG_TONEX_CONTROLLER_HAS_DISPLAY

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
#if CONFIG_LV_USE_LOG
static void __attribute__((unused)) lv_log_cb(const char * buf)
{
    ESP_LOGI("LVGL", "%s", buf);
}
#endif  //CONFIG_LV_USE_LOG

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void display_init(i2c_master_bus_handle_t bus_handle, SemaphoreHandle_t I2CMutex, lv_disp_drv_t* pdisp_drv)
{    
    I2CMutexHandle = I2CMutex;
    disp_drv = pdisp_drv;

    // create queue for UI updates from other threads
    ui_update_queue = xQueueCreate(20, sizeof(tUIUpdate));
    if (ui_update_queue == NULL)
    {
        ESP_LOGE(TAG, "Failed to create UI update queue!");
    }

    lvgl_mux = xSemaphoreCreateRecursiveMutex();
    assert(lvgl_mux);

#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
    // Tick interface for LVGL (using esp_timer to generate 2ms periodic event)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &display_increase_lvgl_tick,
        .name = "lvgl_tick"
    };

    esp_timer_handle_t lvgl_tick_timer = NULL;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, DISPLAY_LVGL_TICK_PERIOD_MS * 1000));

    vTaskDelay(pdMS_TO_TICKS(10));

    // init GUI
    ESP_LOGI(TAG, "Init UI");
    ui_init();

    // init mem
    memset((void*)&msgbox_data, 0, sizeof(msgbox_data));

    // init toast
    ui_init_toast();

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    memset((void*)&SkinTOC, 0, sizeof(SkinTOC));
     
    // load skin table of contents
    ui_load_skin_toc();
#endif // CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI && !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

#if CONFIG_LV_USE_LOG
    // register log handler for lvgl
    lv_log_register_print_cb(lv_log_cb);
#endif  //CONFIG_LV_USE_LOG

#if CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR
    if (control_get_config_item_int(CONFIG_ITEM_DISABLE_BPM_FLASHER) == 1)
    {
        lv_obj_add_flag(objects.ui_bpm_indicator, LV_OBJ_FLAG_HIDDEN);
    }
#endif  //CONFIG_TONEX_CONTROLLER_SHOW_BPM_INDICATOR

    // create display task
    xTaskCreatePinnedToCore(display_task, "Dsp", DISPLAY_TASK_STACK_SIZE, NULL, DISPLAY_TASK_PRIORITY, NULL, 1);
#endif

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    customize_ui();
    loadSavedTheme();
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

    for (size_t index = 0; index < log_cache_count; index++)
    {
        UI_Log(&log_cache[index * MAX_UI_TEXT]);
    }
    free(log_cache);
    log_cache = NULL;
    log_cache_count = 0;
}
