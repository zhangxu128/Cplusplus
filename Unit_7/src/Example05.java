import java.io.*;
public class Example05 {
   public static void main(String[] args) throws Exception
   {
	  InputStream in = new FileInputStream("source\\Сˮ��2.mp3");
	  OutputStream out = new FileOutputStream("target\\Сˮ��2.mp3");
	  byte[] buff = new byte[1024];
	  int len ;
	  long begintime = System.currentTimeMillis();
	  while((len=in.read(buff))!=-1)
	  {
		  out.write(buff, 0,len);
	  }
	  long endtime = System.currentTimeMillis();
	  System.out.println("�ļ�������ʱ��"+(endtime-begintime)+"����");
	  in.close();
	  out.close();
   }
}
