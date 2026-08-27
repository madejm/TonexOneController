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
#include "driver/i2c.h"
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
#define MAX_UI_TEXT                     130
#define MAX_SKIN_IMAGES                 100
#define SKIN_PARTITION_TYPE             0x40
#define SKIN_PARTITION_NAME             "skins"

enum UIElements
{
    UI_ELEMENT_USB_STATUS,
    UI_ELEMENT_BT_STATUS,
    UI_ELEMENT_WIFI_STATUS,
    UI_ELEMENT_WIFI_ENABLED,
    UI_ELEMENT_PRESET_NAME,
    UI_ELEMENT_BANK_INDEX,
    UI_ELEMENT_AMP_SKIN,
    UI_ELEMENT_ALT_BUTTON,
    UI_ELEMENT_FS_BUTTONS,
    UI_ELEMENT_PRESET_DESCRIPTION,
    UI_ELEMENT_PARAMETERS,
    UI_ELEMENT_TOAST,
    UI_ELEMENT_PRESET_LIST,
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

static bool ui_AltMode = false;
static uint8_t ui_PresetIndex = 0;
static uint8_t ui_BankIndex = 0;

#if CONFIG_TONEX_CONTROLLER_HAS_DISPLAY
static void ui_show_toast(char* contents);

#if CONFIG_TONEX_CONTROLLER_HAS_TOUCH
static uint8_t __attribute__((unused)) touch_data_ready_to_read = 0;
#endif

#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
typedef enum
{
    PRESET_LIST_INSERT_MODE_INSERT,
    PRESET_LIST_INSERT_MODE_SWAP
} PresetListInsertMode_t;

static PresetListInsertMode_t preset_list_insert_mode = PRESET_LIST_INSERT_MODE_INSERT;
static int16_t preset_list_insert_index = -1;

#define PRESET_LIST_PRESETS_PER_PAGE 10
static uint8_t preset_list_page = 0;

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
void display_lvgl_touch_cb(lv_indev_drv_t * drv, lv_indev_data_t * data)
{
    uint16_t touchpad_x[1] = {0};
    uint16_t touchpad_y[1] = {0};
    uint8_t touchpad_cnt = 0;
    bool touchpad_pressed = false;

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_LILYGO_TDISPLAY_S3 || CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_169TOUCH || CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_19TOUCH
    // CST816 driver has to set interrupt before data is valid to read
    if (touch_data_ready_to_read)
    {
        if (xSemaphoreTake(I2CMutexHandle, (TickType_t)10) == pdTRUE)
        {
            // Read touch controller data
            esp_lcd_touch_read_data(drv->user_data);

            // Get coordinates 
            touchpad_pressed = esp_lcd_touch_get_coordinates(drv->user_data, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

            // reset flag
            touch_data_ready_to_read = 0;

            xSemaphoreGive(I2CMutexHandle);
        }
    }

#else

    // poll the driver chip
    if (xSemaphoreTake(I2CMutexHandle, (TickType_t)10) == pdTRUE)
    {
        /* Read touch controller data */
        esp_lcd_touch_read_data(drv->user_data);

        /* Get coordinates */
        touchpad_pressed = esp_lcd_touch_get_coordinates(drv->user_data, touchpad_x, touchpad_y, NULL, &touchpad_cnt, 1);

        xSemaphoreGive(I2CMutexHandle);
    }
    else
    {
        ESP_LOGE(TAG, "Touch cb mutex timeout");
    }
#endif 

    if (touchpad_pressed && touchpad_cnt > 0) 
    {
        data->point.x = touchpad_x[0];
        data->point.y = touchpad_y[0];

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
/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_fs_button_clicked(uint32_t buttonIndex)
{
    for (uint32_t item = 0; item < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; item ++)
    {
        tExternalFootswitchEffectConfig config;
        
        control_get_config_item_external_fs_config(item, ui_AltMode, &config);

        if (config.Switch != buttonIndex) {
            continue;
        }

        TonexParameter_t param = midi_helper_get_param_for_change_num(config.CC, config.Value_1, config.Value_2);

        if (param == TONEX_UNKNOWN) {
            return;
        }
            
        ParamType_t type;
        FxSelectedValueIndex_t selectedValueIndex;
        uint8_t CC;

        if (fx_handler_helper_get_values(&param, config, &type, &selectedValueIndex, &CC) != ESP_OK) {
            return;
        }
        
        fx_handler_helper_update_parameter(param, config, type, selectedValueIndex, CC);
        return;
    }
}

void action_previous_bank_clicked(lv_event_t * e)
{
    control_request_bank_down();
}
void action_next_bank_clicked(lv_event_t * e)
{
    control_request_bank_up();
}
void action_tap_tempo_clicked(lv_event_t * e)
{
    control_trigger_tap_tempo();
}
void action_fs1_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(0);
    } else {
        control_request_preset_in_bank_index(0);
    }
}
void action_fs2_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(1);
    } else {
        control_request_preset_in_bank_index(1);
    }
}
void action_fs3_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(2);
    } else {
        control_request_preset_in_bank_index(2);
    }
}
void action_fs4_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(3);
    } else {
        control_request_preset_in_bank_index(3);
    }
}
void action_fs5_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(4);
    } else {
        control_request_bank_down();
    }
}
void action_fs6_clicked(lv_event_t * e)
{
    if (ui_AltMode) {
        action_fs_button_clicked(5);
    } else {
        control_request_bank_up();
    }
}
void action_fs7_clicked(lv_event_t * e)
{
    action_fs_button_clicked(6);
}
void action_fs8_clicked(lv_event_t * e)
{
    action_fs_button_clicked(7);
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

void action_usb_flash(lv_event_t * e) {
    usb_enter_download_mode();
}

void action_wi_fi_enabled_changed(lv_event_t * e) {
    lv_obj_t *wifi_switch = lv_event_get_target(e);
}
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM

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

    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
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

    action_keyboard_ok(e);
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

    if(event_code == LV_EVENT_READY) 
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
void action_parameter_changed(lv_event_t * e)
{
    switch (usb_get_connected_modeller_type())
    {
        case AMP_MODELLER_TONEX_ONE:        // fallthrough
        case AMP_MODELLER_TONEX:            // fallthrough
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

static void updatePresetListSelection()
{
    uint8_t pageStart = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;
    uint8_t selectedPreset = control_get_current_preset_mapped_index();

    lv_obj_set_checked(objects.ui_preset_list_button_0, selectedPreset == (pageStart + 0));
    lv_obj_set_checked(objects.ui_preset_list_button_1, selectedPreset == (pageStart + 1));
    lv_obj_set_checked(objects.ui_preset_list_button_2, selectedPreset == (pageStart + 2));
    lv_obj_set_checked(objects.ui_preset_list_button_3, selectedPreset == (pageStart + 3));
    lv_obj_set_checked(objects.ui_preset_list_button_4, selectedPreset == (pageStart + 4));
    lv_obj_set_checked(objects.ui_preset_list_button_5, selectedPreset == (pageStart + 5));
    lv_obj_set_checked(objects.ui_preset_list_button_6, selectedPreset == (pageStart + 6));
    lv_obj_set_checked(objects.ui_preset_list_button_7, selectedPreset == (pageStart + 7));
    lv_obj_set_checked(objects.ui_preset_list_button_8, selectedPreset == (pageStart + 8));
    lv_obj_set_checked(objects.ui_preset_list_button_9, selectedPreset == (pageStart + 9));
}

static inline void lv_label_set_preset_name(lv_obj_t* label, uint8_t index)
{
    char name[MAX_PRESET_NAME_LENGTH];
    char text[MAX_PRESET_NAME_LENGTH + 8];
    control_get_preset_name(index, name);
    snprintf(text, sizeof(text), "%u: %s", index + usb_get_first_preset_index_for_connected_modeller(), name);
    lv_label_set_text(label, text);
}

static inline void lv_panel_set_preset_color(lv_obj_t* colorPanel, uint8_t index)
{
    uint32_t color = get_preset_color(index);
    lv_obj_set_style_outline_color(colorPanel, lv_color_hex(color), LV_PART_MAIN | LV_STATE_DEFAULT);
}

static void updatePresetListNames()
{
    uint8_t pageStart = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;

    lv_label_set_preset_name(objects.ui_preset_list_label_0, pageStart + 0);
    lv_label_set_preset_name(objects.ui_preset_list_label_1, pageStart + 1);
    lv_label_set_preset_name(objects.ui_preset_list_label_2, pageStart + 2);
    lv_label_set_preset_name(objects.ui_preset_list_label_3, pageStart + 3);
    lv_label_set_preset_name(objects.ui_preset_list_label_4, pageStart + 4);
    lv_label_set_preset_name(objects.ui_preset_list_label_5, pageStart + 5);
    lv_label_set_preset_name(objects.ui_preset_list_label_6, pageStart + 6);
    lv_label_set_preset_name(objects.ui_preset_list_label_7, pageStart + 7);
    lv_label_set_preset_name(objects.ui_preset_list_label_8, pageStart + 8);
    lv_label_set_preset_name(objects.ui_preset_list_label_9, pageStart + 9);

    lv_panel_set_preset_color(objects.ui_preset_list_color_0, pageStart + 0);
    lv_panel_set_preset_color(objects.ui_preset_list_color_1, pageStart + 1);
    lv_panel_set_preset_color(objects.ui_preset_list_color_2, pageStart + 2);
    lv_panel_set_preset_color(objects.ui_preset_list_color_3, pageStart + 3);
    lv_panel_set_preset_color(objects.ui_preset_list_color_4, pageStart + 4);
    lv_panel_set_preset_color(objects.ui_preset_list_color_5, pageStart + 5);
    lv_panel_set_preset_color(objects.ui_preset_list_color_6, pageStart + 6);
    lv_panel_set_preset_color(objects.ui_preset_list_color_7, pageStart + 7);
    lv_panel_set_preset_color(objects.ui_preset_list_color_8, pageStart + 8);
    lv_panel_set_preset_color(objects.ui_preset_list_color_9, pageStart + 9);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_open_presets_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_open_presets_page");

    updatePresetListSelection();
    updatePresetListNames();
    lv_scr_load_anim(objects.presets, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_close_presets_page(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_close_presets_page");

    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_select(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_select");

    uint8_t button_index = (uint8_t)(intptr_t)lv_event_get_user_data(e);
    uint8_t preset_index = button_index + preset_list_page * PRESET_LIST_PRESETS_PER_PAGE;
    lv_scr_load_anim(objects.screen1, LV_SCR_LOAD_ANIM_FADE_IN, 0, 0, false);
    control_request_preset_index(preset_index);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_previous(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_previous");

    if (preset_list_page == 0) {
        preset_list_page = usb_get_max_presets_for_connected_modeller() / PRESET_LIST_PRESETS_PER_PAGE - 1;
    } else {
        preset_list_page -= 1;
    }
    updatePresetListSelection();
    updatePresetListNames();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_next(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_next");

    if (preset_list_page == (usb_get_max_presets_for_connected_modeller() / PRESET_LIST_PRESETS_PER_PAGE - 1)) {
        preset_list_page = 0;
    } else {
        preset_list_page += 1;
    }
    updatePresetListSelection();
    updatePresetListNames();
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_options(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_options");

    uint8_t buttonIndex = (intptr_t)lv_event_get_user_data(e);
    preset_list_insert_index = preset_list_page * PRESET_LIST_PRESETS_PER_PAGE + buttonIndex;

    lv_textarea_set_text(objects.ui_preset_list_dialog_number_entry, "");
    
    lv_label_set_preset_name(objects.ui_preset_list_dialog_name, preset_list_insert_index);

    lv_obj_clear_flag(objects.ui_preset_list_dialog, LV_OBJ_FLAG_HIDDEN);
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_insert_clicked(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_insert_clicked");

    if (lv_obj_has_state(objects.ui_preset_list_dialog_button_insert, LV_STATE_CHECKED)) {
        preset_list_insert_mode = PRESET_LIST_INSERT_MODE_SWAP;
        lv_obj_add_state(objects.ui_preset_list_dialog_button_swap, LV_STATE_CHECKED);
    } else {
        preset_list_insert_mode = PRESET_LIST_INSERT_MODE_INSERT;
        lv_obj_clear_state(objects.ui_preset_list_dialog_button_swap, LV_STATE_CHECKED);
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_swap_clicked(lv_event_t * e)
{
    ESP_LOGI(TAG, "action_preset_list_swap_clicked");

    if (lv_obj_has_state(objects.ui_preset_list_dialog_button_swap, LV_STATE_CHECKED)) {
        preset_list_insert_mode = PRESET_LIST_INSERT_MODE_INSERT;
        lv_obj_add_state(objects.ui_preset_list_dialog_button_insert, LV_STATE_CHECKED);
    } else {
        preset_list_insert_mode = PRESET_LIST_INSERT_MODE_SWAP;
        lv_obj_clear_state(objects.ui_preset_list_dialog_button_insert, LV_STATE_CHECKED);
    }
}

/****************************************************************************
* NAME:        
* DESCRIPTION: 
* PARAMETERS:  
* RETURN:      
* NOTES:       
*****************************************************************************/
void action_preset_list_keyboard_ok(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if (event_code == LV_EVENT_READY) 
    {
        ESP_LOGI(TAG, "action_preset_list_keyboard_ok");
   
        if (preset_list_insert_index > -1)
        {
            char* text = (char*)lv_textarea_get_text(objects.ui_preset_list_dialog_number_entry);
            int value = atoi(text);
            uint8_t presetsCount = usb_get_max_presets_for_connected_modeller();

            if (value > 0 && value <= presetsCount)
            {
                uint8_t newPresetSlot = value - 1;
                uint8_t newPresetOrder[MAX_SUPPORTED_PRESETS];
                memcpy(newPresetOrder, control_get_preset_order(), MAX_SUPPORTED_PRESETS);
                
                switch (preset_list_insert_mode)
                {
                    case PRESET_LIST_INSERT_MODE_INSERT:
                    {
                        uint8_t movedValue = newPresetOrder[preset_list_insert_index];

                        if (preset_list_insert_index < newPresetSlot)
                        {
                            // Shift left
                            for (uint8_t i = preset_list_insert_index; i < newPresetSlot; i++)
                            {
                                newPresetOrder[i] = newPresetOrder[i + 1];
                            }
                        }
                        else if (preset_list_insert_index > newPresetSlot)
                        {
                            // Shift right
                            for (uint8_t i = preset_list_insert_index; i > newPresetSlot; i--)
                            {
                                newPresetOrder[i] = newPresetOrder[i - 1];
                            }
                        }
                        newPresetOrder[newPresetSlot] = movedValue;
                    } break;

                    case PRESET_LIST_INSERT_MODE_SWAP:
                    {
                        uint8_t temp = newPresetOrder[preset_list_insert_index];
                        newPresetOrder[preset_list_insert_index] = newPresetOrder[newPresetSlot];
                        newPresetOrder[newPresetSlot] = temp;
                    } break;

                    default:
                        break;
                }

                control_set_preset_order(newPresetOrder);
                control_save_user_data(0);
                wifi_request_sync(WIFI_SYNC_TYPE_CONFIG, NULL, NULL);
                updatePresetListSelection();
                updatePresetListNames();
            }
            preset_list_insert_index = -1;
        }
        lv_obj_add_flag(objects.ui_preset_list_dialog, LV_OBJ_FLAG_HIDDEN);
    }
}

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
static void setFSSmallButton(
    uint32_t buttonIndex,
    lv_color_t color,
    FxSelectedValueIndex_t selectedValueIndex,
    const char *title,
    bool visible
) {
    lv_obj_t *smallButton;
    lv_obj_t *smallLabel;

    switch (buttonIndex) {
        case 0:
            smallButton = objects.ui_effect_button_small1;
            smallLabel =  objects.ui_effect_label_small1;
            break;
        case 1:
            smallButton = objects.ui_effect_button_small2;
            smallLabel =  objects.ui_effect_label_small2;
            break;
        case 2:
            smallButton = objects.ui_effect_button_small3;
            smallLabel =  objects.ui_effect_label_small3;
            break;
        case 3:
            smallButton = objects.ui_effect_button_small4;
            smallLabel =  objects.ui_effect_label_small4;
            break;
        case 4:
            smallButton = objects.ui_effect_button_small5;
            smallLabel =  objects.ui_effect_label_small5;
            break;
        case 5:
            smallButton = objects.ui_effect_button_small6;
            smallLabel =  objects.ui_effect_label_small6;
            break;
        case 6:
            smallButton = objects.ui_effect_button_small7;
            smallLabel =  objects.ui_effect_label_small7;
            break;
        case 7:
            smallButton = objects.ui_effect_button_small8;
            smallLabel =  objects.ui_effect_label_small8;
            break;
        default:
            return;
    }

    if (visible) {
        lv_obj_set_style_opa(smallButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    } else {
        lv_obj_set_style_opa(smallButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        return;
    }

    lv_label_set_text(smallLabel, title);
    lv_obj_set_style_bg_color(smallButton, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(smallButton, color, LV_PART_MAIN | LV_STATE_CHECKED);

    if (selectedValueIndex == FX_SELECTED_VALUE_2) {
        lv_obj_add_state(smallButton, LV_STATE_CHECKED);
    } else {
        lv_obj_clear_state(smallButton, LV_STATE_CHECKED);
    }
}

static void setFSBigButton(
    uint32_t buttonIndex,
    lv_color_t color,
    FxSelectedValueIndex_t selectedValueIndex,
    const char *title,
    const char *index,
    const char *value1,
    const char *value2,
    bool visible
) {
    lv_obj_t *button;
    lv_obj_t *nameLabel;
    lv_obj_t *indexLabel;
    lv_obj_t *onLabel;
    lv_obj_t *offLabel;

    switch (buttonIndex) {
        case 0:
            button =      objects.ui_effect_button1;
            nameLabel =   objects.ui_effect_label1;
            indexLabel =  objects.ui_preset_index1;
            onLabel =     objects.ui_effect_label1_on;
            offLabel =    objects.ui_effect_label1_off;
            break;
        case 1:
            button =      objects.ui_effect_button2;
            nameLabel =   objects.ui_effect_label2;
            indexLabel =  objects.ui_preset_index2;
            onLabel =     objects.ui_effect_label2_on;
            offLabel =    objects.ui_effect_label2_off;
            break;
        case 2:
            button =      objects.ui_effect_button3;
            nameLabel =   objects.ui_effect_label3;
            indexLabel =  objects.ui_preset_index3;
            onLabel =     objects.ui_effect_label3_on;
            offLabel =    objects.ui_effect_label3_off;
            break;
        case 3:
            button =      objects.ui_effect_button4;
            nameLabel =   objects.ui_effect_label4;
            indexLabel =  objects.ui_preset_index4;
            onLabel =     objects.ui_effect_label4_on;
            offLabel =    objects.ui_effect_label4_off;
            break;
        case 4:
            button =      objects.ui_effect_button5;
            nameLabel =   objects.ui_effect_label5;
            indexLabel =  NULL;
            onLabel =     objects.ui_effect_label5_on;
            offLabel =    objects.ui_effect_label5_off;
            break;
        case 5:
            button =      objects.ui_effect_button6;
            nameLabel =   objects.ui_effect_label6;
            indexLabel =  NULL;
            onLabel =     objects.ui_effect_label6_on;
            offLabel =    objects.ui_effect_label6_off;
            break;
        case 6:
            button =      objects.ui_effect_button7;
            nameLabel =   objects.ui_effect_label7;
            indexLabel =  NULL;
            onLabel =     objects.ui_effect_label7_on;
            offLabel =    objects.ui_effect_label7_off;
            break;
        case 7:
            button =      objects.ui_effect_button8;
            nameLabel =   objects.ui_effect_label8;
            indexLabel =  NULL;
            onLabel =     objects.ui_effect_label8_on;
            offLabel =    objects.ui_effect_label8_off;
            break;
        default:
            return;
    }

    if (visible) {
        lv_obj_set_style_opa(button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(button, LV_OBJ_FLAG_CLICKABLE);
    } else {
        lv_obj_set_style_opa(button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(button, LV_OBJ_FLAG_CLICKABLE);
        return;
    }

    lv_label_set_text(nameLabel, title);
    lv_obj_set_style_bg_color(button, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(button, color, LV_PART_MAIN | LV_STATE_CHECKED);

    if (selectedValueIndex == FX_SELECTED_VALUE_2) {
        lv_obj_add_state(button, LV_STATE_CHECKED);

        if (indexLabel != NULL) {
            lv_obj_add_state(indexLabel, LV_STATE_CHECKED);
        }
    } else {
        lv_obj_clear_state(button, LV_STATE_CHECKED);

        if (indexLabel != NULL) {
            lv_obj_clear_state(indexLabel, LV_STATE_CHECKED);
        }
    }

    if (indexLabel != NULL) {
        if (index != NULL) {
            lv_label_set_text(indexLabel, index);
            lv_obj_set_style_text_color(indexLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(indexLabel, LV_OBJ_FLAG_HIDDEN);
        } else {
            lv_obj_add_flag(indexLabel, LV_OBJ_FLAG_HIDDEN);
        }
    }

    if (value1 != NULL) {
        lv_label_set_text(offLabel, value1);
        lv_obj_clear_flag(offLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(offLabel, LV_OBJ_FLAG_HIDDEN);
    }

    if (value2 != NULL) {
        lv_label_set_text(onLabel, value2);
        lv_obj_clear_flag(onLabel, LV_OBJ_FLAG_HIDDEN);
    } else {
        lv_obj_add_flag(onLabel, LV_OBJ_FLAG_HIDDEN);
    }

    switch (selectedValueIndex) {
        case FX_SELECTED_VALUE_NONE: {
            lv_obj_set_style_opa(offLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;

        case FX_SELECTED_VALUE_1: {
            lv_obj_set_style_opa(offLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, color, LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;

        case FX_SELECTED_VALUE_2: {
            // lv_obj_set_style_opa(offLabel, 127, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_opa(offLabel, 152, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(offLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            // lv_obj_set_style_text_color(onLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(onLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        } break;
    }
}

static void updateFSButtons() {
    char buffer1[MAX_UI_TEXT];
    char buffer2[MAX_UI_TEXT];

    for (uint32_t buttonIndex = 0; buttonIndex < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; buttonIndex++)
    {
        for (int s = 0; s <= 1; s++)
        {
            bool small = s ? true : false;
            bool didSet = false;
            
            // if
            // small == false, ui_AltMode == false
            // or
            // small == true,  ui_AltMode == true
            bool alt = small == ui_AltMode;

            if (alt && buttonIndex < 6) {
                FxSelectedValueIndex_t selectedValueIndex = FX_SELECTED_VALUE_NONE;
                uint32_t color;
                char *name = NULL;
                const char *presetIndex = NULL;

                if (buttonIndex < 4) {
                    bool isInCurrentBank = (ui_PresetIndex/4) == ui_BankIndex;
                    uint16_t selectedPresetButtonIndex = ui_PresetIndex % 4;
                    bool selected = isInCurrentBank && selectedPresetButtonIndex == buttonIndex;
                    
                    uint8_t presetIndexValue = ui_BankIndex * 4 + buttonIndex;
                //     // selectedValueIndex = control_get_current_preset_index() == presetIndexValue ? FX_SELECTED_VALUE_2 : FX_SELECTED_VALUE_1;
                    selectedValueIndex = selected ? FX_SELECTED_VALUE_2 : FX_SELECTED_VALUE_1;
                    
                    const char *indexFormat = "%d";
                    switch (buttonIndex) {
                        case 0: indexFormat = "%dA"; break;
                        case 1: indexFormat = "%dB"; break;
                        case 2: indexFormat = "%dC"; break;
                        case 3: indexFormat = "%dD"; break;
                        default: break;
                    }
                    sprintf(buffer1, indexFormat, ui_BankIndex + 1);
                    presetIndex = buffer1;

                    control_get_preset_name(presetIndexValue, buffer2);
                    name = buffer2;

                    color = get_preset_color(presetIndexValue);
                } else {
                    name = buttonIndex == 4 ? "↓" : "↑";
                    color = theme_colors[THEME_ID_DEFAULT][COLOR_ID_DEFAULT_GRAY];
                }

                if (small) {
                    setFSSmallButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, true);
                } else {
                    setFSBigButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, presetIndex, NULL, NULL, true);
                }

                didSet = true;
            } else {
                for (uint32_t item = 0; item < MAX_EXTERNAL_EFFECT_FOOTSWITCHES; item++)
                {
                    tExternalFootswitchEffectConfig config;
                    
                    control_get_config_item_external_fs_config(item, !alt, &config);

                    if (config.Switch != buttonIndex) {
                        continue;
                    }

                    TonexParameter_t param = midi_helper_get_param_for_change_num(config.CC, config.Value_1, config.Value_2);

                    if (param == TONEX_UNKNOWN) {
                        break;
                    }
                    
                    ParamType_t type;
                    FxSelectedValueIndex_t selectedValueIndex;
                    MidiValue_t CC;

                    if (fx_handler_helper_get_values(&param, config, &type, &selectedValueIndex, &CC) != ESP_OK) {
                        break;
                    }

                    tModellerParameter *param_ptr;

                    if (tonex_params_get_locked_access(&param_ptr) != ESP_OK) {
                        break;
                    }

                    tModellerParameter param_entry = param_ptr[param];
                    // // float paramValue = param_entry.Value;
                    uint32_t color = 0x000000;
                    const char *name = NULL;
                    const char *value1 = NULL;
                    const char *value2 = NULL;

                    switch (type) {
                        case MODELLER_PARAM_TYPE_SWITCH: {
                        } break;

                        case MODELLER_PARAM_TYPE_SELECT: {
                        } break;

                        case MODELLER_PARAM_TYPE_RANGE: {
                    //         float value_1 = midi_helper_scale_midi_to_float(param, config.Value_1);
                    //         float value_2 = midi_helper_scale_midi_to_float(param, config.Value_2);
                    //         if ((param_entry.Max - param_entry.Min) > 10.0f) {
                    //             sprintf(buffer1, "%.0f", value_1);
                    //             sprintf(buffer2, "%.0f", value_2);
                    //         } else {
                    //             sprintf(buffer1, "%.1f", value_1);
                    //             sprintf(buffer2, "%.1f", value_2);
                    //         }
                    //         value1 = buffer1;
                    //         value2 = buffer2;
                        } break;
                    }

                    tonex_params_get_ui_style(
                        param,
                        config.Value_1,
                        config.Value_2,
                        &color,
                        &name,
                        &value1,
                        &value2,
                        param_ptr
                    );
                    tonex_params_release_locked_access();

                    if (small) {
                        setFSSmallButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, true);
                    } else {
                        setFSBigButton(buttonIndex, lv_color_hex(color), selectedValueIndex, name, NULL, value1, value2, true);
                    }

                    // done, break for loop and go to next buttonIndex
                    didSet = true;
                    break;
                }
            }

            if (!didSet) {
                if (small) {
                    setFSSmallButton(buttonIndex, lv_color_hex(0), FX_SELECTED_VALUE_NONE, NULL, false);
                } else {
                    setFSBigButton(buttonIndex, lv_color_hex(0), FX_SELECTED_VALUE_NONE, NULL, NULL, NULL, NULL, false);
                }
            }
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
void action_save_wifi_settings(lv_event_t * e)
{
    ESP_LOGI(TAG, "WiFi Set");
    
    WiFiMode WiFiMode = lv_dropdown_get_selected(objects.ui_wifi_mode_dropdown); // WIFI_MODE_ACCESS_POINT_TIMED
    WiFiTxPower WifiTxPower = lv_dropdown_get_selected(objects.ui_wifi_power_dropdown); // WIFI_TX_POWER_25

    char *WifiSSID = (char*)lv_textarea_get_text(objects.ui_wifi_ssid_textarea);
    char *WifiPassword = (char*)lv_textarea_get_text(objects.ui_wifi_password_textarea);
    char *MDNSName = (char*)lv_textarea_get_text(objects.ui_mdns_name_textarea);

    // char msg[33];
    // sprintf(msg, "WIFI: %u, %u", WiFiMode, WifiTxPower);
    // wifi_log_msg(msg);
    // wifi_log_msg(WifiSSID);
    // wifi_log_msg(WifiPassword);
    // wifi_log_msg(MDNSName);

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
void UI_SetPresetLabel(uint16_t index, char* name)
{
    tUIUpdate ui_update;

    // build command
    ui_update.ElementID = UI_ELEMENT_PRESET_NAME;
    ui_update.Action = UI_ACTION_SET_LABEL_TEXT;
    ui_update.Value = index;
    #if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    sprintf(ui_update.Text, name);
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
                    default:
                    {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
#if !CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
                        lv_obj_clear_flag(objects.ui_bottom_panel_tonex, LV_OBJ_FLAG_HIDDEN);
                        lv_obj_add_flag(objects.ui_bottom_panel_valeton, LV_OBJ_FLAG_HIDDEN);

                        // lv_label_set_text(objects.ui_project_heading_label, "Tonex Controller"); 
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
            // The custom home button represents WiFi power, not client connection state.
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

        case UI_ELEMENT_PRESET_NAME:
        {
            element_1 = objects.ui_preset_heading_label;
            ui_PresetIndex = update->Value;
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
            updateFSButtons();
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
        } break;

        case UI_ELEMENT_BANK_INDEX:
        {
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
            element_1 = objects.ui_bank_value_label;
#endif
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
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#endif //CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
        } break;

        case UI_ELEMENT_TOAST:
        {
            ui_show_toast(update->Text);
        } break;

        case UI_ELEMENT_PRESET_LIST:
        {
            if (lv_scr_act() == objects.presets) {
                updatePresetListSelection();
                updatePresetListNames();
            }
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
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
            else if (element_1 == objects.ui_bank_value_label)
            {
                // set Bank index
                char buf[128];
                sprintf(buf, "%d", (int)round(update->State) + 1);
                lv_label_set_text(objects.ui_bank_value_label, buf);
                ui_BankIndex = update->State;
#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
                updateFSButtons();
#endif //CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM  
            }
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
#endif

    // create display task
    xTaskCreatePinnedToCore(display_task, "Dsp", DISPLAY_TASK_STACK_SIZE, NULL, DISPLAY_TASK_PRIORITY, NULL, 1);
#endif

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
    customize_ui();
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
}
