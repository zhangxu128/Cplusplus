package java1;
import java.util.*;
public class ˫ɫ�� {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
       System.out.println("������Ĵ��۾������濪ʼҡ�������˫ɫ��");   
       Random ran= new Random();
       LinkedList link=new LinkedList();
       int cnt=0;
       link.add(0);
       while(link.size()!=8)
       { 
    	 link.add(ran.nextInt(34));

        	 if(cnt==6)
        	 {
        		 System.out.println("�������ɫ����"+link.get(cnt)+"����");
        	 }
        	 else
        	 {
        		 System.out.println("��"+(cnt+1)+"��������"+link.get(cnt+1)+"��");
   		     }
         
         cnt++;
       }
	}
}
