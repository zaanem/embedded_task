#include "../h/led.h"
#include <stdio.h>
#include <stdbool.h>

void ledInit(){
    printf("Mock LED initialized on");
    led.Green= false;
    led.Yellow = false;
    led.Red = false;
};

void ledSetGreen() {
    led.Green = true;
    printf("Mock Green LED on ");
};

void ledResetGreen() {
    led.Green = false;
    printf("Mock Green LED off ");
};

void ledSetYellow() {
    led.Yellow = true;
    printf("Mock Yellow LED on ");
};

 void ledResetYellow() {
    led.Yellow = false;
    printf("Mock Yellow LED off ");
};

void ledSetRed() {
    led.Red = true;
    printf("Mock Red LED on" );
};

void ledResetRed() {
    led.Red= false;
    printf("Mock Red LED off" );
};
