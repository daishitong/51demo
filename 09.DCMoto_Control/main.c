/* site:https://github.com/daishitong/51demo */

#include "DCMoto.h"

void main()
{
  char i;
  
  while(1)
  {
    // 直流电机，正转，脉宽由0ms到100ms变化，速度逐渐加快
    for(i = 0;i <= 100;i++)
    {
        Moto_RunCW(i);
    }
    
    // 直流电机，反转，脉宽由0ms到100ms变化，速度逐渐加快
    for(i = 0;i <= 100;i++)
    {
        Moto_RunCCW(i);
    }
  }
}