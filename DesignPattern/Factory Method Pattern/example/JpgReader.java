package factorymethod.example;

/**
 * Created by Joki on 2017/7/5.
 */
public class JpgReader extends PicReader {
    @Override
    public void reader() {
        System.out.println("This is a jpg picture");
    }
}
