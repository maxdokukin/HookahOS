#include "setup.h"

int colCon(long hexValue, char color);
int lper(int a, int lo);
void brightnessFade(int del);

void setLine(char lNum, int R, int G, int B);
void setClm(char cNum, int R, int G, int B);
void setLines(char i, int del, char mode, int R, int G, int B);
void setClms(char i, int del, char mode, int R, int G, int B);




int lper(int a, int lo)
{
    int blo = 0;
    
    if(a >= 0 && a < lo)
        return a;
    
    if(a >= lo)
    {
        while(a > lo)
        {
            a--;
            blo++;
        }
        return blo;
    }
    
    while(a < 0)
    {
    lo--;
    a++;
    }
    return lo;
}




int colCon(long hexValue, char color)
{    
    if(color == 'R')        
      return ((hexValue >> 16) & 0xFF);    
    if(color == 'G')
        return ((hexValue >> 8) & 0xFF);
    if(color == 'B')
        return ((hexValue) & 0xFF);
}



void brightnessFade(int del)
{
   for(int k = minBR; k < maxBR; k++)
   {
      strip.setBrightness(k);
      strip.show();
      delay(del);
   }
  
   for(int k = maxBR; k > 0; k--)
   {
      strip.setBrightness(k);
      strip.show();
      delay(del);
   }
  strip.setBrightness(255);
}



void setLine(char lNum, int R, int G, int B)
{
  for(int i = 1; i < scanPat[0][lNum][0] + 1; i++)
    strip.setPixelColor(scanPat[0][lNum][i], R, G, B);
}



void setLines(char i, int del, char mode, int R, int G, int B)
{
  strip.clear();

  if(i < 9 && mode == 'F')
    setLine(i, R / 10, G / 10, B / 10);

  if(i > 0 && i < 10)
    setLine(i - 1, R, G, B);

  if(i > 1 && mode == 'F')
    setLine(i - 2, R / 10, G / 10, B / 10);

  strip.show();

  delay(del);
}



void setClm(char cNum, int R, int G, int B)
{
  for(int i = 1; i < scanPat[1][cNum][0] + 1; i++)
    strip.setPixelColor(scanPat[1][cNum][i], R, G, B);
}



void setClms(char i, int del, char mode, int R, int G, int B)
{
  strip.clear();

  if(i < 11 && mode == 'F')
    setClm(i, R / 10, G / 10, B / 10);

  if(i > 0 && i < 12)
    setClm(i - 1, R, G, B);

  if(i > 1 && mode == 'F')
    setClm(i - 2, R / 10, G / 10, B / 10);

  strip.show();

  delay(del);
}



