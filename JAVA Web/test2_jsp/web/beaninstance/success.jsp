<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 20:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ page import="com.bean.Userinfo" %>
<html>
<head>
    <title>登陆成功</title>
</head>
<body>
<%
    String username = ((Userinfo)request.getAttribute("us")).getName();
    String userjob = ((Userinfo) request.getAttribute("us")).getJob();
%>
<table border="1">
    <tr bgcolor="#add8e6"><td>注册成功</td></tr>
    <tr>
        <td>
            <b>用户名：</b><%=username%>&nbsp;&nbsp;
            <b>职&nbsp;&nbsp;务：</b><%=userjob%>
        </td>
    </tr>
</table>
<a href="login_form.jsp">back</a>
</body>
</html>
