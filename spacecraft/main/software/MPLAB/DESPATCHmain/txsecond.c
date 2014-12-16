#include "despatch.h"

void txsecond(){
	if(txs_termcount>0){
		uint8_t txs_output=bit_test(txs_period,txs_periodcount/10);
		txs_output=txs_output^((txs_periodcount%10)<5);
		output_bit(CWKEY,txs_output);//Low‚Åkeyon,High‚Åkeyoff
		
		txs_periodcount++;
		if(txs_periodcount>49){
			txs_periodcount=0;
			getnextbcode();
		}
	}else{
		output_high(MEMSEL);
		output_high(STLSB);
		txs_periodcount++;
		if(txs_chunkcount>0x70){
			if(txs_periodcount>100){
				key_on();
			}
			if(txs_periodcount>150){
				key_off();
				getnextbcode();
			}else{
				key_off();
			}
		}else{		
			key_off();
			if(txs_periodcount>100){
				txs_periodcount=0;
				getnextbcode();
			}
		}
	}
return;
}

uint8_t bcode_encoder(char c){

	switch(c) {
		case '\0': return 0;	/**/
		case 'e': return 1;	/**/
		case '3': return 1;	/**/
		case '\n': return 2;	/**/
		case 'a': return 3;	/**/
		case ' ': return 4;	/**/
		case '_': return 4;	/**/
		case 's': return 5;	/**/
		case '\'': return 5;	/**/
		case 'i': return 6;	/**/
		case '8': return 6;	/**/
		case 'u': return 7;	/**/
		case '7': return 7;	/**/
		case '\r': return 8;	/**/
		case 'd': return 9;	/**/
		case 'r': return 10;	/**/
		case '4': return 10;	/**/
		case 'j': return 11;	/**/
		case 'n': return 12;	/**/
		case ',': return 12;	/**/
		case 'f': return 13;	/**/
		case '!': return 13;	/**/
		case 'c': return 14;	/**/
		case ':': return 14;	/**/
		case 'k': return 15;	/**/
		case '(': return 15;	/**/
		case 't': return 16;	/**/
		case '5': return 16;	/**/
		case 'z': return 17;	/**/
		case '+': return 17;	/**/
		case 'l': return 18;	/**/
		case ')': return 18;	/**/
		case 'w': return 19;	/**/
		case '2': return 19;	/**/
		case 'h': return 20;	/**/
		case 'y': return 21;	/**/
		case '6': return 21;	/**/
		case 'p': return 22;	/**/
		case '0': return 22;	/**/
		case 'q': return 23;	/**/
		case '1': return 23;	/**/
		case 'o': return 24;	/**/
		case '9': return 24;	/**/
		case 'b': return 25;	/**/
		case '?': return 25;	/**/
		case 'g': return 26;	/**/
		case 'F': return 27;	/*FIGS‚ðŽ¦‚·*/
		case 'm': return 28;	/**/
		case '.': return 28;	/**/
		case 'x': return 29;	/**/
		case '/': return 29;	/**/
		case 'v': return 30;	/**/
		case ';': return 30;	/**/
		case 'L': return 31;	/*LTRS‚ðŽ¦‚·*/
		case 'N': return 0;	/*NULL‚ðŽ¦‚·*/
		default:  return (((uint8_t)c)&0b00011111);
	}

}

void getnextbcode(){
	txs_period=bcode_encoder(txs_chunk[txs_termcount]);
	txs_termcount++;
	if(txs_termcount>CHUNK_UNIT){
		getnextchunk();
		txs_termcount=0;
	}
	return;
}

