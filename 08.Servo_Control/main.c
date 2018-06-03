/* site:https://github.com/daishitong/51demo */

#include "Timer2_PWM.h"
#include "delay.h"

void main()
{
    // 舵机PWM波时钟初始化
    Timer2_PWM_Init();
    
    while (1)
    {
        // 舵机的脉宽为1500us，低电平为20ms，保持2秒
        Timer2_PWM_Set(1500,20000);
        delay_nms(2000);
        
        // 舵机的脉宽为2000us，低电平为20ms，保持2秒
        Timer2_PWM_Set(2000,20000);
        delay_nms(2000);
        
        // 舵机的脉宽为1500us，低电平为20ms，保持2秒
        Timer2_PWM_Set(1500,20000);
        delay_nms(2000);

        // 舵机的脉宽为1000us，低电平为20ms，保持2秒
        Timer2_PWM_Set(1000,20000);
        delay_nms(2000);
    }
}