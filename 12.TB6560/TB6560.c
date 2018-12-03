/* site:https://github.com/daishitong/51demo */

#include "TB6560.h"
#include "delay.h"

void TB6560_SetClkCount(int count)
{
    int i;

    for(i = 0;i < count;i++)
    {
        TB6560_CLK = 1;
        delay_nms(10);
        TB6560_CLK = 0;
        delay_nms(10);
    }
}
