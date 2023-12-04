#include <stdio.h>
#include <time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_event.h"
#include "esp_wifi.h"
#include "esp_err.h"
#include "nvs_flash.h"


esp_err_t eventHandler(void *ctx, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    if (event_id == WIFI_EVENT_SCAN_DONE) {
        printf("Number of access points found: %d\n", ((wifi_event_sta_scan_done_t *)event_data)->number);
        uint16_t apCount = ((wifi_event_sta_scan_done_t *)event_data)->number;
        if (apCount == 0) {
            return ESP_OK;
        }
        wifi_ap_record_t *list = (wifi_ap_record_t *)malloc(sizeof(wifi_ap_record_t) * apCount);
        ESP_ERROR_CHECK(esp_wifi_scan_get_ap_records(&apCount, list));
        int i;
        for (i = 0; i < apCount; i++) {
            char *authmode;
            switch (list[i].authmode) {
                case WIFI_AUTH_OPEN:
                    authmode = "WIFI_AUTH_OPEN";
                    break;
                case WIFI_AUTH_WEP:
                    authmode = "WIFI_AUTH_WEP";
                    break;
                case WIFI_AUTH_WPA_PSK:
                    authmode = "WIFI_AUTH_WPA_PSK";
                    break;
                case WIFI_AUTH_WPA2_PSK:
                    authmode = "WIFI_AUTH_WPA2_PSK";
                    break;
                case WIFI_AUTH_WPA_WPA2_PSK:
                    authmode = "WIFI_AUTH_WPA_WPA2_PSK";
                    break;
                default:
                    authmode = "Unknown";
                    break;
            }
            printf("Wifi Name: %s, Signal Strength: %d, Auth=%s\n", list[i].ssid, list[i].rssi, authmode);
        }
        free(list);
    }
    return ESP_OK;
}

void app_main(void) {
    nvs_flash_init();
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_storage(WIFI_STORAGE_RAM));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_ERROR_CHECK(esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &eventHandler, NULL));

    wifi_scan_config_t scanConf = {
        .ssid = NULL,
        .bssid = NULL,
        .channel = 0,
        .show_hidden = 1
    };
    ESP_ERROR_CHECK(esp_wifi_scan_start(&scanConf, 0));
}