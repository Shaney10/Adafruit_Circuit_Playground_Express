#include <Arduino.h>
#include "NeoPixelScroller.h"

#define PIN_NEOPIXEL 8
#define NUM_PIXELS   10

NeoPixelScroller scroller(NUM_PIXELS, PIN_NEOPIXEL);

void setup() {
    scroller.begin();
    scroller.setSpeed(70); // Adjust step speed in milliseconds
}

void loop() {
    scroller.update();
}