import java.io.*;
public class Example01 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
       FileInputStream in =new FileInputStream("test.txt");
       int b=0;
       while(true)
       {
    	   b=in.read();
    	   if(b==-1)
    		   break;
    	   System.out.println(b);
       }
       in.close();
	}
   
}
