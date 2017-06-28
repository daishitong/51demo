/* site:https://github.com/daishitong/51demo */

#ifndef __LED_H__
#define __LED_H__

#include <reg52.h>

sbit Led_Pin = P2^0;

#define LED_ON 0
#define LED_OFF 1

#define SetLedState(state) {Led_Pin = state;}

void Led_TurnOn();
void Led_TurnOff();

#endif