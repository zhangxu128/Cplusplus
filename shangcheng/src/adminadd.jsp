<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.AdminBean,wyf.zrk.DBcart" %>
<% 
	if(session.getAttribute("admin")==null||session.getAttribute("level")==null)
	{
		response.sendRedirect("adlogin.jsp");
	}
	else
	{
 %>
<html>
  <head>
    <title>����Ա���</title>
    <script language="javascript" src="script/trim.js"></script>
    <script language="javascript">
      function check()
      {
      	var aname = document.addform.aname.value.trim();
      	var apwd = document.addform.apwd.value.trim();
      	var secpwd = document.addform.secpwd.value.trim();
      	if(aname=="")
      	{
      		alert("�û�������Ϊ��!!!");
      		return;
      	}
      	if(apwd==""||apwd.length<6)
      	{
      		alert("���벻�Ϸ�,���Ȳ���С��6!!!");
      		return;
      	}
      	if(secpwd!=apwd)
      	{
      		alert("�����������벻һ��!!!");
      		return;
      	}
      	document.addform.submit();
      }
    </script>
  </head>
  <body>
    <table width="100%" cellpadding="0" cellspacing="0">
      <tr>
        <td><%@ include file="admintop.jsp" %></td>
      </tr>
      <tr>
        <td>
          <table width="100%">
            <tr>
              <td width="20%" align="center">
                <table>
                  <tr>
                    <td><br/><br/><a href="adminadd.jsp">����Ա���</a></td>
                  </tr>
                  <tr>
                    <td><br/><a href="">��������</a></td>
                  </tr>
                  <tr>
                    <td><br/><a href="adminmanage.jsp">�鿴���й���Ա</a></td>
                  </tr>
                </table>
              </td>
              <td align="center"><br/><br/><br/>
                <table width="50%">
                  <form action="AdminServlet" method="post" name="addform">
                    <tr>
                      <td>���������Ա�û���:</td>
                      <td><input name="aname"/></td>
                    </tr>
                    <tr>
                      <td><br/>���������Ա����:</td>
                      <td><br/><input type="password" name="apwd"/></td>
                    </tr>
                    <tr>
                      <td><br/>���ٴ��������Ա����:</td>
                      <td><br/><input type="password" name="secpwd"/></td>
                    </tr>
                    <tr>
                      <td align="right">
                        <input type="hidden" name="action" value="adminAdd"/>
                        <br/><input type="button" value="���" onclick="check()"/>
                      </td>
                      <td><br/><input type="reset" value="����"/></td>
                    </tr>
                  </form>
                </table>
              </td>
            </tr>
          </table>
        </td>
      </tr>
    </table>
  </body>
</html>
<% 
 	}
  %>