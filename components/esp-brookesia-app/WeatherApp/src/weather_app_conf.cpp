/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "weather_app_conf.hpp"
#include "weather_app_conf_main.h"

using namespace std;

LV_IMG_DECLARE(weather_icon);

// This is a static variable to check if the app is already inited
static bool is_inited = false;

WeatherAppConf::WeatherAppConf(bool use_status_bar, bool use_navigation_bar):
    ESP_Brookesia_PhoneApp(
        {
            .name = "Weather",
            .launcher_icon = ESP_BROOKESIA_STYLE_IMAGE(&weather_icon),
            .screen_size = ESP_BROOKESIA_STYLE_SIZE_RECT_PERCENT(100, 100),
            .flags = {
                .enable_default_screen = 0,
                .enable_recycle_resource = 1,
                .enable_resize_visual_area = 1,
            },
        },
        {
            .app_launcher_page_index = 0,
            .status_icon_area_index = 0,
            .status_icon_data = {
                .size = {},
                .icon = {
                    .image_num = 1,
                    .images = {
                        ESP_BROOKESIA_STYLE_IMAGE(&weather_icon),
                    },
                },
            },
            .status_bar_visual_mode = (use_status_bar) ? ESP_BROOKESIA_STATUS_BAR_VISUAL_MODE_SHOW_FIXED :
                                                         ESP_BROOKESIA_STATUS_BAR_VISUAL_MODE_HIDE,
            .navigation_bar_visual_mode = (use_navigation_bar) ? ESP_BROOKESIA_NAVIGATION_BAR_VISUAL_MODE_SHOW_FLEX :
                                                                 ESP_BROOKESIA_NAVIGATION_BAR_VISUAL_MODE_HIDE,
            .flags = {
                .enable_status_icon_common_size = 1,
                .enable_navigation_gesture = 1,
            },
        }
    )
{
}

WeatherAppConf::WeatherAppConf():
    ESP_Brookesia_PhoneApp("Weather", &weather_icon, true)
{
}
WeatherAppConf::~WeatherAppConf()
{
    ESP_BROOKESIA_LOGD("Destroy(@0x%p)", this);
}
bool WeatherAppConf::run(void)
{
    ESP_BROOKESIA_LOGD("Run");

    // Create all UI resources here
    ESP_BROOKESIA_CHECK_FALSE_RETURN(weather_app_conf_main_init(this), false, "Main init failed");
    return true;
}
bool WeatherAppConf::back(void)
{
    ESP_BROOKESIA_LOGD("Back");

    // If the app needs to exit, call notifyCoreClosed() to notify the core to close the app
    ESP_BROOKESIA_CHECK_FALSE_RETURN(notifyCoreClosed(), false, "Notify core closed failed");

    return true;
}
bool WeatherAppConf::init()
{
    ESP_BROOKESIA_LOGD("Init");

    /* Do some initialization here if needed */
    // ESP_BROOKESIA_CHECK_FALSE_RETURN(!is_inited, false, "Already inited");
    // is_inited = true;
    return true;
}

bool WeatherAppConf::deinit()
{
    ESP_BROOKESIA_LOGD("Deinit");

    /* Do some deinitialization here if needed */
    // ESP_BROOKESIA_CHECK_FALSE_RETURN(is_inited, false, "Not inited");
    // is_inited = false;
    return true;
}
