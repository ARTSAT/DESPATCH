#include "despatch.h"

void txfirst(){

  if(bit_test(k1,k0)){
    key_on();
  }else{
    key_off();
	}
  k0++;
  if(k0>k2)
    setmorse();
  return;
}

void setmorse(){
	uint8_t buf;
	char nbuf='a';
	k2=0;
	k1=0;
	k0=0;
	
	if(morseindex>as[morsephase]){
	morseflag = 1;
	morseintarval_10s = 0;
	morseindex = 0;
	morsephase++;
	if(morsephase>3){
		as[0]=5;
		as[1]=15;
		as[2]=14;
		as[3]=11;
		morsephase = 0;
		getallsd();
		}
	}
	
  if(morseflag != 1){
	nbuf=getnextmorse();
    buf=cw_encoder(nbuf);
    
    int8_t v;
    v = 0;									// cwを右から1ビットずつ調べる
    while(!bit_test(buf, v)&&(v<7)) {				// "1"があれば、左からその"1"の1つ手前までがモールス符号
      v++;
    }
    restart_wdt();
    int8_t j=7-v;
    
    for(v=0;v<j;v++){
      if(bit_test(buf,7-v)){
	bit_set(k1,k0++);		
	bit_set(k1,k0++);			
	bit_set(k1,k0++);			
	k0++;			
      }else{
	bit_set(k1,k0);
	k0+=2;			
      }
    }
    k0+=2;
    k2=k0;
    k0=0;
    morseindex++;
  }else{
    restart_wdt();//上の場所(elseでない方）で行っていたので,念のため
    k2=5;
    k1=0;
    if(morseintarval_10s++ > 3){//0.1s*5*4=2s
      morseflag = 0;
    }
  }    
}

char getnextmorse(){
	switch(morsephase){
		case 0: return assignment0(morseindex);
		case 1: return assignment1(morseindex);
		case 2: return assignment2(morseindex);
		case 3: return assignment3(morseindex);
		default : txfinit();
  }
}

void txfinit(){//初期化時、１度のみの起動でお願いします。
	morseindex=0;//for txfirst
	k0=0;
	k1=0;
	k2=0;
	morseindex = 0;
	morsephase = 0;
	morseflag  = 0;
	morseintarval_10s=0;
	getallsd();
	as[0]=5;
	as[1]=15;
	as[2]=14;
	as[3]=11;
	#ifdef _DEBUG_
	printf("TX FIRST INITIAL!!\r\n");
	#endif
}
  
//call sign
char assignment0(uint8_t s){
	switch(s){
		case 0:return 'j';
		case 1:return 'q';
		case 2:return '1';
		case 3:return 'z';
		case 4:return 'n';
		case 5:return 'n';
		default :return 'x';
	}
}

//Status
char assignment1(uint8_t s){
switch(s){
		case 0:return convert_to_hex0((uint8_t)(0x00FF&obctime1));
		case 1:return convert_to_hex1((uint8_t)(0x00FF&obctime1));
		case 2:return convert_to_hex0((uint8_t)(obctime1>>8));
		case 3:return convert_to_hex1((uint8_t)(obctime1>>8));
		case 4:return convert_to_hex0(SD_TXTEMP1);
		case 5:return convert_to_hex1(SD_TXTEMP1);
		case 6:return convert_to_hex0(SD_TXTEMP2);
		case 7:return convert_to_hex1(SD_TXTEMP2);
		case 8:return convert_to_hex0(SD_TXTEMP3);
		case 9:return convert_to_hex1(SD_TXTEMP3);
		case 10:return convert_to_hex0(SD_MSNCUR);
		case 11:return convert_to_hex1(SD_MSNCUR);
		case 12:return convert_to_hex0(SD_BATVOL);
		case 13:return convert_to_hex1(SD_BATVOL);
		case 14:return convert_to_hex0(SD_BATCUR);
		case 15:return convert_to_hex1(SD_BATCUR);
		default :return 'x';
	}
}

