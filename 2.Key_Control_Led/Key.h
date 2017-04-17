/* Version:1.0 site:https://github.com/daishitong/51demo */

#ifndef __Key_H__
#define __Key_H__

#include <reg52.h>

#define bool bit
#define true  1
#define false 0
	
sbit Key_Pin = P0^1;

bool Key_CheckDown();
bool Key_CheckUp();

#endif