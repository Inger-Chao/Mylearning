package com.listener;

import com.bean.UserInfoList;


import javax.servlet.http.HttpSessionBindingEvent;
import javax.servlet.http.HttpSessionBindingListener;

public class UserInfoTrace implements HttpSessionBindingListener {

    private String user;
    private UserInfoList container = UserInfoList.getInstance();
    public UserInfoTrace(){
        user = "";
    }

    public String getUser() {
        return user;
    }

    public void setUser(String user) {
        this.user = user;
    }

    @Override
    public void valueBound(HttpSessionBindingEvent httpSessionBindingEvent) {
        System.out.println(this.user + "上线");
    }

    @Override
    public void valueUnbound(HttpSessionBindingEvent httpSessionBindingEvent) {
        System.out.println(this.user + "下线");
        if (user != null){
            container.removeUserInfo(user);
        }
    }
}
