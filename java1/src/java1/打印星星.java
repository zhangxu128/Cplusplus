package java1;

public class ��ӡ���� {

		public static void main(String[] args){
			int n = 5;
			printStar(n);
		}
		//��ӡ����
		private static void printStar(int n){
			//��ӡ�ϰ벿��
			for(int i=0;i<n;i++){
				for(int j=0;j<2*n;j++){
			  	if(j<n-i)
			  	  System.out.print(" ");
			  	if(j>=n-i && j<=n+i)
			  	  System.out.print("*");
			  }
			  System.out.println();
			}
			//��ӡ�°벿��
			for(int i=1;i<n;i++){
				System.out.print(" ");
				for(int j=0;j<2*n-i;j++){
					if(j<i)
			  	  System.out.print(" ");
			  	if(j>=i && j<2*n-i-1)
			  	  System.out.print("*");
				}
				System.out.println();
			}
		}

}


