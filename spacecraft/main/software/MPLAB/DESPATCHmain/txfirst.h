#ifndef _TXFIRST_H_
#define _TXFIRST_H_
#define MORSEMAX 2//���[���X�̎�ނ̐�

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

uint8_t as[4];//���ꂼ��̃t�F�[�Y�ɂ����郂�[���X�̎��  
uint8_t morsephase;//���[���X�̌��݂̃t�F�[�Y�i0�`3�j
uint16_t morseindex;//���[���X�̃f�[�^�̃C���f�b�N�X�i�t�F�[�Y�̒��ŉ��Ԗڂ��j
uint8_t   morseflag;//���̃t�F�[�Y�Ɉڍs���ɂP�𗧂Ă邱�ƂŁA�C���^�[�o���̎��Ԃ����
uint8_t morseintarval_10s;//�C���^�[�o������񂵗p�B
uint8_t k0;
uint32_t k1;
uint8_t k2;




#endif
