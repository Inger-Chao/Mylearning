Model-View-Controller
=====================
* View:用户界面
* Model:数据保存
* Controller:业务逻辑

##特点
![MVC](http://image.beekka.com/blog/2015/bg2015020108.png)
* 用户可以向View发送指令，再由View直接要求Model改变状态
* 用户也可以直接向Controller发送指令，再由Controller发送给View
* Controller起到事件路由的作用

##Android中的MVC

* Layout中的xml文件相当于View层
* 可以是Values里的xml文件，也可以是Java代码，类似repository类
* Controller层则是对外部世界响应。例如点击事件等

##缺点

 View和Model是相互可以访问的，耦合性较高。因此衍生出了[MVP和MVVM](https://github.com/Joki-memeda/MyLearning/blob/master/DesignPattern/MVP%E5%92%8CMVVM%E6%A1%86%E6%9E%B6.md)两种框架
