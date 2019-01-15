import java.io.*;
public class Example11 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        File file = new File("C:\\file");
        if(file.exists())
        {
        	file.delete();
        	System.out.println("已经成功删除文件夹");
        }
	}

}
