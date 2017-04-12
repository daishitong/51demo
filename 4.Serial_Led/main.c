/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include <reg52.h>

sbit Led_Pin = P0^0;

void main()
{
	unsigned char ch;
	
	Serial_Init();
	
	while(1)
	{
		ch = Serial_Read();
		switch(ch)
		{
		case 0:
			Led_Pin = 1;
			break;
		case 1:
			Led_Pin = 0;
			break;
		default:
			break;
		}
		Serial_Write(ch);
	}
}
