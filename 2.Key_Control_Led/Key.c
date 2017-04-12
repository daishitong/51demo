/* Version:1.0 site:https://github.com/daishitong/51demo */

#include "Key.h"
#include "delay.h"

#define CHECK_KEY_Down() (Key_Pin == 0)
#define CHECK_KEY_UP() (Key_Pin == 1)

#define CHECK_DELAY_MS 10

bool Key_CheckDown()
{
    if (CHECK_KEY_Down())
    {
        delay_nms(CHECK_DELAY_MS);
        if (CHECK_KEY_Down())
        {
            return true;
        }
    }
    return false;
}

bool Key_CheckUp()
{
    if (CHECK_KEY_UP())
    {
        delay_nms(CHECK_DELAY_MS);
        if (CHECK_KEY_UP())
        {
            return true;
        }
    }
    return false;
}