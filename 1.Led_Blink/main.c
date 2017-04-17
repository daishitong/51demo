/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "delay.h"
#include "Led.h"

void main()
{
	while(1)
	{
		Led_TurnOn();
		delay_nms(500);
		Led_TurnOff();
		delay_nms(500);
	}
}