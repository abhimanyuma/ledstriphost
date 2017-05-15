/**
 * LED Strip host.
 * Uses some hacky define rules to make it work.
 */


#define HUE 13
//#define SIMPLERAINBOW 12

#include "Arduino.h"
#include <FastLED.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define NUM_LEDS 300
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

#ifdef SIMPLERAINBOW
CRGB ledcopy[NUM_LEDS];
#endif

void setup()
{
  // Init fastled
  pinMode(LED_BUILTIN, OUTPUT);

  FastLED.addLeds<WS2812, DATA_PIN>(leds, NUM_LEDS);

#ifdef SIMPLERAINBOW
  static uint8_t hue = 0;
  for(int i=0;i<NUM_LEDS;i++)
    leds[i] = CHSV(hue++, 255, 255);
  FastLED.show();
#endif
}

void loop()
{
#ifdef HUE
  // create rainbow hue
  static uint8_t hue = 0;

  FastLED.showColor(CHSV(hue++, 255, 255));
  delay(30);
#endif
#ifdef SIMPLERAINBOW
  static int shift = 3;
  // copy array
  for(int i=0;i<NUM_LEDS;i++)
    ledcopy[i] = leds[i];

  for(int i=0;i<NUM_LEDS;i++)
    leds[i] = ledcopy[(i-shift) % NUM_LEDS];
  FastLED.show();
#endif
}
