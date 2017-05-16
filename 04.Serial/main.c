/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "delay.h"
#include <stdio.h>

void main()
{
    char m,n;

    Serial_Init();
    while(1)
    {
        for(m = 1;m <= 9;m++)
        {
            for(n = 1;n <= m;n++)
            {
                printf("%bd * %bd = %-2bd | ",n,m,n*m);
            }
            printf("\r\n");
            delay_nms(50);
        }
        delay_nms(3000);
    }
}