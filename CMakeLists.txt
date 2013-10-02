cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arduino-cmake/cmake/ArduinoToolchain.cmake)

project(ROVControl)

set(rov_SRCS  rov.cpp)
# set(rov_HDRS  rov.h)
set(rov_BOARD uno)
set(rov_PORT /dev/tty.usbmodem641)


generate_arduino_firmware(rov)

