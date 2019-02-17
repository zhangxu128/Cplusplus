package java1;
import java.util.*;
public class 双色球 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
       System.out.println("睁大你的大眼睛，下面开始摇出今天的双色球：");   
       Random ran= new Random();
       LinkedList link=new LinkedList();
       int cnt=0;
       link.add(0);
       while(link.size()!=8)
       { 
    	 link.add(ran.nextInt(34));

        	 if(cnt==6)
        	 {
        		 System.out.println("今天的蓝色球是"+link.get(cnt)+"号球");
        	 }
        	 else
        	 {
        		 System.out.println("第"+(cnt+1)+"个红球是"+link.get(cnt+1)+"号");
   		     }
         
         cnt++;
       }
	}
}
