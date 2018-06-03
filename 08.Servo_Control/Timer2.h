/* site:https://github.com/daishitong/51demo */

#ifndef __TIMER2_H__
#define __TIMER2_H__

#include "type.h"
#include "pointer.h"
#include "Timer.h"

#define Timer2_Start()  {TR2 = 1;}
#define Timer2_Stop()   {TR2 = 0;}

void Timer2_Init(Action timer2Handler);
void Timer2_SetTimeOut(ushort us);
void Timer2_SetCounterOut(ushort nCount);

#endif