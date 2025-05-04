#include <cstdint>

struct EEPROMData {
    int sensorType;
    uint32_t serialNumber;
};
extern EEPROMData eeprom;

extern void eepromInit();
extern void eepromRead();
void i2c_read(uint8_t byte);
void i2c_write(uint8_t data);