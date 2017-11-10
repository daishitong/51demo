# 51demo
[51简单程序例程](https://github.com/daishitong/51demo)
>通过51简单程序例程，了解51系列单片机的IO口使用，串口数据通信和电机的运动控制等。  
开发环境：Keil uVision5。

序号 | 工程名 | 简介 | 端口
--- | ------ | ---- | ---
00|EmptyDemo|一个空白可编译的工程示例|-
01|Led_Blink|Led闪烁，频率1Hz|P2.0
02|Key_Control_Led|按键切换Led闪烁频率。按键单击，Led慢闪烁；按键双击，Led快速闪烁。Led闪烁时，再单击按键，闪烁停止。|P2.0,P2.1
03|Passive_Buzzer|无源蜂鸣器，演奏"两只老虎"|P2.2
04|Serial|通过串口传输数据，并返回两个数据乘法计算结果。掌握串口字符串的格式化及使用。|P3.0/RXD,P3.1/TXD
05|Serial_Led|串口控制Led亮或灭|P3.0/RXD,P3.1/TXD,P2.0
06|Ultrasound_Led|超声波模块获取障碍物距离，然后根据阈值控制Led亮或灭|P2.3,P2.4,P2.0
07|Ultrasound_Serial|超声波模块获取障碍物距离，然后通过串口返回数据|P2.3,P2.4,P3.0/RXD,P3.1/TXD
08|Servo_Control|舵机控制。通过1个IO口控制舵机进行连续旋转运动，并在经过`1000us`、`1500us`、`2000us`位置停留片刻。|P2.7
09|DCMoto_Control|直流电机控制。先正转从小到大，再反转从小到大|P2.6,P2.7
10|StepperMotor_Control|步进电机控制。先正转，然后反转，最后停止|P2.4,P2.5,P2.6,P2.7

## Change Log
### v1.0.6 2017/11/22
1. 修改舵机模块。
2. 修改部分管脚配置。
3. 修改串口模块。

### v1.0.5 2017/7/3
1. 增加按键类型检测。
2. 修改舵机模块。

### v1.0.4 2017/6/28
1. 将大部分管脚配置到P2口。
2. 统一工程编号04/05的串口设置。

### v1.0.3 2017/6/14
1. 优化串口模块。
2. 优化舵机模块。
3. 修改电机部分使用端口。

### v1.0.2 2017/5/16
1. 增加10号工程。
2. 调整工程编号。

### v1.0.1 2017/4/20
1. 修改和优化Led、舵机、步进电机相关代码。
2. 优化常量数组。
3. 优化变量类型。

### v1.0.0 2017/4/12
1. 添加了0~9号工程。