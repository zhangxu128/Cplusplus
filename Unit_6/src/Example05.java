import java.util.*;
public class Example05 {
   public static void main(String[] args)
   {
	  ArrayList list=new ArrayList();
	  list.add("��ɮ");
	  list.add("���");
	  list.add("�˽�");
	  list.add("ɳɮ");
	  Iterator it = list.iterator();
	  while(it.hasNext())
	  {
		  String str=(String) it.next();
		  System.out.println(str);
		  
	  }
   }
}
