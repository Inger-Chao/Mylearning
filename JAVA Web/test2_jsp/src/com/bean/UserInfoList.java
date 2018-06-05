package com.bean;

import java.util.Vector;

public class UserInfoList {
    private static UserInfoList user = new UserInfoList();
    private Vector vector = null;
    public UserInfoList(){
        this.vector = new Vector();
    }
    public static UserInfoList getInstance(){
        return user;
    }
    public boolean addUserInfo(String user){
        if (user!=null){
            this.vector.add(user);
            return true;
        }else {
            return false;
        }
    }

    public static UserInfoList getUser() {
        return user;
    }

    public static void setUser(UserInfoList user) {
        UserInfoList.user = user;
    }

    public Vector getVector() {
        return vector;
    }

    public void removeUserInfo(String user){
        if (user != null){
            vector.removeElement(user);
        }
    }
}
