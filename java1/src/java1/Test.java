package java1;

import java.util.ArrayList;
import java.util.Scanner;

public  class Test{
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("请输入您要转换的数字：");
		int num = in.nextInt();
		System.out.println(swap(num));
	}
	public static int swap(int temp) {
	    String inputs=Integer.toString(temp);
	    String result="";
	    for(int i=inputs.length()-1;i>=0;i--)
	    {
	    	if(inputs.charAt(i))
	    	result=result+inputs.charAt(i);
	    }
	    if(temp<0)
	    {
	    	result="-"+result;
	    }
	    return Integer.parseInt(result);
	}
	
}

