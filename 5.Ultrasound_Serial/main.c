/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "Serial.h"
#include <stdio.h>

#define BUFFER_SIZE 20
unsigned char str[BUFFER_SIZE];

void main()
{
    float distance;

    Serial_Init();
    HC_SR04_Init();
    while (1)
    {
        distance = HC_SR04_GetDistance();

        sprintf(str, "dis:%.3fmm\r\n", distance);
        Serial_WriteString(str);
    }
}