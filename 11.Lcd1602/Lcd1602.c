/* site:https://github.com/daishitong/51demo */

#include "Lcd1602.h"
#include "delay.h"

#define LCD1602_CMD_CLEAR   1
#define LCD1602_CMD_HOME    2
#define LCD1602_CMD_TEXT_NORMAL 0x6 
#define LCD1602_CMD_TEXT_MOVE   0x7
#define LCD1602_CMD_DISPLAY_HIDE            0x8
#define LCD1602_CMD_DISPLAY_SHOW            0xc
#define LCD1602_CMD_DISPLAY_SHOWCURSOR      0xe
#define LCD1602_CMD_DISPLAY_SHOWCURSORBLINK 0xf
#define LCD1602_CMD_CURSOR_MOVELEFT     0x10
#define LCD1602_CMD_CURSOR_MOVERIGHT    0x14
#define LCD1602_CMD_FUNCTION_8BIT_2LINE_5x7DOT  0x38
#define LCD1602_CMD_CGRAM_ADDRESS   0x40
#define LCD1602_CMD_DDRAM_ADDRESS               0x80
#define LCD1602_CMD_DDRAM_ADDRESS_SECONDLINE    0x40

#define LCD1602_DATA_MASK_BUSY      0x80
#define LCD1602_DATA_MASK_CGRAM_CHAR    0x7
#define LCD1602_DATA_MASK_CGRAM_DOT     0x1f

#define LEVEL_ENABLE 1
#define LEVEL_DISABLE 0

#define LEVEL_READ 1
#define LEVEL_WRITE 0

#define LEVEL_REG_DATA 1
#define LEVEL_REG_CMD  0

bool Lcd1602_IsBusy()
{
    bool result;

    LCD1602_DATAPORT = 0xff;

    LCD1602_RS_Pin = LEVEL_REG_CMD;
    LCD1602_RW_Pin = LEVEL_READ;
    LCD1602_EN_Pin = LEVEL_DISABLE;
    delay_5nop();
    LCD1602_EN_Pin = LEVEL_ENABLE;
    delay_5nop();    
    result=((LCD1602_DATAPORT & LCD1602_DATA_MASK_BUSY) >> 7);
    LCD1602_EN_Pin = LEVEL_DISABLE;    

    return result;
}

void Lcd1602_WaitTimeOutForIdle()
{
    char i = 0;
    do
    {
        delay_100nop();
    }while(Lcd1602_IsBusy() == 1 && (i++) < 100);  
}

void Lcd1602_WriteCmd(unsigned char cmd)
{
    Lcd1602_WaitTimeOutForIdle();

    LCD1602_RS_Pin = LEVEL_REG_CMD;
    LCD1602_RW_Pin = LEVEL_WRITE;
    LCD1602_EN_Pin = LEVEL_DISABLE;
    delay_5nop();
    LCD1602_DATAPORT = cmd;
    delay_5nop();
    LCD1602_EN_Pin = LEVEL_ENABLE;
    delay_5nop();
    LCD1602_EN_Pin = LEVEL_DISABLE;
}

void Lcd1602_WriteData(unsigned char dat)
{
    Lcd1602_WaitTimeOutForIdle();

    LCD1602_RS_Pin = LEVEL_REG_DATA;
    LCD1602_RW_Pin = LEVEL_WRITE;
    LCD1602_EN_Pin = LEVEL_DISABLE;
    LCD1602_DATAPORT = dat;
    delay_5nop();
    LCD1602_EN_Pin = LEVEL_ENABLE;
    delay_5nop();
    LCD1602_EN_Pin = LEVEL_DISABLE;
}

void Lcd1602_SetCursorPosition(unsigned char position)
{
    Lcd1602_WriteCmd(position | LCD1602_CMD_DDRAM_ADDRESS);
}

void Lcd1602_SetCustomGraghicRAM(char c,uint8 dots[8])
{
    char i;

    Lcd1602_WriteCmd(LCD1602_CMD_CGRAM_ADDRESS | ((c & LCD1602_DATA_MASK_CGRAM_CHAR) << 3));
    for(i = 0;i < 8;i++)
    {
        Lcd1602_WriteData((dots[i] & LCD1602_DATA_MASK_CGRAM_DOT));
    }
}

void Lcd1602_Init()
{
    Lcd1602_WriteCmd(LCD1602_CMD_FUNCTION_8BIT_2LINE_5x7DOT);
    Lcd1602_WriteCmd(LCD1602_CMD_DISPLAY_SHOW);
    Lcd1602_WriteCmd(LCD1602_CMD_TEXT_NORMAL);
    Lcd1602_WriteCmd(LCD1602_CMD_CLEAR);
}

void Lcd1602_Clear()
{
    Lcd1602_WriteCmd(LCD1602_CMD_CLEAR);    
}

void Lcd1602_SetPosition_2R_16C(char row,char column)
{
    Lcd1602_SetCursorPosition((row == 0 ? 0x00 : LCD1602_CMD_DDRAM_ADDRESS_SECONDLINE) | column);
}

void Lcd1602_ShowChar(char c)
{
    Lcd1602_WriteData(c);
}

void Lcd1602_ShowText(char str[])
{
    char i = 0;

    while(str[i] != '\0')
    {
        Lcd1602_WriteData(str[i++]);
    }
}