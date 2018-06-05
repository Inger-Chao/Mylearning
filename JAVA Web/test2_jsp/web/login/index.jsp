<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 19:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>用户登陆</title>
</head>

<body>
您现在位置为index.jsp!
<%--请求转发是服务器端的操作，浏览器并不知道请求的二面，所以浏览的地址栏不会发生变化--%>
<jsp:forward page="login.jsp"></jsp:forward>
</body>
</html>
