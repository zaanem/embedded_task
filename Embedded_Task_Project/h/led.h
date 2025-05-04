#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool Green;
    bool Yellow;
    bool Red;
} Led;

void ledInit();
void ledSetGreen();
void ledResetGreen();
void ledSetYellow();
void ledResetYellow();
void ledSetRed();
void ledResetRed();

extern Led led;