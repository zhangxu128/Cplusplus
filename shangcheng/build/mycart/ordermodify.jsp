<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.AdminBean" %>
<% 
	if(session.getAttribute("admin")==null)
	{
		response.sendRedirect("adlogin.jsp");
	}
	else
	{
		Vector<String[]> vordergoods = 
					(Vector<String[]>)request.getAttribute("vordergoods");
		Vector<String[]> vorderinfo = 
					(Vector<String[]>)request.getAttribute("vorderinfo");
		String[] str = vorderinfo.get(0);
%>
<html>
  <head>
    <title>��������</title>
  </head>
  <body>
    <table width="100%" cellpadding="0" cellspacing="0">
      <tr>
        <td><%@ include file="admintop.jsp" %></td>
      </tr>
      <tr align="center">
        <td>
          <table width="60%">
            <tr>
	          <th>��������</td>
	          <th>��������</td>
	          <th>�����ܼ�</td>          
            </tr>
          <% 
          	  int i=0;
          	  for(String[] temp:vordergoods)
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
              <td><%= temp[0] %></td>
              <td><%= temp[1] %></td>
              <td><%=  temp[2]%></td>
            </tr>
           <% 
           	   }
            %>
          </table>
        </td>
      </tr>
      <tr>
        <td><hr/></hr></td>
      </tr>
      <tr align="center">
        <td>
          <table>
            <tr>
              <td>�ջ�������:<%= str[0] %></td>
            </tr>
            <tr>
              <td>�ջ��˵�ַ:<%= str[1] %></td>
            </tr>
            <tr>
              <td>�ջ��˵绰:<%= str[2] %></td>
            </tr>
            <tr>
              <td>��������:<%= str[3] %></td>
            </tr>
            <tr>
              <td>��������״̬:<%= str[4] %></td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td><hr/></hr></td>
      </tr>
      <tr align="center">
        <td>
          <a href="AdminServlet?action=orderEnsure&oid=<%= str[5]%>">��������</a>
          <a href="AdminServlet?action=orderDelete&oid=<%= str[5]%>">����ɾ��</a>
          <a href="javascript:history.back()">����</a>
        </td>
      </tr>
    </table>
  </body>
</html>
<% 
	}
%>