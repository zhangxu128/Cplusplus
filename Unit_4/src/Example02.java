
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
		System.out.println("正在通话。");
	}
}
class NewPhone extends Phone{
	void call() {
		System.out.println("开启语言，关闭语言");
	}
	void ss() {
		super.call();
	}
}	