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
***反射***
反射的方式可以更简洁的生产具体产品对象，只要在工厂方法的参数列表中传入一个Class类来决定是哪一个产品类。
具体代码如下：
```Java
public abstract class Factory {
    /**
     * 抽象工厂方法
     * @param clz 产品对象类类型
     * @param <T> 
     * @return 具体的产品对象
     */
    public abstract <T extends Product> T createProduct(Class<T> clz);
}
```
具体工厂类：
```java
public class ConcreteFactory extends Factory {

    @Override
    public <T extends Product> T createProduct(Class<T> clz) {
        Product product = null;
        try {
            product = (Product) Class.forName(clz.getName()).newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return (T) product;
    }
}
```
客户端调用代码：
```java
public class Client {
    public static void main(String[] args){
        Factory factory = new ConcreteFactory();
        Product product = factory.createProduct(ConcreteProductA.class);
        product.method();
    }
}
```

### 简单例子

使用工厂方法模式设计一个程序来读取各种不同类型的图片格式，针对每一种图片格式都设计一个图片读取器，如GIF图片读取器用于读取GIF格式的图片、JPG图片读取器用于读取JPG格式的图片。需充分考虑系统的灵活性和可扩展性。

先写出图片读取器的抽象方法：
```java
public abstract class PicReader {
    /**
     * 图片读取器的抽象方法
     */
    public abstract void reader();
}
```
然后是两个具体图片读取器：
```java
public class GifReader extends PicReader{
    @Override
    public void reader() {
        System.out.println("This is a gif picture！");
    }
}

public class JpgReader extends PicReader {
    @Override
    public void reader() {
        System.out.println("This is a jpg picture");
    }
}
```
抽象工厂类：
```java
public abstract class ReaderFactory {
    /**
     * 图片读取器的工厂方法
     * @param clz
     * @param <T>
     * @return
     */
    public abstract <T extends PicReader> T createReader(Class<T> clz);
}
```
具体的图片读取工厂：
```java
public class PicReaderFactory extends ReaderFactory {
    @Override
    public <T extends PicReader> T createReader(Class<T> clz) {
        PicReader reader = null;
        try {
            reader = (PicReader) Class.forName(clz.getName()).newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return (T) reader;
    }
}
```
客户端调用代码：
```java
public class Client {
    public static void main(String[] args){
        //实例化一个读取图片的工厂对象
        ReaderFactory readerFactory = new PicReaderFactory();

        //生产gif读取器并读取
        GifReader gifReader = readerFactory.createReader(GifReader.class);
        gifReader.reader();
        //生产jpg读取器并读取
        JpgReader jpgReader =  readerFactory.createReader(JpgReader.class);
        jpgReader.reader();
    }
}
```
运行结果：
```
This is a gif picture！
This is a jpg picture
```

---------------------------------------------------------------------
参考资料：https://gof.quanke.name 、《Android设计模式》

[源码](https://github.com/Joki-memeda/MyLearning/edit/master/DesignPattern/Factory%20Method%20Pattern/)
