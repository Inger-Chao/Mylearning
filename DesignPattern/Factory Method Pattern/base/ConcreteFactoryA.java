package factorymethod;

/**
 * 产品A的具体工厂
 */
public class ConcreteFactoryA extends Factory {
    @Override
    public Product factoryMethod() {
        return new ConcreteProductA();
    }
}
