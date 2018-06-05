<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 20:14
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<%
    session.invalidate(); //destroy session
    response.sendRedirect("index.jsp");
%>