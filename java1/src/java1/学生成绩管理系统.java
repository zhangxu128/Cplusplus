package java1;
import java.util.*;
public class ѧ���ɼ�����ϵͳ {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
      Scanner in = new Scanner(System.in);
      System.out.print("������������");
      int renshu=in.nextInt();
      System.out.print("������γ�����");
      int coursenum=in.nextInt();
      String[] name=new String[renshu];
      String[] course=new String[coursenum];
      int[][] grade=new int[renshu][coursenum];
      int[][] number=new int[renshu][coursenum];
      int[] sum=new int[coursenum];
      int[] sum1=new int[coursenum];
      for(int i=0;i<course.length;i++) {
    	  System.out.print("�������"+(i+1)+"�ſγ����ƣ�");
    	  course[i]=in.next();
      }
      
      for(int i=0;i<renshu;i++) {
    	  System.out.print("�������"+(i+1)+"��ѧ��������");
    	  name[i]=in.next();
    	  for(int j=0;j<coursenum;j++) {
    		  System.out.print("�������"+(j+1)+"�ſγ̳ɼ���");
    		  grade[i][j]=in.nextInt();
    		  sum[i]+=grade[i][j];
    	  }
           
      }
      sum1=sum;
      Arrays.sort(sum1);
      
      System.out.print("ѧ��");
      for(int i=0;i<course.length;i++) {
    	  System.out.print("\t"+course[i]);
      }
      System.out.println("\t�ܷ�\t����");
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
