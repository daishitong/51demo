/* site:https://github.com/daishitong/51demo */

#include "HC_SR04.h"
#include "SerialBase.h"
#include <stdio.h>

void main()
{
    float distance;

    SerialBase_Init();  // 串口初始化
    HC_SR04_Init();     // 超声模块初始化
    while (1)
    {
        // 获取超声模块到障碍物的距离
        distance = HC_SR04_GetDistance();

        // 通过串口，显示距离信息
        printf("dis:%.3fmm\r\n", distance);
    }
}