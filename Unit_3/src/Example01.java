/*
 ��ϰ3-3 �����вεĹ��췽��
���˼·
1��	����һ��Student�࣬������һ��age���ԣ������ж���һ���в����Ĺ��췽�����ò�������Ϊage���Ը�ֵ��
2��	��дһ��������Example04����main()������ͨ���вι��췽������һ������
3��	��ӡ�ö���age���Ե�ֵ��
��ϰ3-4  ���췽��������
���˼·
1����Student������޸ģ������ж����������صĹ��췽���������޲εĹ��췽��������һ��String���Ͳ����Ĺ��췽��������String���ͺ�int�������������Ĺ��췽����
2����д������Example05����main()�����У��ֱ�ʹ���������صĹ��췽����������Student����

 */
public class Example01 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student s1=new Student();
        s1.age=19;
        s1.name="����";
        s1.speak();
        Student s2=new Student();
        s2.age=20;
        s2.name="����";
        s2.speak();
        Student s3=new Student();
        s3=s2;
        s3.speak();
	}

}
//����ѧ����
class Student{
	String name;
	int age;
	public void speak() { 
		System.out.println("�ҵ������ǣ�"+name+"\t"+"�ҵ������ǣ�"+age);
	}
}