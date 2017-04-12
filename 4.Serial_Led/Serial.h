/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __SERIAL_H__
#define __SERIAL_H__

#define XTAL_FREQUENCY_HZ  11059200
#define BAUDRATE 9600

void Serial_Init();

unsigned char Serial_Read();
void Serial_Write(unsigned char ch);

#endif
