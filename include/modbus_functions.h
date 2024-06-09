#ifndef MODBUS_FUNCTIONS_H
#define MODBUS_FUNCTIONS_H

#include <cstdint>

class ModbusFunctions {
public:
    static void readHoldingRegisters(int fd, uint8_t slaveAddr, uint16_t startAddr, uint16_t numRegs);
};

#endif // MODBUS_FUNCTIONS_H
