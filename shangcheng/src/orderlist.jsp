<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="wyf.zrk.AdminBean,wyf.zrk.DBcart,java.util.*"%>
<table width="100%" border="0">
  <tr>
    <th>������</th>
    <th>������</th>
    <th>��������</th>
    <th>����״̬</th>
    <th>������ϸ��Ϣ</th>
  </tr>
  <% 
  	Vector<String[]> vorder = (Vector<String[]>)request.getAttribute("vorder");
  	if(vorder==null)
  	{
  		DBcart.setSpan(10);
  		int nowpage = adBean.getCurPage();
  		String sql = "select Oid,Uname,Odate,Ostate from OrderInfo,UserInfo"+
  				" where Ostate='δ����' and OrderInfo.Uid=UserInfo.Uid order by Oid";
  		String sqlpage = "select count(*) from OrderInfo where Ostate='δ����'";
  		sqlpage = new String(sqlpage.getBytes(),"ISO-8859-1");
  		int totalpage = DBcart.getTotalPage(sqlpage);
  		sql = new String(sql.getBytes(),"ISO-8859-1");
  		adBean.setSql(sql);
  		//��ס��ǰ��ҳ��
  		adBean.setTotalPage(totalpage);
		vorder = DBcart.getPageContent(nowpage,sql);
		DBcart.setSpan(2);
  	}
	for(int i=0;i<vorder.size();i++)
	{
		String[] str = vorder.get(i);
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
   		<td><%= str[3] %></td>
   		<td><a href="AdminServlet?action=ordermanage&oid=<%= str[0]%>">�鿴/����</a></td>
   	 </tr>
   <% 
   	}
   %>
   <tr>
     <td colspan="5"><hr/></hr></td>
   </tr>
   <tr>
     <% 
    	int curPage = adBean.getCurPage();
    	int totalPage = adBean.getTotalPage();
      %>
     <td align="right">
     <% 
     	if(curPage>1)
     	{
     %>
     	<a href="AdminServlet?action=orderPageChange&curPage=<%= curPage-1%>"><<��һҳ</a>
     <%
     	}
     %>
     </td>
     <form action="AdminServlet" method="post">
       <td colspan="3" align="center">
      	  <select onchange="this.form.submit()" name="selPage">
      	   <% 
      	   		for(int i=1;i<=totalPage;i++)
      	   		{
      	   			String flag = "";
      	   			if(i==curPage)
      	   			{
      	   				flag = "selected";
      	   			}
      	    %>
      	    	<option value="<%=i%>" <%= flag %>>��<%= i %>ҳ</option>
      	    <% 
      	    	}
      	     %>
      	  </select>
       </td>
       <input type="hidden" name="action" value="orderPageChange"/>
     </form>
     <td align="left">
     <% 
     	if(curPage<totalPage)
     	{
      %>
      	<a href="AdminServlet?action=orderPageChange&curPage=<%= curPage+1%>">��һҳ>></a>
      <% 
      	}
      %>
     </td>
   </tr>
</table>