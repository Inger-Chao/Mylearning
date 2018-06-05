<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/8
  Time: 20:24
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="us" class="com.bean.Userinfo" scope="request" />
<jsp:setProperty name="us" property="*" />
<%
    String name = us.getName();
    String job = us.getJob();
    if (name.equals("")|| job.equals("")){

%>
<jsp:forward page="false.jsp"/>
<%} else {%>
<jsp:forward page="success.jsp"/>
<% } %>