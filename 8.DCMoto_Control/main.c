/* site:https://github.com/daishitong/51demo */

#include "DCMoto.h"

void main()
{
  char i;
  
  while(1)
  {
    for(i = 0;i <= 100;i++)
    {
        Moto_RunCW(i);
    }
    
    for(i = 0;i <= 100;i++)
    {
        Moto_RunCCW(i);
    }
  }
}