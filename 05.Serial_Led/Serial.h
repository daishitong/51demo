/* site:https://github.com/daishitong/51demo */

#ifndef __SERIAL_H__
#define __SERIAL_H__

#define XTAL_FREQUENCY_HZ  11059200
#define BAUDRATE 9600

#define mcu_printf printf
#include <stdio.h>

void Serial_Init();

unsigned char Serial_Read();
void Serial_Write(unsigned char ch);

unsigned char Serial_ReadLine(unsigned char* str,unsigned char maxSize);
void Serial_WriteLine(unsigned char* str);

unsigned char Serial_ReadString(unsigned char* str,unsigned char maxSize);
void Serial_WriteString(unsigned char* str);

#endif
