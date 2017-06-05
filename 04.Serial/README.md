# Serial
简介：通过串口传输数据，循环输出`99乘法表`,并可以通过发送数据帧，传输两个乘数，然后返回两个乘数的计算结果。掌握串口字符串的格式化及使用。  
输入数据格式为：`>?{d}*{d};`。其中`{d}`表示一个字符数据。  
输出数据格式为：`{d} * {d} = {d}`。输出计算结果。  
如果格式不正确，则输出"Unknown Command!"。  
乘法结果需在：`-32768` ~ `32767` 之间。

>使用端口：  
`P3.0/RXD`：数据接收，接串口模块的发送端`TXD`  
`P3.1/TXD`：数据发送，接串口模块的接收端`RXD`

!includeurl http://uml.mvnsearch.org/github/daishitong/51demo/master/04.Serial/flow.puml