void genArr()
{
  circlePat[0] = 0;
  circlePat[1] = 1;
  circlePat[2] = 5;
  circlePat[3] = 10;
  circlePat[4] = 15;
  circlePat[5] = 21;
  circlePat[6] = 26;
  circlePat[7] = 31;
  circlePat[8] = 35;
  circlePat[9] = 37;
  circlePat[10] = 36;
  circlePat[11] = 32;
  circlePat[12] = 27;
  circlePat[13] = 22;
  circlePat[14] = 16;
  circlePat[15] = 11;
  circlePat[16] = 6;
  circlePat[17] = 2;
  circlePat[18] = 3;
  circlePat[19] = 4;
  circlePat[20] = 9;
  circlePat[21] = 14;
  circlePat[22] = 20;
  circlePat[23] = 25;
  circlePat[24] = 30;
  circlePat[25] = 34;
  circlePat[26] = 33;
  circlePat[27] = 28;
  circlePat[28] = 23;
  circlePat[29] = 17;
  circlePat[30] = 12;
  circlePat[31] = 7;
  circlePat[32] = 13;
  circlePat[33] = 8;
  circlePat[34] = 19;
  circlePat[35] = 24;
  circlePat[36] = 29;
  circlePat[37] = 18;

  scanPat[0][0][0] = 2;
    scanPat[0][0][1] = 0;
    scanPat[0][0][2] = 1;
  
  scanPat[0][1][0] = 4;
    scanPat[0][1][1] = 2;
    scanPat[0][1][2] = 3;
    scanPat[0][1][3] = 4;
    scanPat[0][1][4] = 5;
  
  scanPat[0][2][0] = 5;
    scanPat[0][2][1] = 6;
    scanPat[0][2][2] = 7;
    scanPat[0][2][3] = 8;
    scanPat[0][2][4] = 9;
    scanPat[0][2][5] = 10;
  
  scanPat[0][3][0] = 5;
    scanPat[0][3][1] = 11;
    scanPat[0][3][2] = 12;
    scanPat[0][3][3] = 13;
    scanPat[0][3][4] = 14;
    scanPat[0][3][5] = 15;
  
  scanPat[0][4][0] = 6;
    scanPat[0][4][1] = 16;
    scanPat[0][4][2] = 17;
    scanPat[0][4][3] = 18;
    scanPat[0][4][4] = 19;
    scanPat[0][4][5] = 20;
    scanPat[0][4][6] = 21;
  
  scanPat[0][5][0] = 5;
    scanPat[0][5][1] = 22;
    scanPat[0][5][2] = 23;
    scanPat[0][5][3] = 24;
    scanPat[0][5][4] = 25;
    scanPat[0][5][5] = 26;
  
  scanPat[0][6][0] = 5;
    scanPat[0][6][1] = 27;
    scanPat[0][6][2] = 28;
    scanPat[0][6][3] = 29;
    scanPat[0][6][4] = 30;
    scanPat[0][6][5] = 31;
  
  scanPat[0][7][0] = 4;
    scanPat[0][7][1] = 32;
    scanPat[0][7][2] = 33;
    scanPat[0][7][3] = 34;
    scanPat[0][7][4] = 35;
  
  scanPat[0][8][0] = 2;
    scanPat[0][8][1] = 36;
    scanPat[0][8][2] = 37;


  scanPat[1][0][0] = 1;
      scanPat[1][0][1] = 16;

  scanPat[1][1][0] = 4;
    scanPat[1][1][1] = 6;
    scanPat[1][1][2] = 11;
    scanPat[1][1][3] = 22;
    scanPat[1][1][4] = 27;

  scanPat[1][2][0] = 3;
    scanPat[1][2][1] = 2;
    scanPat[1][2][2] = 17;
    scanPat[1][2][3] = 32;

  scanPat[1][3][0] = 4;
    scanPat[1][3][1] = 7;
    scanPat[1][3][2] = 12;
    scanPat[1][3][3] = 23;
    scanPat[1][3][4] = 28;

  scanPat[1][4][0] = 5;
    scanPat[1][4][1] = 0;
    scanPat[1][4][2] = 3;
    scanPat[1][4][3] = 18;
    scanPat[1][4][4] = 33;
    scanPat[1][4][5] = 36;

  scanPat[1][5][0] = 4;
    scanPat[1][5][1] = 8;
    scanPat[1][5][2] = 13;
    scanPat[1][5][3] = 24;
    scanPat[1][5][4] = 29;

  scanPat[1][6][0] = 5;
    scanPat[1][6][1] = 1;
    scanPat[1][6][2] = 4;
    scanPat[1][6][3] = 19;
    scanPat[1][6][4] = 34;
    scanPat[1][6][5] = 37;

  scanPat[1][7][0] = 4;
    scanPat[1][7][1] = 9;
    scanPat[1][7][2] = 14;
    scanPat[1][7][3] = 25;
    scanPat[1][7][4] = 30; 

  scanPat[1][8][0] = 3;
    scanPat[1][8][1] = 5;
    scanPat[1][8][2] = 20;
    scanPat[1][8][3] = 35; 

  scanPat[1][9][0] = 4;
    scanPat[1][9][1] = 10;
    scanPat[1][9][2] = 15;
    scanPat[1][9][3] = 26;
    scanPat[1][9][4] = 31;

  scanPat[1][10][0] = 1;
    scanPat[1][10][1] = 21;



  ledGrid[0][0] = -1;
  ledGrid[0][1] = -1;
  ledGrid[0][2] = -1;
  ledGrid[0][3] = -1;
  ledGrid[0][4] = -1;
  ledGrid[0][5] = -1;
  ledGrid[0][6] = -1;
  ledGrid[0][7] = -1;
  ledGrid[0][8] = -1;
  ledGrid[0][9] = -1;
  ledGrid[0][10] = -1;
  ledGrid[0][11] = -1;

  ledGrid[1][0] = -1;
  ledGrid[1][1] = -1;
  ledGrid[1][2] = -1;
  ledGrid[1][3] = 0;
  ledGrid[1][4] = -1;
  ledGrid[1][5] = 0;
  ledGrid[1][6] = 1;
  ledGrid[1][7] = -1;
  ledGrid[1][8] = 1;
  ledGrid[1][9] = -1;
  ledGrid[1][10] = -1;
  ledGrid[1][11] = -1;

  ledGrid[2][0] = -1;
  ledGrid[2][1] = -1;
  ledGrid[2][2] = 2;
  ledGrid[2][3] = 2;
  ledGrid[2][4] = 3;
  ledGrid[2][5] = 3;
  ledGrid[2][6] = 4;
  ledGrid[2][7] = 4;
  ledGrid[2][8] = 5;
  ledGrid[2][9] = 5;
  ledGrid[2][10] = -1;
  ledGrid[2][11] = -1;

  ledGrid[3][0] = -1;
  ledGrid[3][1] = -1;
  ledGrid[3][2] = 6;
  ledGrid[3][3] = 7;
  ledGrid[3][4] = 7;
  ledGrid[3][5] = 8;
  ledGrid[3][6] = 8;
  ledGrid[3][7] = 9;
  ledGrid[3][8] = 9;
  ledGrid[3][9] = 10;
  ledGrid[3][10] = -1;
  ledGrid[3][11] = -1;

  ledGrid[4][0] = -1;
  ledGrid[4][1] = 11;
  ledGrid[4][2] = 11;
  ledGrid[4][3] = 12;
  ledGrid[4][4] = 12;
  ledGrid[4][5] = 13;
  ledGrid[4][6] = 13;
  ledGrid[4][7] = 14;
  ledGrid[4][8] = 14;
  ledGrid[4][9] = 15;
  ledGrid[4][10] = 15;
  ledGrid[4][11] = -1;

  ledGrid[5][0] = -1;
  ledGrid[5][1] = 16;
  ledGrid[5][2] = 17;
  ledGrid[5][3] = 17;
  ledGrid[5][4] = 18;
  ledGrid[5][5] = 18;
  ledGrid[5][6] = 19;
  ledGrid[5][7] = 19;
  ledGrid[5][8] = 20;
  ledGrid[5][9] = 20;
  ledGrid[5][10] = 21;
  ledGrid[5][11] = -1;

  ledGrid[6][0] = -1;
  ledGrid[6][1] = 22;
  ledGrid[6][2] = 22;
  ledGrid[6][3] = 23;
  ledGrid[6][4] = 23;
  ledGrid[6][5] = 24;
  ledGrid[6][6] = 24;
  ledGrid[6][7] = 25;
  ledGrid[6][8] = 25;
  ledGrid[6][9] = 26;
  ledGrid[6][10] = 26;
  ledGrid[6][11] = -1;

  ledGrid[7][0] = -1;
  ledGrid[7][1] = -1;
  ledGrid[7][2] = 27;
  ledGrid[7][3] = 28;
  ledGrid[7][4] = 28;
  ledGrid[7][5] = 29;
  ledGrid[7][6] = 29;
  ledGrid[7][7] = 30;
  ledGrid[7][8] = 30;
  ledGrid[7][9] = 31;
  ledGrid[7][10] = -1;
  ledGrid[7][11] = -1;

  ledGrid[8][0] = -1;
  ledGrid[8][1] = -1;
  ledGrid[8][2] = 32;
  ledGrid[8][3] = 32;
  ledGrid[8][4] = 33;
  ledGrid[8][5] = 33;
  ledGrid[8][6] = 34;
  ledGrid[8][7] = 34;
  ledGrid[8][8] = 35;
  ledGrid[8][9] = 35;
  ledGrid[8][10] = -1;
  ledGrid[8][11] = -1;

  ledGrid[9][0] = -1;
  ledGrid[9][1] = -1;
  ledGrid[9][2] = -1;
  ledGrid[9][3] = 36;
  ledGrid[9][4] = -1;
  ledGrid[9][5] = 36;
  ledGrid[9][6] = 37;
  ledGrid[9][7] = -1;
  ledGrid[9][8] = 37;
  ledGrid[9][9] = -1;
  ledGrid[9][10] = -1;
  ledGrid[9][11] = -1;

  ledGrid[10][0] = -1;
  ledGrid[10][1] = -1;
  ledGrid[10][2] = -1;
  ledGrid[10][3] = -1;
  ledGrid[10][4] = -1;
  ledGrid[10][5] = -1;
  ledGrid[10][6] = -1;
  ledGrid[10][7] = -1;
  ledGrid[10][8] = -1;
  ledGrid[10][9] = -1;
  ledGrid[10][10] = -1;
  ledGrid[10][11] = -1;




  snowPat[0][0] = -1;
  snowPat[0][1] = -1;
  snowPat[0][2] = 0;
  snowPat[0][3] = 1;
  snowPat[0][4] = -1;
  snowPat[0][5] = -1;

  snowPat[1][0] = -1;
  snowPat[1][1] = 2;
  snowPat[1][2] = 3;
  snowPat[1][3] = 4;
  snowPat[1][4] = 5;
  snowPat[1][5] = -1;

  snowPat[2][0] = 6;
  snowPat[2][1] = 7;
  snowPat[2][2] = 8;
  snowPat[2][3] = 9;
  snowPat[2][4] = 10;
  snowPat[2][5] = -1;

  snowPat[3][0] = 11;
  snowPat[3][1] = 12;
  snowPat[3][2] = 13;
  snowPat[3][3] = 14;
  snowPat[3][4] = 15;
  snowPat[3][5] = -1;

  snowPat[4][0] = 16;
  snowPat[4][1] = 17;
  snowPat[4][2] = 18;
  snowPat[4][3] = 19;
  snowPat[4][4] = 20;
  snowPat[4][5] = 21;

  snowPat[5][0] = 22;
  snowPat[5][1] = 23;
  snowPat[5][2] = 24;
  snowPat[5][3] = 25;
  snowPat[5][4] = 26;
  snowPat[5][5] = -1;

  snowPat[6][0] = 27;
  snowPat[6][1] = 28;
  snowPat[6][2] = 29;
  snowPat[6][3] = 30;
  snowPat[6][4] = 31;
  snowPat[6][5] = -1;

  snowPat[7][0] = -1;
  snowPat[7][1] = 32;
  snowPat[7][2] = 33;
  snowPat[7][3] = 34;
  snowPat[7][4] = 35;
  snowPat[7][5] = -1;

  snowPat[8][0] = -1;
  snowPat[8][1] = -1;
  snowPat[8][2] = 36;
  snowPat[8][3] = 37;
  snowPat[8][4] = -1;
  snowPat[8][5] = -1;
}
