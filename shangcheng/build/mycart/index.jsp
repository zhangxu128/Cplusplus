<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.CartBean,wyf.zrk.DBcart" %>

<html>
  <head>
    <title>�ҵ��̳�</title>
  </head>
  <link href="css/generalstyle.css" type="text/css" rel="stylesheet">
  <body>
    <jsp:useBean id="mycart" class="wyf.zrk.CartBean" scope="session"/>
    <center>
      <table border="0" width="100%" height="100%" cellpadding="0" cellspacing="0">
        <tr height="100">
          <td colspan="2" align="center"><%@ include file="top.jsp" %></td>
        </tr>
        <tr height="100">
          <td width="200" height="100" align="center">
          <% 
             if(session.getAttribute("user")==null)
             {
          %>
              <%@ include file="login.jsp" %>
          <% 
             }
             else
             {
             	out.println("<table border='0' bgcolor='#FFF0E1' width='80%' height='150'>");
             	out.println("<tr align='center' height='80'><td>");
             	out.println(session.getAttribute("user")+"���,<br/>��ӭ���˱���!!!");
             	out.println("<br/><a href='userinfo.jsp'>�鿴/�޸ĸ�����Ϣ</a>");
             	out.println("<a href='CartServlet?action=logout'>[ע��]</a>");
             	out.println("</td></tr></table>");
             }
            %>
          </td>
          <td rowspan="3"><%@ include file="splist.jsp" %></td>
        </tr>
        <tr>
          <td height="50"><%@ include file="spsearch.jsp" %></td>
        </tr>
        <tr>
          <td valign="top"><%@ include file="spclass.jsp" %></td>
        </tr>
      </table>
    </center>
  </body>
</html>