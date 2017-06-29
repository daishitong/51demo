/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void MakeServoRun(short pwm_us1,short pwm_us2,short pwm_us3,short pwm_us4)
{
    char i;
    static ServoPinInfo pinGroup[4] = {{4,1500},{5,1500},{6,1500},{7,1500}};
    
    pinGroup[0].pwm_us = pwm_us1;
    pinGroup[1].pwm_us = pwm_us2;
    pinGroup[2].pwm_us = pwm_us3;
    pinGroup[3].pwm_us = pwm_us4;
    for(i = 0;i < 20;i++)
    {
        Servo_Multi(pinGroup,4);
    }
}

void main()
{
    while (1)
    {
        MakeServoRun(1000,1000,1000,1000);
        MakeServoRun(1500,1500,1500,1500);
        MakeServoRun(2000,2000,2000,2000);
        MakeServoRun(1500,1500,1500,1500);
    }
}