package com.servlet;

import com.bean.UserBean;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

//@WebServlet("AddressServlet")
public class AddressServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("UTF-8");
        String name = req.getParameter("name");
        String sex = req.getParameter("sex");
        String add = req.getParameter("add");
        UserBean user = new UserBean();
        user.setName(name);
        user.setSex(sex);
        user.setAddress(add);
        ServletContext application = getServletContext();
        List<UserBean> userBeans = (List<UserBean>) application.getAttribute("users");
        if (userBeans == null){
            userBeans = new ArrayList<UserBean>();
        }
        userBeans.add(user);
        application.setAttribute("users",userBeans);
        RequestDispatcher dispatcher = req.getRequestDispatcher("/chapter9/manager.jsp");
        dispatcher.forward(req,resp);
    }
}
