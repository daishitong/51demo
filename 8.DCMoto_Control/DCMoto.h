/* site:https://github.com/daishitong/51demo */

#ifndef __DCMOTO_H__
#define __DCMOTO_H__

#include <reg52.h>

sbit Moto_Pin0 = P0^0;
sbit Moto_Pin1 = P0^1;

void Moto_RunCW(char speed);
void Moto_RunCCW(char speed);

#endif