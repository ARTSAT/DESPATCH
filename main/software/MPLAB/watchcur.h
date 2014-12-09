#ifndef _WATCHCUR_H_
#define _WATCHCUR_H_

#define MSNCURRENTLIMIT	(220)//—vŒŸ“¢
#define MSNOVERCUR	(1)
#define MSNNORMAL	(0)

uint8_t msnovercurflag;

void watchcurinit();
void watchmsncur();

#endif