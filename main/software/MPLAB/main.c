#include "despatch.h"


#include "txcontrol.c"
#include "debug.c"
#include "watchcur.c"
#include "getsd.c"
#include "txfirst.c"
#include "txsecond.c"
#include "txthird.c"
#include "obctime.c"
#include "adc.c"
#include "usesrom.c"

int main(){
	#ifdef _DEBUG_
	printf("DESPATCH START!!\r\n");
	#endif
//initialize
//timer initalize
	setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);//絶対必要
	setup_counters(RTCC_INTERNAL,WDT_2304MS);//同上
	getobctime();//同上
	output_high(SWSENS);//センサオン
	output_high(SWMSN);//ミッションオン
	delay_ms(10);
	adcinit();//ADCオン
	watchcurinit();
	sdinit();
//loop0
	while(obctime1<ZEROPHASE){
		advanceobctime();
		restart_wdt();//wdtはここだけで使いましょう。
		watchmsncur();
		while(get_timer1()<CYCLEPERIOD);
	set_timer1(0);
	}
	txinit();//PLL設定、CWオン
	txfinit();
		#ifdef _DEBUG_
			printf("TX First start!\r\n");
		#endif

//loop1
	while(obctime1<FIRSTPHASE){
		txfirst();
		advanceobctime();
		restart_wdt();//wdtはここだけで使いましょう。
		watch_txtemp();
		watchmsncur();
			while(get_timer1()<CYCLEPERIOD);
			set_timer1(0);
		
	}
	
	#ifdef _DEBUG_
		printf("TX Second start!\r\n");
	#endif

	txsinit();
//loop2
	while(obctime1<SECONDPHASE){
		txsecond();
		advanceobctime();
		watch_txtemp();
		watchmsncur();
		restart_wdt();//wdtはここだけで使いましょう。
		while(get_timer1()<CYCLEPERIOD);
		set_timer1(0);
	}
//loopfinal
	#ifdef _DEBUG_
		printf("TX Third start!\r\n");
	#endif

	txtinit();
	while(1){
		txthird();
		restart_wdt();//wdtはここだけで使いましょう。
		watch_txtemp();
		watchmsncur();
		while(get_timer1()<CYCLEPERIOD);
		set_timer1(0);

	}

	return 0;
}