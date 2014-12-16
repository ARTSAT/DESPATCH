#include "despatch.h"

void getobctime(){

	uint8_t othb1=read_eeprom(OBCTIMEHIGHBYTE1);
	uint8_t othb2=read_eeprom(OBCTIMEHIGHBYTE2);
	uint8_t othb3=read_eeprom(OBCTIMEHIGHBYTE3);
	
	uint16_t obctimehighbyte=(othb1&othb2)|(othb3&othb2)|(othb1&othb3);
	obctimehighbyte=obctimehighbyte<<8;
	
	uint8_t otlb1=read_eeprom(OBCTIMELOWBYTE1);	
	uint8_t otlb2=read_eeprom(OBCTIMELOWBYTE2);
	uint8_t otlb3=read_eeprom(OBCTIMELOWBYTE3);
	
	uint16_t obctimelowbyte=(otlb1&otlb2)|(otlb3&otlb2)|(otlb1&otlb3);

	obctime1=obctimelowbyte+obctimehighbyte;
	obctime2=obctimelowbyte+obctimehighbyte;
	obctime3=obctimelowbyte+obctimehighbyte;
	
	tinytime1=0;
	tinytime2=0;
	tinytime3=0;
	return;
}

void saveobctime(){
	uint16_t tempobctime=(obctime1&obctime2)|(obctime3&obctime2)|(obctime1&obctime3);
	uint8_t othb=tempobctime>>8;
	write_eeprom(OBCTIMEHIGHBYTE1,othb);
	write_eeprom(OBCTIMEHIGHBYTE2,othb);
	write_eeprom(OBCTIMEHIGHBYTE3,othb);
	uint8_t otlb=tempobctime&0b0000000011111111;
	write_eeprom(OBCTIMELOWBYTE1,otlb);
	write_eeprom(OBCTIMELOWBYTE2,otlb);
	write_eeprom(OBCTIMELOWBYTE3,otlb);
	return;
}

void advanceobctime(){
	uint8_t temptinytime=(tinytime1&tinytime2)|(tinytime3&tinytime2)|(tinytime1&tinytime3);
	tinytime1=temptinytime+1;
	tinytime2=temptinytime+1;
	tinytime3=temptinytime+1;
	temptinytime=(tinytime1&tinytime2)|(tinytime3&tinytime2)|(tinytime1&tinytime3);
	//ƒRƒŒ‚ð10s‚Å‚Ü‚Æ‚ß‚é
	if(temptinytime>TINYPERIOD){
		tinytime1=0;
		tinytime2=0;
		tinytime3=0;
		uint16_t tempobctime=(obctime1&obctime2)|(obctime3&obctime2)|(obctime1&obctime3);
		obctime1=tempobctime+1;
		obctime2=tempobctime+1;
		obctime3=tempobctime+1;
		tempobctime=(obctime1&obctime2)|(obctime3&obctime2)|(obctime1&obctime3);
		#ifdef _DEBUG_
			printf("Hello! I am despatch at %lu!\r\n",tempobctime);
			uint8_t thermo1=getCriticalDatas(TXTEMP1);
			uint8_t thermo2=getCriticalDatas(TXTEMP2);
			uint8_t thermo3=getCriticalDatas(TXTEMP3);
			uint8_t tempthermo=(thermo1&thermo2)|(thermo2&thermo3)|(thermo3&thermo1);
			printf("The temp is %u (%u,%u,%u) now.\r\n",tempthermo,thermo1,thermo2,thermo3);
			printf("The GYRO is %u,%u,%u now.\r\n",SD_GYRO1,SD_GYRO2,SD_GYRO3);
			printf("The BAT is %u,%u now.\r\n",SD_BATCUR,SD_BATVOL);
			printf("The MSNTEMP is %u now.\r\n",SD_MSNTEMP);
			printf("The morseindex is %lu now.\r\n",morseindex);
			printf("The morsephase is %u now.\r\n",morsephase);
		#endif
		tempobctime=tempobctime%10;//100•b–ˆ
		if(tempobctime==0){
			saveobctime();
			#ifdef _DEBUG_
				printf("time saved!\r\n");
			#endif
		}
	}
}
