#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define _ADS1115
#include "../Adafruit_ADS1015_c.h"

void    printBits(size_t const size, void const *const ptr);

int main(int argc, char *argv[])
{
    int16_t adc0;
    double  milliVolts;
    double  bits2milliVoltsFactor;

    setGain(GAIN_FOUR);
    bits2milliVoltsFactor = 0.03125;    // remember to change this according to gain
    begin();
    while (true) {
        adc0 = readADC_Differential_0_1();
        milliVolts = adc0 * bits2milliVoltsFactor;
        printBits(sizeof(adc0), &adc0);
        printf(" *** %5d *** %f\n", adc0, milliVolts);
        usleep(100000);
    }
}

//assumes little endian
void printBits(size_t const size, void const *const ptr)
{
    unsigned char   *b = (unsigned char *) ptr;
    unsigned char   byte;
    int             i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }

    //puts("");
}
