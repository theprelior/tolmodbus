#ifndef MODBUS_CRC_H
#define MODBUS_CRC_H

#include <cstdint>

class ModbusCRC {
public:
    static uint16_t calculateCRC(uint8_t *buffer, uint16_t length);
};

#endif // MODBUS_CRC_H
