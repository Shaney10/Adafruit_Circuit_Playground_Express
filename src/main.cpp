#include <Arduino.h>
#include "NeoPixelScroller.h"

#define PIN_NEOPIXEL 8
#define NUM_PIXELS   10

#define PIN_BUTTON_A 4
#define PIN_BUTTON_B 5
#define PIN_SWITCH   7

NeoPixelScroller scroller(NUM_PIXELS, PIN_NEOPIXEL);

void setup() {
    // Configure onboard switch inputs with internal pull-down/pull-up
    pinMode(PIN_BUTTON_A, INPUT_PULLDOWN);
    pinMode(PIN_BUTTON_B, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH, INPUT_PULLUP);

    scroller.begin();
    scroller.setSpeed(70);
}

void loop() {
    // Option A: Use Push Buttons to set direction
    if (digitalRead(PIN_BUTTON_A) == HIGH) {
        scroller.setDirection(COUNTER_CLOCKWISE);
    } else if (digitalRead(PIN_BUTTON_B) == HIGH) {
        scroller.setDirection(CLOCKWISE);
    }

    // Option B (Uncomment to use Slide Switch instead):
    // if (digitalRead(PIN_SWITCH) == HIGH) {
    //     scroller.setDirection(CLOCKWISE);
    // } else {
    //     scroller.setDirection(COUNTER_CLOCKWISE);
    // }

    scroller.update();
}