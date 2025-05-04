#include <stdint.h>

struct ADCData {
    int sensorReading;
    float sensorTemperature;
};

extern ADCData adc;

extern void adcInit();
extern void adcRead();
extern void updateTemperature();


