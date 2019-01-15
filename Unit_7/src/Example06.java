import java.io.*;
public class Example06 {
   public static void main(String args[])throws Exception
   {
        FileReader reader = new FileReader("fr.txt");
        int ch;
        while((ch=reader.read())!=-1)
        {
        	System.out.println((char)ch);
        }
        reader.close();
   }
}
