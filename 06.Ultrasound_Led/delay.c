/* site:https://github.com/daishitong/51demo */

#include "delay.h"

#ifdef XTAL_12M
    #define CONST_MILLISECOND_COUNT 122
    #define CONST_COUNT_MICROSECOND 17
#else // 11.0592M
    #define CONST_MILLISECOND_COUNT 115
    #define CONST_COUNT_MICROSECOND 12
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
