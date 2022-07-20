cmake_minimum_required(VERSION 3.20)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

project(firstEye)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

add_executable(firstEye.cbp main.cpp)

target_link_libraries(firstEye.cbp pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(firstEye.cbp)