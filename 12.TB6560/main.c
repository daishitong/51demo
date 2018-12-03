/* site:https://github.com/daishitong/51demo */

#include "TB6560.h"
#include "delay.h"

void main()
{
    while(1)
    {
        TB6560_SetEn(0);        // 禁止
        TB6560_SetClkCount(200);
        
        TB6560_SetEn(1);        // 使能
        delay_nms(5000);

        TB6560_SetCW(0);        // 正转
        TB6560_SetClkCount(500);
        TB6560_SetCW(1);        // 反转
        TB6560_SetClkCount(500);
    }
}
