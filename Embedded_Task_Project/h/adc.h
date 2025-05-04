#include <stdint.h>
#define REVA_GAIN 1
#define REVB_GAIN 0.1

typedef struct {
    uint16_t sensorReading;
    float sensorTemperature;
} Adc;

extern void adcInit();
extern void adcRead();
extern void updateTemperature(void);

extern Adc adc;

