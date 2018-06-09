package reflection;

import java.util.List;

/**
 * Created by Joki on 2017/7/1.
 */
public class Example extends Father implements InterA{

    public double d;

    private String str;
    private int x;

    private List<String> stringList;

    public Example(){}
    public Example(String str){
        this.str = str;
    }
    public Example(int x){
        this.x = x;
    }
    public Example(String str , int x){
        this.str = str;
        this.x = x;
    }

    public String getStr() {
        return str;
    }

    public void setStr(String str) {
        this.str = str;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public List<String> getStringList() {
        return stringList;
    }

    public void setStringList(List<String> stringList) {
        this.stringList = stringList;
    }
}
