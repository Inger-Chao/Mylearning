# 简单工厂模式(工厂方法模式的小弟)

简单工厂模式并不属于GoF23个经典设计模式，但通常作为23个设计模式的基础。因为在简单工厂模式中用于创建实例的方法是static方法，所以它也被称为Static Factory Method Pattern.

***定义***

定义一个工厂类，它可以根据参数的不同返回不同类的实例，被创建的实例通常都具有共同的父类。

***UML类图***

![SimpleFactoryPattern](http://img.blog.csdn.net/20130711143612921?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvTG92ZUxpb24=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

* Factory:工厂角色即工厂类，负责实现创建所有产品实例的内部逻辑；工厂类可以被外界直接调用静态的工厂方法factoryMethod()，创建产品对象。

* Product：抽象产品角色，是工厂类所创建所有产品的父类，封装了各种产品对象的公有方法。

* ConcreteProduct：具体产品角色，所有被工厂创建的对象都充当这个角色的某个具体类的实例。

在简单工厂模式中，客户端不用通过new创建对象，只需要通过工厂类就可以创建一个产品类的实例。

使用简单工厂模式时，首先要对产品类进行重构，要根据实际情况设计一个产品层次结构，将所有产品类的公共代码移至抽象产品类，并声明一些抽象方法，以供不同的具体产品类来实现。
```java
public abstract class Product {
    //所有产品类的公共业务方法
    public void methodSame(){
        //公共方法的实现
    }

    //声明抽象业务方法
    public abstract void methodDiff();
}
```

然后是具体产品的实现，继承抽象产品方法，实现自己内部业务逻辑
```java
public class ConcreteProductA extends Product {
    //实现业务方法
    @Override
    public void methodDiff() {

    }
}
```

创建简单工厂模式的核心工厂类，工厂类提供一个静态工厂方法供客户端使用，根据传入参数的不同创建不同的产品对象，典型代码：
```java
public class Factory {
    //静态工厂方法
    public static Product getProduct(String arg){
        Product product = null;
        if (arg.equalsIgnoreCase("A")){
            product = new ConcreteProductA();
            //初始化设置product
        }else if (arg.equalsIgnoreCase("B")){
            product = new ConcreteProductB();
            //初始化设置product
        }
        return product;
    }
}
```

客户端调用代码如下
```java
public class Client {
    public static void main(String[] args){
        Product product;
        product = Factory.getProduct("A");
        product.methodSame();
        product.methodDiff();
    }
}
```
