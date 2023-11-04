#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_freertos_hooks.h"
#include "sdkconfig.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_system.h"
#include "driver/gpio.h"


volatile uint32_t ulIdleCycleCount = 0UL;
volatile uint16_t task1CycleCount = 0UL;
volatile uint16_t task2CycleCount = 0UL;
volatile uint16_t task3CycleCount = 0UL;


void vApplicationIdleHook(void) {
    ulIdleCycleCount++;
    printf("======================================\n");
    printf("Idle task\n");
    printf("======================================\n");
    
}

/*
    Task 1: (high, event)
    Print the counting from 1 to 1000
    Print the time (ms) after the count terminate
*/
void Task1(void){
    printf("======================================\n");
    printf("Task 1 will be start!\n");
    printf("======================================\n");
    int64_t begin_time = esp_timer_get_time();
    while (1)
    {
        /* code */
        task1CycleCount++;
        if(task1CycleCount > 1000){
            int64_t end_time = esp_timer_get_time();
            printf("======================================\n");
            printf("Task 1 terminate during: %lld ms\n", (end_time-begin_time)/1000);
            printf("======================================\n");
            printf("Task 1 ended!\n");
            printf("======================================\n");
            vTaskDelete(NULL);
        } else {
            printf("Task1 is Counting: %d\n",task1CycleCount);
        }
        
    }
       
    
}
/*
    Task 2: (Idle priority, continuous)
    Print the counting from 1 to 2000
    Print the time (ms) after the count terminate
*/
void Task2(void){
    printf("======================================\n");
    printf("Task 2 will be start!\n");
    printf("======================================\n");
    int64_t begin_time = esp_timer_get_time();
    while (1)
    {
        /* code */
        task2CycleCount++;
        if(task2CycleCount > 2000){
            int64_t end_time = esp_timer_get_time();
            printf("======================================\n");
            printf("Task 2 terminate during: %lld ms\n", (end_time-begin_time)/1000);
            printf("======================================\n");
            printf("Task 2 ended!\n");
            printf("======================================\n");
            vTaskDelete(NULL);
        } else {
            printf("Task2 is Counting: %d\n",task2CycleCount);
        }
        
    }
}

void Task3(void){
    printf("======================================\n");
    printf("Task 3 will be start!\n");
    printf("======================================\n");

    //TODO

    printf("======================================\n");
    printf("Task 3 ended!\n");
    printf("======================================\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}
void app_main() {
    xTaskCreatePinnedToCore(Task1, "Task1", 2048, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(Task2, "Task2", 2048, NULL, 2, NULL, 0);
    vTaskDelay(10000 / portTICK_PERIOD_MS);
    esp_register_freertos_idle_hook_for_cpu(vApplicationIdleHook, 0);
}