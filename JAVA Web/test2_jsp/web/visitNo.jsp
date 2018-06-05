<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 19:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" isThreadSafe="false" %>
<html>
<head>
    <title>来访统计</title>
</head>
<body>
    <%!
        int count = 0;
        public int getCount(){
            count++;
            return count;
        }
    %>
您好，您是本站的第<%=getCount()%>位来访者！
</body>
</html>
