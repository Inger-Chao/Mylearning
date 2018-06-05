<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/22
  Time: 19:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Caculate days</title>
</head>
<body>
<form action="${pageContext.request.contextPath}/MyServlet" method="post">
    请输入你的姓名：<input type="text" name="name"/>
    <input type="submit" value="submit" />
</form>
</body>
</html>
