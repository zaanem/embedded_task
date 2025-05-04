#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../h/led.h"
#include "../h/adc.h"
#include "../h/eeprom.h"

#define TEMP_MEASUREMENT_INTERVAL 1000

ADCData adc;
EEPROMData eeprom;

class StatusLedController {
public:
    void setStatusLed() {
        if (adc.sensorTemperature < 85.0) {
            ledSetGreen();
            ledResetYellow();
        } else if (adc.sensorTemperature >= 85.0) {
            ledSetYellow();
            ledResetGreen();
        }

        if (adc.sensorTemperature < 5.0 || adc.sensorTemperature >= 105.0) {
            ledSetRed();
        } else {
            ledResetRed();
        }
    }
};

class TemperatureSensor {
public:
    void readTemperature() {
        adcRead();
    }

    float getTemperature() const {
        return adc.sensorTemperature;
    }
};

class SensorLogger {
private:
    std::ofstream logFile;
    const std::string filename = "run_log_file.txt";

public:
    SensorLogger() : logFile(filename, std::ios::app) {
        if (!logFile.is_open()) {
            std::cerr << "Error opening log file: " << filename << std::endl;
            // Consider throwing an exception or handling the error more robustly
        }
    }

    ~SensorLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void logData(const EEPROMData& eepromData, const ADCData& adcData, const LEDState& ledState) {
        if (logFile.is_open()) {
            logFile << " sensor type: " << eepromData.sensorType
                    << " sensor ADC: " << adcData.sensorReading
                    << " sensor Temp: " << std::fixed << std::setprecision(2) << adcData.sensorTemperature
                    << " Green led Status: " << (ledState.Green ? "true" : "false")
                    << " Yellow led Status: " << (ledState.Yellow ? "true" : "false")
                    << " Red led Status: " << (ledState.Red ? "true" : "false") << std::endl;
        } else {
            std::cerr << "Log file is not open, cannot write data." << std::endl;
        }
    }
};

class SystemController {
private:
    StatusLedController ledController;
    TemperatureSensor tempSensor;
    SensorLogger logger;
    uint16_t measurementCounter = 0;
    const uint16_t measurementInterval = TEMP_MEASUREMENT_INTERVAL; // Assuming this is defined

public:
    void initialize() {
        eepromInit();
        ledInit();
        adcInit();
    }

    void run(uint16_t duration) {
        for (uint16_t counterTime = 0; counterTime < duration; ++counterTime) {
            if (measurementCounter > measurementInterval) {
                tempSensor.readTemperature();
                measurementCounter = 0;
            } else {
                measurementCounter++;
            }

            eepromRead();
            updateTemperature();
            ledController.setStatusLed();
            logger.logData(eeprom, adc, led);
        }
    }
};

int main() {
    SystemController systemController;
    systemController.initialize();
    systemController.run(1000);
    return 0;
}