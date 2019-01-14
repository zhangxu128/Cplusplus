import java.util.*;
public class Example07 {
   public static void main(String[] args)
   {
	   HashSet hs=new HashSet();
	   hs.add("I");
	   hs.add("love");
	   hs.add("you");
	   hs.add("you");
	   hs.add("are");
	   hs.add("pig");
	   System.out.println(hs.size());
	   Iterator it=hs.iterator();
	   while(it.hasNext())
	   {
		   Object s=it.next();
		   System.out.println(s);
	   }
   }
}
