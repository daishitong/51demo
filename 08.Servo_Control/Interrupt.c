/* site:https://github.com/daishitong/51lib */

#include "Interrupt.h"

void Interrupt_Init(Enum_Interrupt_ID interrupt_id)
{
    IE |= interrupt_id;
}
