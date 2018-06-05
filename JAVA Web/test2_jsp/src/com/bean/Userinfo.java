package com.bean;

public class Userinfo {
    private String name;
    private String job;

    public Userinfo(){
        name = "";
        job = "";
    }

    public String getName() {
        return name;
    }

    public void setName(String name) throws Exception{
        this.name = new String(name.getBytes("ISO-8859-1"),"gbk");
    }

    public String getJob() {
        return job;
    }

    public void setJob(String job) throws Exception {
        this.job = new String(job.getBytes("ISO-8859-1"),"GBK");
    }
}
