package factorymethod.example;

/**
 * Created by Joki on 2017/7/5.
 */
public class GifReader extends PicReader{
    @Override
    public void reader() {
        System.out.println("This is a gif picture！");
    }
}
