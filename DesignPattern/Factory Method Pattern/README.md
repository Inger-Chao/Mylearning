# 工厂方法模式
简单工厂模式很简单，但是存在问题。当系统中需要引入新的产品时，必定要修改工厂类的源代码，违背“开闭原则”。而且在简单工厂模式中，所有的产品都由同一个工厂创建，工厂职责较重，业务逻辑也会变得复杂，concreteProduct和Factory的耦合度较高。

在工厂方法模式中，针对不同的产品提供不同的工厂，系统提供一个与产品等级结构对应的工厂等级结构。

***定义***

定义一个抽象工厂接口来声明抽象工厂方法，而由其子类来实现具体工厂方法。

***使用场景***

在任何需要生成复杂对象的地方，都可以使用工厂方法模式。
`用new就可以完成创建的对象无需使用工厂模式`

***UML类图***

![FactoryMethod](http://img.blog.csdn.net/20130712101002890?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvTG92ZUxpb24=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

* Product：抽象产品。定义产品的接扣，产品对象的公共父类。
* ConcreteProduct：具体产品。
* Factory：抽象工厂。抽象工厂类中，声明一个工厂方法用于返回一个产品。所有创建对象的工厂类都必须实现该接口。
* ConcreteFactory：具体工厂。实现抽象工厂中定义的工厂方法，并可由客户端调用，返回一个具体类的实例。

***工厂方法模式通用代码***
```java
/**
 * 抽象产品类 
 * 抽象工厂可以是一个接口，也可以是一个抽象类
 */
public abstract class Product {
    //产品类的抽象方法
    public abstract void method();
}
```
```java
/**
 * 具体产品A 
 */
public class ConcreteProductA  extends Product{
    @Override
    public void method() {
        //产品A的处理逻辑
    }
}
/**
 * 具体产品B
 */
public class ConcreteProductB extends Product{
    @Override
    public void method() {
        //产品B的处理逻辑
    }
}
```
接下来定义抽象工厂
```java
/**
 * 抽象工厂类
 */
public abstract class Factory {
    //抽象工厂方法
    public abstract Product factoryMethod();
}
```
定义一个产品A的具体工厂
```java
/**
 * 产品A的具体工厂
 */
public class ConcreteFactoryA extends Factory {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductA();
    }
}
```
客户端测试代码
```java
public class Client {
    public static void main(String[] args){
        Factory factory = new ConcreteFactoryA();
        Product p = factory.factoryMethod();
        p.method();
    }
}
```

---------------------------------------------------------------------
参考资料：https://gof.quanke.name 《Android设计模式》
