<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 19:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>OUT输出对象</title>
</head>
<body>
<%
    out.print("我是小可爱");
%>
<%="我是大可爱"%>
<%
    out.println("Hey!Ak");
    out.println("battle king");
%>
<pre>
    <%
        out.println("Hey!BRO");
        out.println("I will never let you part");
    %>
</pre>
<%--clear() clear buffer area --%>
<%--chearBuffer () clear current buffer things--%>
<%--flush() isAutoFlush() if buffer area is full throw exception or auto-clear--%>
<%--getBufferSize()--%>
</body>
</html>
