#include "modbus_serial.h"
#include <unistd.h>

ssize_t ModbusSerial::modbusWrite(int fd, uint8_t* buffer, size_t length) {
    return write(fd, buffer, length);
}

ssize_t ModbusSerial::modbusRead(int fd, uint8_t* buffer, size_t length) {
    return read(fd, buffer, length);
}
