#include "Adafruit_NeoPixel.h"

#define PIN 12        
#define NUM_LEDS 38   
#define bCircleLED 18
#define mCircleLED 14
#define sCircleLED 8
#define xsCircleLED 4
#define lowBR 50
#define medBR 12
#define hghBR 5
#define NUM_COL 3

#define maxBR 255
#define minBR 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void genArr();

char circlePat[NUM_LEDS];
char scanPat[2][11][7];
char ledGrid[11][12];
char snowPat[9][6];

float voltage = 0;
long t;

void setup()
{
  genArr();
  strip.begin();
  strip.setBrightness(255);
  strip.clear();
  strip.show();
  Serial.begin(9600);
}
