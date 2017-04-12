/* Version:1.0 site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "Serial.h"

#define BAUDRATE2COUNT(baudRate) (256 - (XTAL_FREQUENCY_HZ >> 4) / 12 / baudRate)

void Serial_Init() // 8-n-1
{
	PCON = (PCON & 0x3f | 0x80);		// SMOD0 = 0,SMOD1 = 1;
	SM0 = 0;	// SM0 = 0 & SM1 = 1, Mode = 2;
	SM1 = 1;
	
	TMOD = (TMOD & 0xf | 0x20); // Timer1,Mode2
	
	TH1 = TL1 = BAUDRATE2COUNT(BAUDRATE);
	TR1 = 1;
	
	REN = 1;
}

unsigned char Serial_Read()
{
	unsigned char ch;
	
	while(RI == 0);
	ch = SBUF;
	RI = 0;
	
	return ch;
}

void Serial_Write(unsigned char ch)
{
	SBUF = ch;
	while(TI == 0);
	TI = 0;
}
