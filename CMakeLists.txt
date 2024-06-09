cmake_minimum_required(VERSION 3.10)
project(ModbusLibrary)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_library(modbus_lib
    src/modbus_config.cpp
    src/modbus_crc.cpp
    src/modbus_functions.cpp
    src/modbus_serial.cpp
)

add_executable(main main.cpp)
target_link_libraries(main modbus_lib)
