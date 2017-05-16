/* site:https://github.com/daishitong/51demo */

#include "DCMoto.h"
#include "delay.h"

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