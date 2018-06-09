/* site:https://github.com/daishitong/51demo */

#include "Timer2.h"
#include "Interrupt.h"
#include "type.h"

Action Timer2_Action = NULL;

void Timer2_Init(Action timer2Handler)
{
    C_T2 = 0;
    TR2 = 0;

    Timer2_Action = timer2Handler;

    Interrupt_Init(Interrupt_ID_ET2);
    Interrupt_Enable();
}

void Interrupt_Handler_TF2_VECTOR() interrupt TF2_VECTOR
{
    TF2 = 0;

    if(Timer2_Action != NULL)
    {
        Timer2_Action();
    }
}

void Timer2_SetTimeOut(ushort us)
{
    Timer2_SetCounterOut(TIMER_US2COUNT(us));
}

void Timer2_SetCounterOut(ushort nCount)
{
    TH2 = nCount >> 8;
    TL2 = nCount & 0xff;
}
