/* Version:1.0 site:https://github.com/daishitong/51demo */

#include <reg52.h>
#include "delay.h"

sbit Moto_Pin0 = P0^0;
sbit Moto_Pin1 = P0^1;

void Moto_RunCW(char speed)
{
  Moto_Pin1 = 0;
  
  Moto_Pin0 = 1;
  delay_nms(speed);
  Moto_Pin0 = 0;
  delay_nms(40 - speed);
}

void Moto_RunCCW(char speed)
{
  Moto_Pin0 = 0;
  
  Moto_Pin1 = 1;
  delay_nms(speed);
  Moto_Pin1 = 0;
  delay_nms(40 - speed);
}

void main()
{
  char i,j;
  
  while(1)
  {
    for(i = 1;i <= 40;i++)
    {
      for(j = 0;j < 25;j++)
      {
        Moto_RunCW(i);
      }
    }
    
    for(i = 1;i <= 40;i++)
    {
      for(j = 0;j < 25;j++)
      {
        Moto_RunCCW(i);
      }
    }
  }
}