/* site:https://github.com/daishitong/51demo */

#include "StepperMotor.h"
#include "delay.h"

void main()
{
    unsigned char i;

    while(1)
    {
        // 步进电机，正转128个时序周期
        for(i = 0;i < 128;i++)
        {
            StepperMotor_Run_CW();
        }

        // 步进电机，反转128个时序周期
        for(i = 0;i < 128;i++)
        {
            StepperMotor_Run_CCW();
        }

        // 步进电机，停止
        for(i = 0;i < 128;i++)
        {
            delay_nms(10);
        }
    }
}