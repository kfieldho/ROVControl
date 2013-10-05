cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/arduino-cmake/cmake/ArduinoToolchain.cmake)

project(ROVControl)

# These work for my Mac and Chromebook and are reasonable guesses elsewhere
if (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin")
	set(TTY /dev/tty.usbmodem641)
elseif (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Linux")
	set(TTY /dev/ttyACM0)
else()
	set(TTY /dev/TTY0)
endif()

set(TTY ${TTY} CACHE STRING "The Unix Serial Device your Arduino is attached to.")
set(BOARD "uno" CACHE STRING "What type of Arduino are you using?")

set(rov_SRCS  rov.cpp)
# set(rov_HDRS  rov.h)

set(rov_BOARD ${BOARD})
set(rov_PORT ${TTY})

generate_arduino_firmware(rov)

