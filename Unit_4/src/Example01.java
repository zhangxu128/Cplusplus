
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
	  System.out.print("���ڳԷ�,");
	}
	void sleep() {
		  System.out.println("�����˯����");
	}
}
class Student extends Person{
	Student(){
		System.out.println("����ѧ����");
	}
}
class Teacher extends Person{
	Teacher(){
		System.out.println("������ʦ��");
	}
}