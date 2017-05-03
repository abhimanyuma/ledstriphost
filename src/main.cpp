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
int count = 0;

void setup()
{
  // Init fastled
  FastLED.addLeds<WS2812, DATA_PIN, BGR>(leds, NUM_LEDS);
}

void loop()
{
  int i;
  for (i=0;i<=count;i++)
    leds[i] = CRGB::Blue;

  for (;i<NUM_LEDS;i++)
    leds[i] = CRGB::White;

  count++;
  if (count >= NUM_LEDS)
    count = 0;

  FastLED.show();
  // wait for a second
  delay(100);
}
