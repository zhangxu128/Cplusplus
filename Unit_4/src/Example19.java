
public class Example19 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        try {
        	int result=divide(4,0);
            System.out.println(result);
        }
        catch(MyException e) {
        	System.out.println(e.getMessage());
        }
	}
    public static int divide(int x,int y) throws MyException{
    	if(y==0) {
    		throw new MyException("除数不能为0");
    	}
    	int result=x/y;
    	return result;
    }
}
class MyException extends Exception{
    public MyException() {
    	super();
    }
    public MyException(String str) {
    	super(str);
    }
}