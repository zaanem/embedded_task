#include <stdint.h>
typedef struct {
    uint8_t sensorType;
    uint32_t serialNumber;
} Eeprom;

extern Eeprom eeprom;

extern void eepromInit();
extern void eepromRead();
void i2c_read(uint8_t byte);
void i2c_write(uint8_t data);