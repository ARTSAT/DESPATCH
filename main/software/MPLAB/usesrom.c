#include "despatch.h"

char read_ex_eeprom_01(int8_t page,int16_t adrs){ //eeprom U1C01の読み込みadrsでアドレス指定。　pageビットでページ切り替え可能。

	char value;
	
	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA0); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_start();
		i2c_write(0xA0 | 0x01 ); //チップ指定と読み込みモード
		value = i2c_read(0); //データ読み込み
		i2c_stop();
	}else{//page1
		i2c_start();
		i2c_write(0xA8); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_start(); 
		i2c_write(0xA8 | 0x01 ); //チップ指定と読み込みモード
		value = i2c_read(0); //データ読み込み
		i2c_stop();
	}
	return(value);
}

char read_ex_eeprom_02(int8_t page,int16_t adrs){ //eeprom U1C02の読み込み。adrsでアドレス指定。　pageビットでページ切り替え可能。

	char value;

	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA2); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_start(); 
		i2c_write(0xA2 | 0x01 ); //チップ指定と読み込みモード
		value = i2c_read(0); //データ読み込み
		i2c_stop();
	}else{//page1
		i2c_start();
		i2c_write(0xAA); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_start(); 
		i2c_write(0xAA | 0x01 ); //チップ指定と読み込みモード
		value = i2c_read(0); //データ読み込み
		i2c_stop();
	}
	return(value);
}

void write_ex_eeprom_01(int8 page,int16_t adrs, char wdata){ //eeprom U1C01への書き込み。adrsでアドレス指定。　pageビットでページ切り替え可能。

	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA0); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_write(wdata);//データの書き込み
		i2c_stop();
		delay_ms(5);//eepromへの書き込み完了待ち
	}else{//page1
		i2c_start();
		i2c_write(0xA8); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_write(wdata);//データの書き込み
		i2c_stop();
		delay_ms(5);//eepromへの書き込み完了待ち
	}
}

void write_ex_eeprom_02(int8_t page,int16_t adrs,char wdata){//U1CO2への書き込み
		
	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA2); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_write(wdata);//データの書き込み
		i2c_stop();
		delay_ms(5);//eepromへの書き込み完了待ち
	}else{//page1
		i2c_start();
		i2c_write(0xAA); //チップ指定
		i2c_write((adrs >> 8 ) & 0xFF); //上位アドレス送信
		i2c_write(adrs& 0xFF); //下位アドレス送信
		i2c_write(wdata);//データの書き込み
		i2c_stop();
		delay_ms(5);//eepromへの書き込み完了待ち
	}
}