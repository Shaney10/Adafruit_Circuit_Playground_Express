#ifndef NEOPIXEL_SCROLLER_H
#define NEOPIXEL_SCROLLER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

enum ScrollDirection {
    CLOCKWISE,
    COUNTER_CLOCKWISE
};

class NeoPixelScroller {
public:
    NeoPixelScroller(uint16_t numPixels, uint8_t pin);
    void begin();
    void update();
    void setSpeed(uint16_t delayMs);
    void setDirection(ScrollDirection dir);

private:
    Adafruit_NeoPixel strip;
    uint16_t numPixels;
    int16_t currentPixel;
    uint8_t colorHue;
    unsigned long lastUpdate;
    uint16_t stepDelay;
    ScrollDirection direction;

    uint32_t Wheel(byte WheelPos);
};

#endif // NEOPIXEL_SCROLLER_H