package gongju;
import java.io.*;
import java.net.*;
import gonggong.*;
import jiemian.*;


public class Ljfwqxc extends Thread
{
    private Socket s;
	
	public Ljfwqxc(Socket s)
	{
		this.s=s;
	}
	public Socket getS() {
		return s;
	}

	public void setS(Socket s) {
		this.s = s;
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
					Liaotian lt= Glliaotian.getLiaotian(m.getGetter()+" "+m.getSender());
					lt.showMessage(m);
				}else if(m.getMesType().equals(MessageType.message_ret_onLineFriend))
				{
					String con=m.getCon();
					String friends[]=con.split(" ");
					String getter=m.getGetter();
					System.out.println("getter="+getter);
					liebiao lb=Glhylb.getQqFriendList(getter);
					if(lb !=null)
					{
						lb.upateFriend(m);
					}				
				}
			} catch (Exception e) {}
		}
	}
}
