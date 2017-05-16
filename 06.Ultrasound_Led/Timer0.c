/* site:https://github.com/daishitong/51demo */

#include "Timer0.h"
#include <reg52.h>

typedef enum EnumTimerMode
{
    Mode_13Bit,
    Mode_16Bit,
    Mode_8Bit,
}TimerMode;

void Timer0_Init()
{
    TMOD = (TMOD & 0xf0 | Mode_16Bit);
}

void Timer0_Start()
{
    TH0 = TL0 = 0;
    
    TF0 = 0; 	// Clear Timer0 Overflow Flag
    TR0 = 1;	// 1:Turn on timer0
}

void Timer0_Stop()
{
    TR0 = 0;	// 0:Turn off timer0
}

unsigned short Timer0_CurrentCount()
{
     return ((TH0 << 8) | TL0);
}
