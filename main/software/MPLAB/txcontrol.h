#ifndef _TXCONTROL_H_
#define _TXCONTROL_H_

#define TX_THERMO_LIMIT	(76)
#define TX_RESTART_LIMIT	(90)
#define TX_IS_HOT	(63)
#define TX_IS_COOL	(0)

//温度センサ：中心は2.5V:17℃
//1.5Vで70℃


uint8_t txhotflag;

void key_on();
void key_off();
void pll_on();
void pll_off();

void out_bit_cw(short);
void strobe_cw(void);
void out_bits_cw(int8_t, uint16_t);
void set_reference_divider_cw(uint16_t);
void set_option_register_cw(int8_t, int8_t, int8_t, int8_t, int8_t);
void set_programmable_divider_cw(uint8_t, uint16_t, int8_t);
void pll_init_cw(uint16_t, uint8_t, uint16_t, int8_t, int8_t, int8_t, int8_t, int8_t, int8_t);
void set_pll_cw(void);

char convert_to_hex1(uint8_t);
char convert_to_hex0(uint8_t);
char hex(uint8_t);
void watch_txtemp();


#endif