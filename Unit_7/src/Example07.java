import java.io.*;
public class Example07 {
    public static void main(String[] args)throws Exception
    {
    	FileWriter writer = new FileWriter("write.txt");
    	String str="��ã���������";
    	writer.write(str);
    	writer.write("\r\n");
    	writer.close(); 	
    }
}
