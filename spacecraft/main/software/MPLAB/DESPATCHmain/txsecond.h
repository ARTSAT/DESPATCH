#ifndef _TXSECOND_H_

#define CHUNK_UNIT	(10)	//�`�����N�̍\��������
#define CHUNK_MAX	(8)	//�`�����N�̐�

uint8_t txs_period;//�������Ă�ꕶ��
uint8_t txs_periodcount;//�ꕶ���𑗂邽�߂́A���b�o�������̃J�E���g�A1sec�Ń��Z�b�g
uint8_t txs_termcount;//��P��𑗂邽�߂́A�����̕����𑗂������̃J�E���g�A10�����Ń��Z�b�g
uint16_t txs_chunkcount;//�����̒P��𑗂������̃J�E���g�A8�����Ń��Z�b�g
uint16_t txs_sentencecount1;//�����̒P��𑗂������̃J�E���g�A8�����Ń��Z�b�g
uint16_t txs_sentencecount2;//�����̒P��𑗂������̃J�E���g�A8�����Ń��Z�b�g
uint16_t txs_sentencecount3;//�����̒P��𑗂������̃J�E���g�A8�����Ń��Z�b�g
char txs_chunk[11];//10������1�`�����N


void txsinit();
void txsecond();
uint8_t bcode_encoder(char);
void getnextbcode();
void getnextchunk();
void savesentencecount();
void getsentencecount();


#endif
