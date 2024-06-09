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
