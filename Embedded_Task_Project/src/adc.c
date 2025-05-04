#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../h/adc.h"
#include "../h/eeprom.h"

#define ADC_HISTORY_SIZE 5
uint16_t adc_history[ADC_HISTORY_SIZE];
int history_index = 0;

void adcInit(void) {
  printf("Mock ADC initialized for virtual channel./n");
  printf("Clearing ADCAN0 interrupt flag./n");
  printf(" Set Timer/Counter1 to CTC mode (Clear Timer on Compare Match)./n");
  // Set the compare value to achieve approximately 100us with a 16MHz clock
  // Use a prescaler of 64.
  // 16000000 Hz / 64 = 250000 Hz
  // 1 / 250000 Hz = 4 microseconds per tick
  // To get 100us, we need 100 / 4 = 25 ticks.

  printf("Initialize counter. Enable Timer/Counter1 Interrupt.Set the prescaler to 64/n");

  // Seed the random number generator 
  srand(time(NULL));
  // Initialize the history with some random values
  for (int i = 0; i < ADC_HISTORY_SIZE; i++) {
    adc_history[i] = rand() % 4096; // Simulate a 12-bit ADC (0-4095)
  }
  printf("Setting ADCAN0 interrupt flag./n");
};

void adcRead(void) {
    uint16_t simulatedValue;
    // Simulate reading a slightly changing value
    if (eeprom.sensorType == 1)
        simulatedValue = rand() % 100 + 50; // Simulate a value around 50-150
    if (eeprom.sensorType == 2)
        simulatedValue = rand() % 1000 + 500; // Simulate a value around 500-1500
    
    printf("Read the ADC value from the ADCBUF./n");
    printf("clear the ADCAN0 interrupt flag./n");
    printf("Mock ADC reading  , simulated_value:%d \n", simulatedValue);
   
    // Update the history
    adc_history[history_index] = simulatedValue;
    history_index = (history_index + 1) % ADC_HISTORY_SIZE;
  
    adc.sensorReading=simulatedValue;
    printf("ADC process has finished. Real Time ISR is triggered./n");
     // Clearing ADC0 interrupt.
     // Enabling ADC0 interrupt.
     // Activating ADC0 Common interrupt (Control).
  };

 void updateTemperature(void)
  {
    if (eeprom.sensorType ==1)
      adc.sensorTemperature =  adc.sensorReading * REVA_GAIN ;

    if (eeprom.sensorType ==2)
      adc.sensorTemperature=  adc.sensorReading * REVB_GAIN ;

  };


