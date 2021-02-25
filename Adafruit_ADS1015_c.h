/**************************************************************************/
/*!
    @file     Adafruit_ADS1015_C.h

    v1.0  - First release
*/
/**************************************************************************/

#include "Adafruit_ADS1015.h"


#ifdef __cplusplus

extern "C" void begin_f(Adafruit_ADS1015* p)
    { return p->begin(); }
extern "C" void setGain_f(Adafruit_ADS1015* p, adsGain_t gain)
    { return p->setGain(gain); }
extern "C" uint16_t readADC_SingleEnded_f(Adafruit_ADS1015* p, uint8_t channel)
    { return p->readADC_SingleEnded(channel); }
  int16_t   readADC_Differential_0_1(void);

extern "C" int16_t   readADC_Differential_0_1_f(Adafruit_ADS1015* p)
    { return p->readADC_Differential_0_1(); }
extern "C" int16_t   readADC_Differential_2_3_f(Adafruit_ADS1015* p)
    { return p->readADC_Differential_2_3(); }
#endif  // __cplusplus

#ifdef _ADS1115
Adafruit_ADS1115    ads;
#else
Adafruit_ADS1015    ads;
#endif
void      begin_f(struct Adafruit_ADS1015* p);
void      setGain_f(struct Adafruit_ADS1015* p, adsGain_t gain);
uint16_t  readADC_SingleEnded_f(struct Adafruit_ADS1015* p, uint8_t channel);
int16_t   readADC_Differential_0_1_f(struct Adafruit_ADS1015* p);
int16_t   readADC_Differential_2_3_f(struct Adafruit_ADS1015* p);

#define   begin()                       begin_f(&ads)
#define   setGain(gain)                 setGain_f(&ads, gain)
#define   readADC_SingleEnded(channel)  readADC_SingleEnded_f(&ads, channel)
#define   readADC_Differential_0_1()    readADC_Differential_0_1_f(&ads)
#define   readADC_Differential_2_3()    readADC_Differential_2_3_f(&ads)

