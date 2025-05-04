#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../h/main.h"

void setStatusLed ()
{
    if (adc.sensorTemperature < 85.0)
    {
        ledSetGreen();
        ledResetYellow();
    }
    else if (adc.sensorTemperature >= 85.0)
    {
        ledSetYellow();
        ledResetGreen();
    }      
    
    if (adc.sensorTemperature < 5.0 || adc.sensorTemperature >= 105.0)
        ledSetRed();
    else
        ledResetRed();
    
}
int main(void)
{
    eepromInit();
    ledInit();
    adcInit();
    uint16_t measurementCounter=0;
    uint16_t counterTime=0;
    FILE *log_file = NULL;
    log_file = fopen("run_log_file.txt", "a");
    
    if (log_file == NULL) {
        fprintf(stderr, "Error opening log file!\n");
        return 1;
    }
    while(counterTime<1000)
    {         
            if (measurementCounter>TEMP_MEASUREMENT_INTERVAL)
            {
                adcRead();
                measurementCounter=0;
            }
            else
                measurementCounter++;

            eepromRead();
            updateTemperature();
            setStatusLed();
            counterTime++;

            fprintf(log_file, " sensor type: %d sensor ADC: %d sensor Temp: %f Green led Status: %s 
                Yellow led Status: %s Red led Status: %s\n",
                eeprom.sensorType, adc.sensorReading, adc.sensorTemperature, 
                led.Green ? "true" : "false" , led.Yellow ? "true" : "false" , led.Red ? "true" : "false");
        
    }

    fclose(log_file);
    log_file = NULL;
    exit;
        

    

}