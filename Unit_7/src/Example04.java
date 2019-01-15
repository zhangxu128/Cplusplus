import java.io.*;
public class Example04 {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
			InputStream in = new FileInputStream("source\\小水果1.mp3");
			OutputStream out = new FileOutputStream("target\\小水果1.mp3");
			int len;
			long begintime=System.currentTimeMillis();
			while((len=in.read())!=-1)
			{
				out.write(len);
			}
			long endtime=System.currentTimeMillis();
			System.out.println("文件拷贝的时间是："+(endtime-begintime)+"毫秒");
			in.close();
			out.close();
	}
}
