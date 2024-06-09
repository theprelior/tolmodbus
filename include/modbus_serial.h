#ifndef MODBUS_SERIAL_H
#define MODBUS_SERIAL_H

#include <cstddef>
#include <cstdint>

class ModbusSerial {
public:
    static ssize_t modbusWrite(int fd, uint8_t* buffer, size_t length);
    static ssize_t modbusRead(int fd, uint8_t* buffer, size_t length);
};

#endif // MODBUS_SERIAL_H
