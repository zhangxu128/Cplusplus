<%@ page contentType="text/html;charset=gb2312" %>
<%@ page import="java.util.*,wyf.zrk.CartBean" %>
<script language="javascript" src="script/trim.js"></script>
<script language="javascript">
  function txtclear()
  {
    document.mfsearch.tsearch.value="";
  }
  function tijiao()
  {
    var key = document.mfsearch.tsearch.value;
    if(key.trim()=="")
    {
      alert("�ؼ��ֲ���Ϊ��");
      return;
    }
    document.mfsearch.submit();
  }
</script>


<center>
<form name="mfsearch" method="post" action="CartServlet">
 	<table border="0" bgcolor="#FFE8D0" width="80%">
	  <tr>
	    <td>
	      <input type="text" id="tsearch" name="tsearch" value="������Ҫ�����Ĺؼ���" onfocus="txtclear()"/>
	    </td>
	  </tr>
	  <tr>
	  	<td align="right">
	  	    <input type="hidden" name="action" value="search"/>
	  	    <input type="button" id="bsearch" name="bsearch" value="����" onclick="tijiao()"/>
	  	  </a>
	  	</td>
	  </tr>
	</table>
</form>
</center>