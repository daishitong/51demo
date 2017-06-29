/* site:https://github.com/daishitong/51demo */

#include "Key.h"
#include "Led.h"
#include "delay.h"

void Led_Blink(short ms)
{
    Led_TurnOn();
    delay_nms(ms);
    Led_TurnOff();
    delay_nms(ms);
}

void main()
{
    int i;

    while(1)
    {
        switch(Key_GetClickType())
        {
            case Key_OneClick:
            for(i = 0;i < 3;i++)
            {
                Led_Blink(500);
            }
            break;
            case Key_DoubleClick:
            for(i = 0;i < 5;i++)
            {
                Led_Blink(300);
            }
            break;
        }
    }
}
