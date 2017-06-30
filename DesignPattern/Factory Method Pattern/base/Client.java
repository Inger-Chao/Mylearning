package factorymethod;

/**
 * Created by Joki on 2017/6/30.
 */
public class Client {
    public static void main(String[] args){
        Factory factory = new ConcreteFactoryA();
        Product p = factory.factoryMethod();
        p.method();
    }
}
