<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 20:32
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>用户注册</title>
</head>
<body>
<form action="doreg.jsp">
    <table border="1">
        <tr bgcolor="lightgrey">
            <td colspan="2">用户注册</td>
        </tr>
        <tr>
            <td>用户名：</td>
            <td><input type="text" name="name" size="29"></td>
        </tr>
        <tr>
            <td>职&nbsp;&nbsp;务：</td>
            <td><input type="text" name="job" size="29"></td>
        </tr>
        <tr>
            <td colspan="2">
                <input type="submit" value="注册">
                <input type="reset" value="重置">
            </td>
        </tr>

    </table>
</form>
</body>
</html>
