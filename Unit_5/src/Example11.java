import java.util.*;
public class Example11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       Random r=new Random();
       for(int i=0;i<10;i++) {
    	   System.out.println(r.nextInt());
       }
       for(int j=0;j<10;j++) {
    	   System.out.println(r.nextInt(10));
       }
       
	}

}
