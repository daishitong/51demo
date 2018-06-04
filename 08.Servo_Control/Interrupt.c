/* site:https://github.com/daishitong/51demo */

#include "Interrupt.h"

void Interrupt_Init(Enum_Interrupt_ID interrupt_id)
{
    IE |= interrupt_id;
}
