<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.AdminBean" %>
<% 
	if(session.getAttribute("admin")==null)
	{
		response.sendRedirect("adlogin.jsp");
	}
	else
	{
 %>
<html>
  <head>
    <title>��ӭ����</title>
  </head>
  <body>
     <jsp:useBean id="adBean" class="wyf.zrk.AdminBean" scope="session"/>
    <table width="100%">
      <tr>
        <td><%@ include file="admintop.jsp" %></td>
      </tr>
      <tr>
        <td>
		 <table>
		  <tr>
		    <td>
		      <table>
				<tr>
				  <td><%@ include file="adminsearch.jsp" %></td>
				</tr>
				<tr align="center">
				  <td>
				    <a href="addgoods.jsp">��Ʒ���</a>
				  </td>
				</tr>
				<tr align="center">
				  <td><br/>��Ʒ���</td>
				</tr>
				<tr>
				  <td>
				  <% 
				  	String sql = "select distinct Gclass from GoodsInfo";
				    Vector<String> vclass = DBcart.getInfo(sql);
				    for(String st:vclass)
				    {
				  %>
				    <tr>
				      <td align="center">
				        <a href="AdminServlet?action=search&cname=<%= st %>"><%= st %></a>
				      </td>
				    </tr>
				  <%
				    }
				  %>
				  </td>
				</tr>
		      </table>
		    </td>
		    <td width="100%"><%@ include file="goodsmanage.jsp" %></td>
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