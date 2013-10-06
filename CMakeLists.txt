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

set(rov_PORT ${TTY} CACHE STRING "The Unix Serial Device your Arduino is attached to.")
set(rov_BOARD "uno" CACHE STRING "What type of Arduino are you using?")
set(rov_SERIAL screen @SERIAL_PORT@ 19200)

set(rov_SRCS  rov.cpp)
# set(rov_HDRS  rov.h)


link_directories(${PROJECT_SOURCE_DIR}/ArduinoNunchuk)

generate_arduino_firmware(rov)

generate_arduino_example(ArduinoNunchuk_example
 	LIBRARY ArduinoNunchuk	
	EXAMPLE ArduinoNunchukDemo
	BOARD ${rov_BOARD}
	PORT ${rov_PORT}
	SERIAL ${rov_SERIAL}
	)



