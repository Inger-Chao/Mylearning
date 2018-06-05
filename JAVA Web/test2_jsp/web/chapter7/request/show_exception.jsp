<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 19:36
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Show Exception page</title>
</head>
<body>
<%
    String message = request.getAttribute("result").toString();
%>
<%=message%>
</body>
</html>
