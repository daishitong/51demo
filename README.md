# 51demo
[51简单程序例程](https://github.com/daishitong/51demo)
>通过51简单程序例程，了解51系列单片机的IO口使用，串口数据通信和电机的运动控制等。  
开发环境：Keil uVision5。

序号 | 工程名 | 简介 | 端口
--- | ------ | ---- | ---
00|EmptyDemo|一个空白可编译的工程示例|-
01|Led_Blink|Led闪烁，频率1Hz|P0.0
02|Key_Control_Led|按键切换Led亮或灭|P0.0,P0.1
03|Passive_Buzzer|无源蜂鸣器，演奏"两只老虎"|P0.2
04|Serial|每隔3秒，通过串口输出一张"九九乘法表"|P3.0/RXD,P3.1/TXD
05|Serial_Led|串口控制Led亮或灭|P3.0/RXD,P3.1/TXD,P0.0
06|Ultrasound_Serial|超声波模块获取障碍物距离，然后通过串口返回数据|P0.3,P0.4,P3.0/RXD,P3.1/TXD
07|Ultrasound_Led|超声波模块获取障碍物距离，然后根据阈值控制Led亮或灭|P0.3,P0.4,P0.0
08|Servo_Control|舵机控制。4个端口分别输出：连续旋转，正方向最大，零位，反方向最大|P0.4,P0.5,P0.6,P0.7
09|DCMoto_Control|直流电机控制。先正转从小到大，再反转从小到大|P0.0,P0.1
10|StepperMotor_Control|步进电机控制。先正转，然后反转，最后停止|P0.0,P0.1,P0.2,P0.3


## Change Log
### v1.0.0 2017/4/12
1. 添加了0~9号工程。

### v1.0.1 2017/4/20
1. 修改和优化Led、舵机、步进电机相关代码。
2. 优化常量数组。
3. 优化变量类型。

### v1.0.2 2017/5/16
1. 增加10号工程。
2. 调整工程编号。
