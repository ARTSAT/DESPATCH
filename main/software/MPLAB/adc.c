#include "despatch.h"

void adcinit(void){
	setup_adc(ADC_CLOCK_DIV_8);
	setup_adc_ports(ALL_ANALOG);	
	return ;
}

uint8_t getMULAD(uint8_t id){
	//MPXを通したデータ取得用
	uint16_t data=0;
	uint8_t data_r;
	uint8_t portid=id/8;
	int8_t port=0;
	switch(portid){
		case 0:port=MULAD_LA;break;
		case 2:port=MULAD_LB;break;
		case 4:port=MULAD_UA;break;
		case 8:port=MULAD_UB;break;
		default: return 0;
	}
	if(bit_test(id,1)){
		output_high(MPX1);
	}else{
		output_low(MPX1);
	}
	
	if(bit_test(id,2)){
		output_high(MPX2);
	}else{
		output_low(MPX2);
	}
	
	if(bit_test(id,3)){
		output_high(MPX3);
	}else{
		output_low(MPX3);
	}
	
	set_adc_channel(port);
	restart_wdt();
	delay_us(20);
	data=read_adc();
	data_r=data/4;//8bit分取る
	return data_r;
}

uint8_t getCriticalDatas(uint8_t port){
	uint16_t data;	
	uint8_t data_r;
	set_adc_channel(port);
	restart_wdt();
	delay_us(20);
	data=read_adc();
	data_r=data/4;//8bit分取る
	return data_r;
}