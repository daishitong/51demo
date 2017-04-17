# 51demo
[51简单程序例程](https://github.com/daishitong/51demo)
>通过51简单程序例程，了解51系列单片机的IO口使用，串口数据通信和电机的运动控制等。

序号 | 工程名 | 简介 | 端口
--- | ------ | ---- | ---
0|EmptyDemo|一个空白可编译的工程示例|-
1|Led_Blink|Led闪烁，频率1Hz|P0.0
2|Key_Control_Led|按键切换Led亮或灭|P0.0,P0.1
3|Passive_Buzzer|无源蜂鸣器，演奏"两只老虎"|P0.2
4|Serial_Led|串口控制Led亮或灭|P3.0/RXD,P3.1/TXD,P0.0
5|Ultrasound_Serial|超声波模块获取障碍物距离，然后通过串口返回数据|P0.3,P0.4,P3.0/RXD,P3.1/TXD
6|Ultrasound_Led|超声波模块获取障碍物距离，然后根据阈值控制Led亮或灭|P0.3,P0.4,P0.0
7|Servo_Control|舵机控制。3个端口分别输出：正方向最大，反方向最大，零位|P0.5,P0.6,P0.7
8|DCMoto_Control|直流电机控制。先正转从小到大，再反转从小到大|P0.0,P0.1
9|StepperMotor_Control|步进电机控制。先正转，然后反转，最后停止|P0.0~P0.3

## Change Log
### v1.0 2017/4/12
1. 添加了0~9号工程。

### v1.1 2017/4/17
1. 修改Led相关代码。
