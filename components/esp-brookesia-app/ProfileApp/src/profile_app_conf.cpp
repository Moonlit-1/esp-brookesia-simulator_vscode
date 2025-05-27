/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "profile_app_conf.hpp"
#include "profile_app_conf_main.h"

using namespace std;

//LV_IMG_DECLARE(weather_icon);
LV_IMG_DECLARE(ui_img_sls_logo_png);
// This is a static variable to check if the app is already inited
static bool is_inited = false;

profileAppConf::profileAppConf(bool use_status_bar, bool use_navigation_bar):
    ESP_Brookesia_PhoneApp("Squareline", &ui_img_sls_logo_png, false, use_status_bar, use_navigation_bar)
{
}


profileAppConf::profileAppConf():
    ESP_Brookesia_PhoneApp("Profile", &ui_img_sls_logo_png, true)
{
}
profileAppConf::~profileAppConf()
{
    ESP_BROOKESIA_LOGD("Destroy(@0x%p)", this);
}
bool profileAppConf::run(void)
{
    ESP_BROOKESIA_LOGD("Run");

    // Create all UI resources here
    ESP_BROOKESIA_CHECK_FALSE_RETURN(profile_app_conf_main_init(this), false, "Main init failed");
    return true;
}
bool profileAppConf::back(void)
{
    ESP_BROOKESIA_LOGD("Back");

    // If the app needs to exit, call notifyCoreClosed() to notify the core to close the app
    ESP_BROOKESIA_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");

    return true;
}
bool profileAppConf::init()
{
    ESP_BROOKESIA_LOGD("Init");

    /* Do some initialization here if needed */
    // ESP_BROOKESIA_CHECK_FALSE_RETURN(!is_inited, false, "Already inited");
    // is_inited = true;
    return true;
}

bool profileAppConf::deinit()
{
    ESP_BROOKESIA_LOGD("Deinit");

    /* Do some deinitialization here if needed */
    // ESP_BROOKESIA_CHECK_FALSE_RETURN(is_inited, false, "Not inited");
    // is_inited = false;
    return true;
}
