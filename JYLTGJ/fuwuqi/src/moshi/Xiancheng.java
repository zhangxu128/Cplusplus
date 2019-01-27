package moshi;
import java.util.*;
import java.net.*;
import java.io.*;
import gonggong.*;

public class Xiancheng extends Thread
{
    private Socket s;
	
	public Xiancheng(Socket s)
	{
		this.s=s;
	}	
	public void tongzhi(String iam)
	{
		HashMap hm=Xianchengbaioshi.hm;
		Iterator it=hm.keySet().iterator();
		while(it.hasNext())
		{
			Message m=new Message();
			m.setCon(iam);
			m.setMesType(MessageType.message_ret_onLineFriend);
			String onLineUserId=it.next().toString();
			try {
				ObjectOutputStream oos=new ObjectOutputStream(Xianchengbaioshi.getxiancheng(onLineUserId).s.getOutputStream());
				m.setGetter(onLineUserId);
				oos.writeObject(m);
			} catch (Exception e) {}			
		}
	}	
	public void run()
	{		
		while(true)
		{
			try {
				ObjectInputStream ois=new ObjectInputStream(s.getInputStream());
				Message m=(Message)ois.readObject();
				if(m.getMesType().equals(MessageType.message_comm_mes))
				{
					Xiancheng xc=Xianchengbaioshi.getxiancheng(m.getGetter());
					ObjectOutputStream oos=new ObjectOutputStream(xc.s.getOutputStream());
					oos.writeObject(m);
				}
				else if(m.getMesType().equals(MessageType.message_get_onLineFriend))
				{
					String res=Xianchengbaioshi.getZaixianyonghu();
					Message m2=new Message();
					m2.setMesType(MessageType.message_ret_onLineFriend);
					m2.setCon(res);
					m2.setGetter(m.getSender());
					ObjectOutputStream oos=new ObjectOutputStream(s.getOutputStream());
					oos.writeObject(m2);
				}	
			} catch (Exception e) {}			
		}		
	}
}