/* site:https://github.com/daishitong/51demo */

#ifndef __Key_H__
#define __Key_H__

#include <reg52.h>
#include "boolean.h"

sbit Key_Pin = P2^1;

typedef enum
{
    Key_NoClick,
    Key_OneClick,
    Key_DoubleClick
}Key_ClickType;

bool Key_CheckDown();
bool Key_CheckUp();
bool Key_CheckClicked();
Key_ClickType Key_GetClickType();

#endif