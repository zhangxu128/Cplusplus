import java.util.Scanner;
public class Example10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
          Scanner in=new Scanner(System.in);
          System.out.println("�������·ݣ����磺10 ");
          int month=in.nextInt();
          if(month==3||month==4||month==5) { 
        	  System.out.println("����");
          }
          else if(month==6||month==7||month==8) { 
        	  System.out.println("�ļ�");
          }
          else if(month==9||month==10||month==11) { 
        	  System.out.println("�＾");
          }
          else if(month==12||month==1||month==2) { 
        	  System.out.println("����");
          }
          
	}

}
