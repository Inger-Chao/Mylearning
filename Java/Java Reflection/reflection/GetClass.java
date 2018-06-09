package reflection;

import java.lang.reflect.*;
import java.util.List;


public class GetClass {
    public static void main(String[] args) {

        //获得一个Class对象
        Class<?> aClass = null;
        Class<?> bClass = null;
        Class<?> cClass = null;
        try {
            //尽量采用这种方法
            String className = "reflection.Example";
            aClass = Class.forName(className);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        //bClass = new Example().getClass();
       // cClass = Example.class;

        System.out.println(aClass.getName());//输出包名和类名
        System.out.println(aClass.getPackage());//输出包名
        System.out.println(aClass.getSimpleName());//输出类名
        System.out.println(Modifier.isPublic(aClass.getModifiers()));//输出修饰符类型

        Class superClass = aClass.getSuperclass();//得到aClass的父类
        System.out.println(superClass.getName());

        Class<?> interfaces[] = aClass.getInterfaces();
        System.out.println(interfaces[0]);

        Constructor<?> constructors[] = aClass.getConstructors();//获取构造方法
        for (Constructor i : constructors){
            Class<?> parameterTypes[] = i.getParameterTypes();
            System.out.println("constructor: "+i);//输出构造方法
            for (Class j : parameterTypes){
                System.out.println("parameterType: "+j);//输出参数类型
            }
        }
        /**
         * 通过constructor实例化一个Example对象
         */
//        try {
//            Example example1 = (Example) constructors[0].newInstance();
//        } catch (Exception e) {
//            e.printStackTrace();
//        }

        Method[] methods = aClass.getMethods();//获得Example类中的所有public方法

        /**
         * 获取名为setStr，参数类型为String的方法
         */
        try {
            Method methodSetStr = aClass.getMethod("setStr",String.class);
            System.out.println("RETURN TYPE: "+methodSetStr.getReturnType());//输出返回类型
            System.out.println("method Parameter: "+methodSetStr.getParameterTypes()[0]);//输出第一个参数类型

            Object o = aClass.newInstance();
            Object returnValue = methodSetStr.invoke(o,"nihaoya");
            System.out.println("returnValue: " + returnValue);
        } catch (Exception e) {
            e.printStackTrace();
        }

        /**
         * 可以获得类的成员变量
         */
        try {
            Field field = aClass.getField("d");//只能获得public成员变量
            System.out.println("publicField: " + field);
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }
        Field[] privateFields = aClass.getDeclaredFields();//获得所有成员变量，包括私有成员变量
        for (Field i : privateFields){
            System.out.println("allFields: " + i);
            i.setAccessible(true);//这行代码会关闭i的反射访问检查。
        }


        /**
         * 获取返回集合泛型的参数类型
         */
        try {
            Method methodGetList = aClass.getMethod("getStringList",null);
            Type returnType = methodGetList.getGenericReturnType();

            if (returnType instanceof ParameterizedType){
                ParameterizedType type = (ParameterizedType) returnType;
                Type[] typeArguments = type.getActualTypeArguments();
                for(Type typeArgument : typeArguments){
                    Class typeArgClass = (Class) typeArgument;
                    System.out.println("typeArgClass = " + typeArgClass);
                }
            }
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }

        /**
         * 获取参数泛型的参数类型
         */
        try {
            Method methodSetList = aClass.getMethod("setStringList", List.class);

            Type[] genericParameterTypes = methodSetList.getGenericParameterTypes();

            for (Type i : genericParameterTypes){
                if (i instanceof ParameterizedType){
                    ParameterizedType type = (ParameterizedType) i;
                    Type[] parameterTypes = type.getActualTypeArguments();
                    for (Type parameterArgType : parameterTypes){
                        Class parameterArgClass = (Class) parameterArgType;
                        System.out.println("parameterArgClass = " + parameterArgClass);
                    }
                }
            }
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }

    }
}
