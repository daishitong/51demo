/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "StepperMotor.h"
#include "delay.h"

void main()
{
	unsigned char i;

    for(i = 0;i < 128;i++)
    {
        StepperMotor_Run_CW();
    }
    for(i = 0;i < 128;i++)
    {
        StepperMotor_Run_CCW();
    }
    StepperMotor_Stop();
    for(i = 0;i < 128;i++)
    {
        delay_nms(10);
    }
}