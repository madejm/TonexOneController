#include "display_cab_vir.h"
#include <stdio.h>
#include "sdkconfig.h"
#include <math.h>
#include "lvgl.h"
#if CONFIG_TONEX_CONTROLLER_DISPLAY_FULL_UI
    #include "screens.h"
    #include "actions.h"
#endif
#include "display_helpers.h"
#include "eq_canvas.h"
#include "tonex_params.h"
#include "control.h"

#if CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM
#define VIR_CABS_PAGES          2
#define VIR_CABS_GROUP_SIZE     3
#define VIR_CABS_GROUPS_COUNT   7
#define VIR_CABS_PAGE_SIZE      (VIR_CABS_GROUP_SIZE * VIR_CABS_GROUPS_COUNT)
#define VIR_CABS_COUNT          40
#define VIR_CABS_ARRAY_SIZE     ((VIR_CABS_GROUP_SIZE + 1) * VIR_CABS_GROUPS_COUNT)

static const char * vir_cabs_page_1[VIR_CABS_ARRAY_SIZE] = {
    "1x6 Brian May",
    "1x8 Fend '57 Champ",
    "1x10 Fend Princeton",
    "\n",
    "1x12 Fend '65 Delx Rev",
    "1x12 Mesa MK III",
    "1x12 Mesa Cali Tweed",
    "\n",
    "1x12 Dr. Z MAZ 18 Jr",
    "1x12 Orange Tiny Terror",
    "1x15 Fend '53 Bassman",
    "\n",
    "2x12 Fend '65 Twin Reverb",
    "2x12 AC30 Alnico Blue",
    "2x12 AC30 G12H",
    "\n",
    "2x12 Roland JC120",
    "2x12 Silvertone",
    "2x12 Orange PPC 212",
    "\n",
    "2x12 Mesa Recto Horiz",
    "2x12 Dr. Z Z-Wreck",
    "4x12 Marsh 1960AV",
    "\n",
    "4x12 Marsh 1960A V30",
    "4x12 Marsh 1960 VG12-80",
    "4x12 Marsh 1960A T75",
    ""
};

static const char * vir_cabs_page_2[VIR_CABS_ARRAY_SIZE] = {
    "4x12 Marsh 2551A",
    "4x12 Randall 412 JB",
    "4x12 Hiwatt",
    "\n",
    "4x12 Fender MH",
    "4x12 Mesa 4FB",
    "4x12 Peavey 5150",
    "\n",
    "4x12 Marshall JCM800",
    "4x12 Orange PPC 412",
    "4x12 Mesa Rect Trad Slnt",
    "\n",
    "4x12 Mesa Road King Blck",
    "4x12 Mesa Road King Vint",
    "4x12 Marsh Major",
    "\n",
    "4x12 Marsh Greenback 20W",
    "4x12 ENGL PRO XXL",
    "4x12 ENGL Std",
    "\n",
    "4x10 Ampeg SVT-410H",
    "1x15 Ampeg Heritage B15N",
    "8x10 Ampeg SVT-810 AV",
    "\n",
    "8x10 Orange OBC 810",
    " ",
    " ",
    ""
};

static const char * getVirCabName(uint8_t index)
{
    if (index >= VIR_CABS_COUNT) {
        return "";
    }
    uint8_t page = index / VIR_CABS_PAGE_SIZE;
    uint8_t indexOnPage = index - page * VIR_CABS_PAGE_SIZE;
    uint8_t group = indexOnPage / VIR_CABS_GROUP_SIZE;
    uint8_t element = indexOnPage % VIR_CABS_GROUP_SIZE;
    uint8_t resultIndex = group * (VIR_CABS_GROUP_SIZE + 1) + element;

    switch (page) {
        case 0:
            return vir_cabs_page_1[resultIndex];
        case 1:
            return vir_cabs_page_2[resultIndex];
        default:
            return "";
    }
}

static uint8_t virCabPage = 0;
static uint8_t virCabSelectedIndex = 0;

