add_executable(
    imu
    main.cpp
    imu/bno055/bno055.c
    imu/bno055/bno055_support.c
    imu/sh2/sh2.c
    imu/sh2/shtp.c
    imu/sh2/euler.c
    imu/sh2/sh2_util.c
    imu/sh2/sh2_SensorValue.c
)

# enable usb output, disable uart output
pico_enable_stdio_usb(imu 1)
pico_enable_stdio_uart(imu 0)

target_include_directories(
    imu
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# pull in common dependencies and additional pwm hardware support
target_link_libraries(imu pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(imu)

# add url via pico_set_program_url
example_auto_set_url(imu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-psabi")