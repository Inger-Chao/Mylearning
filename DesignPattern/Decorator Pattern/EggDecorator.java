package decorator;

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
