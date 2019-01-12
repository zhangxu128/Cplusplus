
public class Example12 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Animal cat=new Cat();
        cat.sleep();

	}

}
interface Animal{
	void sleep();
}
class Cat implements Animal{
	public void catchMouse() {
		
	}

	@Override
	public void sleep() {
		// TODO Auto-generated method stub
		System.out.println("ÀÏÊóÔÚË¯¾õ");
	}
}