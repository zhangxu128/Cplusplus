import java.io.*;
public class Example11 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
        File file = new File("C:\\file");
        if(file.exists())
        {
        	file.delete();
        	System.out.println("�Ѿ��ɹ�ɾ���ļ���");
        }
	}

}
