
public class Example02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       NewPhone a=new NewPhone();
       a.call();
       a.ss();
	}

}
class Phone{
	void call(){
		System.out.println("����ͨ����");
	}
}
class NewPhone extends Phone{
	void call() {
		System.out.println("�������ԣ��ر�����");
	}
	void ss() {
		super.call();
	}
}	