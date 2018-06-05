<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<html>
<head>
    <title>应用Session对象模拟用户登录</title>
</head>
<body>
<form  method="post" action="dealwith.jsp">
    <div>
        <ul>
            <li><h3>用户登录</h3></li>
        </ul>
        <ul>
            <li>用户名：<input type="text" name="username" id="username"></li>
        </ul>
        <ul>
            <li>密码：<input type="password" name="password" id="password"></li>
        </ul>
        <ul>
            <li><input type="submit" value="登录"></li>
        </ul>
    </div>
    </form>
</body>
</html>
