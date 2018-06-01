# Serial_Led
简介：串口控制Led亮或灭，使用字符文本格式。`0;`:灭，`1;`:亮。使用串口模块与主控板相连时，注意`RXD`和`TXD`需交叉连接。  
串口设置：波特率`9600`BPS，数据位`8`位，奇偶校验`无`，停止位`1`位。  
>使用端口：  
`P3.0/RXD`：数据接收，接串口模块的发送端`TXD`  
`P3.1/TXD`：数据发送，接串口模块的接收端`RXD`  
`P2.0`:Led

[![下载](../download_logo.png)](https://github.com/daishitong/51demo/releases/download/download/05_Serial_Led.zip)  