import java.sql.*;
public class jdbc {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Statement stmt = null;
		ResultSet re = null;
		Connection conn = null;
		try {
			//ע�����ݿ�����
			Class.forName("com.mysql.jdbc.Driver");
			//ͨ��Driver��ȡ���ݿ�����
			String url = "jdbc:mysql://localhost:3306/jdbc";
			String username = "root";
			String password = "z000621";
			conn=DriverManager.getConnection(url, username, password);
			//ͨ��connection �����ȡ Statement ����
			stmt = conn.createStatement();
			//ʹ��statement ִ��mysql���
			String sql = "select *from student";
			re=stmt.executeQuery(sql);
			//����ResultSet �����
			System.out.println("id |   name    |   sex   |  age   |");
			while(re.next()) {
				int id = re.getInt("id"); //��ȡ�ֶ�
				String name = re.getString("name");
				String sex = re.getString("sex");
				int age = re.getInt("age"); //��ȡ�ֶ�
			}
		}catch(Exception e) {
		  e.printStackTrace();	
		} finally {
			//�������ݿ���Դ
			if(re!=null) {
				try {
					re.close();
				}catch(SQLException e){
					e.printStackTrace();
				}
				re=null;
			}
			if(stmt!=null)
			{
				try {
					stmt.close();
				}catch(SQLException e){
					e.printStackTrace();
				}
				stmt=null;
			}
			if(conn!=null)
			{
				try {
					conn.close();
				}catch(SQLException e){
					e.printStackTrace();
				}
				conn=null;
			}
		}
	}
}
