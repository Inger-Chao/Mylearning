# 观察者模式-让你的对象知悉现况
## 定义
观察者模式定义了对象之间的一对多的依赖。当一个对象改变状态时，他的所有依赖者都会收到通知并自动更新。
* Observer 观察者，有时也叫Subscriber(订阅者)
* Observable 被观察者，有时候也叫Subject(主题)
![观察者模式](http://img.blog.csdn.net/20170330130959292?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
## UML类图
![观察者模式UML类图](http://img.blog.csdn.net/20170330132325662?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvSm9raTIzMw==/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)
* Observable--被观察者接口，对象使用此接口注册为观察者或者把自己从观察者中删除
* Observer--观察者接口，当被观察者状态改变时update()方法被调用
*  ConcreteObservable--具体被观察者，实现被观察者接口。有时也有可能设置和获取状态的方法
* ConcreteObserver--具体的观察者，可以是实现此接口的任意类。观察者必须注册具体主题，以便接口更新。
## 观察者模式的简单实现
首先建立Observer和Observable的接口，另外建立的一个DisplayElement用来显示布告板。
```Java
public interface Observable {
    public void registerObserver(Observer o);
    public void removeObserver(Observer o);
    public void notifyObservers();
}

public interface Observer {
    public void update(float temp , float humidity,float pressure);
}

public interface DisplayElement {
    public void display();
}
```
实现具体的Observable接口
```Java
/**
 * ConcreteObservable:WeatherData
 */
public class WeatherData implements Observable {

    private ArrayList observers;//ArrayList用来记录观察者
    private float temperature;
    private float humidity;
    private float pressure;

    public WeatherData(){
        observers = new ArrayList();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        int i = observers.indexOf(o);
        if(i>=0){
            observers.remove(o);
        }
    }

    /**
     * 把状态告诉每一位观察者
     */
    @Override
    public void notifyObservers() {
        for(int i = 0; i < observers.size(); i++){
            Observer observer = (Observer) observers.get(i);
            observer.update(temperature,humidity,pressure);
        }
    }

    /**
     * 从气象站得到更新观测值时立刻通知观察者
     */
    public void measurementsChanged(){
        notifyObservers();
    }

    /**
     * 设置当前的temperatrue/humidity/pressure
     * @param temperature
     * @param humidity
     * @param pressure
     */
    public void setMeasurements(float temperature,float humidity ,float pressure){
        this.temperature = temperature;
        this.humidity = humidity;
        this.pressure = pressure;
        measurementsChanged();
    }
}
```
接下来是布告器
```Java
/**
 * 布告板：实现Observer接口和DisplayElement接口
 */
public class CurrentConditionDisplay implements Observer,DisplayElement {

    private float temperature;
    private float humidity;
    private Observable weatherData;

    /**
     * 构造器需要weatherData对象用来注册
     * @param weatherData
     */
    public CurrentConditionDisplay(Observable weatherData){
        this.weatherData = weatherData;
        weatherData.registerObserver(this);
    }



    @Override
    public void display() {
        System.out.println("Current conditions: " + temperature +"F degrees and " + humidity +"% humidity" );
        //display只是显示温度和湿度
    }

    /**
     * 当update()被调用时，保存温度和湿度，然后调用display()
     * @param temperature
     * @param humidity
     * @param pressure
     */
    @Override
    public void update(float temperature, float humidity, float pressure) {
        this.temperature = temperature;
        this.humidity = humidity;
        display();
    }
}
```
然后建立一个测试程序
```Java
public class WeatherStation {
    public static void main(String[] args){
        WeatherData weatherData = new WeatherData();

        CurrentConditionDisplay currentConditionDisplay = new CurrentConditionDisplay(weatherData);
        /*模拟新的气象测量*/
        weatherData.setMeasurements(80,65,30.4f);
        weatherData.setMeasurements(82,70,29.2f);
    }
}
```

__运行结果:__

`Current conditions: 80.0F degrees and 65.0% humidity`

`Current conditions: 82.0F degrees and 70.0% humidity`

## 优点
观察者和被观察者之间耦合大大降低。被观察者不知道观察者的细节，只知道观察者实现了观察者接口。
