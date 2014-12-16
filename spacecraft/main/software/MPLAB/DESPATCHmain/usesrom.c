#include "despatch.h"

char read_ex_eeprom_01(int8_t page,int16_t adrs){ //eeprom U1C01�̓ǂݍ���adrs�ŃA�h���X�w��B�@page�r�b�g�Ńy�[�W�؂�ւ��\�B

	char value;
	
	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA0); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_start();
		i2c_write(0xA0 | 0x01 ); //�`�b�v�w��Ɠǂݍ��݃��[�h
		value = i2c_read(0); //�f�[�^�ǂݍ���
		i2c_stop();
	}else{//page1
		i2c_start();
		i2c_write(0xA8); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_start(); 
		i2c_write(0xA8 | 0x01 ); //�`�b�v�w��Ɠǂݍ��݃��[�h
		value = i2c_read(0); //�f�[�^�ǂݍ���
		i2c_stop();
	}
	return(value);
}

char read_ex_eeprom_02(int8_t page,int16_t adrs){ //eeprom U1C02�̓ǂݍ��݁Badrs�ŃA�h���X�w��B�@page�r�b�g�Ńy�[�W�؂�ւ��\�B

	char value;

	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA2); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_start(); 
		i2c_write(0xA2 | 0x01 ); //�`�b�v�w��Ɠǂݍ��݃��[�h
		value = i2c_read(0); //�f�[�^�ǂݍ���
		i2c_stop();
	}else{//page1
		i2c_start();
		i2c_write(0xAA); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_start(); 
		i2c_write(0xAA | 0x01 ); //�`�b�v�w��Ɠǂݍ��݃��[�h
		value = i2c_read(0); //�f�[�^�ǂݍ���
		i2c_stop();
	}
	return(value);
}

void write_ex_eeprom_01(int8 page,int16_t adrs, char wdata){ //eeprom U1C01�ւ̏������݁Badrs�ŃA�h���X�w��B�@page�r�b�g�Ńy�[�W�؂�ւ��\�B

	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA0); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_write(wdata);//�f�[�^�̏�������
		i2c_stop();
		delay_ms(5);//eeprom�ւ̏������݊����҂�
	}else{//page1
		i2c_start();
		i2c_write(0xA8); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_write(wdata);//�f�[�^�̏�������
		i2c_stop();
		delay_ms(5);//eeprom�ւ̏������݊����҂�
	}
}

void write_ex_eeprom_02(int8_t page,int16_t adrs,char wdata){//U1CO2�ւ̏�������
		
	if( page == 0){//page0
		i2c_start();
		i2c_write(0xA2); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_write(wdata);//�f�[�^�̏�������
		i2c_stop();
		delay_ms(5);//eeprom�ւ̏������݊����҂�
	}else{//page1
		i2c_start();
		i2c_write(0xAA); //�`�b�v�w��
		i2c_write((adrs >> 8 ) & 0xFF); //��ʃA�h���X���M
		i2c_write(adrs& 0xFF); //���ʃA�h���X���M
		i2c_write(wdata);//�f�[�^�̏�������
		i2c_stop();
		delay_ms(5);//eeprom�ւ̏������݊����҂�
	}
}