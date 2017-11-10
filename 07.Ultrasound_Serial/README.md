# Ultrasound_Serial
简介：超声波模块获取障碍物距离，然后通过串口返回数据，数据格式：`"dis:%.3fmm\r\n"`
>使用端口：  
`P2.3`:Trig  
`P2.4`:Echo  
`P3.0/RXD`：数据接收，接串口模块的发送端`TXD`  
`P3.1/TXD`：数据发送，接串口模块的接收端`RXD`