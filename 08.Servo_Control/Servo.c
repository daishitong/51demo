/* site:https://github.com/daishitong/51demo */

#include "Servo.h"
#include "delay.h"

void Servo_Run(short high_us)
{
    Servo_Pin = 1;
    delay_nus(high_us);
    Servo_Pin = 0;

    delay_nms(20);
}
