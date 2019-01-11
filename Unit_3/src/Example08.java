/*
 练习3-6静态变量
设计思路
1）	定义Student类，并在类中定义name和className属性。
2）	编写测试类Example08，在main()方法中创建三个学生对象，并分别为这些对象的name和className属性赋值，然后输出这些对象的name和className值。
3）	对Student类进行修改，将className定义为静态变量。
4）	修改测试类，在main()方法中使用Student.className = “三年级二班”语句为静态变量className进行赋值，然后输出这些对象的name和className值。

 */
public class Example08 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        Student4 s1=new Student4();
        s1.setName("张三");
        s1.setClassName("物联网一班");
        System.out.println(s1);
        Student4 s2=new Student4();
        s2.setName("李四");
        s2.setClassName("物联网二班");
        System.out.println(s2);
        Student4 s3=new Student4();
        s3.setName("王五");
        s3.setClassName("物联网三班");
        System.out.println(s3);
        Student4.className="三年级二班";
        s1.setName("张三");
        s1.setClassName("物联网一班");
        System.out.println(s1);
        s2.setName("李四");
        s2.setClassName("物联网二班");
        System.out.println(s2);
        s3.setName("王五");
        s3.setClassName("物联网三班");
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
		return "我的姓名是："+this.name+"\t"+"我的班级名称是："+this.className;
	}
}