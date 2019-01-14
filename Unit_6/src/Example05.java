import java.util.*;
public class Example05 {
   public static void main(String[] args)
   {
	  ArrayList list=new ArrayList();
	  list.add("ÌÆÉ®");
	  list.add("Îò¿Õ");
	  list.add("°Ë½ä");
	  list.add("É³É®");
	  Iterator it = list.iterator();
	  while(it.hasNext())
	  {
		  String str=(String) it.next();
		  System.out.println(str);
		  
	  }
   }
}
