#include <Arduino.h>
#include <Adafruit_FreeTouch.h>
#include "NeoPixelScroller.h"

#ifndef PIN_NEOPIXEL
#define PIN_NEOPIXEL 8
#endif

#define NUM_PIXELS   10
#define TOUCH_THRESHOLD 550

Adafruit_FreeTouch qt_A1(A1, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A2(A2, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A3(A3, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A4(A4, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A5(A5, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A6(A6, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_A7(A7, OVERSAMPLE_4, RESISTOR_0, FREQ_MODE_NONE);

NeoPixelScroller scroller(NUM_PIXELS, PIN_NEOPIXEL);

void setup() {
    scroller.begin();
    scroller.setSpeed(70);

    qt_A1.begin(); qt_A2.begin(); qt_A3.begin();
    qt_A4.begin(); qt_A5.begin(); qt_A6.begin();
    qt_A7.begin();
}

void loop() {
    uint16_t touchMask = 0;

    // Shifted 180 degrees (offset by 5 pixels)
    if (qt_A1.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 6); // Pad A1 -> LED 6
    if (qt_A2.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 7); // Pad A2 -> LED 7
    if (qt_A3.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 8); // Pad A3 -> LED 8
    if (qt_A4.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 1); // Pad A4 -> LED 1
    if (qt_A5.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 2); // Pad A5 -> LED 2
    if (qt_A6.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 3); // Pad A6 -> LED 3
    if (qt_A7.measure() > TOUCH_THRESHOLD) touchMask |= (1 << 4); // Pad A7 -> LED 4

    scroller.update(touchMask);
}