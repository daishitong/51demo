/* site:https://github.com/daishitong/51demo */

#ifndef __DCMOTO_H__
#define __DCMOTO_H__

#include <reg52.h>

sbit Moto_Pin0 = P2^6;
sbit Moto_Pin1 = P2^7;

void Moto_RunCW(char dutyCycle);
void Moto_RunCCW(char dutyCycle);

#endif