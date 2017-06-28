/* site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "SerialBase.h"
#include <stdio.h>

void main()
{
    float distance;

    SerialBase_Init();
    HC_SR04_Init();
    while (1)
    {
        distance = HC_SR04_GetDistance();

        printf("dis:%.3fmm\r\n", distance);
    }
}