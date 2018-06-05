<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Visitor Counter</title>
</head>
<body>
<%
    Integer visitorCount = (Integer) application.getAttribute("visitorCount");
    if (visitorCount == null){
        visitorCount = 1;
    }else {
        visitorCount++;
    }
    application.setAttribute("visitorCount",visitorCount);
%>
<h3>Hi,You are the <%=visitorCount%> visitor !</h3>
</body>
</html>
