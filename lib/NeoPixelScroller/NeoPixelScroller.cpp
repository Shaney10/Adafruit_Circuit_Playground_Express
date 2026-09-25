#include "NeoPixelScroller.h"

NeoPixelScroller::NeoPixelScroller(uint16_t numPixels, uint8_t pin)
    : strip(numPixels, pin, NEO_GRB + NEO_KHZ800),
      numPixels(numPixels),
      currentPixel(0),
      colorHue(0),
      lastUpdate(0),
      stepDelay(80) {}

void NeoPixelScroller::begin() {
    strip.begin();
    strip.setBrightness(30);
    strip.show();
}

void NeoPixelScroller::setSpeed(uint16_t delayMs) {
    stepDelay = delayMs;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition R -> G -> B -> back to R.
uint32_t NeoPixelScroller::Wheel(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85) {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if (WheelPos < 170) {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void NeoPixelScroller::update() {
    if (millis() - lastUpdate >= stepDelay) {
        lastUpdate = millis();

        strip.clear();
        
        // Draw active pixel with dynamic rainbow color
        strip.setPixelColor(currentPixel, Wheel(colorHue));
        strip.show();

        // Advance to next pixel position around the ring
        currentPixel = (currentPixel + 1) % numPixels;

        // Shift color hue by 15 steps per frame for smooth transitions
        colorHue = (colorHue + 15) % 256;
    }
}