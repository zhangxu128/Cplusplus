
public class Example18 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		print99(9);
		print99();
	}
	public static int print99(int row) {
        for(int i=1;i<=+9;i++) {
        	for(int j=1;j<=i;j++) {
        		System.out.print(j+"*"+i+"="+i*j+"\t");
        		}
        System.out.println("\n");
        }
        return 0;
	}
	public static void print99() {
		for(int i=1;i<=9;i++) {
        	for(int j=1;j<=i;j++) {
        		System.out.print(j+"*"+i+"="+i*j+"\t");
        		}
        System.out.println("\n");
        }
	}	
}