void getnextchunk(){
	output_low(STLSB);
	output_low(MEMSEL);//EEPROM“Ç‚Ýž‚Ý‚Ì\‚¦
	uint16_t temp_txs_sentencecount=(txs_sentencecount1&txs_sentencecount2)|(txs_sentencecount2&txs_sentencecount3)|(txs_sentencecount3&txs_sentencecount2);
	
	
	if(txs_chunkcount>0x70){
		txs_chunkcount=0;
		savesentencecount();
		temp_txs_sentencecount++;
		txs_sentencecount1=temp_txs_sentencecount;
		txs_sentencecount2=temp_txs_sentencecount;
		txs_sentencecount3=temp_txs_sentencecount;
	}
	
	//EEPROM‚ð“Ç‚Þ
	int i=0;
	uint16_t tempadress=0;
	if(temp_txs_sentencecount>=0x300)
		getsentencecount();
	
	if(temp_txs_sentencecount<0x100){
		for(i=0;i<CHUNK_UNIT;i++){
			tempadress=temp_txs_sentencecount*0x100;
			tempadress+=txs_chunkcount;
			tempadress+=i;
			txs_chunk[i]=read_ex_eeprom_01(0,tempadress);
		}
	}else if(temp_txs_sentencecount<0x200){
		for(i=0;i<CHUNK_UNIT;i++){
			tempadress=temp_txs_sentencecount*0x100;
			tempadress+=txs_chunkcount;
			tempadress+=i;
			txs_chunk[i]=read_ex_eeprom_01(1,tempadress);
		}
	}else if(temp_txs_sentencecount<0x300){
		for(i=0;i<CHUNK_UNIT;i++){
			tempadress=temp_txs_sentencecount*0x100;
			tempadress+=txs_chunkcount;
			tempadress+=i;
			txs_chunk[i]=read_ex_eeprom_02(0,tempadress);
		}
	}else{
		txs_sentencecount1=0;
		txs_sentencecount2=0;
		txs_sentencecount3=0;
		savesentencecount();	
	}
	txs_chunk[CHUNK_UNIT]='\0';
	#ifdef _DEBUG_
	printf("Now sentencecount is %lu and tempadress is %lu.\r\n",temp_txs_sentencecount,tempadress);
	printf(txs_chunk);
	printf("\r\n");
	#endif
	txs_chunkcount=txs_chunkcount+0x10;
	delay_ms(10);
	return;
	

}

void savesentencecount(){
	uint16_t temp_txs_sentencecount=(txs_sentencecount1&txs_sentencecount2)|(txs_sentencecount2&txs_sentencecount3)|(txs_sentencecount3&txs_sentencecount2);
	uint8_t othb=temp_txs_sentencecount>>8;
	write_eeprom(SENTENCECOUNTHIGHBYTE1,othb);
	write_eeprom(SENTENCECOUNTHIGHBYTE2,othb);
	write_eeprom(SENTENCECOUNTHIGHBYTE3,othb);
	uint8_t otlb=temp_txs_sentencecount&0b0000000011111111;
	write_eeprom(SENTENCECOUNTLOWBYTE1,otlb);
	write_eeprom(SENTENCECOUNTLOWBYTE2,otlb);
	write_eeprom(SENTENCECOUNTLOWBYTE3,otlb);
	return;
}

void getsentencecount(){
	uint8_t othb1=read_eeprom(SENTENCECOUNTHIGHBYTE1);
	uint8_t othb2=read_eeprom(SENTENCECOUNTHIGHBYTE2);
	uint8_t othb3=read_eeprom(SENTENCECOUNTHIGHBYTE3);
	
	uint16_t sentencecounthighbyte=(othb1&othb2)|(othb3&othb2)|(othb1&othb3);
	sentencecounthighbyte=sentencecounthighbyte<<8;
	
	uint8_t otlb1=read_eeprom(SENTENCECOUNTLOWBYTE1);	
	uint8_t otlb2=read_eeprom(SENTENCECOUNTLOWBYTE2);
	uint8_t otlb3=read_eeprom(SENTENCECOUNTLOWBYTE3);
	
	uint16_t sentencecountlowbyte=(otlb1&otlb2)|(otlb3&otlb2)|(otlb1&otlb3);
	
	txs_sentencecount1=sentencecountlowbyte+sentencecounthighbyte;
	txs_sentencecount2=sentencecountlowbyte+sentencecounthighbyte;
	txs_sentencecount3=sentencecountlowbyte+sentencecounthighbyte;
}

void txsinit(){
	txs_periodcount=0;
	txs_termcount=0;
	txs_chunkcount=0;
	txs_sentencecount1=0;
	txs_sentencecount2=0;
	txs_sentencecount3=0;
	getsentencecount();
	output_low(STMSB);
	output_high(MEMSEL);
	output_high(STLSB);
	restart_wdt();
	int i=0;
	for (i=0;i<100;i++){
		delay_ms(100);
		set_timer1(0);
		restart_wdt();
	}
	getnextchunk();
	delay_ms(100);
	output_high(MEMSEL);
	output_high(STLSB);
}
