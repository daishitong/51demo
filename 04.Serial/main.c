/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "delay.h"
#include <stdio.h>

// CMD_ARGUMENTS_COUNT:The number of input fields that should be successfully converted.
#define CMD_ARGUMENTS_COUNT 2

// 打印九九乘法表
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

// 处理串口数据
void Serial_ParseReceiveBuffer(unsigned char* buffer)
{
    int m,n;
    if(sscanf(buffer,">?%d*%d;",&m,&n) == CMD_ARGUMENTS_COUNT)  // 串口数据格式匹配成功，输出结果
    {
        printf("%d * %d = %d\r\n",m,n,m*n);
    }
    else    // 串口数据格式不匹配，输出提示信息
    {
        printf("Unknown Command!\r\n");
        print_99Table();
        printf("Please Enter Question,for example:>?9*9;\r\n");
    }
}

void main()
{
    //  串口初始化
    Serial_Init();
    // 设置串口接收处理函数
    Serial_SetParseHandler(Serial_ParseReceiveBuffer);
    
    // 通过串口，输出提示
    printf("Please Enter Question,for example:>?9*9;\r\n");
    while(1)
    {

    }
}