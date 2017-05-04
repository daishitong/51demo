/* site:https://github.com/daishitong/51demo */

#include "StepperMotor.h"
#include "delay.h"

void main()
{
    unsigned char i;

    while(1)
    {
        for(i = 0;i < 128;i++)
        {
            StepperMotor_Run_CW();
        }
        for(i = 0;i < 128;i++)
        {
            StepperMotor_Run_CCW();
        }
        for(i = 0;i < 128;i++)
        {
            delay_nms(10);
        }
    }
}