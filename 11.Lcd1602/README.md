# Lcd1602
简介：控制Lcd1602，第一行显示固定字符串:"XAUT-GCXLZX 1602"，第二行显示0~200依次累加的数据。

注：V0和GND间的电压约`0.4V`~`1.2V`之间。
>使用端口：`P0.5`、`P0.6`、`P0.7`、`P2.0~P2.7`。  
![wiring](51demo_11.png)

序号 | 单片机端口 | Lcd1602端口
---- | --------- | ------
1 | `GND`  | `VSS` 
2 | `VCC`  | `VDD` 
3 | `P0.7` | `RS` 
4 | `P0.6` | `RW` 
5 | `P0.5` | `EN` 
6 | `P2.0~P2.7`   | `D0~D7` 
7 | `VCC`  | `A` 
8 | `GND`  | `K` 

[![下载](../download_logo.png)](https://github.com/daishitong/51demo/releases/download/download/11_Lcd1602.zip)  