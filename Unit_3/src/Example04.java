/*
 ��ϰ3-3 �����вεĹ��췽��
���˼·
1��	����һ��Student�࣬������һ��age���ԣ������ж���һ���в����Ĺ��췽�����ò�������Ϊage���Ը�ֵ��
2��	��дһ��������Example04����main()������ͨ���вι��췽������һ������
3��	��ӡ�ö���age���Ե�ֵ��

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
