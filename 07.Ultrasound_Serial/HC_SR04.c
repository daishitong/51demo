/* site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "TimeCounter2.h"
#include "delay.h"

void HC_SR04_Init()
{
    TimeCounter2_Init();

    Echo_Pin = 1;
}

// distance = v * t / 2 = v * count * 12 * T / 2 = v * count * 12 / f / 2 
// distance = 340 m/s * count * 12 / 11.0592M / 2
//          = 340 m/s * count * 12 / (11.0592 * 1e6) s / 2
//          = count * (340 * 12) / (11059200 * 2) m
//          = count * (340 * 12 * 1000) / (11059200 * 2) mm
//          = count * 0.1845 mm
#define DistancePerCount 0.1845

float HC_SR04_GetDistance()
{
    unsigned short count;

    // 回波接收引脚设置为输入
    Echo_Pin = 1;
  
    // 在触发引脚上，产生一个10us的脉冲
    Trig_Pin = 1;
    delay_nus(10);
    Trig_Pin = 0;

    // 等待回波接收引脚变高，然后启动定时器
    while(Echo_Pin == 0);
    TimeCounter2_Start();

    // 等待回波接收引脚变低，然后停止定时器
    while(Echo_Pin == 1);
    TimeCounter2_Stop();

    // 读取定时器计数值
    count = TimeCounter2_CurrentCount();

    // 返回探测到的障碍物距离
    return (float)count * DistancePerCount;
}