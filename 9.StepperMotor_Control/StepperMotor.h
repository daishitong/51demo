/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __STEPPERMOTOR_H__
#define __STEPPERMOTOR_H__

#include <reg52.h>

#define CLEAR_STEPPERMOTOR_Port()   {P0 &= 0xf0;}
#define SET_STEPPERMOTOR_Port(value) {CLEAR_STEPPERMOTOR_Port();P0 |= value;}

#define STEPPERMOTOR_StepTime 5

void StepperMotor_Run_CW();
void StepperMotor_Run_CCW();
void StepperMotor_Stop();

#endif