<%--
  Created by IntelliJ IDEA.
  User: Joki
  Date: 2018/5/22
  Time: 20:05
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>HomePage</title>
</head>
<body>
<form action="${pageContext.request.contextPath}/AddressServlet" method="post" onsubmit="return check(this);">
    <h2>添加人员信息</h2>
    <ul>
        <li>name：<input type="text" name="name" > </li>
        <li>sex：<input type="radio" name="sex"
                       value="boy" checked="checked" >boy
            <input type="radio" name="sex" value="girl">girl </li>
        <li>address：<textarea rows="5" cols="30" name="add"></textarea> </li>
        <li><input type="submit" value="submit"></li>
    </ul>
</form>

<script type="text/javascript">
    function check(form) {
        with(form){
            if(name.value == ""){
                alert("Name can not be empty!");
                return false;
            }
            if(add.value == ""){
                alert("Address can not be empty!");
                return false;
            }
        }
    }
</script>
</body>
</html>
