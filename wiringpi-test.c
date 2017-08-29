#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

#include <wiringPiI2C.h>

#define ADS1X15_ID 100 // 48

static uint8_t i2cread(void);
static void i2cwrite(uint8_t x);
static uint16_t readRegister(uint8_t i2cAddress, uint8_t reg);
static void writeRegister(uint8_t i2cAddress, uint8_t reg, uint16_t value);

int i2cFd;

int main(int argc, char *argv[])
{
  i2cFd = wiringPiI2CSetup(ADS1X15_ID);

  if (i2cFd == -1) {
    printf("\n open() failed with error [%s]\n", strerror(errno));
    return 1;
  }

  i2cread();
  i2cwrite(0);
  readRegister(0, 0);
  writeRegister(0, 0, 0);

  return 0;
}


uint8_t i2cread(void) {
  return wiringPiI2CRead(i2cFd);
}

void i2cwrite(uint8_t x) {
  wiringPiI2CWrite(i2cFd, x);
}

uint16_t readRegister(uint8_t i2cAddress, uint8_t reg) {
  return wiringPiI2CReadReg16(i2cFd, reg);
}

void writeRegister(uint8_t i2cAddress, uint8_t reg, uint16_t value) {
  wiringPiI2CWriteReg16(i2cFd, reg, value);
}

