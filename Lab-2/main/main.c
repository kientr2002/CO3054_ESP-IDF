#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "esp_timer.h"



#define DEBOUNCE_TIME 50
#define LED_ON 1
#define LED_OFF 0

// We will using it when the button is holding not pressed
#define HOLD_TIME 1000
bool HOLDING_TASK = 0; 

static uint32_t current_ms()
{
    // get current time (ms)
    return esp_timer_get_time() / 1000;
}
// Task 1 Default every second
int LED2_STATE = 0; //led 2 is use to identify that Task1 is acive and this is the led's state
void print_studentID(void *pvParameter)
{
    //setup pin 2 for led.
    esp_rom_gpio_pad_select_gpio(GPIO_NUM_2);
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    if(!HOLDING_TASK){
        while (1)
            {
                /* code */
                // print student ID and time (s)
                printf("%lld s: 2013552 2013223\n", esp_timer_get_time() / 1000000);
                gpio_set_level(GPIO_NUM_2, LED2_STATE);
                //Reverse led 2 state
                LED2_STATE = LED2_STATE?LED_OFF:LED_ON;
                vTaskDelay(1000 / portTICK_PERIOD_MS); //1s
            }
    }

    
}
// Task 2 When the button pressed

void read_button(void *param)
    {
    // setup pin 17 for button (pull-up)
    esp_rom_gpio_pad_select_gpio(GPIO_NUM_17);
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_17, GPIO_PULLUP_ONLY);

    // setup pin 5 for led.
    esp_rom_gpio_pad_select_gpio(GPIO_NUM_5);
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    //initial variable
    int previousStableState = 1; //Using after DEBOUNCE_TIME
    int previousState = 1; //Every times
    int currentState;

    uint32_t lastDebounceTime = 0; // the last time input pin was toggled

    while (1)
    {
        /* code */
        // read the state of the button:
        currentState = gpio_get_level(GPIO_NUM_17);
        // If the button changed, due to noise or pressing:
        if (currentState != previousState)
        {
            lastDebounceTime = current_ms();
            previousState = currentState;
        }
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state:
        if ((current_ms() - lastDebounceTime) > DEBOUNCE_TIME)
        {
            // if the button state has changed
            if (previousStableState == 1 && currentState == 0)
            {
                gpio_set_level(GPIO_NUM_5, LED_ON);
                printf("ESP32\n");
            } else if (previousStableState == 0 && currentState == 1)
            {
                gpio_set_level(GPIO_NUM_5, LED_OFF);
            } else if (previousStableState == 0 && currentState == 0){
                if((current_ms() - lastDebounceTime) > HOLD_TIME){
                    printf("Button is holding!\n");
                        HOLDING_TASK = 1;
                } 
                
            }
            previousStableState = currentState;
        }
        vTaskDelay(20 / portTICK_PERIOD_MS);
    }
    
}

void app_main(void)
{
    xTaskCreate(print_studentID, "Task 1", 2048, NULL, 5, NULL);
    xTaskCreate(read_button, "Task 2", 2048, NULL, 6, NULL);
}

//Run task without GUI: idf.py build ; idf.py -p COM3 flash ; idf.py -p COM3 monitor