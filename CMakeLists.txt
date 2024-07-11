cmake_minimum_required(VERSION 3.13)

# initialize pico-sdk from GIT
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_FETCH_FROM_GIT on)
set(PICO_DEOPTIMIZED_DEBUG 1)
set(CMAKE_BUILD_TYP Debug)
set(-Wno-dev)

# initialize the SDK directly
include(pico_sdk_import.cmake)

project(example CXX C ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(main example.c)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(main pico_stdlib hardware_uart)

# enable usb output, disable uart output
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)

add_custom_command(TARGET main
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy -t ${beispiel_SOURCE_DIR} $<TARGET_FILE:main> $<TARGET_FILE_DIR:main>/main.uf2)