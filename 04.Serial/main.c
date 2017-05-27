/* site:https://github.com/daishitong/51demo */

#include "Serial_Interrupt.h"
#include "delay.h"

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

void Serial_ParseReceiveBuffer(char* buffer,char length)
{
    char m,n;
    
    if(length < 6)
        return;
    
    if(buffer[0] == '>' && buffer[1] == '?' && buffer[5] == ';' && buffer[3] == '*'
        && buffer[2] >= '0' && buffer[2] <= '9'
        && buffer[4] >= '0' && buffer[4] <= '9')
    {
        m = buffer[4] - '0';
        n = buffer[2] - '0';
        
        printf("%bd * %bd = %-2bd\r\n",n,m,n*m);
    }
    else
    {
        print_99Table();
    }
}

void main()
{
    Serial_Interrupt_Init();
    
    print_99Table();
    while(1)
    {        
        Serial_ParseMessage(Serial_ParseReceiveBuffer);
    }
}