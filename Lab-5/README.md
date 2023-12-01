| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |
# Embedded System Lab 05: FreeRTOS Software Timer
* Description: <br>
  * Understanding FreeRTOS Software Timer:
  * Understanding Software Timer Callback Functions:
  * Understanding the characteristics and states of a Software Timer.
  * Understanding the Context of a Software Timer.
  * Understanding how to Create and Start a Software Timer and how to use related functions.
  * Understanding Timer ID and how to use related functions.
  * Knowing how to change the period of a Timer and understanding the operation of the xTimerChangePeriod() API Function, along with how to use it.
  * Knowing how to Reset a Timer and understanding the operation of the xTimerReset() API Function, along with how to use it.
  * Completing the exercises given at the end of the lab.
* Preparation:
   * IDE and Extensions (We use VSCode and Espressif IDF, You can reference from [here](https://github.com/kientr2002/CO3054_ESP-IDF)
   * ESP32-DevKitC-32D Module WiFi Bluetooth 2.4GHz (You also use another version of ESP32, this device that you can buy [here](https://www.thegioiic.com/esp32-devkitc-32d-module-wifi-bluetooth-2-4ghz)) <br>
     ![Lab5](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab5/esp32.png)
   * Technical Specifications:
      * Brand: Espressif
      * Type: Board
      * Supply Voltage: 3.3V
      * Integrated Bluetooth: Yes
      * Communication Interface: UART
      * Flash Memory: 4 MB
      * Operating Frequency: 2.4 GHz
   * Product Description:
      * Module Type: WiFi + Bluetooth
      * Main Processor: ESP32-WROOM-32D
      * Supported Protocols: 802.11 b/g/n
      * Bluetooth Version: Bluetooth v4.2
      * Frequency: 2.4 GHz
      * Supply Voltage: 3.3V, 5V
      * Communication Interfaces: GPIO, SPI, UART, I2C  <br>
     ![Lab5](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab5/esp32-real-diagram.png) <br>
      ![Lab5](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab5/esp32-diagram.png) <br>
* Result: All Details are written in logs.txt
* You also can reference the README.md from the development team below:<br>
# _Sample project_

(See the README.md file in the upper level 'examples' directory for more information about examples.)

This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.
