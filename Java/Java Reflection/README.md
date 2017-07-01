# JAVA反射机制

JAVA反射机制可以在编译期之外的运行期获得任何一个类的字节码，包括接口、变量、方法等，还可以在运行期实例化对象，通过调用get/set方法获取变量的值。

***Class对象***

JAVA是面向对象的语言，所有类的对象都是Class的实例，当我们想知道一个类的信息时，首先需要获取类的Class对象。
```JAVA
//获得一个Class对象
        String className = "reflection.Example";
        Class<?> aClass = null;
        Class<?> bClass = null;
        Class<?> cClass = null;
        try {
            //尽量采用这种方法
            aClass = Class.forName(className);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        bClass = new Example().getClass();
        cClass = Example.class;
```
***类名***

可以在编译期得到class对象的类名
```java
        aClass.getName();//输出包名.类名
        aClass.getPackage();//输出包名
        aClass.getSimpleName();//输出类名
```
***修饰符***

也可以获取到类对象的修饰符，即public、private、abstract等关键字，关键代码如下：
```java
        aClass.getModifiers();
```
修饰符是一个int型的值，可以使用java.lang.reflect.Modifier类中的方法来检查修饰符的类型：
```java
        Modifier.isAbstract(int modifiers);
        Modifier.isFinal(int modifiers);
        Modifier.isInterface(int modifiers);
        Modifier.isNative(int modifiers);
        Modifier.isPrivate(int modifiers);
        Modifier.isProtected(int modifiers);
        Modifier.isPublic(int modifiers);
        Modifier.isStatic(int modifiers);
        Modifier.isStrict(int modifiers);
        Modifier.isSynchronized(int modifiers);
        Modifier.isTransient(int modifiers);
        Modifier.isVolatile(int modifiers);
```
***父类***
```java
        Class superClass = aClass.getSuperclass();//得到aClass的父类
```
父类也是一个class对象，也可以进行反射操作。
