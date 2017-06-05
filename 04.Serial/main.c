/* site:https://github.com/daishitong/51demo */

#include "Serial_Interrupt.h"
#include "delay.h"
#include <stdio.h>

void print_99Table()
{
    char m,n;
    
    for(m = 1;m <= 9;m++)
    {
        for(n = 1;n <= m;n++)
        {
            printf("%bd * %bd = %-2bd | ",n,m,n*m);
        }
        printf("\r\n");
    }  
}

void Serial_ParseReceiveBuffer(char* buffer)
{
    int m,n;
    
    if(sscanf(buffer,">?%d*%d;",&m,&n) == 2) // 2:The number of input fields that should be successfully converted.
    {
        printf("%d * %d = %d\r\n",m,n,m*n);
    }
    else
    {
        printf("Unknown Command!\r\n");
    }
}

void main()
{
    Serial_Interrupt_Init();
    
    while(1)
    {
        print_99Table();
        Serial_ParseMessage(Serial_ParseReceiveBuffer);
        delay_nms(5000);
    }
}