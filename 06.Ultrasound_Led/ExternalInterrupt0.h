#ifndef __EXTERNALINTERRUPT0_H__
#define __EXTERNALINTERRUPT0_H__

#include <reg52.h>
#include "Interrupt.h"

sbit ExternalInterrupt0_Pin = P3^2;

void ExternalInterrupt0_Init(EventHandler IE0_Handler);
void ExternalInterrupt0_WaitHighLevel();

#endif