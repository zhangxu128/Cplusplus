
public class Example11 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MIPhone mi=new MIPhone();
		mi.useMIUI();
	}

}
interface Phone1{
	void receiveMessages();
	void call();
}
interface SmartPhone extends Phone1{
	void faceTime();
}
class MIPhone implements SmartPhone{
	public void useMIUI() {
		this.receiveMessages();
		this.call();
		this.faceTime();
	}

	@Override
	public void receiveMessages() {
		// TODO Auto-generated method stub
		System.out.println("�յ���Ϣ");
	}

	@Override
	public void call() {
		// TODO Auto-generated method stub
		System.out.println("����ͨ��");
	}

	@Override
	public void faceTime() {
		// TODO Auto-generated method stub
		System.out.println("hello");
	}
}