<%@ page contentType="text/html;charset=gb2312" %>
<script language="javascript" src="script/trim.js"></script>
<script language="javascript">
  function fcheck()
  {
    var uid = document.all.uid.value.trim();
    var pwd = document.all.pwd.value.trim();
    if(uid=="")
    {
      alert("�û�������Ϊ��!!!");
      return;
    }
    if(pwd=="")
    {
      alert("���벻��Ϊ��!!!");
      return;
    }
    if(pwd.length<6)
    {
      alert("���볤�Ȳ���С��6!!!");
      return;
    }    
    document.loginform.submit();
  }
</script>
<form name="loginform" action="CartServlet" method="post">
  <center>
  <table border="0" bgcolor="#FFF0E1" width="80%" height="150">
    <tr align="center" height="40">
      <td>�û���:</td>
      <td><input type="text" id="uid" name="uid" size="12"/></td>
    </tr>
    <tr>
      <td>��&nbsp;&nbsp;��:</td>
      <td><input type="password" id="pwd" name="pwd" size="12"/></td>
    </tr>
    <tr height="40">
      <td>
        <input type="button" id="denglu" name="denglu" value="��¼" onclick="fcheck()"/>
        <input type="hidden" name="action" value="login"/>
      </td>
      <td><input type="reset" id="zhuce" name="zhuce" value="����"/></td>
    </tr>
    <tr align="right">
      <td colspan="2"><a href="register.jsp">[���û�ע��]</a></td>
    </tr>
  </table>
  </center>
</form>