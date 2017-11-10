/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void main()
{
    short i;

    while (1)
    {
        for(i = 0;i < 100;i++)
        {
            Servo_Run(1500);
        }
        
        for(i = 1500;i < 2000;i+=50)
        {
            Servo_Run(i);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(2000);
        }
        
        for(i = 2000;i > 1500;i-=50)
        {
            Servo_Run(i);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(1500);
        }
        
        for(i = 1500;i > 1000;i-=50)
        {
            Servo_Run(i);
        }

        for(i = 0;i < 100;i++)
        {
            Servo_Run(1000);
        }
        
        for(i = 1000;i < 1500;i+=50)
        {
            Servo_Run(i);
        }
    }
}