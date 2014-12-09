#include "despatch.h"

void sdinit(){
	output_low(STLSB);
	output_high(STMSB);
	output_high(MEMSEL);
	output_low(MEMS2);
	int8_t i;
	for(i=0;i<MAX_SENSOR;i++){
		sensordatas[i]=0;
	}
}

void getallsd(){
	#ifdef _DEBUG_
	printf("GET SD now!\r\n");
	#endif
	delay_ms(10);
	output_low(STMSB);
	output_low(STLSB);
	output_low(MEMSEL);
	SD_GYRO1=GET_SD_GYRO1;
	SD_GYRO2=GET_SD_GYRO2;
	SD_GYRO3=GET_SD_GYRO3;
	SD_BATCUR=GET_SD_BATCUR;
	SD_BATVOL=GET_SD_BATVOL;
	SD_RSSI=GET_SD_RSSI;
	SD_MSNTEMP=GET_SD_MSNTEMP;
	SD_TXTEMP1=getCriticalDatas(TXTEMP1);
	SD_TXTEMP2=getCriticalDatas(TXTEMP2);
	SD_TXTEMP3=getCriticalDatas(TXTEMP3);
	SD_BATTEMP1=getMULAD(MUL_BATTEMP1);
	SD_BATTEMP2=getMULAD(MUL_BATTEMP2);
	SD_COVERTEMP1=getMULAD(MUL_COVERTEMP1);
	SD_COVERTEMP2=getMULAD(MUL_COVERTEMP2);
	SD_BATCASETEMP=getMULAD(MUL_BATCASETEMP);
	SD_MSNCUR=getCriticalDatas(CMSN);
	SD_MEMS=getmemssd();
	uint16_t txtempbuf=((SD_TXTEMP1&SD_TXTEMP2)|(SD_TXTEMP2&SD_TXTEMP3)|(SD_TXTEMP3&SD_TXTEMP1));
	txtempbuf=SD_TXTEMPMEAN*99+txtempbuf;
	txtempbuf=txtempbuf/100;
	SD_TXTEMPMEAN=(uint8_t)txtempbuf;
	output_high(STMSB);
	output_low(STLSB);
	output_high(MEMSEL);
}

uint8_t getmemssd(){
	uint8_t memsdata8=0;
	output_high(MEMS2);
	delay_ms(1);
	output_low(MEMS2);
	delay_ms(10);
	memsdata8=spi_xfer(0);
	
	return memsdata8;

}