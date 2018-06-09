package factorymethod.example;

/**
 * Created by Joki on 2017/7/5.
 */
public class Client {
    public static void main(String[] args){
        //实例化一个读取图片的工厂对象
        ReaderFactory readerFactory = new PicReaderFactory();

        //生产gif读取器并读取
        GifReader gifReader = readerFactory.createReader(GifReader.class);
        gifReader.reader();
        //生产jpg读取器并读取
        JpgReader jpgReader =  readerFactory.createReader(JpgReader.class);
        jpgReader.reader();
    }
}
