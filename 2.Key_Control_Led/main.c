/* Version:1.0 site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "Key.h"

sbit Led_Pin = P0^0;

void Led_Switch()
{
	static bool switch_state = 0;
	
	Led_Pin = switch_state;
	
	switch_state = ~switch_state;
}

void main()
{
	while(1)
	{
        if(Key_CheckDown())
        {
            Led_Switch();
            while(!Key_CheckUp());
        }
	}
}
