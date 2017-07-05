package factorymethod.reflect;

import factorymethod.base.ConcreteProductA;
import factorymethod.base.Product;

/**
 * Created by Joki on 2017/7/5.
 */
public class Client {
    public static void main(String[] args){
        Factory factory = new ConcreteFactory();
        Product product = factory.createProduct(ConcreteProductA.class);
        product.method();
    }
}
