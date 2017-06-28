/* site:https://github.com/daishitong/51demo */

#ifndef __SERIALBASE_H__
#define __SERIALBASE_H__

#define XTAL_FREQUENCY_HZ  11059200
#define BAUDRATE 9600

#define mcu_printf printf
#include <stdio.h>

void SerialBase_Init();

unsigned char SerialBase_Read();
void SerialBase_Write(unsigned char ch);

unsigned char SerialBase_ReadLine(unsigned char* str,unsigned char maxSize);
void SerialBase_WriteLine(unsigned char* str);

unsigned char SerialBase_ReadString(unsigned char* str,unsigned char maxSize);
void SerialBase_WriteString(unsigned char* str);

#endif
