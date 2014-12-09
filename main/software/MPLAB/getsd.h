#ifndef _GETSD_H_
#define _GETSD_H_

#define MAX_SENSOR (18)

#define SD_GYRO1	(sensordatas[0])
#define SD_GYRO2	(sensordatas[1])
#define SD_GYRO3	(sensordatas[2])
#define SD_BATCUR	(sensordatas[3])
#define SD_RSSI		(sensordatas[4])
#define SD_MSNTEMP	(sensordatas[5])
#define SD_TXTEMP1	(sensordatas[6])
#define SD_TXTEMP2	(sensordatas[7])
#define SD_TXTEMP3	(sensordatas[8])
#define SD_BATTEMP1	(sensordatas[9])
#define SD_BATTEMP2	(sensordatas[10])
#define SD_COVERTEMP1	(sensordatas[11])
#define SD_COVERTEMP2	(sensordatas[12])
#define SD_BATCASETEMP	(sensordatas[13])
#define SD_MSNCUR	(sensordatas[14])
#define SD_MEMS		(sensordatas[15])
#define SD_BATVOL		(sensordatas[16])
#define SD_TXTEMPMEAN		(sensordatas[17])


uint8_t sensordatas[MAX_SENSOR];

void sdinit();
void getallsd();
uint8_t getmemssd();

#endif