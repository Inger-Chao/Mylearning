package decorator;

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
