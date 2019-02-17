package java1;

import java.util.Scanner;

public class 日历 {

	public static void main(String[] args) {
		// TODO Auto -generated method stub
      Scanner in = new Scanner (System.in);
      System.out.println("请输入您要查找的年份：");
      int year=in.nextInt();
      System.out.println("请输入您要查找的月份：");
      int month=in.nextInt();
      int sum=0;
      int days;
      for(int i=1900;i<year;i++) {
    	  if(i%4==0&&i%100!=0||i%400==0) {
    		  sum+=366;    	  
    		  }
           
          else {
        	  sum+=365;
         }
      }
      for(int i=1;i<month;i++) {
    	  if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) {
    		  sum+=31;
    	  }
    	  else if(i==2) {
    		  if(year%4==0&&year%100!=0||year%400==0) {
    			  sum+=29;
    		  }
    		  else {
    			  sum+=28;
    		  }
    	  }
    	  else {
    		  sum+=30;
    	  }
      }
      sum+=1;
      System.out.println("日\t一\t二\t三\t四\t五\t六");
      int day=sum%7;
      for(int i=0;i<day;i++) {
     	  System.out.print("\t");
       }
      if(month==1||month==3||month==5||month==7||month==8||month==10||month==12) {
		  days=31;
	  }
	  else if(month==2) {
		  if(year%4==0&&year%100!=0||year%400==0) {
			  days=29;
		  }
		  else {
			  days=28;
		  }
	  }
	  else {
		  days=30;
	  }
      for(int i=1;i<=days;i++) {
    	  System.out.print(i+"\t");
    	  if(sum%7==6) {
    		  System.out.print("\n");
    	  }
    	  sum++;
      }
    	  
	}
}
