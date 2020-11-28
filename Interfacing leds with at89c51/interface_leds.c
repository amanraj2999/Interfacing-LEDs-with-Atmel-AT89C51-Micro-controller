#include<reg51.h>
void delay(unsigned int x); //delay declaration
void main(void) //start main
  { 
      while(1) //run infinite loop
          {
              P2 = 0x00;
              P1 = 0x00; delay(10000);
              P2 = 0x01;
              P1 = 0x80; delay(10000);
              P2 = 0x03;
              P1 = 0xC0; delay(10000);
              P2 = 0x07;
              P1 = 0xE0; delay(10000);
              P2 = 0x0F;
              P1 = 0xF0; delay(10000);
              P2 = 0x1F;
              P1 = 0xF8; delay(10000);
              P2 = 0x3F;
              P1 = 0xFC; delay(10000);
              P2 = 0x7F;
              P1 = 0xFE; delay(10000);
              P2 = 0xFF;
              P1 = 0xFF; delay(10000);
              P2 = 0x7F;
              P1 = 0xFE; delay(10000);
              P2 = 0x3F;
              P1 = 0xFC; delay(10000);
              P2 = 0x1F;
              P1 = 0xF8; delay(10000);P2 = 0x0F;
              P1 = 0xF0; delay(10000);
              P2 = 0x07;
              P1 = 0xE0; delay(10000);
              P2 = 0x03;
              P1 = 0xC0 ;delay(10000);
              P2 = 0x01;
              P1 = 0x80; delay(10000);
          }
}
void delay(unsigned int x)
    { 
        unsigned int y;
        for (y=0; y<x; y++); //delay by for loop
    }
