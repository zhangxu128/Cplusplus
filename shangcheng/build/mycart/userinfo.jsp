<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="wyf.zrk.CartBean,wyf.zrk.DBcart,java.util.*"%>
<html>
  <head>
    <title>�û���Ϣ�޸�</title>
    <script language="javascript" src="script/trim.js"></script>
    <script language="javascript">
      function check()
      {
      	var pwd = document.mfmodify.upwd.value;
      	var email = document.mfmodify.uemail.value;
      	if(pwd.trim()=="")
      	{
      		alert("���벻����Ϊ��!!!");
      		return;
      	}
      	else if(pwd.trim().length<6)
      	{
      		alert("���볤�Ȳ�������6!!!");
      		return;
      	}
      	else if(email.trim()=="")
      	{
      		alert("E-mail����Ϊ��!!!");
      		return;
      	}
      	document.mfmodify.submit();
      }
    </script>
  </head>
  <body>
    <jsp:useBean id="mycart" class="wyf.zrk.CartBean" scope="session"/>
     <table width="100%">
		  <tr>
		    <td><%@ include file="top.jsp" %></td>
		  </tr>
		  <tr align="center">
		    <td>
		      <table>
		        <form action="CartServlet" method="post" name="mfmodify">
		          <% 
		              String uname = (String)session.getAttribute("user");
		              uname = new String(uname.getBytes(),"ISO-8859-1");
		          	  String sql = "select Uname,Upwd,Uemail from UserInfo where Uname='"+uname+"'";
		          	  Vector<String[]> vuser = DBcart.getInfoArr(sql);
		          	  String[] str = vuser.get(0);
		           %>
		          <tr align="center">
		            <td><br/><br/>�û���:</td>
		            <td align="left"><br/><br/><%=str[0] %></td>
		          </tr>
		          <tr>
		            <td><br/><br/>��&nbsp;��:</td>
		            <td><br/><br/><input type="password" name="upwd" value="<%=str[1] %>"/></td>
		          </tr>
		          <tr>
		            <td><br/><br/>E-mail:</td>
		            <td><br/><br/><input name="uemail" value="<%=str[2] %>"/></td>
		          </tr>
		          <tr>
		            <td align="right">
		              <br/><br/><input type="button" value="�޸�" onclick="check()"/>
		              <input type="hidden" name="action" value="uinfomodify"/>
		            </td>
		            <td align="right"><br/><br/>
		              <a href="javascript:history.back()">�������ﷵ��</a>
		            </td>
		          </tr>
		        </form>
		      </table>
		    </td>
		  </tr>
	</table>
  </body>
</html>