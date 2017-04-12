/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"

#define AlarmDistance 200

sbit Led_Pin = P0 ^ 0;

void main()
{
    float distance;

    HC_SR04_Init();
    while (1)
    {
        distance = HC_SR04_GetDistance();

        if (distance < AlarmDistance)
        {
            Led_Pin = 0;
        }
        else
        {
            Led_Pin = 1;
        }
    }
}