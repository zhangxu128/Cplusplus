//题目：求1+2!+3!+...+20!的和

package java1;

public class 求和 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        int sum=0;
		for(int i=0;i<20;i++) {
        	sum+=sum(i+1);
        }
		System.out.println(sum);
	}
    private static long sum(int n) {
    	int m=1;
    	for(int i=1;i<n+1;i++) {
    	  m=m*i;
    	}
    	return m;
    } 
}
