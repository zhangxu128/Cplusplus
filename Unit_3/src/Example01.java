/*
 练习3-3 定义有参的构造方法
设计思路
1）	定义一个Student类，该类有一个age属性，在类中定义一个有参数的构造方法，该参数用于为age属性赋值。
2）	编写一个测试类Example04，在main()方法中通过有参构造方法创建一个对象。
3）	打印该对象age属性的值。
练习3-4  构造方法的重载
设计思路
1）对Student类进行修改，在类中定义三个重载的构造方法，包括无参的构造方法，接收一个String类型参数的构造方法，接收String类型和int类型两个参数的构造方法。
2）编写测试类Example05，在main()方法中，分别使用三个重载的构造方法创建三个Student对象。

 */
public class Example01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student s1=new Student();
        s1.age=19;
        s1.name="张三";
        s1.speak();
        Student s2=new Student();
        s2.age=20;
        s2.name="李四";
        s2.speak();
        Student s3=new Student();
        s3=s2;
        s3.speak();
	}

}
//定义学生类
class Student{
	String name;
	int age;
	public void speak() { 
		System.out.println("我的姓名是："+name+"\t"+"我的年龄是："+age);
	}
}