<%@ page contentType="text/html;charset=gb2312"%>
<% 
	if(session.getAttribute("admin")!=null)
	{
		response.sendRedirect("adminindex.jsp");
	}
	else
	{
 %>
<html>
  <head>
    <title>����Ա��¼</title>
    <script language="javascript" src="script/trim.js"></script>
    <script language="javascript">
      function check()
      {
          var aname = document.adform.aname.value.trim();
          var apwd = document.adform.apwd.value.trim();
          if(aname=="")
          {
          	alert("�û�������Ϊ��!!!");
          	return;
          }
          if(apwd=="")
          {
            alert("���벻��Ϊ��!!!");
            return;
          }
          document.adform.submit();
      }
    </script>
  </head>
  <body>
    <table width="100%">
      <tr>
        <td><%@ include file="top.jsp" %></td>
      </tr>
      <tr align="center">
        <td><h2>����Ա���¼</h2></td>
      </tr>
      <form action="AdminServlet" method="post" name="adform">
      <tr align="center">
        <td><br/>�û���:<input name="aname"/></td>
      </tr>
      <tr align="center">
        <td><br/>��&nbsp;��:<input type="password" name="apwd"/></td>
      </tr>
      <tr align="center">
        <td>
          <input type="hidden" name="action" value="login"/>
          <br/><input type="button" value="��¼" onclick="check()"/>
          &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
          <input type="reset" name="����"/>
        </td>
      </tr>
      </form>
    </table>
  </body>
</html>
<% 
	}
 %>