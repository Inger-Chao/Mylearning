package decorator;

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
