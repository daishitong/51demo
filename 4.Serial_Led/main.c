/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "Led.h"

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
			Led_TurnOff();
			break;
		case 1:
			Led_TurnOn();
			break;
		default:
			break;
		}
		Serial_Write(ch);
	}
}