//Temparture
char assignment2(uint8_t s){
	switch(s){
		case 0:return SD_MSNTEMP;
		case 1:return convert_to_hex0(SD_COVERTEMP1);
		case 2:return convert_to_hex1(SD_COVERTEMP1);
		case 3:return convert_to_hex0(SD_COVERTEMP2);
		case 4:return convert_to_hex1(SD_COVERTEMP2);
		case 5:return convert_to_hex0(SD_BATTEMP1);
		case 6:return convert_to_hex1(SD_BATTEMP1);
		case 7:return convert_to_hex0(SD_BATTEMP2);
		case 8:return convert_to_hex1(SD_BATTEMP2);
		case 9:return convert_to_hex0(SD_BATCASETEMP);
		case 10:return convert_to_hex1(SD_BATCASETEMP);
		case 11:return convert_to_hex0(SD_TXTEMPMEAN);
		case 12:return convert_to_hex1(SD_TXTEMPMEAN);
		case 13:return convert_to_hex0(SD_BATVOL);
		case 14:return convert_to_hex1(SD_BATVOL);
		default :return 'x';
	}
}

//Others

char assignment3(uint8_t s){
	switch(s){
		case 0:return convert_to_hex0(SD_GYRO1);
		case 1:return convert_to_hex1(SD_GYRO1);
		case 2:return convert_to_hex0(SD_GYRO2);
		case 3:return convert_to_hex1(SD_GYRO2);
		case 4:return convert_to_hex0(SD_GYRO3);
		case 5:return convert_to_hex1(SD_GYRO3);
		case 6:return convert_to_hex0(SD_RSSI);
		case 7:return convert_to_hex1(SD_RSSI);
		case 8:return convert_to_hex0(SD_TXTEMPMEAN);
		case 9:return convert_to_hex1(SD_TXTEMPMEAN);
		case 10:return convert_to_hex0(SD_BATVOL);
		case 11:return convert_to_hex1(SD_BATVOL);
		default :return 'x';
		}
}

uint8_t cw_encoder(char morse) {
	switch(morse) {				/* 2進数表示*/
		case '0': return 252;	/* 11111100*/
		case '1': return 124;	/* 01111100*/
		case '2': return 60; 	/* 00111100*/
		case '3': return 28; 	/* 00011100*/
		case '4': return 12; 	/* 00001100*/
		case '5': return 4;  	/* 00000100*/
		case '6': return 132;	/* 10000100*/
		case '7': return 196;	/* 11000100*/
		case '8': return 228;	/* 11100100*/
		case '9': return 244;	/* 11110100*/
		
		case 'a': return 96; 	/* 01100000*/
		case 'b': return 136;	/* 10001000*/
		case 'c': return 168;	/* 10101000*/
		case 'd': return 144;	/* 10010000*/
		case 'e': return 64; 	/* 01000000*/
		case 'f': return 40; 	/* 00101000*/
		case 'g': return 208;	/* 11010000*/
		case 'h': return 8;  	/* 00001000*/
		case 'i': return 32; 	/* 00100000*/
		case 'j': return 120;	/* 01111000*/
		case 'k': return 176;	/* 10110000*/
		case 'l': return 72; 	/* 01001000*/
		case 'm': return 224;	/* 11100000*/
		case 'n': return 160;	/* 10100000*/
		case 'o': return 240;	/* 11110000*/
		case 'p': return 104;	/* 01101000*/
		case 'q': return 216;	/* 11011000*/
		case 'r': return 80; 	/* 01010000*/
		case 's': return 16; 	/* 00010000*/
		case 't': return 192;	/* 11000000*/
		case 'u': return 48; 	/* 00110000*/
		case 'v': return 24; 	/* 00011000*/
		case 'w': return 112;	/* 01110000*/
		case 'x': return 152;	/* 10011000*/
		case 'y': return 184;	/* 10111000*/
		case 'z': return 200;	/* 11001000*/
		
		case '.': return 86; 	/* 01010110*/
		case '-': return 134;	/* 10000110*/

		case '_': return 134;	/* 100011100*/
		
		default:  return 152;//x
	}
}
