/*
 ��ϰ3-6��̬����
���˼·
1��	����Student�࣬�������ж���name��className���ԡ�
2��	��д������Example08����main()�����д�������ѧ�����󣬲��ֱ�Ϊ��Щ�����name��className���Ը�ֵ��Ȼ�������Щ�����name��classNameֵ��
3��	��Student������޸ģ���className����Ϊ��̬������
4��	�޸Ĳ����࣬��main()������ʹ��Student.className = �����꼶���ࡱ���Ϊ��̬����className���и�ֵ��Ȼ�������Щ�����name��classNameֵ��

 */
public class Example08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student4 s1=new Student4();
        s1.setName("����");
        s1.setClassName("������һ��");
        System.out.println(s1);
        Student4 s2=new Student4();
        s2.setName("����");
        s2.setClassName("����������");
        System.out.println(s2);
        Student4 s3=new Student4();
        s3.setName("����");
        s3.setClassName("����������");
        System.out.println(s3);
        Student4.className="���꼶����";
        s1.setName("����");
        s1.setClassName("������һ��");
        System.out.println(s1);
        s2.setName("����");
        s2.setClassName("����������");
        System.out.println(s2);
        s3.setName("����");
        s3.setClassName("����������");
        System.out.println(s3);
	}

}
class Student4{
	String name;
	static String className;
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getClassName() {
		return className;
	}
	public void setClassName(String className) {
		this.className = className;
	}
	public String toString() {
		return "�ҵ������ǣ�"+this.name+"\t"+"�ҵİ༶�����ǣ�"+this.className;
	}
}