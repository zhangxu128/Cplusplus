
public class Example03 {
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
      String s="abcdefgcdea";
      System.out.println("字符串大的长度："+s.length());
	  System.out.println("字符串中的第一个字符："+s.charAt(0));
	  System.out.println("字符c第一次出现的位置："+s.indexOf('c'));
	  System.out.println("字符c最后一次出现的位置："+s.lastIndexOf('c'));
	  System.out.println("子字符串第一次出现的位置："+s.indexOf("de"));
	  System.out.println("子字符串最后一次出现的位置："+s.lastIndexOf("de"));
	  System.out.println("字符串转换为大写："+s.toUpperCase());
	}

}
