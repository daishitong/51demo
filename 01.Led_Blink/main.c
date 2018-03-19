/* site:https://github.com/daishitong/51demo */

#include "delay.h"
#include "Led.h"

void main()
{
    while(1)
    {
        // 点亮LED，保持500ms
        Led_TurnOn();
        delay_nms(500);

        // 熄灭LED，保持500ms
        Led_TurnOff();
        delay_nms(500);
    }
}