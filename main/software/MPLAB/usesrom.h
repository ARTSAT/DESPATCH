#ifndef _USESROM_H_
#define _USESROM_H_

#ifdef _DEBUG_
#endif

#define GET_SD_GYRO1	read_ex_eeprom_02(1,0xFA00)
#define GET_SD_GYRO2	read_ex_eeprom_02(1,0xFA01)
#define GET_SD_GYRO3	read_ex_eeprom_02(1,0xFA02)
#define GET_SD_BATCUR	read_ex_eeprom_02(1,0xFA03)
#define GET_SD_BATVOL	read_ex_eeprom_02(1,0xFA04)
#define GET_SD_RSSI		read_ex_eeprom_02(1,0xFA05)
#define GET_SD_MSNTEMP	read_ex_eeprom_02(1,0xFA06)

char read_ex_eeprom_01(int8_t page,int16_t adrs);//eeprom U1C01‚Ì“Ç‚İ‚İ
char read_ex_eeprom_02(int8_t page,int16_t adrs);//eeprom U1C02‚Ì“Ç‚İ‚İ
void write_ex_eeprom_01(int8_t page,int16_t adrs ,char wdata);//U1CO1‚Ö‚Ì‘‚«‚İ)
void write_ex_eeprom_02(int8_t page,int16_t adrs ,char wdata);//U1CO2‚Ö‚Ì‘‚«‚İ)

#endif