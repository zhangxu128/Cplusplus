package java1;
import java.util.*;
public class 学生成绩管理系统 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      Scanner in = new Scanner(System.in);
      System.out.print("请输入人数：");
      int renshu=in.nextInt();
      System.out.print("请输入课程数：");
      int coursenum=in.nextInt();
      String[] name=new String[renshu];
      String[] course=new String[coursenum];
      int[][] grade=new int[renshu][coursenum];
      int[][] number=new int[renshu][coursenum];
      int[] sum=new int[coursenum];
      int[] sum1=new int[coursenum];
      for(int i=0;i<course.length;i++) {
    	  System.out.print("请输入第"+(i+1)+"门课程名称：");
    	  course[i]=in.next();
      }
      
      for(int i=0;i<renshu;i++) {
    	  System.out.print("请输入第"+(i+1)+"名学生姓名：");
    	  name[i]=in.next();
    	  for(int j=0;j<coursenum;j++) {
    		  System.out.print("请输入第"+(j+1)+"门课程成绩：");
    		  grade[i][j]=in.nextInt();
    		  sum[i]+=grade[i][j];
    	  }
           
      }
      sum1=sum;
      Arrays.sort(sum1);
      
      System.out.print("学生");
      for(int i=0;i<course.length;i++) {
    	  System.out.print("\t"+course[i]);
      }
      System.out.println("\t总分\t排名");
      for(int i=0;i<renshu;i++) {
    	  System.out.print(name[i]);
    	  for(int j=0;j<coursenum;j++) {
    		  System.out.print("\t"+grade[i][j]);  
    	  }
    	  System.out.print("\t"+sum[i]);
    	  System.out.print("\t"+sum[i]);
      }

	}

}
