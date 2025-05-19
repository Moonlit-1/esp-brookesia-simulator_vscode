/*
 * SPDX-FileCopyrightText: 2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <assert.h>
#include "esp_brookesia.h"
#include "ui/ui.h"
#include "weather_app_conf.hpp"
#include "weather_app_conf_main.h"

static WeatherAppConf *weather_app_conf = nullptr;

bool weather_app_conf_main_init(WeatherAppConf *app)
{
    ESP_BROOKESIA_CHECK_NULL_RETURN(app, false, "App is null");
    weather_app_conf = app;
    weather_app_conf_ui_init();
    return true;
}
