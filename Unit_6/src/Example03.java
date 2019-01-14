import java.util.*;
public class Example03 {
   public static void main(String[] args)
   {
	  ArrayList arr= new ArrayList();
	  arr.add("ÄãÊÇÖí");
	  arr.add("yes");
	  arr.add("À²À²À²");
	  System.out.println(arr.get(1));
	  System.out.println(arr.get(arr.size()-1));
   }
}
