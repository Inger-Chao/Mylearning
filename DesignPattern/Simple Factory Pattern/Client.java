package simplefactory;

/**
 * Created by Joki on 2017/6/30.
 */
public class Client {
    public static void main(String[] args){
        Product product;
        product = Factory.getProduct("A");
        product.methodSame();
        product.methodDiff();
    }
}
