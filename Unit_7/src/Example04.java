import java.io.*;
public class Example04 {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
			InputStream in = new FileInputStream("source\\Сˮ��1.mp3");
			OutputStream out = new FileOutputStream("target\\Сˮ��1.mp3");
			int len;
			long begintime=System.currentTimeMillis();
			while((len=in.read())!=-1)
			{
				out.write(len);
			}
			long endtime=System.currentTimeMillis();
			System.out.println("�ļ�������ʱ���ǣ�"+(endtime-begintime)+"����");
			in.close();
			out.close();
	}
}
