/* site:https://github.com/daishitong/51demo */

#include "Timer2_PWM.h"
#include "Timer2.h"

typedef enum
{
    PWM_LEVEL_HIGH,
    PWM_LEVEL_LOW
}PWM_LEVEL;

PWM_LEVEL _pwm_level = PWM_LEVEL_HIGH;
ushort _high_count = TIMER_US2COUNT(1),_low_count = TIMER_US2COUNT(0xffff);
void Timer2_PWM_Handler()
{
    if(_pwm_level == PWM_LEVEL_HIGH)
    {
        Timer_PWM_Pin = 1;
        Timer2_SetCounterOut(_high_count);
        _pwm_level = PWM_LEVEL_LOW;
    }
    else
    {
        Timer_PWM_Pin = 0;
        Timer2_SetCounterOut(_low_count);
        _pwm_level = PWM_LEVEL_HIGH;
    }
}

void Timer2_PWM_Init()
{
    Timer_PWM_Pin = 0;
    CP_RL2 = 1;
    Timer2_Init(Timer2_PWM_Handler);
}

void Timer2_PWM_Start()
{
    _pwm_level = PWM_LEVEL_HIGH;
    Timer2_PWM_Handler();
    
    Timer2_Start();
}

void Timer2_PWM_Stop()
{
    Timer2_Stop();
    
    Timer_PWM_Pin = 0;
}

void Timer2_PWM_Set(ushort high_us,ushort low_us)
{
    Timer2_Stop();

    _high_count = TIMER_US2COUNT(high_us);
    _low_count = TIMER_US2COUNT(low_us);
    
    Timer2_Start();
}