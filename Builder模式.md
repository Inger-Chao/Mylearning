Builder(建造者)模式
===================
   Builder模式是一步一步创建一个复杂对象的创建型模式。一个复杂对象有很多大量组成的部分，Builder模式可以使得构建对象过程和部件的表示隔离开来，两者都可以自由扩展，使得耦合性降到最低。
  
## 定义
将一个复杂对象的构建与它的表示分离，使得童杨的构建过程可以创建不同的表示。
## 使用场景
* 相同的方法，不同的执行顺序，产生不同的事件结果。
* 初始化一个对象特别复杂，如参数多，且很多参数都有默认值时。
* 多个部件或零件都可以装配到一个对象中，但是产生的运行结果又不相同时。
## UML类图
![Builder模式的UML类图](http://pic002.cnblogs.com/images/2011/328668/2011112120433967.jpg)


* Product--产品的抽象类
* Builder--抽象Builder类，规范产品的组建，由子类实现具体的组件过程
* ConcreatBuilder--具体Builder类
* Director--统一组建过程

    `在现实开发过程中，Director角色常常会被省略，而直接使用一个Builder来进行对象的组装。这个Builder通常为链式调用，它的关键点在每个setter方法都返回自身，return this，setter链式调用的代码如下：`
    ```Java
    new TestBuilder().setA("A).setB("B").create();
    ```

## Android源码中的Builder模式
Android源码中最常用的Builder模式就是AlertDialog.Builder，使用该Builder来构建复杂的AlertDialog对象。

```Java
//显示基本的AlertDialog  
    private void showDialog(Context context) {  
        AlertDialog.Builder builder = new AlertDialog.Builder(context);  
        builder.setIcon(R.drawable.icon);  
        builder.setTitle("Title");  
        builder.setMessage("Message");  
        builder.setPositiveButton("Button1",  
                new DialogInterface.OnClickListener() {  
                    public void onClick(DialogInterface dialog, int whichButton) {  
                        setTitle("点击了对话框上的Button1");  
                    }  
                });  
        builder.setNeutralButton("Button2",  
                new DialogInterface.OnClickListener() {  
                    public void onClick(DialogInterface dialog, int whichButton) {  
                        setTitle("点击了对话框上的Button2");  
                    }  
                });  
        builder.setNegativeButton("Button3",  
                new DialogInterface.OnClickListener() {  
                    public void onClick(DialogInterface dialog, int whichButton) {  
                        setTitle("点击了对话框上的Button3");  
                    }  
                });  
        builder.create().show();  // 构建AlertDialog， 并且显示
    } 
```

## 优点
* 具有良好的封装性，使用建造者模式可以使客户端不必知道产品内部组成的细节
* 建造者独立，容易扩展
## 缺点
* 会产成多余的Builder对象以及Director对象，消耗内存
