# Embedded System Lab 04: FreeRTOS Queue Management
* Description: <br>
  Suppose that we are designing an application on the ESP32 development board in which there are one reception task and some functional tasks. The reception task is designed to receive requests from somewhere and classify these tasks and send them to a queue. Each functional task would check if the next request is for it or not. If yes, it will receive the request and handle it. Vice versa, it does nothing. If no functional task receives the request, raise an error and simply ignore that request. Students are asked to implement an example for the application model mentioned above. <br>
* Preparation:
   * IDE and Extensions (We use VSCode and Espressif IDF, You can reference from [here](https://github.com/kientr2002/CO3054_ESP-IDF)
   * Mtiny ESP32 WROOM-32E (Arduino Compatible) (You also use another version of ESP32, this device that you can buy [here](https://hshop.vn/products/mach-mtiny-esp32-wroom-32e-arduino-compatible)) <br>
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab1/10.png)
   *  Mtiny Programmer (Arduino Compatible) (You must use it if you buy the ESP32 like the one above, this device that you can buy [here](https://hshop.vn/products/mach-mtiny-programmer-arduino-compatible)) <br>
     ![Lab2](https://github.com/kientr2002/CO3054_ESP-IDF/blob/main/Images/Lab1/11.png)
* Result: All Details are written in logs.txt
