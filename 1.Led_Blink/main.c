/* Version:1.0 site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "delay.h"

sbit Light_Pin = P0^0;

void main()
{
	while(1)
	{
		Light_Pin = 0;
		delay_nms(500);
		Light_Pin = 1;
		delay_nms(500);
	}
}