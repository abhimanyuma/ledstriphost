/**
 * LED Strip host.
 *
 * Turns LEDs red (for now)
 */

#include "Arduino.h"
#include <FastLED.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define NUM_LEDS 300
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup()
{
  // Init fastled
  pinMode(LED_BUILTIN, OUTPUT);

  FastLED.addLeds<WS2812, DATA_PIN>(leds, NUM_LEDS);
  for (int i=0;i<NUM_LEDS;i++)
    leds[i] = CRGB::White;
  FastLED.show();
}

void loop()
{
  // create rainbow hue
  static uint8_t hue = 0;
  FastLED.showColor(CHSV(hue++, 255, 255)); 
  delay(30);
}
