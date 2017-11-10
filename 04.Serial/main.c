/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "delay.h"
#include <stdio.h>

// CMD_ARGUMENTS_COUNT:The number of input fields that should be successfully converted.
#define CMD_ARGUMENTS_COUNT 2

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
    if(sscanf(buffer,">?%d*%d;",&m,&n) == CMD_ARGUMENTS_COUNT)
    {
        printf("%d * %d = %d\r\n",m,n,m*n);
    }
    else
    {
        printf("Unknown Command!\r\n");
        print_99Table();
    }
}

void main()
{
    Serial_Init();
    Serial_SetParseHandler(Serial_ParseReceiveBuffer);
    
    printf("Please Enter Question,for example:>?9*9;\r\n");
    while(1)
    {

    }
}