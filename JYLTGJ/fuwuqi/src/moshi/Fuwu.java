package moshi;
import java.net.*;
import java.io.*;
import java.util.*;
import gonggong.*;

public class Fuwu 
{
	public Fuwu()
	{
        try {
			ServerSocket ss=new ServerSocket(9999);
			while(true)
			{
				Socket s=ss.accept();
				ObjectInputStream ois=new ObjectInputStream(s.getInputStream());
				User u=(User)ois.readObject();
				Message m=new Message();
				ObjectOutputStream oos=new ObjectOutputStream(s.getOutputStream());
				if(u.getPasswd().equals("123123"))
				{
					m.setMesType("1");
					oos.writeObject(m);
					Xiancheng xc=new Xiancheng(s);
					Xianchengbaioshi.addxiancheng(u.getUserId(), xc);
					xc.start();
					xc.tongzhi(u.getUserId());
				}	
				else
				{
					m.setMesType("2");
					oos.writeObject(m);
					s.close();
				}				
			}				
		} catch (Exception e) {}
	}
}
