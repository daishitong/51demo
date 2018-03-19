/* site:https://github.com/daishitong/51demo */

#include "Key.h"
#include "Led.h"
#include "delay.h"

// LED闪烁程序
void Led_Blink(short ms)
{
    Led_TurnOn();
    delay_nms(ms);
    Led_TurnOff();
    delay_nms(ms);
}

void main()
{
    while (1)
    {
        // 根据按键点击类型，选择不同的闪烁间隔时间
        switch (Key_GetClickType())
        {
        case Key_OneClick:              // 按键点击类型为：单击
            while(!Key_CheckClicked())  // 一直闪烁，直到再次单击按键
            {
                Led_Blink(100);     // 闪烁时间间隔：100ms
            }
            break;
        case Key_DoubleClick:           // 按键点击类型为：双击
            while(!Key_CheckClicked())  // 一直闪烁，直到再次单击按键
            {
                Led_Blink(30);      // 闪烁时间间隔：30ms
            }
            break;
        }
    }
}
