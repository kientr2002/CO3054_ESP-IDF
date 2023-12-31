| Supported Targets | ESP32 | ESP32-C2 | ESP32-C3 | ESP32-C6 | ESP32-H2 | ESP32-S2 | ESP32-S3 |
| ----------------- | ----- | -------- | -------- | -------- | -------- | -------- | -------- |
# Embedded System Lab 02: ESP32 GPIO and FreeRTOS task
* Description:
  * Read Input and write Output to GPIO pins.
  * Create, schedule, and delete FreeRTOS tasks on the ESP32 development board.
  * Successfully complete the final exercise of the lab with the following content:
    * Students create 2 tasks and schedule them using FreeRTOS’s task management
functions: <br>
      • A cyclic task printing your student identifier every second. <br>
      • An acyclic task polling a button and print "ESP32" every when the button 
is pressed. <br>
* Preparation:
   * IDE and Extensions (We use VSCode and Espressif IDF, You can reference from [here](https://github.com/kientr2002/CO3054_ESP-IDF)
   * Mtiny ESP32 WROOM-32E (Arduino Compatible) (You also use another version of ESP32, this device that you can buy [here](https://hshop.vn/products/mach-mtiny-esp32-wroom-32e-arduino-compatible)) <br>
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab1/10.png)
   *  Mtiny Programmer (Arduino Compatible) (You must use it if you buy the ESP32 like the one above, this device that you can buy [here](https://hshop.vn/products/mach-mtiny-programmer-arduino-compatible)) <br>
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab1/11.png)
* Simulation Diagram:
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab2/1.png)
*  Real-life images:
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab2/2.png)
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
