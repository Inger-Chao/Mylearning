<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 19:23
  To change this template use File | Settings | File Templates.
--%>
<%--指令标识--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@page import="java.util.Date" %>
<%@page import="java.text.SimpleDateFormat" %>
<%--HTML代码--%>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <%--嵌入的JAVA代码--%>
  <%
    Date date = new Date();
    SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd HH:hh:mm:ss");
    String today = dateFormat.format(date);
  %>
  <%--输出当前时间--%>
  当前时间：<%=today%>
  </body>
</html>
