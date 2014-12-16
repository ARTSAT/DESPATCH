#include "despatch.h"

void txthird(){
	if(txt_count++<txt_length){
		key_on();
	}else if(txt_count<(txt_length<<1)){
		key_off();
	}else{
		getnextlength();
	}
}

void getnextlength(){
	uint8_t thermo1=getCriticalDatas(TXTEMP1);
	uint8_t thermo2=getCriticalDatas(TXTEMP2);
	uint8_t thermo3=getCriticalDatas(TXTEMP3);
	uint8_t tempthermo=(thermo1&thermo2)|(thermo2&thermo3)|(thermo3&thermo1);
	txt_length=tempthermo>>2;
	txt_count=0;
}

void txtinit(){
	uint8_t thermo1=getCriticalDatas(TXTEMP1);
	uint8_t thermo2=getCriticalDatas(TXTEMP2);
	uint8_t thermo3=getCriticalDatas(TXTEMP3);
	uint8_t tempthermo=(thermo1&thermo2)|(thermo2&thermo3)|(thermo3&thermo1);
	txt_length=tempthermo>>2;
	txt_count=0;
}

