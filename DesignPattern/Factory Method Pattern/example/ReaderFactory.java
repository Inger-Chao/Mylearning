package factorymethod.example;

/**
 * Created by Joki on 2017/7/5.
 */
public abstract class ReaderFactory {
    /**
     * 图片读取器的工厂方法
     * @param clz
     * @param <T>
     * @return
     */
    public abstract <T extends PicReader> T createReader(Class<T> clz);
}
