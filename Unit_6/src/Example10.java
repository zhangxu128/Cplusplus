import java.util.*;
public class Example10 {
   public static void main(String[] args)
   {
	   Map map=new HashMap();
	   map.put("1","hh");
	   map.put("2","aa");
	   map.put("3","bb");
	   Iterator it=map.keySet().iterator();
	   Iterator it1=map.entrySet().iterator();
	   while(it.hasNext())
	   {
		   Object obj=it.next();
		   Object value=map.get(obj);
		   System.out.println(obj+":"+value);
	   }
       while(it1.hasNext())
       {
    	   Map.Entry entry=(Map.Entry)(it1.next());
    	   Object key = entry.getKey();
    	   Object values=entry.getValue();
    	   System.out.println(key+":"+values);
       }
       
   }
}
