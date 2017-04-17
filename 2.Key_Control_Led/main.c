/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "Key.h"
#include "Led.h"

void Led_Switch()
{
	static bool led_state = 0;
	
	SetLedState(led_state);
	
	led_state = ~led_state;
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
