<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 21:10
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>bookstore</title>
</head>
<body>
<%
    String[] bookname = {"默小","朱雪婷","铜陵人"};
    %>
<table border="1" align="center">
    <tr bgcolor="#add8e6">
        <td align="center">Number</td>
        <td align="center">Zasui</td>
    </tr>
    <%
        for(int i = 0; i < bookname.length;i++){
    %>
    <tr>
        <td align="center"><%=i%></td>
        <td align="center"><%=bookname[i]%></td>
    </tr>
    <% } %>
</table>
</body>
</html>
