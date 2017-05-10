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
  pinMode(LED_BUILTIN, OUTPUT);

  FastLED.addLeds<WS2812, DATA_PIN>(leds, NUM_LEDS);
  for (int i=0;i<NUM_LEDS;i++)
    leds[i] = CRGB::White;
  FastLED.show();
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  int i = 0;
  for (;i<count;i++)
    leds[i] = CRGB::Blue;
  for (;i<NUM_LEDS;i++)
    leds[i] = CRGB::Green;
  count = (count+1) % NUM_LEDS;

  FastLED.show();
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
