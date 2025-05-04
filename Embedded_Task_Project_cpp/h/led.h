#include <cstdint>
#include <stdbool.h> 

struct LEDState {
    bool Green;
    bool Yellow;
    bool Red;
};

extern LEDState led;

extern void ledInit();
extern void ledSetGreen();
extern void ledResetGreen();
extern void ledSetYellow();
extern void ledResetYellow();
extern void ledSetRed();
extern void ledResetRed();
