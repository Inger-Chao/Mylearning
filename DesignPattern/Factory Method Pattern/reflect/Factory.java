package factorymethod.reflect;

import factorymethod.base.Product;

/**
 * Created by Joki on 2017/7/5.
 */
public abstract class Factory {
    /**
     * 抽象工厂方法
     * @param clz 产品对象类类型
     * @param <T> 
     * @return 具体的产品对象
     */
    public abstract <T extends Product> T createProduct(Class<T> clz);
}
