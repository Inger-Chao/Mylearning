Model-View-Presenter
=====================

* Persenter:交互中间人
* View:用户界面
* Model:数据存储

## 特点

![MVP](http://image.beekka.com/blog/2015/bg2015020109.png)

* 各部分间的通信都是双向的
* Model和View分离
* Presenter作为View和Model的桥梁

## Android中的MVP
* 把Activity当作了View层
* View和Presenter主要通过接口的方式连接

Activity中没有任何Model层的代码，把相应的代码放在Presenter层，Presenter获取Model的数据后，通过接口的方式返回给View层。

## 优点

* 减少了Activity中的代码逻辑

* Model和View完全解耦

每个类型的代码量大幅减少，职责单一，易于维护。

Model-ViewModel-Model
======================
基本与VMP模式完全一致，只是View和Model采用双向绑定(data-binding)

![MVVM](http://image.beekka.com/blog/2015/bg2015020110.png)

## 特点
两者间有任何一方变化便会反应到另一方上。Model的数据变化后会自动更新View，View的修改也会直接导致数据的变更。
