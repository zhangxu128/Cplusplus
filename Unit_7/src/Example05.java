import java.io.*;
public class Example05 {
   public static void main(String[] args) throws Exception
   {
	  InputStream in = new FileInputStream("source\\小水果2.mp3");
	  OutputStream out = new FileOutputStream("target\\小水果2.mp3");
	  byte[] buff = new byte[1024];
	  int len ;
	  long begintime = System.currentTimeMillis();
	  while((len=in.read(buff))!=-1)
	  {
		  out.write(buff, 0,len);
	  }
	  long endtime = System.currentTimeMillis();
	  System.out.println("文件拷贝的时间"+(endtime-begintime)+"毫秒");
	  in.close();
	  out.close();
   }
}
