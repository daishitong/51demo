/* site:https://github.com/daishitong/51demo */

#ifndef __TIMER2_PWM_H__
#define __TIMER2_PWM_H__

#include <reg52.h>
#include "type.h"

sbit Timer_PWM_Pin = P2^7;

void Timer2_PWM_Init();
void Timer2_PWM_Set(ushort high_us,ushort low_us);

void Timer2_PWM_Start();
void Timer2_PWM_Stop();

#endif