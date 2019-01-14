import java.util.*;
public class Example11 {
   public static void main(String[] args)
   {
	   Properties p=new Properties();
	   p.setProperty("Backgroup","red");
	   p.setProperty("Font-size","14px");
	   p.setProperty("language","Chinese");
	   Enumeration names=p.propertyNames();
	   while(names.hasMoreElements())
	   {
		   String key=(String) names.nextElement();
		   String value=(String) p.getProperty(key);
		   System.out.println(key+"="+value);
	   }
   }
}
