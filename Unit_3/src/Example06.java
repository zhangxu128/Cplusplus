/*练习3-5  this关键字访问构造方法
设计思路
1）	在Student类中创建多个重载的构造方法，包括无参的构造方法和一个参数的构造方法，以及两个参数的构造方法。
2）	在一个参数的构造方法中使用this关键字调用无参构造方法，在两个参数的构造方法中调用一个参数的构造方法。
3）	编写测试类Example06，在main()方法中，调用两个参数的构造方法创建对象，演示构造方法的执行顺序。
*/
public class Example06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student1 s1=new Student1();
		s1.speak(12, "张三");
	}

}
class Student1{
	String name;
	int age;
	void speak() {
		System.out.println("Hello World!");
	}
	void speak(int age) {
		this.speak();
	}
	void speak(int age,String name) {
		this.speak(age);
	}
}
