#ifndef _OBCTIME_H_
#define _OBCTIME_H_


#define TINYPERIOD (100)//CYCLEPERIOD�ƍ��킹��10sec�ɂȂ�悤��

#define ZEROPHASE		(22)//220�b
#define FIRSTPHASE		(100)//8���ԁAdebug�p�A��
#define SECONDPHASE		(38880)//4��

uint16_t obctime1;
uint16_t obctime2;
uint16_t obctime3;

uint8_t tinytime1;
uint8_t tinytime2;
uint8_t tinytime3;


void getobctime();
void saveobctime();
void advanceobctime();

#endif