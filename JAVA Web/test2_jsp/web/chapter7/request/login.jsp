<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 19:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>title!</title>
</head>
<body>
<%
    request.setCharacterEncoding("UTF-8");
    //Get username
    String username = request.getParameter("username");
    //get password
    String password = request.getParameter("password");
    //judge whether username&password are equal to 'admin'
    if ("admin".equals(username) && "admin".equals(password)){
        out.print("Congratulation!");
    }else {
        out.print("sorry,wrong username or password");
    }
%>
<br>Client post method ： <%=request.getMethod()%>
<br>protocol: <%=request.getProtocol()%>
<br>Client URI: <%=request.getRequestURI()%>
<br>Client URL: <%=request.getRequestURL()%>
<br>Client IP address: <%=request.getRemoteAddr()%>
<br>Server port : <%=request.getServerPort()%>
<br>Server name : <%=request.getServerName()%>
<br>Client Host : <%=request.getRemoteHost()%>
<br>Servlet Path of Client requested: <%=request.getServletPath()%>
<br>the host of the header of HTTP : <%=request.getHeader("host")%>
<br>the User-Agent of the header of HTTP : <%=request.getHeader("User-Agent")%>
<br>the accept-language of the header of HTTP : <%=request.getHeader("accept-language")%>
</body>
</html>
