/* site:https://github.com/daishitong/51demo */

#include "Servo.h"

void main()
{
    // 舵机初始化
    Servo_Init();
    
    while (1)
    {
        Servo_Run(1500,100);    // 舵机的脉宽为1500us，运行100个周期
        Servo_Run(2000,100);    // 舵机的脉宽为2000us，运行100个周期
        Servo_Run(1500,100);    // 舵机的脉宽为1500us，运行100个周期
        Servo_Run(1000,100);    // 舵机的脉宽为1000us，运行100个周期
    }
}