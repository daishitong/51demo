/* Version:1.0 site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "delay.h"

sbit CWMoto_Pin = P0 ^ 5;
sbit CCWMoto_Pin = P0 ^ 6;
sbit ZeroMoto_Pin = P0 ^ 7;

void main()
{
    while (1)
    {
        CWMoto_Pin = 1;
        delay_nus(1000);
        CWMoto_Pin = 0;

        CCWMoto_Pin = 1;
        delay_nus(2000);
        CCWMoto_Pin = 0;

        ZeroMoto_Pin = 1;
        delay_nus(1500);
        ZeroMoto_Pin = 0;

        delay_nms(16);
    }
}