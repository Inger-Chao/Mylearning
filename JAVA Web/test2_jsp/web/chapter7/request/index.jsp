<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 19:09
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Request请求对象——用户注册功能</title>
</head>
<body>
<form action="login.jsp" method="post">
    <div>
        <ul>
            <li><h3>用户登录</h3></li>
        </ul>
        <ul>
            <li>用户名：<input type="text" name="username"></li>
        </ul>
        <ul>
            <li>密码：<input type="password" name="password"></li>
        </ul>
        <ul>
            <li><input type="submit" value="登录"></li>
        </ul>
    </div>
</form>
</body>
</html>
