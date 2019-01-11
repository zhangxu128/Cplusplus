/*
 练习3-3 定义有参的构造方法
设计思路
1）	定义一个Student类，该类有一个age属性，在类中定义一个有参数的构造方法，该参数用于为age属性赋值。
2）	编写一个测试类Example04，在main()方法中通过有参构造方法创建一个对象。
3）	打印该对象age属性的值。

 */
public class Example04 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student2 s=new Student2();
		s.setAge(18);
		System.out.println(s.getAge());
	}

}
class Student2{
    int age;

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}
	
}
