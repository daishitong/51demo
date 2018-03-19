/* site:https://github.com/daishitong/51demo */

#include "Lcd1602.h"
#include "delay.h"
#include <stdio.h>

const uint8 code right_dots[8] = {0x0,0x0,0x8,0x4,0x1e,0x4,0x8,0x0};    // 字符 ->
const uint8 code left_dots[8]  = {0x0,0x0,0x2,0x4,0xf,0x4,0x2,0x0};     // 字符 <-

void main()
{
    char text[5];
    int i;

    // Lcd1602初始化
    Lcd1602_Init();

    // Lcd1602设置自定义字符
    Lcd1602_SetCustomGraghicRAM(0, right_dots);
    Lcd1602_SetCustomGraghicRAM(1, left_dots);

    // Lcd1602第1行，显示XAUT-GCXLZX 1602
    Lcd1602_SetPosition_2R_16C(0, 0);
    Lcd1602_ShowText("XAUT-GCXLZX 1602");
    
    // Lcd1602第2行，显示-><-Text:
    Lcd1602_SetPosition_2R_16C(1, 0);
    Lcd1602_ShowChar(0);
    Lcd1602_ShowChar(1);
    Lcd1602_ShowText("Text:");

    while (1)
    {
        // Lcd1602第2行第7个字符开始，显示0-200依次变化的数字
        for(i = 0;i < 200;i++)
        {
            Lcd1602_SetPosition_2R_16C(1, 7);
            sprintf(text,"%3d",i);
            Lcd1602_ShowText(text);
            delay_nms(300);
        }
    }
}