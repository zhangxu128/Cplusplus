package gongju;
import java.util.*;
import java.io.*;
import jiemian.*;

public class Glhylb 
{
    private static HashMap hm=new HashMap<String,liebiao>();
	public static void addliebiao(String lt,liebiao lb)
	{
		hm.put(lt,lb);
	}
	
	public static liebiao getQqFriendList(String lt)
	{
		return (liebiao)hm.get(lt);
	}
}
