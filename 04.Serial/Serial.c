/* site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "Serial.h"

#define BAUDRATE2COUNT(baudRate) (256 - (XTAL_FREQUENCY_HZ >> 4) / 12 / baudRate)

#ifndef NULL
#define NULL ((void *)0)
#endif

void Serial_Init() // 8-n-1
{
    PCON = (PCON & 0x3f | 0x80); // SMOD0 = 0,SMOD1 = 1;
    SM0 = 0;			 // SM0 = 0 & SM1 = 1, Mode = 1;
    SM1 = 1;

    TMOD = (TMOD & 0xf | 0x20); // Timer1,Mode2

    TH1 = TL1 = BAUDRATE2COUNT(BAUDRATE);
    TR1 = 1;

    REN = 1;
}

unsigned char Serial_Read()
{
    unsigned char ch;

    while (RI == 0);
    
    ch = SBUF;
    RI = 0;

    return ch;
}

void Serial_Write(unsigned char ch)
{
    SBUF = ch;
    while (TI == 0);
    
    TI = 0;
}

unsigned char Serial_ReadLine(unsigned char *str, unsigned char maxSize)
{
    unsigned char count = 0;
    unsigned char ch;

    while (1)
    {
        if (count == maxSize)
            break;

        ch = Serial_Read();
        str[count] = ch;

        count++;
        if (ch == '\n')
        {
            break;
        }
    }

    return count;
}

void Serial_WriteLine(unsigned char *str)
{
    if (str == NULL)
        return;

    while (1)
    {
        Serial_Write(*str);

        if (*str == '\n' || *str == '\0')
        {
            break;
        }
        str++;
    }
}

unsigned char Serial_ReadString(unsigned char *str, unsigned char maxSize)
{
    unsigned char count = 0;
    unsigned char ch;

    while (1)
    {
        if (count == maxSize)
            break;

        ch = Serial_Read();
        str[count] = ch;

        count++;
        if (ch == '\0')
        {
            break;
        }
    }

    return count;
}

void Serial_WriteString(unsigned char *str)
{
    if (str == NULL)
        return;

    while (1)
    {
        if (*str == '\0')
        {
            break;
        }

        Serial_Write(*str);

        str++;
    }
}

char putchar(char c)
{
    Serial_Write(c);
    return c;
}

char _getkey(void)
{
    return Serial_Read();
}