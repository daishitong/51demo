/* site:https://github.com/daishitong/51demo */

#ifndef __TB6560_H__
#define __TB6560_H__

#include <reg52.h>
#include "boolean.h"

#define TB6560_SetCW(cw_flag) (TB6560_CW = cw_flag)
#define TB6560_SetEn(en_flag) (TB6560_EN = en_flag)

sbit TB6560_EN = P2^7;
sbit TB6560_CW = P2^6;
sbit TB6560_CLK = P2^5;

void TB6560_SetClkCount(int count);

#endif
