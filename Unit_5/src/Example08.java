import java.util.*;
public class Example08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
     Properties properties =System.getProperties();
     System.out.println(properties);//获取系统属性
     long starttime = System.currentTimeMillis();
     int sum=0;
     for(int i=0;i<100000000;i++) {
    	 sum=sum+i;
     }
     long endtime = System.currentTimeMillis();
     System.out.println("运行时间："+(endtime-starttime)+"毫秒");
     int[] a= {11,22,33,44,55};
     int[] b= {66,77,88,99, 100 };
     System.arraycopy(a, 2, b, 2, 2);
     for(int i=0;i<b.length;i++) {
    	 System.out.println(i+":"+b[i]);
     }
	}

}
