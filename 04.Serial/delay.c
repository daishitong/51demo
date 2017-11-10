/* site:https://github.com/daishitong/51demo */

#include "delay.h"

//CONST_MILLISECOND_COUNT = ROUND_NUM(US2CLOCKF(1000) / 8.2);  // count/ms,12M,122
//CONST_COUNT_MICROSECOND = ROUND_NUM(US2CLOCKF(1) * 17);      // us/count,12M,17
#ifdef XTAL_12M
    #define CONST_MILLISECOND_COUNT 122
    #define CONST_COUNT_MICROSECOND 17
#else // 11.0592M
    #define CONST_MILLISECOND_COUNT 112
    #define CONST_COUNT_MICROSECOND 16
#endif

void delay_nms(short ms)
{
  unsigned char i;
  while((--ms) >= 0)
  {
    for(i = 0;i < CONST_MILLISECOND_COUNT;i++);
  }
}

void delay_nus(short us)
{
  us /= CONST_COUNT_MICROSECOND;
  while((--us) >= 0);
}

void delay_5nop()
{
    
}

#include <intrins.h>
void delay_100nop()
{
    char i;
    for(i = 0;i < 10;i++)
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}