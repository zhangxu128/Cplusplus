/* 
 ��Ŀ���ŵ����⣺��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ����Ӷ���Ϊ���٣� 
��������� ���ӵĹ���Ϊ����1,1,2,3,5,8,13,21.... 
*/
package java1;

import java.util.Scanner;

public class �ݹ������� {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in =new Scanner(System.in);
		int n=in.nextInt();
		System.out.println("��"+n+"������������Ϊ"+fun(n));
	}
	private static int fun(int n){
		if(n==1 || n==2)
		   return 1;
		else
		   return fun(n-1)+fun(n-2);

	}

}
