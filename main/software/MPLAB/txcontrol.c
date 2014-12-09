#include "despatch.h"

void txinit(){
	key_off();
	pll_off();
	output_low(CWSTB);
	output_low(CWCLK);
	output_low(CWDAT);
	restart_wdt();
	delay_ms(500);
	delay_ms(500);
	restart_wdt();
	pll_on();
	delay_ms(500);
	delay_ms(500);
	txhotflag=TX_IS_COOL;
	
	restart_wdt();
	pll_init_cw(
	0x0EF,				// refernce driver 		(Nref = 239）
	0x015,				// swallow counter 		(Nprg = 2613)
	0x051,				// programmable_counter (Nprg = 2613)
	1,					// channel 				(Group code "01")
	3,					// charge_pump_tx 		(CPT1 = 1, CPT2 = 1)
	0,					// charge_pump_rx 		(CPR1 = 0, CPR2 = 0)
	1,					// lock_detector 		(LD1 = 1, LD2 = 0)
	0,					// standby_control_tx 	(Tx = 0)
	1					// standby_control_rx 	(Rx = 1)
	); 
	delay_ms(500);
	restart_wdt();
}
//100011101
//101000110101

void key_on(){
	output_low(CWKEY);
}

void key_off(){
	output_high(CWKEY);
}

void pll_on(){
	output_high(CWTXE);
}

void pll_off(){
	output_low(CWTXE);
}

void out_bit_cw(short dat) {
	if (dat == 0) {
		output_low(CWDAT);
	}
	else {
		output_high(CWDAT);
	}
	
	
	//クロックを進める
	output_high(CWCLK);
	delay_us(10);		// PLL ICのデータシートより0.2us以上
	output_low(CWCLK);
	delay_us(10);
}

/*strobe信号・・・終わりましたよーって言う合図*/
void strobe_cw() {
	output_high(CWSTB);
	delay_us(10);		// PLL ICのデータシートより0.2us以上
	output_low(CWSTB);
	delay_us(20);
}


void out_bits_cw(int8_t num_bits, uint16_t dat) {
	int v;
	
	for (v = 0; v < num_bits; v++) {
		out_bit_cw(dat & 0x0001);
		dat >>=1;
	}
}


// Reference_dividerの設定 (Group code:"11")
void set_reference_divider_cw(uint16_t count) {
	
	// Refernce divider (12bit)
	out_bits_cw(12, count);
	
	// Refernce dividerのGroup code
	out_bit_cw(1);
	out_bit_cw(1);
	
	// ストローブ信号送信
	strobe_cw();
}


// Optional controlの設定 (Group code:"00")
void set_option_register_cw(
	int8_t charge_pump_tx,
	int8_t charge_pump_rx,
	int8_t lock_detector,
	int8_t standby_control_tx,
	int8_t standby_control_rx
	) {
	strobe_cw();
	out_bits_cw(3, 0);					// Test mode (Usually set up T1=T2=T3=0) 
	out_bits_cw(2, (uint16_t)charge_pump_tx);		// CPT1, CPT2
	out_bits_cw(2, (uint16_t)charge_pump_rx);		// CPR1, CPR2
	out_bits_cw(2, (uint16_t)lock_detector);		// LD1, LD2
	out_bit_cw(standby_control_tx);		// TX
	out_bit_cw(standby_control_rx);		// RX
	
	// Optional controlのGroup code
	out_bit_cw(0);
	out_bit_cw(0);
	
	// ストローブ信号送信
	strobe_cw();
}


// Programmable dividerの設定 (Group code: Tx="10", Rx="01")

void set_programmable_divider_cw(
	uint8_t swallow_counter,
	uint16_t programmable_counter,
	int8_t channel
	) {
	out_bits_cw(5,(uint16_t) swallow_counter);
	out_bits_cw(12, programmable_counter);
	
	
	if (channel == 1) {			// chanel=1: Tx
		out_bit_cw(1);
		out_bit_cw(0);
	}
	else if (channel == 2) {						// chanel=2: Rx
		out_bit_cw(0);
		out_bit_cw(1);
	}else if (channel == 3) {						// chanel=2: Rx
		out_bit_cw(1);
		out_bit_cw(1);
	}
	
	// ストローブ信号送信
	strobe_cw();
}

void pll_init_cw(
	uint16_t reference_divider, 
	uint8_t swallow_counter,
	uint16_t programmable_counter,
	int8_t channel,							//channel 1 : Tx "10"、channel 2 : Rx "01"
	int8_t charge_pump_tx,
 	int8_t charge_pump_rx,
 	int8_t lock_detector,
 	int8_t standby_control_tx,
 	int8_t standby_control_rx
 	) {
	set_option_register_cw(charge_pump_tx, charge_pump_rx, lock_detector,
	standby_control_tx, standby_control_rx);
	set_reference_divider_cw(reference_divider);
	set_programmable_divider_cw(swallow_counter, programmable_counter, channel);
}


char convert_to_hex1(uint8_t data){
	uint8_t hexdata=data/16;
	return hex(hexdata);
}

char convert_to_hex0(uint8_t data){
	uint8_t hexdata=data%16;
	return hex(hexdata);
}


char hex(uint8_t dec){
	switch(dec) {
		case 0:	return '0';
		case 1:	return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'a';
		case 11: return 'b';
		case 12: return 'c';
		case 13: return 'd';
		case 14: return 'e';
		case 15: return 'f';
	}
}
	
void watch_txtemp(){
	uint8_t thermo1=getCriticalDatas(TXTEMP1);
	uint8_t thermo2=getCriticalDatas(TXTEMP2);
	uint8_t thermo3=getCriticalDatas(TXTEMP3);
	uint8_t tempthermo=(thermo1&thermo2)|(thermo2&thermo3)|(thermo3&thermo1);
	if(txhotflag==TX_IS_HOT){
		key_off();
		pll_off();
		if(tempthermo>TX_RESTART_LIMIT){
			txinit();
		}
	}else if(tempthermo<TX_THERMO_LIMIT){
			txhotflag=TX_IS_HOT;
			key_off();
			pll_off();
	}
	return;
}
