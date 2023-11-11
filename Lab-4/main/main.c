#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "freertos/queue.h"
#include "esp_timer.h"
#include <freertos/queue.h>

#define QUEUE_CAPACITY 4

QueueHandle_t xQueue;
//message structure
typedef enum{
  TASK1,
  TASK2,
  TASK3
} ID_t;
typedef struct {
   ID_t eDataID;
   int32_t lDataValue;
} Data;

// Some service functional
float random_Number(int32_t num1, int32_t num2)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float r = random * (num2 - num1);
    return num1 + r;
}
void not_send_Error(){
  printf("Do not send the data into the queue!!!\n");
}

void full_Queue_Error(){
  printf("Queue was full!!!\n");
}

// Task 1: Print random Student's Identification (from 2010000 - 2019999)
void task_1_sender(void *pvParameter){
  BaseType_t task1Status;
  const TickType_t task1Wait = pdMS_TO_TICKS(100UL);
  Data task1Buffer;
  srand(time(NULL));
  while (1)
  {
    /* code */
    task1Buffer.eDataID = TASK1;
    task1Buffer.lDataValue = random_Number(2010000, 2019999);
    task1Status = xQueueSendToBack(xQueue, &task1Buffer, task1Wait);
    if(task1Status == pdPASS){
      printf("Task 1: The Student's Identification is %ld\n", task1Buffer.lDataValue);
    } else {
      // Print error
      not_send_Error();
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }
  
}

// Task 2: Print random Student's GPA (from 0 to 10) 
void task_2_sender(void *pvParameter){
  BaseType_t task2Status;
  const TickType_t task2Wait = pdMS_TO_TICKS(100UL);
  Data task2Buffer;
  srand(time(NULL));
  while (1)
  {
    /* code */
    task2Buffer.eDataID = TASK2;
    task2Buffer.lDataValue = random_Number(0, 10);
    task2Status = xQueueSendToBack(xQueue, &task2Buffer, task2Wait);
    if(task2Status == pdPASS){
      printf("Task 2: The Student's GPA is %ld\n", task2Buffer.lDataValue);
    } else {
      // Print error
      not_send_Error();
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }  
}

// Task 3: Print Student's class number (from 101 to 199) 
void task_3_sender(void *pvParameter){
  BaseType_t task3Status;
  const TickType_t task3Wait = pdMS_TO_TICKS(100UL);
  Data task3Buffer;
  srand(time(NULL));
  while (1)
  {
    /* code */
    task3Buffer.eDataID = TASK3;
    task3Buffer.lDataValue = random_Number(0, 10);
    task3Status = xQueueSendToBack(xQueue, &task3Buffer, task3Wait);
    if(task3Status == pdPASS){
      printf("Task 3: The Student's class number is %ld\n", task3Buffer.lDataValue);
    } else {
      // Print error
      not_send_Error();
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
  }  
}

//Receive Task
void receive_Task(void *pvParameter){
  Data receive;

  while (1)
  {
    /* code */
    if(uxQueueMessagesWaiting(xQueue) == QUEUE_CAPACITY){
      //Print error
      full_Queue_Error();
    }
    if(xQueueReceive(xQueue, &receive, 0) == pdPASS){
      // if(receive.eDataID == TASK1){
      //   printf("1\n");
      // } else if(receive.eDataID == TASK2){
      //   printf("2\n");
      // } else if(receive.eDataID == TASK3){
      //   printf("3\n");
      // } 
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
}



void app_main(void){
  xQueue = xQueueCreate(QUEUE_CAPACITY, sizeof(Data));
  if(xQueue != NULL){
    //TODO
    printf("The queue created successfully!!!\n");
    xTaskCreatePinnedToCore(&task_1_sender, "task1", 1024 * 5, NULL, 2, NULL, 0);
    xTaskCreatePinnedToCore(&task_2_sender, "task2", 1024 * 5, NULL, 2, NULL, 0);
    xTaskCreatePinnedToCore(&task_3_sender, "task3", 1024 * 5, NULL, 2, NULL, 0);
    xTaskCreatePinnedToCore(&receive_Task, "receive", 1024 * 5, NULL, 1, NULL, 0);
  } else {
    printf("The queue created unsuccessfully!!!\n");
  }

}
