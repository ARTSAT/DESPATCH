#ifndef _TXSECOND_H_

#define CHUNK_UNIT	(10)	//チャンクの構成文字数
#define CHUNK_MAX	(8)	//チャンクの数

uint8_t txs_period;//今送ってる一文字
uint8_t txs_periodcount;//一文字を送るための、何秒経ったかのカウント、1secでリセット
uint8_t txs_termcount;//一単語を送るための、何この文字を送ったかのカウント、10周期でリセット
uint16_t txs_chunkcount;//何この単語を送ったかのカウント、8周期でリセット
uint16_t txs_sentencecount1;//何この単語を送ったかのカウント、8周期でリセット
uint16_t txs_sentencecount2;//何この単語を送ったかのカウント、8周期でリセット
uint16_t txs_sentencecount3;//何この単語を送ったかのカウント、8周期でリセット
char txs_chunk[11];//10文字で1チャンク


void txsinit();
void txsecond();
uint8_t bcode_encoder(char);
void getnextbcode();
void getnextchunk();
void savesentencecount();
void getsentencecount();


#endif
