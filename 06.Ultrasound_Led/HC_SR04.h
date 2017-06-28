/* site:https://github.com/daishitong/51demo */

#ifndef __HC_SR04_H__
#define __HC_SR04_H__
#include <reg52.h>

sbit Trig_Pin = P2^3;
//sbit ExternalInterrupt0_Pin = P3^2;

void HC_SR04_Init();
float HC_SR04_GetDistance();

#endif