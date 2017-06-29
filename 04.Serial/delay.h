/* site:https://github.com/daishitong/51demo */

#ifndef __DELAY_H__
#define __DELAY_H__

void delay_nms(int ms);
void delay_nus(int us);            // fixed-offset:56us
void delay_100nop();
void delay_5nop();

#endif