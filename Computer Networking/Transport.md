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

![这里写图片描述](http://img.blog.csdn.net/20170529141655041?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
