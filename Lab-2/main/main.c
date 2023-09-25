#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_timer.h"

void print_studentID(void *pvParameter)
{
    for (;;)
    {
        // print student ID and time (s)
        printf("Task1: 2013552 2013223, time: %lld(s)\n", esp_timer_get_time() / 1000000);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

#define DEBOUNCE_TIME 50

static uint32_t millis()
{
    // get current time (ms)
    return esp_timer_get_time() / 1000;
}

void read_button(void *param)
    {
    // setup pin 19 for button
    esp_rom_gpio_pad_select_gpio(GPIO_NUM_17);
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_17, GPIO_PULLUP_ONLY);

    // setup pin 5 for led
    esp_rom_gpio_pad_select_gpio(GPIO_NUM_5);
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    int lastSteadyState = 1;      // the previous steady state from the input pin
    int lastFlickerableState = 1; // the previous flickerable state from the input pin
    int currentState;             // the current reading from the input pin

    uint32_t lastDebounceTime = 0; // the last time input pin was toggled

    for (;;)
    {
        // read the state of the button:
        currentState = gpio_get_level(GPIO_NUM_17);

        // If the button changed, due to noise or pressing:
        if (currentState != lastFlickerableState)
        {
            // reset the debouncing timer
            lastDebounceTime = millis();
            // save the last flickable state
            lastFlickerableState = currentState;
        }

        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:
        if ((millis() - lastDebounceTime) > DEBOUNCE_TIME)
        {
            // if the button state has changed
            if (lastSteadyState == 1 && currentState == 0)
            {
                gpio_set_level(GPIO_NUM_5, 1);

                printf("ESP32\n");
            }
                else if (lastSteadyState == 0 && currentState == 1)
            {
                gpio_set_level(GPIO_NUM_5, 0);
            }
            // save the last steady state
            lastSteadyState = currentState;
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    xTaskCreate(print_studentID, "Print student ID", 2048, NULL, 5, NULL);
    xTaskCreate(read_button, "Reading from button", 2048, NULL, 6, NULL);
}