#include "modbus_functions.h"
#include "modbus_serial.h"
#include "modbus_crc.h"

void ModbusFunctions::readHoldingRegisters(int fd, uint8_t slaveAddr, uint16_t startAddr, uint16_t numRegs) {
    uint8_t request[8];
    request[0] = slaveAddr;
    request[1] = 0x03;
    request[2] = (startAddr >> 8) & 0xFF;
    request[3] = startAddr & 0xFF;
    request[4] = (numRegs >> 8) & 0xFF;
    request[5] = numRegs & 0xFF;
    uint16_t crc = ModbusCRC::calculateCRC(request, 6);
    request[6] = crc & 0xFF;
    request[7] = (crc >> 8) & 0xFF;

    ModbusSerial::modbusWrite(fd, request, 8);

    uint8_t response[5 + 2 * numRegs];
    ModbusSerial::modbusRead(fd, response, sizeof(response));

    // CRC ve veri kontrolü eklemelisiniz
}
