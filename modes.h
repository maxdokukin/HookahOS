#include "auxiliary_functions.h"

void demo_mode();

void fill_mode(long color, int del, char par, char par2);
void fade_mode(long color, int del);
void mix_mode(long del, char mpl, char grReduc, char color1, char color2);
void random_mode(long color, int del);
void scan_mode(long color, int del, char mode);
void gazer_mode(long color, int del);
void radar_mode(long color1, long color2, int del);
void snow_mode(long color1, long color2, int del);
void rainbow_mode(int del, char grReduc);



void demo_mode()
{
  fill_mode(0x0000FF, 4000, 'L', ' '); 
  fill_mode(0x0000FF, 4000, 'C', 'I');
  fill_mode(0x0000FF, 4000, 'C', 'O');

  fade_mode(0x7401DF, 10000);
  fade_mode(0xFF00BF, 10000);
  fade_mode(0xDF0174, 10000);
  fade_mode(0x0000FF, 10000);

  t = millis();
  while(millis() - t < 20000)
  random_mode(0xFFFFFF, 4000);

  scan_mode(0xFFFFFF, 3000, 'T');
  scan_mode(0xFFFFFF, 3000, 'F');

  t = millis();
  while(millis() - t < 20000)
    gazer_mode(0xFF00FF, 4000);

  t = millis();
  while(millis() - t < 20000)
  radar_mode(0xFF00FF, 0x0000FF, 2500);

  t = millis();
  while(millis() - t < 20000)
  snow_mode(0x0000FF, 0x110011, 400);

  rainbow_mode(10000, 4);
  rainbow_mode(10000, 4);

  mix_mode(120000, 10, 6, 'R', 'G');
  mix_mode(120000, 10, 6, 'R', 'B');
  mix_mode(120000, 10, 6, 'G', 'R');
  mix_mode(120000, 10, 6, 'G', 'B');
  mix_mode(120000, 10, 6, 'B', 'R');
  mix_mode(120000, 10, 6, 'B', 'G');
}



void fill_mode(long color, int del, char par, char par2)
{
  del  = del / 41.1;
  int R = colCon(color, 'R');
  int G = colCon(color, 'G');
  int B = colCon(color, 'B');

  if(par == 'L')
  {
    for(int i = 0; i < NUM_LEDS + 3; i++)
    {
      if( i < NUM_LEDS)
        strip.setPixelColor(i, R / lowBR, G / lowBR, B / lowBR);
      if(i >= 1 && i < NUM_LEDS + 1)
        strip.setPixelColor(i - 1, R / medBR, G / medBR, B / medBR);
      if(i >= 2 && i < NUM_LEDS + 2)
        strip.setPixelColor(i - 2, R / hghBR, G / hghBR, B / hghBR);
      if(i >= 3 && i < NUM_LEDS + 3)
        strip.setPixelColor(i - 3, R, G , B);
      
      strip.show();
      delay(del);
    }
  }
  else if(par == 'C')
  {
    if(par2 == 'I')
    { 
      for(int i = 0; i < NUM_LEDS + 3; i++)
      {
        if( i < NUM_LEDS)
          strip.setPixelColor(circlePat[i], R / lowBR, G / lowBR, B / lowBR);
        if(i >= 1 && i < NUM_LEDS + 1)
          strip.setPixelColor(circlePat[i - 1], R / medBR, G / medBR, B / medBR);
        if(i >= 2 && i < NUM_LEDS + 2)
          strip.setPixelColor(circlePat[i - 2], R / hghBR, G / hghBR, B / hghBR);
        if(i >= 3 && i < NUM_LEDS + 3)
          strip.setPixelColor(circlePat[i - 3], R, G, B);

        strip.show();
        delay(del); 
      } 
    }
    if(par2 == 'O')
    {
      for(int i = NUM_LEDS + 3; i > -1; i--)
      {
        if( i < NUM_LEDS)
          strip.setPixelColor(circlePat[i], R, G, B);
        if(i >= 1 && i < NUM_LEDS + 1)
          strip.setPixelColor(circlePat[i - 1], R / hghBR, G / hghBR, B / hghBR);
        if(i >= 2 && i < NUM_LEDS + 2)
          strip.setPixelColor(circlePat[i - 2], R / medBR, G / medBR, B / medBR);
        if(i >= 3 && i < NUM_LEDS + 3)
          strip.setPixelColor(circlePat[i - 3], R / lowBR, G / lowBR, B / lowBR);

         strip.show();
        delay(del); 
      }      
    }  
  }
   strip.clear();
}



void fade_mode(long color, int del)
{
  del = del / 526;
  int R = colCon(color, 'R');
  int G = colCon(color, 'G');
  int B = colCon(color, 'B');  

  for(int i = 0; i < NUM_LEDS; i++)
    strip.setPixelColor(i, R, G, B);
  
  brightnessFade(del);
  
  strip.clear();
}



