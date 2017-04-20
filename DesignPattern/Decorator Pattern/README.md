# 装饰者模式(Decorator Pattern)/包装模式(Wrapper Pattern)

## 概述
装饰模式是结构型设计模式之一。它使用一种对客户端透明的方式来动态扩展对象的功能，同时它也是继承关系的一种替代方式之一。在现实生活中，装饰者模式无处不在，比如人穿着衣服，人的本质不变，只是在外面披上一层衣服，这就是装饰模式。

## 定义

动态的给一个对象添加一些额外的职责。

## 使用场景
需要透明且动态的扩展类的功能时。

## UML类图

![](http://www.oodesign.com/images/design_patterns/structural/decorator-design-pattern-implementation-uml-class-diagram.png)

* Component：被装饰的原始对象，可以是一个接口或者抽象类

* ConcreteComponent：Component的具体实现，被装饰的具体对象。在这里说明具体的可以添加职责的对象。

* Decorator：抽象装饰者。其承担的责任就是为了装饰我们的Component，且内部一定有指向组件对象的引用。

* Concrete Decorators：对抽象装饰者的具体实现。

## 装饰者模式的简单实现
下面这个例子实现一个豆浆可以加鸡蛋和糖。

先创建一个Drink的接口：
```Java
/**
 * Drink Interface
 * Component drink
 */
public interface Drink {
    String description();
    float coast();
}
```
然后是ConcreteComponent:
```Java
/**
 * Drink implemention
 *
 * Concrete implemention
 */
public class SoyaBeanMilk implements Drink {
    @Override
    public String description() {
        return "SoyaBeanMilk";
    }

    @Override
    public float coast() {
        return 2.0F;
    }
}
```
接下来写一个Decorator的抽象类：
```Java
  /**
 * abstract Decorator
 */
public abstract class Decorator implements Drink {
    /**
     * private reference to the drink being decorated
     */
    private Drink drink;

    public Decorator(Drink drink){
        this.drink = drink;
    }

    @Override
    public String description() {
        return this.drink.description();
    }

    @Override
    public float coast() {
        return this.drink.coast();
    }
}
```
然后是两个ConcreteDecorator，一个是加鸡蛋的豆浆，一个是加糖的豆浆：
```
/**
 * Concrete Decorator extends Decorator
 * EggDecorator creates a milk adds egg
 */
public class EggDecorator extends Decorator {
    public EggDecorator(Drink drink) {
        super(drink);
    }

    @Override
    public String description() {
        return super.description()+" With Egg";
    }

    @Override
    public float coast() {
        return super.coast() + 1.0F;
    }
}

/**
 /**
 * Concrete Decorator extends Decorator
 * SugerDecorator creates a milk adds suger
 */
public class SugerDecorator extends Decorator {
    public SugerDecorator(Drink drink) {
        super(drink);
    }

    @Override
    public String description() {
        return super.description() + " With Suger";
    }

    @Override
    public float coast() {
        return super.coast() + 0.5F;
    }
}
```

最后测试一下：
```
public class Test {
    public static void main(String[] args){
        //create a new soyaBeanMilk
        Drink drink = new SoyaBeanMilk();
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());

        //decorate Milk add Suger
        drink = new SugerDecorator(drink);
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());

        //decorate SugerMilk add Egg
        drink = new EggDecorator(drink);
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());
    }
}
```

__运行结果__:
>This is a SoyaBeanMilk,and it's costs 2.0

>This is a SoyaBeanMilk With Suger,and it's costs 2.5

>This is a SoyaBeanMilk With Suger With Egg,and it's costs 3.5


## DecoratorPattern的应用

* GUI工具包使用装饰者模式添加功能动态解释

* Android中的Context就是一个典型的装饰者模式

## 总结
* 装饰者模式可以更方便的添加或删除功能到对象。

* 通过使用不同装饰者的排列组合可以创造出很多不同行为的组合。

* 装饰者模式会产生很多小对象，增加了系统的复杂性。对于多次装饰的对象，会比较容易出错，调试时排错也比较困难。

-------------------------------------------------------------------------------------------------------------
参考资料：http://www.oodesign.com/decorator-pattern.html
