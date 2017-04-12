/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __HC_SR04_H__
#define __HC_SR04_H__
#include <reg52.h>

sbit Trig_Pin = P0^3;
sbit Echo_Pin = P0^4;

void HC_SR04_Init();
float HC_SR04_GetDistance();

#endif