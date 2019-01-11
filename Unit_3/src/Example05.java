/*
 练习3-4  构造方法的重载
设计思路
1）对Student类进行修改，在类中定义三个重载的构造方法，包括无参的构造方法，接收一个String类型参数的构造方法，接收String类型和int类型两个参数的构造方法。
2）编写测试类Example05，在main()方法中，分别使用三个重载的构造方法创建三个Student对象。

 */
public class Example05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student3 s1=new Student3();
        Student3 s2=new Student3("张三");
        Student3 s3=new Student3("张三",18);
	}

}
class Student3{
	public Student3() {
		System.out.println("Hello World");
	}
	public Student3(String name) {
        System.out.println(name);
	}
	
	public Student3(String name,int age) {
		System.out.println(name+"\t"+age);
	}

}
