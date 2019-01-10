
public class Example20 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        int[] a= {2,56,10,78,1};
		System.out.println(min(a));
		
	}
    public static int min(int[] a) {
        int minmum=a[0];
        for(int i=1;i<a.length;i++) {
        	if(minmum>=a[i]) {
        		minmum=a[i];
        	}
        }
        return minmum;
    }
}