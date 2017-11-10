/* site:https://github.com/daishitong/51demo */

#ifndef __SERVO_H__
#define __SERVO_H__

#include <reg52.h>

sbit Servo_Pin = P2^7;

void Servo_Run(short high_us);

#endif