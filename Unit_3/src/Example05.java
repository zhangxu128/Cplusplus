/*
 ��ϰ3-4  ���췽��������
���˼·
1����Student������޸ģ������ж����������صĹ��췽���������޲εĹ��췽��������һ��String���Ͳ����Ĺ��췽��������String���ͺ�int�������������Ĺ��췽����
2����д������Example05����main()�����У��ֱ�ʹ���������صĹ��췽����������Student����

 */
public class Example05 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student3 s1=new Student3();
        Student3 s2=new Student3("����");
        Student3 s3=new Student3("����",18);
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
