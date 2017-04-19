/* site:https://github.com/daishitong/51demo */

#include "Servo.h"
#include "delay.h"

void Servo_Single(char pin_id,int pwm_us)
{
    SERVO_PORT |= (1 << pin_id);
    delay_nus(pwm_us);
    SERVO_PORT &= (~(1 << pin_id));
    delay_nus(20000 - pwm_us);
}

void Servo_Multi(ServoPinInfo pinGroup[],int count)
{
    int i;
    char pin_id;
    int pwm_us;

    for(i = 0;i < count;i++)
    {
        pin_id = pinGroup[i].pin_id;
        pwm_us = pinGroup[i].pwm_us;

        SERVO_PORT |= (1 << pin_id);
        delay_nus(pwm_us);
        SERVO_PORT &= (~(1 << pin_id));
        delay_nus(2500 - pwm_us);
    }
    if(count < 8)
    {
        delay_nus(2500 * (8 - count));
    }
}
