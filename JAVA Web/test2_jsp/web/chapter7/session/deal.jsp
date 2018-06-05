<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:06
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<%@page import="java.util.*" %>
<%
    String[][] userList={{"cat","cat123"},{"dog","dog123"},{"pig","pig123"}};
    boolean flag = false;
    request.setCharacterEncoding("GB18030");
    String username = request.getParameter("username");
    String password = request.getParameter("password");
    for (int i = 0; i <userList.length ; i++){
        if (userList[i][0].equals(username)){
            if (userList[i][1].equals(password)){
                flag = true;
                break;
            }
        }
    }
    if (flag){
        session.setAttribute("username",username);
        response.sendRedirect("main.jsp");
    }else {
        response.sendRedirect("index.jsp");
    }
%>