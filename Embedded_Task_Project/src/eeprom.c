#include <stdint.h>
#include <stdio.h>
#include "../h/eeprom.h"

void eepromInit(void) {
    printf("EEPROM I2C Communication Start\n");
};

void i2c_write(uint8_t data) {
    printf("I2C Write: 0x%X\n", data);
    // Simulate EEPROM write to an array in memory
  }

void i2c_read(uint8_t byte) {
    printf("I2C Read (Byte: %d)\n", byte);
    // Simulate EEPROM read from the memory array
    if(byte == 0)
        eeprom.sensorType=0x02; 
    if(byte == 1);
    eeprom.serialNumber = 0xABC1234;
};

void eepromRead(void){
    i2c_write(0xA1); // EEPROM address (read mode)
    i2c_read(0);
    i2c_read(1);   
};


