#include <stdio.h>
#include <time.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "freertos/queue.h"

QueueHandle_t xQueue;
//message structure
typedef struct {
   int eDataID;
   char *IDataValue;
}Data;
//TODO



void app_main(void){
  xQueue = xQueueCreate(3, sizeof(Data));
  if(xQueue != NULL){
    //TODO
  } else {
    printf("The queue created unsuccessfully!!!");
  }

}