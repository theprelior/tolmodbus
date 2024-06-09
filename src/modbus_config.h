#ifndef MODBUS_CONFIG_H
#define MODBUS_CONFIG_H

#include <termios.h>
#include <string>

class ModbusConfig {
public:
    static int configurePort(int fd, speed_t baudRate = B9600);
};

#endif // MODBUS_CONFIG_H
