# 传输层

## User Datagram Protocol

__用户数据包协议__ 是一个简单的面向数据报的传输协议。


## Transmission Control Protocol

__传输控制协议__ 是一种面向连接的、可靠的基于字节流的传输层通信协议。

* 点对点
    * 一个发送方，一个接收方
* 可靠的、按序的字节流
* 流水线机制
    * TCP拥塞控制和流量控制机制
* 发送方/接收方缓存
* 全双工
    * 同一连接中能够传输双向数据流
* 面向连接
    * 通信双方在发送数据前必须先建立连接
    * 连接状态只在连接的两端中维护，在沿途节点中并不维护状态
    * TCP连接
        * 两台主机上的缓存
        * 连接状态变量
        * socket等

### TCP报文

![这里写图片描述](http://img.blog.csdn.net/20170529143355269?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
* 序号：4bytes 文本本段所发送的数据的第一字节的序号
* 确认序号：4bytes 期望下次接收的数据的第一字节的编号。表示该编号以前的数据已安全接受
* 数据偏移：4bits 报文段首部的长度
* 标志字段：6个标志位
    * 紧急位URG = 1：该报文要尽快传送
    * 确认为ACK = 1：表头的确认号有效；ACK = 0:连接请求报文
    * 急迫位PSH = 1：请求接收端的TCP将本报文段立即传送到应用层，而不是等到整个缓存都填满后才向上传送
    * 复位位RST = 1：出现了严重错误，必须释放连接再重建
    * 同步位SYN = 1：该报文段是一个连接请求或连接响应报文
    * 终止位FIN = 1：要发送的字符串已经发送完毕，并要求释放连接
* 窗口： 2bytes 该报文发送者接收窗口的大小
* 校验和：2bytes 对首部和数据部分进行校验
* 紧急指针：2bytes 指明本报文段中紧急数据的最后一个字节的序号 和URG配合使用
* 选项：长度可变，若该字段长度不够4bytes，填充对齐
### TCP连接的建立和释放
![这里写图片描述](http://img.blog.csdn.net/20170529155549607?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
#### 建立：三次握手
>A->B发送请求报文段：SYN = 1，SEQ =  x;

>B->A发送响应报文段：SYN = 1，ACK = x+1，SEQ = y;

>A->B发送确认报文段：SEQ = x+1 , ACK = y+1;

####释放：四次握手

数据传输结束后，任何一方都可以发出释放连接请求。图中加入A向B发起：

>A->B发送请求释放报文段：FIN = 1，SEQ = x;//x=已经发送数据的最后一个字节序号+1

>B->A发送确认报文段：ACK= x+1;

此时A->B的连接已经释放，连接处于半关闭状态，B不再接受A发来的数据。但是B还可以向A发送数据，A收到B的请求后依然可以做出响应。

>B->A发送请求释放报文段：FIN = 1,SEQ = y,ACK = x+1;

>A->B发送确认报文段：ACK = y+1;
