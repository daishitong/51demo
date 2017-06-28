#include "ExternalInterrupt0.h"

EventHandler _IE0_EventHandler = NULL;
void ExternalInterrupt0_Init(EventHandler IE0_Handler)
{
    _IE0_EventHandler = IE0_Handler;

    IT0 = 1;    // 0:low level active,1:falling edge active
	ExternalInterrupt0_Pin = 1;

    Interrupt_Init(Interrupt_ID_EX0);
    Interrupt_Enable();
}

void ExternalInterrupt0_WaitHighLevel()
{
	while(ExternalInterrupt0_Pin == 0);	// wait high level
}

void Interrupt_Handler(IE0_VECTOR)
{
    if(_IE0_EventHandler != NULL)
    {
        _IE0_EventHandler();
    }
}