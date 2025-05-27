/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <assert.h>
#include "esp_brookesia.h"
#include "ui/ui.h"
#include "profile_app_conf.hpp"
#include "profile_app_conf_main.h"

static profileAppConf *profile_app_conf = nullptr;
static void tab_changed_cb(lv_event_t * e)
{
    lv_obj_t * tabview = lv_event_get_target(e);

    // 获取当前选中的 tab index（0, 1, 2...）
    uint32_t tab_index = lv_tabview_get_tab_act(tabview);

    if(tab_index == 0) {
        // Tab 1 时
        lv_obj_set_style_opa(ui_Screen1_Button_Buttonleft, LV_OPA_COVER, LV_PART_MAIN);
        lv_obj_set_style_opa(ui_Screen1_Button_Buttonright, LV_OPA_80, LV_PART_MAIN);
    } else if(tab_index == 1) {
        // Tab 2 时
        lv_obj_set_style_opa(ui_Screen1_Button_Buttonleft, LV_OPA_60, LV_PART_MAIN);
        //lv_obj_set_style_bg_color(ui_Screen1_Button_Buttonright, lv_color_hex(0xFFFFFF), LV_PART_MAIN);
        lv_obj_set_style_opa(ui_Screen1_Button_Buttonright, LV_OPA_COVER, LV_PART_MAIN);
        //lv_obj_set_style_bg_color(ui_Screen1_Button_Buttonright, lv_color_hex(0xFFFFFF), LV_PART_MAIN);

    }
    // 根据你的需要继续扩展
}
bool profile_app_conf_main_init(profileAppConf *app)
{
    ESP_BROOKESIA_CHECK_NULL_RETURN(app, false, "App is null");
    profile_app_conf = app;
    profile_app_conf_ui_init();

    lv_obj_add_event_cb(ui_Screen1_Tabview_TabView, tab_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);

    return true;
}
