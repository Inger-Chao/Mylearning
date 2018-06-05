<%@ page import="java.util.List" %>
<%@ page import="com.bean.UserBean" %>
<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/22
  Time: 20:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<h2 align="center" style="width: 350px;text-align: center;">用户信息列表</h2>
<table align="center" border="1" width="400">
    <tr align="center" style="font-weight: bold">
        <td>name</td>
        <td>sex</td>
        <td>address</td>
    </tr>
    <%
        List<UserBean> list = (List<UserBean>) application.getAttribute("users");
        if (list !=null){
            for (UserBean user :list){
      %>
    <tr align="center" >
        <td><%=user.getName()%></td>
        <td><%=user.getSex()%></td>
        <td><%=user.getAddress()%></td>
    </tr>
    <%
            }
        }
    %>
    <tr align="center" colspan="3">
        <td>
            <a href="/chapter9/app1.jsp">continue add</a>
        </td>
    </tr>
</table>
</body>
</html>
