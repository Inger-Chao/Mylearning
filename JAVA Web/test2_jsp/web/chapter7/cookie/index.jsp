<%@ page import="java.net.URLDecoder" %><%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/15
  Time: 21:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=GB18030" language="java" %>
<html>
<head>
    <title>Save and read users¡¯ information by cookie</title>
</head>
<body>
<%
    Cookie[] cookies = request.getCookies();
    String user = "";
    String date = "";
    if (cookies != null){
        for (int i = 0; i < cookies.length ; i++){
            if (cookies[i].getName().equals("mrCookie")){
                user = URLDecoder.decode(cookies[i].getValue().split("#")[0]); //get username
                date = cookies[i].getValue().split("#")[1]; // get register  date
            }
        }
    }
    if ("".equals(user) && "".equals(date)){ // if not register

%>
Hey boy!Welcome to my first cookie page!
<form action="deal.jsp" method="post">
    Please input your name : <input name="user" type="text" value="">
    <input type="submit" value="confirm" >
</form>
<%
    }else { // already registered

%>
Thanks for your visit!Welcome to come again!<br>
Your register time is <%=date%>
<%
    }
%>
</body>
</html>