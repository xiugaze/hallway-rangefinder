#include <FastLED.h>
#include <Wire.h>
#include <LIDARLite.h>

#define LED_PIN 13
#define NUM_LEDS 160
 
LIDARLite lidarLite;
int cal_cnt = 0;


CRGB leds[NUM_LEDS];
 
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
  
  Serial.begin(9600);
  lidarLite.begin(0, true);
  lidarLite.configure(0);
  
  
  Serial.begin(9600);
  lidarLite.begin(0, true);
  lidarLite.configure(0);
}
 
void loop() {
  // RED Green Blue
for (int i=0; i<NUM_LEDS; i++ )
{
    leds[i] = CRGB(0, 255-2*i, 20*i );
    FastLED.setBrightness(6*i);
    FastLED.show();
    delay (50);
} 
for (int i=NUM_LEDS; i> 0; i-- )
{
    leds[i] = CRGB(20*i, 0, 255-20*i );
    FastLED.setBrightness(60-2*i);
    FastLED.show();
        delay (50);
 
}
}