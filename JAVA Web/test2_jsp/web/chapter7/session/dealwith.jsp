<%@ page import="java.net.URL" %><%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%--防止表单在网站外部提交--%>
<html>
<head>
    <title>Title</title>
</head>
<%
    String address = request.getHeader("referer");
    String pathAdd = "";
    if (address != null){
        URL urlOne = new URL(address);
        pathAdd = urlOne.getHost();
    }
    String address1 = request.getRequestURL().toString();
    String pathAdd1 = "";
    if (address1 != null){
        URL urlTwo = new URL(address1);
        pathAdd1 = urlTwo.getHost(); //get server host of current page
    }
%>
<body>
<table align="">
    <%
        if (!pathAdd.equals(pathAdd1)){
            response.sendRedirect("main.jsp");
        }else {
            response.sendRedirect("exit.jsp");
        }
    %>
</table>
</body>
</html>
