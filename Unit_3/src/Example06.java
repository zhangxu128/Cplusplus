/*��ϰ3-5  this�ؼ��ַ��ʹ��췽��
���˼·
1��	��Student���д���������صĹ��췽���������޲εĹ��췽����һ�������Ĺ��췽�����Լ����������Ĺ��췽����
2��	��һ�������Ĺ��췽����ʹ��this�ؼ��ֵ����޲ι��췽���������������Ĺ��췽���е���һ�������Ĺ��췽����
3��	��д������Example06����main()�����У��������������Ĺ��췽������������ʾ���췽����ִ��˳��
*/
public class Example06 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student1 s1=new Student1();
		s1.speak(12, "����");
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
