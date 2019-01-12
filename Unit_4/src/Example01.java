
public class Example01 {
    public static void main(String[] args) {
    	Student s1=new Student();
    	s1.eat();s1.sleep();
    	Teacher t1=new Teacher();
    	t1.eat();t1.sleep();
    }
}
class Person{
	void eat() {
	  System.out.print("我在吃饭,");
	}
	void sleep() {
		  System.out.println("吃完就睡觉。");
	}
}
class Student extends Person{
	Student(){
		System.out.println("我是学生，");
	}
}
class Teacher extends Person{
	Teacher(){
		System.out.println("我是老师，");
	}
}