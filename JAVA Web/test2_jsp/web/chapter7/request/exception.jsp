<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 19:34
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Exception</title>
</head>
<body>
<%
    try{
        int money = 100;
        int number = 0;
        request.setAttribute("result",money/number);
    }catch (Exception e){
        request.setAttribute("result","sorry,page error!");
    }
%>
<jsp:forward page="show_exception.jsp"/>
</body>
</html>
