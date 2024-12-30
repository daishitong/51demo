/* site:https://github.com/daishitong/51demo */

#include "TimeCounter0.h"
#include <reg52.h>

void TimeCounter2_Init()
{
    // 预设自动重装载值（假设需要）
    RCAP2H = 0;  // 设定高8位重装载值
    RCAP2L = 0;  // 设定低8位重装载值

    // 设置T2为16位自动重装模式
    T2CON = 0x04;
}

void TimeCounter2_Start()
{
    TH2 = TL2 = 0;
    
    TF2 = 0;     // Clear Timer2 Overflow Flag
    TR2 = 1;    // 1:Turn on timer2
}

void TimeCounter2_Stop()
{
    TR2 = 0;    // 0:Turn off timer2
}

unsigned short TimeCounter2_CurrentCount()
{
     return ((TH2 << 8) | TL2);
}
