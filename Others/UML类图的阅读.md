## 类的表示方式


* 类名
* 属性(filed)`可见性 名称:类型 [ = 缺省值 ]`
* 方法(method)`可见性 名称(参数列表) [ : 返回类型]`

    * +: public
    * -: private
    * #: protected(friendly)

例如下面这个Person类,有三个private属性和一个public方法，一目了然。

![example](http://img.blog.csdn.net/20170406151203247?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

## 类与类之间关系的表示方式
### 关联关系
#### 单向关联
![单向关联](http://img.blog.csdn.net/20170406161909014?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

UML类图中单向关联用一条单向箭头表示。上图表示Person类中有Address类的对象。

#### 双向关联
![这里写图片描述](http://img.blog.csdn.net/20170406152558456?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

UML类图中双向关联用不带箭头的一条直线表示。

#### 自关联
![这里写图片描述](http://img.blog.csdn.net/20170406152858176?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

自关联在UML类图中用一个带有箭头且指向自身的直线表示。上图的意思就是Node类包含类型为Node的成员变量，也就是“自己包含自己”。

### 聚合关系

![聚合关系](http://img.blog.csdn.net/20170406160319521?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

聚合关系强调是“整体”包含“部分”，但是“部分”可以脱离“整体”而单独存在。UML中聚合关系用带空心菱形和箭头的直线表示。比如上图中汽车包含了发动机，而发动机脱离了汽车也能够单独存在。

### 组合关系

![组合关系](http://img.blog.csdn.net/20170406160518944?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

组合（Composition）是一种强的拥有关系，体现了严格的部分和整体的关系，部分和整体的生命周期一样。即“部分”不能脱离“整体”存在。在UML类图中，组合关系用一个带实心菱形和箭头的直线表示。

### 依赖关系

![依赖关系](http://img.blog.csdn.net/20170406161045822?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

司机开车必须要有车，所以Driver和Car之间是依赖关系。在UML类图中，依赖关系用一条带有箭头的虚线表示。

### 继承关系

![继承关系](http://img.blog.csdn.net/20170406162818769?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

在UML类图中用带空心三角形的直线表示。上图表示Student类和Teacher类继承了Person类。

### 接口实现关系

![接口实现关系](http://img.blog.csdn.net/20170406163110833?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

在UML类图中用空心三角形的虚线表示。上图表示Ship和Car实现了Vehicle接口。


-------------------------------------------------------------------------------------


参考资料：http://www.jianshu.com/p/1178ec9f2007
