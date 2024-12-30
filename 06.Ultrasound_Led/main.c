/* site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "Led.h"
#include "delay.h"

#define AlarmDistance 200   // 报警距离：200mm

void main()
{
    float distance;

    // 超声模块初始化
    HC_SR04_Init();
    while (1)
    {
        // 获取超声模块到障碍物的距离
        distance = HC_SR04_GetDistance();

        if (distance < AlarmDistance)
        {
            Led_TurnOn();       // 距离小于报警距离，点亮LED
        }
        else
        {
            Led_TurnOff();      // 距离大于报警距离，熄灭LED
        }
        
        delay_nms(200);
    }
}