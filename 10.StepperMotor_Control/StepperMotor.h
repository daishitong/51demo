/* site:https://github.com/daishitong/51demo */

#ifndef __STEPPERMOTOR_H__
#define __STEPPERMOTOR_H__

#include <reg52.h>

#define STEPPERMOTOR_PORT P2
#define SET_STEPPERMOTOR_PORT(value) {STEPPERMOTOR_PORT = (STEPPERMOTOR_PORT & 0xf) | (value << 4);}

#define STEPPERMOTOR_STEPTIME 5

void StepperMotor_Run_CW();
void StepperMotor_Run_CCW();

#endif