# tolmodbus
Modbus Library for RTU 

```
# Modbus Library

This library is developed to implement the Modbus protocol using C++ with termios. It includes functions for serial port configuration, CRC calculation, and the implementation of Modbus function codes.

## Directory Structure
```

```
modbus_lib/
├── include/
│   ├── modbus_config.h
│   ├── modbus_crc.h
│   ├── modbus_functions.h
│   └── modbus_serial.h
├── src/
│   ├── modbus_config.cpp
│   ├── modbus_crc.cpp
│   ├── modbus_functions.cpp
│   └── modbus_serial.cpp
├── CMakeLists.txt
└── main.cpp
```

## Getting Started

### Prerequisites

- C++11 or later
- CMake 3.10 or later
- A C++ compiler (GCC, Clang, etc.)

### Installation

1. Clone the repository:
    ```sh
    git clone <repository_url>
    cd modbus_lib
    ```

2. Create the build directory and compile:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

3. Run the main program:
    ```sh
    ./main
    ```

### Usage

To use the library, include the appropriate header files in your main program and call the necessary functions.

#### Example:

```cpp
#include <iostream>
#include "modbus_config.h"
#include "modbus_functions.h"

int main() {
    const char* portname = "/dev/ttyUSB0";

    int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0) {
        std::cerr << "Error opening " << portname << ": " << strerror(errno) << std::endl;
        return -1;
    }

    if (ModbusConfig::configurePort(fd) != 0) {
        return -1;
    }

    ModbusFunctions::readHoldingRegisters(fd, 1, 0x0000, 10);

    close(fd);
    return 0;
}
```

### Modules

#### ModbusConfig

Manages serial port configuration.

- `static int configurePort(int fd, speed_t baudRate = B9600);`

#### ModbusCRC

Calculates CRC16 for Modbus messages.

- `static uint16_t calculateCRC(uint8_t *buffer, uint16_t length);`

#### ModbusFunctions

Implements Modbus protocol functions (e.g., reading holding registers).

- `static void readHoldingRegisters(int fd, uint8_t slaveAddr, uint16_t startAddr, uint16_t numRegs);`

#### ModbusSerial

Manages reading and writing data over the serial port.

- `static ssize_t modbusWrite(int fd, uint8_t* buffer, size_t length);`
- `static ssize_t modbusRead(int fd, uint8_t* buffer, size_t length);`

### License

This project is licensed under the MIT License. See the `LICENSE` file for more details.
```


