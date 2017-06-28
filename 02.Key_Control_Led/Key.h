/* site:https://github.com/daishitong/51demo */

#ifndef __Key_H__
#define __Key_H__

#include <reg52.h>
#include "boolean.h"

sbit Key_Pin = P2^1;

bool Key_CheckDown();
bool Key_CheckUp();

#endif