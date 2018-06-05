<%@ page import="com.bean.UserInfoList" %>
<%@ page import="com.listener.UserInfoTrace" %>
<%@ page import="java.util.Vector" %><%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/22
  Time: 20:54
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    UserInfoList list = UserInfoList.getInstance();
    UserInfoTrace trace = new UserInfoTrace();
    request.setCharacterEncoding("UTF-8");
    String name = request.getParameter("user");
    trace.setUser(name);
    session.setAttribute("list",trace);
    list.addUserInfo(trace.getUser());
    session.setMaxInactiveInterval(30);
%>
<textarea rows="8" cols="20">
    <%
        Vector vector = list.getVector();
        if (vector!=null && vector.size() > 0){
            for (int i = 0; i < vector.size() ; i++){
                out.print(vector.elementAt(i));
            }
        }
    %>
</textarea>
<a href="login.jsp">back</a>
</body>
</html>
