<%@ page contentType="text/html;charset=gb2312"%>
<%@ page import="wyf.zrk.AdminBean,wyf.zrk.DBcart,java.util.*"%>
<% 
	if(session.getAttribute("admin")==null)
	{
		response.sendRedirect("adlogin.jsp");
	}
	else
	{
		Vector<String[]> vgoods = (Vector<String[]>)request.getAttribute("vgoods");
		String[] str = vgoods.get(0);
 %>
 <html>
   <head>
     <title>��Ʒ����</title>
     <script language="javascript" src="script/trim.js"></script>
     <script language="javascript">
       function modifyGoods()
       {
		 document.myform.action.value="modify";
         if(document.myform.gname.value.trim()=="")
         {
         	alert("��Ʒ���Ʋ���Ϊ��!!!");
         	return;
         }
         if(document.myform.gprice.value.trim()=="")
         {
         	alert("��Ʒ�۸���Ϊ��!!!");
         	return;
         }
         if(isNaN(document.myform.gprice.value*1))
         {
         	alert("��Ʒ�۸�ֻ��������!!!");
         	return;
         }
         if(document.myform.gamount.value.trim()=="")
         {
         	alert("��Ʒ��������Ϊ��!!!");
         	return;
         }
         if(isNaN(document.myform.gamount.value*1))
         {
         	alert("��Ʒ����ֻ��������!!!");
         	return;
         }
         if(document.myform.gdate.value.trim()=="")
         {
         	alert("���ڲ���Ϊ��!!!");
         	return;
         }
         var reg = /^\d{4}-(0[1-9]|1[0-2])-([0-2][1-9]|3[0-1])$/;
         if(!reg.test(document.myform.gdate.value.trim()))
         {
         	alert("���ڸ�ʽ����,ֻ��Ϊyyyy-mm-dd");
         	return;
         }
         if(document.myform.gintro.value.trim()=="")
         {
         	alert("��Ʒ˵������Ϊ��!!!");
         	return;
         }
         if(document.myform.gbrief.value.trim()=="")
         {
         	alert("��Ʒ��鲻��Ϊ��!!!");
         	return;
         }
         document.myform.submit();
       }
       function deleteGoods()
       {
       		document.myform.action.value="delete";
       		document.myform.submit();
       }
     </script>
   </head>
   <body>
     <table width="100%" cellpadding="0" cellspacing="0">
       <tr>
         <td><%@ include file="admintop.jsp" %></td>
       </tr>
       <tr>
         <td align="center">
           <form action="AdminServlet" method="post" name="myform">
             <table>
               <tr>
                 <td>��Ʒ����:</td>
                 <td><input name="gname" size="30" value="<%=str[1] %>"/></td>
               </tr>
               <tr>
                 <td>��Ʒ�۸�:</td>
                 <td><input name="gprice" size="30" value="<%=str[2] %>"/></td>
               </tr>
               <tr>
                 <td>��Ʒ����:</td>
                 <td><input name="gamount" size="30" value="<%=str[3] %>"/></td>
               </tr>
               <tr>
                 <td>��Ʒ���:</td>
                 <td><input name="gclass" size="30" value="<%=str[4] %>"/></td>
               </tr>
               <tr>
                 <td>�ϼ�����:</td>
                 <td><input name="gdate" size="30" value="<%=str[5] %>"/></td>
               </tr>
               <tr>
                 <td>ͼƬURL:</td>
                 <td><input name="gurl" size="30" value="<%=str[6] %>"/></td>
               </tr>
               <tr>
                 <td>��Ʒ˵��:</td>
               </tr>
               <tr>
                 <td colspan="2">
                   <textarea cols="60" rows="6" name="gintro"><%=str[7] %></textarea>
                 </td>
               </tr>
               <tr>
                 <td>��Ʒ���:</td>
               </tr>
               <tr>
                 <td colspan="2">
                   <textarea cols="60" rows="6" name="gbrief"><%=str[8] %></textarea>
                 </td>
               </tr>
               <tr align="center">
                 <td colspan="2">
                   <input type="hidden" name="gid" value="<%= str[0] %>"/>
                   <input type="hidden" name="action" value=""/>
                   <input type="button" value="�޸�" onclick="modifyGoods()"/>
                   <input type="button" value="ɾ��" onclick="deleteGoods()"/>
                   <input type="button" value="����" onclick="javascript:history.back()"/>
                 </td>
               </tr>
             </table>
           </form>
         </td>
       </tr>
     </table>
   </body>
 </html>
 <% 
 	}
  %>