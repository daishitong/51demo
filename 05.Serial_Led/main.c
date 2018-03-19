/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "Led.h"

// CMD_ARGUMENTS_COUNT:The number of input fields that should be successfully converted.
#define CMD_ARGUMENTS_COUNT 1

void Serial_ParseReceiveBuffer(char* buffer)
{
    unsigned char ch;
    
    if(sscanf(buffer,"%bd;",&ch) == CMD_ARGUMENTS_COUNT)    // 串口数据格式匹配成功，输出结果
    {
        switch(ch)
        {
        case 0:     // 0:熄灭LED
            Led_TurnOff();
            break;
        case 1:     // 1:点亮LED
            Led_TurnOn();
            break;
        default:
            break;
        }
    }

    printf("%bd",ch);
}

void main()
{
    //  串口初始化
    Serial_Init();
    // 设置串口接收处理函数
    Serial_SetParseHandler(Serial_ParseReceiveBuffer);

    // 通过串口，输出提示
    printf("Please Enter Command,for example:1; Or 0;\r\n");
    while(1)
    {
        
    }
}