void mix_mode(long del, char mpl, char grReduc, char color1, char color2)
{
  del = (del / (62303 / mpl) - 1);
  int i = NUM_LEDS;
  
  for(int c1 = 0; c1 < maxBR; c1+= mpl)
    for(int c2 = minBR; c2 < maxBR; c2++)
    {      
      if(i < 0)
        i = NUM_LEDS;

      if(color1 == 'R' && color2 == 'G')
        strip.setPixelColor(circlePat[i], c1, c2 / grReduc, 0);
      if(color1 == 'R' && color2 == 'B')
        strip.setPixelColor(circlePat[i], c1, 0, c2);
      if(color1 == 'G' && color2 == 'R')
          strip.setPixelColor(circlePat[i], c2, c1 / grReduc, 0);
      if(color1 == 'G' && color2 == 'B')
        strip.setPixelColor(circlePat[i], 0, c1 / grReduc, c2);
      if(color1 == 'B' && color2 == 'R')
        strip.setPixelColor(circlePat[i], c2, 0, c1);
      if(color1 == 'B' && color2 == 'G')
        strip.setPixelColor(circlePat[i], 0, c2 / grReduc, c1);


      strip.show();
      i--;
      delay(del);
    }
  strip.clear();
}



void scan_mode(long color, int del, char mode)
{
  del = del / 38;
  int R = colCon(color, 'R');
  int G = colCon(color, 'G');
  int B = colCon(color, 'B');

  for(int i = 0; i < 11; i++)
    setLines(i, del, mode, R, G, B);

  for(int i = 11; i > -1; i--)
    setLines(i, del, mode, R, G, B);

  for(int i = 0; i < 13; i++)
    setClms(i, del, mode, R, G, B);

  for(int i = 13; i > -1; i--)
    setClms(i, del, mode, R, G, B);
}



void random_mode(long color, int del)
{
  del = del / 525;
  int R = colCon(color, 'R');
  int G = colCon(color, 'G');
  int B = colCon(color, 'B');

  strip.setPixelColor(random(NUM_LEDS - 1), R, G, B);
  
  brightnessFade(del);
  
  strip.clear();
}



void gazer_mode(long color, int del)
{
  del = del / 525;
  int R = colCon(color, 'R');
  int G = colCon(color, 'G');
  int B = colCon(color, 'B');
  
  int i, j, c = 0;

  char p = random(NUM_LEDS - 1);
  
  for(i = 1; i < 11; i++)
    for(j = 1; j < 12; j++)
      if(ledGrid[i][j] == p)
      {
        strip.setPixelColor(ledGrid[i][j], R, G, B);
        strip.setPixelColor(ledGrid[i + 1][j], R, G, B);
        strip.setPixelColor(ledGrid[i - 1][j], R, G, B);
        strip.setPixelColor(ledGrid[i][j + 1], R, G, B);
        strip.setPixelColor(ledGrid[i][j - 1], R, G, B);
      }
      
  brightnessFade(del);
  
  strip.clear();
}



void radar_mode(long color1, long color2, int del)
{
  del = del / 18;
  int R_1 = colCon(color1, 'R');
  int G_1 = colCon(color1, 'G');
  int B_1 = colCon(color1, 'B');

  int R_2 = colCon(color2, 'R');
  int G_2 = colCon(color2, 'G');
  int B_2 = colCon(color2, 'B');
  
  for(int i = 0; i < NUM_LEDS; i++)
    strip.setPixelColor(i, R_2, G_2, B_2);
    
  for(int i = 0; i < bCircleLED; i++)
  {
    strip.setPixelColor(circlePat[i], 0xFFFFFF);
    strip.setPixelColor(circlePat[lper(i - 1, bCircleLED)], R_1, G_1, B_1);

    strip.show();
    delay(del);
    
  }
  strip.clear();
}



void snow_mode(long color1, long color2, int del)
{
  int R_1= colCon(color1, 'R');
  int G_1 = colCon(color1, 'G');
  int B_1 = colCon(color1, 'B');

  int R_2 = colCon(color2, 'R');
  int G_2 = colCon(color2, 'G');
  int B_2 = colCon(color2, 'B');

  for(int i = 0; i < NUM_LEDS; i++)
    strip.setPixelColor(i, R_2, G_2, B_2);

  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 6; j++)
      if(snowPat[i][j] >= 38)
        strip.setPixelColor(snowPat[i][j] - 39, R_1, G_1, B_1);

  strip.show();

  delay(del);

  for(int i = 0; i < 9; i++)  
    for(int j = 5; j > -1; j--)
      if(snowPat[i][j] >= 38)
      {
        snowPat[i][j] -= 39;
        if(j < 5)
          snowPat[i][j + 1] += 39;
      }
      
  snowPat[random(9)][0] += 39;

  strip.clear();
}

  

void rainbow_mode(int del, char grReduc)
{
  del /= 1650;
  int vC = 0;
  int i = -1;

  for(int gC = 0; gC < 3; gC++)
  { 
    for(; vC < maxBR; vC++, i--)
    {
      if(i < 0)
        i = NUM_LEDS - 1;

      if(gC == 0)
        strip.setPixelColor(circlePat[i], 255, vC / grReduc, 0);
      if(gC == 1)
        strip.setPixelColor(circlePat[i], 0, 255 / grReduc, vC);
      if(gC == 2)
        strip.setPixelColor(circlePat[i], vC, 0, 255);
        
      strip.show();
      delay(del);
  
    }
     
    for(; vC > 0; vC--, i--)
    {
      if(i < 0)
        i = NUM_LEDS - 1;
      
      if(gC == 0)
        strip.setPixelColor(circlePat[i], vC, 255 / grReduc, 0);
      if(gC == 1)
        strip.setPixelColor(circlePat[i], 0, vC / grReduc, 255);
      if(gC == 2)
        strip.setPixelColor(circlePat[i], 255, 0, vC);
        
      strip.show();
      delay(del);
  
    }    
  }
  strip.clear();
}
