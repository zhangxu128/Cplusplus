import java.sql.*;
public class jdbc {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Statement stmt = null;
		ResultSet re = null;
		Connection conn = null;
		try {
			//注册数据库驱动
			Class.forName("com.mysql.jdbc.Driver");
			//通过Driver获取数据库连接
			String url = "jdbc:mysql://localhost:3306/jdbc";
			String username = "root";
			String password = "z000621";
			conn=DriverManager.getConnection(url, username, password);
			//通过connection 对象获取 Statement 对象
			stmt = conn.createStatement();
			//使用statement 执行mysql语句
			String sql = "select *from student";
			re=stmt.executeQuery(sql);
			//操作ResultSet 结果集
			System.out.println("id |   name    |   sex   |  age   |");
			while(re.next()) {
				int id = re.getInt("id"); //获取字段
				String name = re.getString("name");
				String sex = re.getString("sex");
				int age = re.getInt("age"); //获取字段
			}
		}catch(Exception e) {
		  e.printStackTrace();	
		} finally {
			//回收数据库资源
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
