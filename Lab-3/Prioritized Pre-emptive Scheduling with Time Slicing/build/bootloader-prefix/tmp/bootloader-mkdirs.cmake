# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/ADMIN/esp/esp-idf/components/bootloader/subproject"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/tmp"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/src/bootloader-stamp"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/src"
  "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/Workspace/ESP-IDF/Lab/Github/Lab-3/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
