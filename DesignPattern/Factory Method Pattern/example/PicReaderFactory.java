package factorymethod.example;

/**
 * Created by Joki on 2017/7/5.
 */
public class PicReaderFactory extends ReaderFactory {
    @Override
    public <T extends PicReader> T createReader(Class<T> clz) {
        PicReader reader = null;
        try {
            reader = (PicReader) Class.forName(clz.getName()).newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return (T) reader;
    }
}
