<%@ page contentType="text/html;charset=gb2312" %>
<html>
  <head>
    <title>��ʾҳ��</title>
    <link href="css/generalstyle.css" type="text/css" rel="stylesheet">
  </head>
  <body>
    <%
 		String msg = (String)request.getAttribute("msg");
     %>
      <table width="100%">
		  <tr height="70">
		    <td align="center"><img src="img/other/logo.gif" width="50" height="50"/>���������</td>
		  </tr>
		  <tr height="15">
		    <td><hr color="#FF7F00" width="100%"/></hr></td>
		  </tr>
	 </table>
	 <br/><br/><br/><br/><br/><br/><br/><br/><br/>
	 <center>
	   <font color="" size="12"><%= msg %></font>
	   <br/><br/>
	   <a href="javascript:history.back()">�������ﷵ��</a>
	   &nbsp;&nbsp;&nbsp;&nbsp;
	   <a href="index.jsp">��ҳ</a>
	 </center>
  </body>
</html>