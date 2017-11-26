/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void main()
{
    short i;

    Servo_Init();
    while (1)
    {
        for(i = 0;i < 100;i++)
        {
            Servo_Run(1500);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(2000);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(1500);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(1000);
        }
    }
}