<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="wyf.zrk.AdminBean,wyf.zrk.DBcart,java.util.*"%>
<table border="0" width="100%">
<% 
	Vector<String[]> vgoods = (Vector<String[]>)request.getAttribute("vgoods");
	if(vgoods==null)
	{
		adBean.setCurPage(1);
        String gsql = "select Gimgurl,Gname,Gintro,Gclass,"+
        			"Gprice,Glook,Gid,Gdate from GoodsInfo";
        int totalpage = DBcart.getTotalPage("select count(*) from GoodsInfo");
        adBean.setTotalPage(totalpage);
        adBean.setSql(gsql);
		vgoods = DBcart.getPageContent(1,gsql);
	}
	for(int i=0;i<vgoods.size();i++)
	{
		String[] str = vgoods.get(i);
 %>
  <tr>
    <td width="150" align="center">
        <img src="<%= str[0] %>" height="150" border="1"/>
    </td>
    <td colspan="2">
      <table width="100%">
        <tr>
          <td bgcolor="#E4EDFA"><%= str[1] %></td>
        </tr>
        <tr>
          <td><font><%= adBean.manageStr(str[2]) %></font></td>
        </tr>
        <tr>
          <td bgcolor="#E4EDFA"><font>��������:<%= str[3] %></font></td>
        </tr>
        <tr>
          <td><font>����:��<%= str[4] %></font></td>
        </tr>
        <tr>
          <td bgcolor="#E4EDFA"><font>�������:<%= str[5] %></font></td>
        </tr>
        <tr>
          <td><font>�ϼ�����:<%= str[7] %></font></td>
        </tr>
        <tr>
          <td bgcolor="#E4EDFA">
            <a href="AdminServlet?action=goodsManage&gid=<%= str[6] %>">�޸�/ɾ����Ʒ</a>
          </td>
        </tr>
      </table>
    </td>
  </tr>
  <% 
  	}
   %>
   <tr>
     <td colspan="3"><hr/></hr></td>
   </tr>
   <tr align="center">
     <% 
    	int curPage = adBean.getCurPage();
    	int totalPage = adBean.getTotalPage();
     %>
      <td>
      <% 
      	if(curPage>1)
      	{
      %>
      	<a href="AdminServlet?action=pageChange&curPage=<%= curPage-1%>"><<��һҳ</a>
      <%
      	}
      %>
      </td>
      <form action="AdminServlet" method="post">
      <td align="right" width="200">
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
      	  <input type="hidden" name="action" value="pageChange"/>
      	</td>
      	</form>
      <td align="left" width="40%">
      	<% 
      		if(curPage<totalPage)
      		{
      	 %>
      	 	<a href="AdminServlet?action=pageChange&curPage=<%= curPage+1%>">��һҳ>></a>
      	 <% 
      	 	}
      	  %>
      </td>
    </tr>
</table>