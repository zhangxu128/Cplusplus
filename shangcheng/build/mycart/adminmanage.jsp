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
    <title>����Ա����</title>
  </head>
  <body>
    <table width="100%" cellspacing="0" cellpadding="0">
      <tr>
        <td><%@ include file="admintop.jsp" %></td>
      </tr>
      <tr>
        <td align="center"><br/><br/><br/>
          <table width="100%">
            <tr>
              <td width="20%" align="center">
                <table>
                  <tr>
                    <td><a href="adminadd.jsp">����Ա���</a></td>
                  </tr>
                  <tr>
                    <td><br/><a href="resetpwd.jsp">��������</a></td>
                  </tr>
                  <tr>
                    <td><br/><a href="adminmanage.jsp">�鿴���й���Ա</a></td>
                  </tr>
                </table>
              </td> 
              <td>
                <table width="70%" hight="100%">
                  <tr>
      			    <th>����ԱID</th>
				    <th>�û���</th>
				    <th>����Ա����</th>
				    <th>����Աɾ��</th>           
                  </tr>
                  <% 
                  	String sql = "select Aid,Aname,Alevel from AdminInfo";
                  	Vector<String[]> vadmin = DBcart.getInfoArr(sql);
                  	int i=0;
					for(String[] str:vadmin)
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
                   		<td><%= str[0] %></td>
                   		<td><%= str[1] %></td>
                   		<td><%= str[2] %></td>
                   		<td><a href="AdminServlet?action=adminDelete&aid=<%= str[0] %>">ɾ��</a></td>
                  </tr>
                   <% 
                   	} 
                    %>
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