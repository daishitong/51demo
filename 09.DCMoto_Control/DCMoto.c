/* site:https://github.com/daishitong/51demo */

#include "DCMoto.h"
#include "delay.h"

void Moto_RunCW(char dutyCycle)
{
  Moto_Pin1 = 0;
  
  Moto_Pin0 = 1;
  delay_nms(dutyCycle);
  Moto_Pin0 = 0;
  delay_nms(100 - dutyCycle);
}

void Moto_RunCCW(char dutyCycle)
{
  Moto_Pin0 = 0;
  
  Moto_Pin1 = 1;
  delay_nms(dutyCycle);
  Moto_Pin1 = 0;
  delay_nms(100 - dutyCycle);
}