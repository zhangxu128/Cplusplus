<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.CartBean" %>
<jsp:useBean id="mycart" class="wyf.zrk.CartBean" scope="session"/>
<% 
	String[] recMsg = (String[])session.getAttribute("recMsg");
	if(recMsg==null)
	{
		response.sendRedirect("index.jsp");
	}
	else
	{
 %>
<html>
  <head>
    <title>����ȷ��</title>
    <script language="javascript" src="script/trim.js"></script>
    <script language="javascript">
      function checkMsg()
      {
      	var recname = document.mfrec.recname.value;
      	var recadr = document.mfrec.recadr.value;
      	var rectel = document.mfrec.rectel.value;
      	if(recname.trim()=="")
      	{
      		alert("�ջ��˲���Ϊ��!!!");
      		return;
      	}
      	if(recadr.trim()=="")
      	{
      		alert("�ջ��˵�ַ����Ϊ��!!!");
      		return;
      	}
      	if(rectel.trim()=="")
      	{
      		alert("�绰���벻��Ϊ��!!!");
      		return;
      	}
      	document.mfrec.submit();
      }
    </script>
  </head>
  <body>
    <center>
      <table width="100%">
        <tr>
          <td><%@ include file="top.jsp" %></td>
        </tr>
        <tr>
          <td>
            <center>
            <table width="80%">
              <tr>
 	        	<th>��Ʒ����</th>
	        	<th>��Ʒ�۸�</th>
	        	<th>��Ʒ����</th>
              </tr>
			<% 
				Vector<String[]> vgoods = mycart.getCartContent();
				int i = 0;
				for(String[] arr:vgoods)
				{
					i++;
					if(i%2==0)
					{
						out.println("<tr align='center'>");
					}
					else
					{
						out.println("<tr align='center' bgcolor='#F5F9FE'>");
					}
			%>
				  <td><%= arr[0] %></td>
				  <td>��<%= arr[1] %></td>
				  <td><%= arr[2] %></td>
				</tr>
			<% 
				}
			 %>
			   <tr>
			     <td colspan="3" align="right"><b>��Ʒ�۸��ܼ�:��<%= mycart.getAccount() %></b></td>
			   </tr>
            </table>
            </center>
          </td>
        </tr>
        <form action="CartServlet" method="post" name="mfrec">
        <tr align="center">
          <td><br/>�ջ�������:&nbsp;<input name="recname" value="<%= recMsg[0] %>"/></td>
        </tr>
        <tr align="center">
          <td><br/>�ջ��˵�ַ:&nbsp;<input name="recadr" value="<%= recMsg[1] %>"/></td>
        </tr>
        <tr align="center">
          <td><br/>�ջ��˵绰:&nbsp;<input name="rectel" value="<%= recMsg[2] %>"/></td>
        </tr>
        <tr align="center">
          <td>
          	<input type="hidden" name="action" value="recModify"/>
            <br/><input type="button" value="�ջ�����Ϣ�޸�" onclick="checkMsg()"/>&nbsp;&nbsp;&nbsp;
            <a href="CartServlet?action=orderConfirm">����ȷ��</a>
          </td>
        </tr>     
        </form>
      </table>
    </center>
  </body>
</html>
<% 
	}
 %>