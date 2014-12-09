#include "despatch.h"

void watchmsncur(){
	if(msnovercurflag==MSNOVERCUR){
		msnovercurflag=MSNNORMAL;
		output_high(SWMSN);
		return;
	}
	
	
	uint8_t tempmsncur=getCriticalDatas(CMSN);
	if(tempmsncur>MSNCURRENTLIMIT){
		output_low(SWMSN);
		msnovercurflag=MSNOVERCUR;
		return;
	}
	return;
}

void watchcurinit(){
	msnovercurflag=MSNNORMAL;
}