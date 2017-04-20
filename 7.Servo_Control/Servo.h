/* site:https://github.com/daishitong/51demo */

#ifndef __SERVO_H__
#define __SERVO_H__

#include <reg52.h>

#define SERVO_PORT P0

typedef struct
{
    char pin_id;
    short pwm_us;
}ServoPinInfo;

void Servo_Single(char pin_id,short pwm_us);
void Servo_Multi(ServoPinInfo pinGroup[],short count);

#endif