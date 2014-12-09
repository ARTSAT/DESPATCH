#ifndef _TXFIRST_H_
#define _TXFIRST_H_
#define MORSEMAX 2//モールスの種類の数

void txfrist();
uint8_t cw_encoder(char morse);
char getnextmorse();
void setmorse();
void txfinit();
char assignment0(uint8_t s);
char assignment1(uint8_t s);
char assignment2(uint8_t s);
char assignment3(uint8_t s);

void morseInit();

uint8_t as[4];//それぞれのフェーズにおけるモールスの種類  
uint8_t morsephase;//モールスの現在のフェーズ（0～3）
uint16_t morseindex;//モールスのデータのインデックス（フェーズの中で何番目か）
uint8_t   morseflag;//次のフェーズに移行時に１を立てることで、インターバルの時間を作る
uint8_t morseintarval_10s;//インターバルから回し用。
uint8_t k0;
uint32_t k1;
uint8_t k2;




#endif
