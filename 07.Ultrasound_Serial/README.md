# Ultrasound_Serial
简介：超声波模块获取障碍物距离，然后通过串口返回数据，数据格式：`"dis:%.3fmm\r\n"`  
串口设置：波特率`9600`BPS，数据位`8`位，奇偶校验`无`，停止位`1`位。  
>使用端口：  
`P2.3`:Trig  
`P2.4`:Echo  
`P3.0/RXD`：数据接收，接串口模块的发送端`TXD`  
`P3.1/TXD`：数据发送，接串口模块的接收端`RXD`  
![wiring](51demo_7.png)

[![下载](../download_logo.png)](https://github.com/daishitong/51demo/releases/download/download/07_Ultrasound_Serial.zip)  