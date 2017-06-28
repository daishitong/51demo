/* site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "Timer0.h"
#include "ExternalInterrupt0.h"
#include "delay.h"
#include "boolean.h"

void HC_SR04_Start();

// distance = v * t / 2 = v * count * 12 * T / 2 = v * count * 12 / f / 2 
// distance = 340 m/s * count * 12 / 11.0592M / 2
//          = 340 m/s * count * 12 / (11.0592 * 1e6) s / 2
//          = count * (340 * 12) / (11059200 * 2) m
//          = count / ((11059200 * 2) / (340 *12)) m
//          = count / 5421.2 m
//          = count / 5421.2 * 1000 mm
//          = count / 5.4212 mm
#define DistancePerCount 5.4212

float g_distance = 0;
void ExteralInterrupt0_Handler()
{
    unsigned int count;
    
    Timer0_Stop();

    count = Timer0_CurrentCount();
    g_distance = (float)count / DistancePerCount;
    
    HC_SR04_Start();
}

void HC_SR04_Init()
{
    Timer0_Init();
    ExternalInterrupt0_Init(ExteralInterrupt0_Handler);
    
    HC_SR04_Start();
}

void HC_SR04_Start()
{   
    Trig_Pin = 1;
    delay_nus(10);
    Trig_Pin = 0;

    ExternalInterrupt0_WaitHighLevel();
    Timer0_Start();
}

float HC_SR04_GetDistance()
{
    return g_distance;
}