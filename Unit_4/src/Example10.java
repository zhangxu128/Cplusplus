
public class Example10 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		InterImpl i=new InterImpl();
		i.method();
	}

}
interface inter{
	int num=20;
    void method();
}
class InterImpl implements inter{
	public void method() {
		System.out.println("Œ“ΩÒƒÍ"+num);
	}
	
}