/* site:https://github.com/daishitong/51demo */

#include "Servo.h"
#include "delay.h"

#define ZERO_HIGH_US 1500
#define STEP_HIGH_US 25

short _last_high_us = ZERO_HIGH_US;

void Servo_Run_OneCycle(short high_us)
{
    Servo_Pin = 1;
    delay_nus(high_us);
    Servo_Pin = 0;

    delay_nms(20);
}

void Servo_Run(short high_us)
{
    short current;

    if(_last_high_us < high_us)
    {
        for(current = _last_high_us; current < high_us; current += STEP_HIGH_US)
        {
            Servo_Run_OneCycle(current);
        }        
    }
    else if(_last_high_us > high_us)
    {
        for(current = _last_high_us; current > high_us; current -= STEP_HIGH_US)
        {
            Servo_Run_OneCycle(current);
        }
    }
    
    Servo_Run_OneCycle(high_us);
    
    _last_high_us = high_us;
}

void Servo_Init()
{
    Servo_Run(ZERO_HIGH_US);
}