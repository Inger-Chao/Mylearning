package decorator;

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
