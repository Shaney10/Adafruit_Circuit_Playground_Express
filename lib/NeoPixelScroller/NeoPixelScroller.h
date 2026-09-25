#ifndef NEOPIXEL_SCROLLER_H
#define NEOPIXEL_SCROLLER_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class NeoPixelScroller {
public:
    NeoPixelScroller(uint16_t numPixels, uint8_t pin);
    void begin();
    void update();
    void setSpeed(uint16_t delayMs);

private:
    Adafruit_NeoPixel strip;
    uint16_t numPixels;
    uint8_t currentPixel;
    uint8_t colorHue;          // Tracks the current position on the color wheel (0-255)
    unsigned long lastUpdate;
    uint16_t stepDelay;

    uint32_t Wheel(byte WheelPos); // Helper to calculate RGB colors across the hue wheel
};

#endif // NEOPIXEL_SCROLLER_H