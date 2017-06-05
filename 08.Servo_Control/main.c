/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void main()
{
    char i;
    ServoPinInfo pinGroup[4] = {{4,1000},{5,1000},{6,1500},{7,2000}};

    while (1)
    {
        pinGroup[0].pwm_us = 1000;
        pinGroup[1].pwm_us = 1000;
        pinGroup[2].pwm_us = 1500;
        pinGroup[3].pwm_us = 2000;
        for(i = 0;i < 100;i++)
        {
            Servo_Multi(pinGroup,4);
        }
        
        pinGroup[0].pwm_us = 1000;
        pinGroup[1].pwm_us = 1000;
        pinGroup[2].pwm_us = 1000;
        pinGroup[3].pwm_us = 1000;
        for(i = 0;i < 100;i++)
        {
            Servo_Multi(pinGroup,4);
        }
        
        pinGroup[0].pwm_us = 2000;
        pinGroup[1].pwm_us = 2000;
        pinGroup[2].pwm_us = 2000;
        pinGroup[3].pwm_us = 2000;
        for(i = 0;i < 100;i++)
        {
            Servo_Multi(pinGroup,4);
        }
    }
}