<%@ page import="java.net.URLEncoder" %>
<%@ page import="java.util.Date" %>
<%@ page import="java.text.DateFormat" %>
<%@ page import="java.text.SimpleDateFormat" %><%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 21:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    request.setCharacterEncoding("GB18030");
    String user = URLEncoder.encode(request.getParameter("user"),"GB18030");
    Date date = new Date();
    DateFormat df = new SimpleDateFormat("y.m.d-h:m:s");
    Cookie cookie = new Cookie("mrCookie",user+"#"+df.format(date));
    cookie.setMaxAge(60*60*24*30); //available days = 30
    response.addCookie(cookie);
%>
<script type="text/javascript">window.location.href="index.jsp"</script>
</body>
</html>
