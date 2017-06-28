/* site:https://github.com/daishitong/51demo */

#include "Serial.h"
#include "Led.h"

// CMD_ARGUMENTS_COUNT:The number of input fields that should be successfully converted.
#define CMD_ARGUMENTS_COUNT 1

void Serial_ParseReceiveBuffer(char* buffer)
{
    unsigned char ch;
    
    if(sscanf(buffer,"%bd;",&ch) == CMD_ARGUMENTS_COUNT)
    {
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
    }

	printf("%bd",ch);
}

void main()
{
	Serial_Init();
	
	while(1)
	{
		Serial_ParseMessage(Serial_ParseReceiveBuffer);
	}
}
