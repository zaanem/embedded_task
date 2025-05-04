#include "../h/led.h"
#include <iostream>
#include <string>

LEDState led;

void ledInit() {
    std::cout << "Mock LED initialized on" << std::endl;
    led.Green = false;
    led.Yellow = false;
    led.Red = false;
}

void ledSetGreen() {
    led.Green = true;
    std::cout << "Mock Green LED on ";
}

void ledResetGreen() {
    led.Green = false;
    std::cout << "Mock Green LED off ";
}

void ledSetYellow() {
    led.Yellow = true;
    std::cout << "Mock Yellow LED on ";
}

void ledResetYellow() {
    led.Yellow = false;
    std::cout << "Mock Yellow LED off ";
}

void ledSetRed() {
    led.Red = true;
    std::cout << "Mock Red LED on";
}

void ledResetRed() {
    led.Red = false;
    std::cout << "Mock Red LED off";
}