<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.AdminBean,wyf.zrk.DBcart" %>
<script language="javascript" src="script/trim.js"></script>
<script language="javascript">
  function txtclear()
  {
    document.mfsearch.txtsearch.value="";
  }
  function check()
  {
    var key = document.mfsearch.txtsearch.value;
    if(key.trim()=="")
    {
      alert("�ؼ��ֲ���Ϊ��!!!");
      return;
    }
    var reg = /^\d+$/;
    if(!reg.test(key))
    {
      alert("������ֻ��Ϊ����!!!");
      return;
    }
    document.mfsearch.submit();
  }
</script>
<table>
<form name="mfsearch" action="AdminServlet" method="post">
  <tr>
    <td>
      <input name="txtsearch" value="������Ҫ��ѯ�Ķ�����" onfocus="txtclear()"/>
    </td>
  </tr>
  <tr>
    <td align="right">
      <input type="button" value="����" onclick="check()"/>
      <input type="hidden" name="action" value="orderSearch"/>
    </td>
  </tr>
</form>
</table>