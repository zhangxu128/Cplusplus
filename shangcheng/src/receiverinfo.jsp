<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.CartBean" %>
<jsp:useBean id="mycart" class="wyf.zrk.CartBean" scope="session"/>
<% 
	if(session.getAttribute("user")==null)
	{
		String msg = "<h1>�����ȵ�½!!!</h1><a href='index.jsp'>[��¼]</a>";
		request.setAttribute("msg",msg);
		String url = "/error.jsp";
		ServletContext sc = getServletContext(); 
		RequestDispatcher rd = sc.getRequestDispatcher(url); 
		rd.forward(request,response);
	}
	else
	{
 %>
<html>
  <head>
    <title>������Ϣ</title>
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
      <table width="100%" cellpadding="0" cellspacing="0">
        <tr>
          <td><%@ include file="top.jsp" %></td>
        </tr>
        <tr>
          <td>
            <center>
            <table>
              <caption><b><br/>�ջ�����Ϣ</b></caption>
              <form action="CartServlet" method="post" name="mfrec">
                <tr>
                  <td><br/>�ջ�������:</td>
                  <td><br/><input name="recname"/></td>
                </tr>
                <tr>
                  <td><br/>�ջ��˵�ַ:</td>
                  <td><br/><input name="recadr"/></td>
                </tr>
                <tr>
                  <td><br/>�ջ��˵绰:</td>
                  <td><br/><input name="rectel"/></td>
                </tr>
                <tr>
                  <td align="center" colspan="2">
                    <font color="red" size="">
                      <br/>���������д��ȷ����Ϣ,�Ա�֤��Ļ�����˳���յ�.
                    </font>
                  </td>
                </tr>
                <tr>
                  <td colspan="2" align="right">
                  	<input type="hidden" name="action" value="saveRec"/>
                    <br/><input type="button" value="ȷ��" onclick="checkMsg()"/>
                  </td>
                </tr>
              </form>
            </table>            
            </center>
          </td>
        </tr>
      </table>
    </center>
  </body>
</html>
<% 
	}
 %>