<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:12
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<%
    String username = (String) session.getAttribute("username");
%>
<html>
<head>
    <title>Main page</title>
</head>
<body>
Hello![<%=username%>],Welcome to main page!<br>
<a href="exit.jsp">exit</a>
</body>
</html>
