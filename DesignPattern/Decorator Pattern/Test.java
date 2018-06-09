package decorator;

/**
 * Created by Joki on 2017/4/19.
 */
public class Test {
    public static void main(String[] args){
        //create a new soyaBeanMilk
        Drink drink = new SoyaBeanMilk();
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());

        //decorate Milk add Suger
        drink = new SugerDecorator(drink);
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());

        //decorate SugerMilk add Egg
        drink = new EggDecorator(drink);
        System.out.println("This is a " + drink.description() + ",and it's costs " + drink.coast());
    }
}