static void updateVIRCabButtonMatrixSelection()
{
    if (lv_obj_has_flag(objects.ui_settings_vir_cab_dialog, LV_OBJ_FLAG_HIDDEN)) {
        return;
    }

    lv_btnmatrix_clear_btn_ctrl_all(objects.ui_cabinet_vir_button_matrix, LV_BTNMATRIX_CTRL_CHECKED);

    switch (virCabPage) {
        case 0: {
            if (virCabSelectedIndex < VIR_CABS_PAGE_SIZE) {
                lv_btnmatrix_set_btn_ctrl(objects.ui_cabinet_vir_button_matrix, virCabSelectedIndex, LV_BTNMATRIX_CTRL_CHECKED);
            }
        } break;

        case 1: {
            if (virCabSelectedIndex >= VIR_CABS_PAGE_SIZE) {
                lv_btnmatrix_set_btn_ctrl(objects.ui_cabinet_vir_button_matrix, virCabSelectedIndex - VIR_CABS_PAGE_SIZE, LV_BTNMATRIX_CTRL_CHECKED);
            }
        } break;
    }
}

static void updateVIRCabButtonMatrixElements()
{
    if (lv_obj_has_flag(objects.ui_settings_vir_cab_dialog, LV_OBJ_FLAG_HIDDEN)) {
        return;
    }

    switch (virCabPage) {
        case 0: {
            lv_btnmatrix_set_map(objects.ui_cabinet_vir_button_matrix, vir_cabs_page_1);
            lv_btnmatrix_clear_btn_ctrl_all(objects.ui_cabinet_vir_button_matrix, LV_BTNMATRIX_CTRL_HIDDEN);
        } break;

        case 1: {
            lv_btnmatrix_set_map(objects.ui_cabinet_vir_button_matrix, vir_cabs_page_2);
            lv_btnmatrix_set_btn_ctrl(objects.ui_cabinet_vir_button_matrix, VIR_CABS_PAGE_SIZE - 2, LV_BTNMATRIX_CTRL_HIDDEN); // 19
            lv_btnmatrix_set_btn_ctrl(objects.ui_cabinet_vir_button_matrix, VIR_CABS_PAGE_SIZE - 1, LV_BTNMATRIX_CTRL_HIDDEN); // 20
        } break;
    }

    updateVIRCabButtonMatrixSelection();
}

uint8_t getVirCabSelectedModelIndex()
{
    return virCabSelectedIndex;
}

void setVirCabSelectedModelIndex(uint8_t index)
{
    if (index >= VIR_CABS_COUNT) {
        return;
    }
    virCabSelectedIndex = index;
    lv_label_set_text(objects.ui_cabinet_vir_model_label, getVirCabName(index));
    updateVIRCabButtonMatrixSelection();
}

void setVirCabSelectedButtonIndex(uint8_t index)
{
    setVirCabSelectedModelIndex(index + virCabPage * VIR_CABS_PAGE_SIZE);
}

// ==== ACTIONS ====

void action_settings_vir_dialog_open(lv_event_t * e)
{
    lv_obj_clear_flag(objects.ui_settings_vir_cab_dialog, LV_OBJ_FLAG_HIDDEN);
    updateVIRCabButtonMatrixElements();
}

void action_settings_vir_dialog_close(lv_event_t * e)
{
    lv_obj_add_flag(objects.ui_settings_vir_cab_dialog, LV_OBJ_FLAG_HIDDEN);
}

void action_settings_vir_dialog_page_next(lv_event_t * e)
{
    if (virCabPage < VIR_CABS_PAGES - 1) {
        virCabPage++;
    } else {
        virCabPage = 0;
    }
    updateVIRCabButtonMatrixElements();
}

void action_settings_vir_dialog_page_previous(lv_event_t * e)
{
    if (virCabPage > 0) {
        virCabPage--;
    } else {
        virCabPage = VIR_CABS_PAGES - 1;
    }
    updateVIRCabButtonMatrixElements();
}
#endif // CONFIG_TONEX_CONTROLLER_HARDWARE_PLATFORM_WAVESHARE_43B_CUSTOM