/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void main()
{
    short us;
    ServoPinInfo pinGroup[4] = {{4,1000},{5,1000},{6,1500},{7,2000}};

    while (1)
    {
        for(us = 1000;us <= 2000;us += 5)
        {
            pinGroup[0].pwm_us = us;
            Servo_Multi(pinGroup,4);
        }

        for(us = 2000;us >= 1000;us -= 5)
        {
            pinGroup[0].pwm_us = us;
            Servo_Multi(pinGroup,4);
        }
    }
}