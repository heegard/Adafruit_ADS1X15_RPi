#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#include "../Adafruit_ADS1015_c.h"

void        printBits(size_t const size, void const *const ptr);
uint8_t     chan = 0;
adsGain_t   gain = GAIN_EIGHT;

int main(int argc, char *argv[])
{
    uint16_t    adc0;

    setGain(gain);
    begin_f(&ads);
    printf("Channel %d, Gain %d\n", chan, gain);
    while (true) {
        adc0 = readADC_SingleEnded_f(&ads, chan);
        printBits(sizeof(adc0), &adc0);
        printf(" *** %d\n", adc0);
        usleep(500000);
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
