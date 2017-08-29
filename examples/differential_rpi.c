#include <stdio.h>
#include <unistd.h>

#include "../Adafruit_ADS1015.h"

void printBits(size_t const size, void const * const ptr);

Adafruit_ADS1115 ads;

int main(int argc, char *argv[])
{
  uint16_t adc0;

  ads.setGain(GAIN_TWOTHIRDS);
  usleep(500000);
  ads.begin();
  usleep(500000);
  while (true) {
    adc0 = ads.readADC_SingleEnded(0);
        //unsigned char adc0c = adc0;
        //printf("adc0c before: ");
        //printBits(sizeof(adc0c), &adc0c);
        //adc0c = ((adc0c << 8) & 0xFF00) | ((adc0c >> 8) & 0x00FF);
        //printf("\nadc0c  after: ");
    //printBits(sizeof(adc0), &adc0);
    //printf(" *** %d\n", adc0);
    uint16_t adc0r = adc0;
    adc0r = (adc0r >> 8) | (adc0r << 8);
    printBits(sizeof(adc0r), &adc0r);
    printf(" ||| %d\n", adc0r);
    usleep(100000);
  }
}

//assumes little endian
void printBits(size_t const size, void const * const ptr)
{
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i=size-1;i>=0;i--) {
    for (j=7;j>=0;j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  //puts("");
}
