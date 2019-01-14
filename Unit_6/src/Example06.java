import java.util.*;
public class Example06 {
   public static void main(String[] args)
   {
	   ArrayList arr= new ArrayList(0);
	   arr.add(1);
	   arr.add("eee");
	   arr.add(2);
	   arr.add("ggg");
	   for(Object obj:arr)
	   {
		   System.out.println(obj);
	   }
	   int[] arr1= {3,2,6};
	   for(int i:arr1)
	   {
		   System.out.println(i);
	   }
   }
}
