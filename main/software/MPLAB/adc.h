#ifndef _ADC_H_
#define _ADC_H_

#define MULAD_LA (4)
#define MULAD_LB (1)
#define MULAD_UA (6)
#define MULAD_UB (7)
#define CMSN	(0)
#define TXTEMP1 (2)
#define TXTEMP2 (3)
#define TXTEMP3 (5)

#define MUL_BATTEMP1	0b00010000
#define MUL_BATTEMP2	0b00010001
#define MUL_COVERTEMP1	0b00010010
#define MUL_COVERTEMP2	0b00010011
#define MUL_BATCASETEMP	0b00010100

void adcinit();
uint8_t getMULAD(uint8_t);
uint8_t getCriticalDatas(uint8_t);



#endif