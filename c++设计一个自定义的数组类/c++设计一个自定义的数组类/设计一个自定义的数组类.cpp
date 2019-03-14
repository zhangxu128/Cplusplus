#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "myArray.h"

using namespace std;

void test() {

	myArray array(10); //调用有参构造函数

	//对数组元素进行赋值

	for (int i = 0; i < array.getLen(); i++)
	{
		array.setData(i, 10);
	}

	cout << "-------------------------" << endl;

	//遍历数组元素
	for (int i = 0; i < array.getLen(); i++)
	{
		cout << array.getData(i) << " ";
	}
	cout << endl;


	//拷贝构造函数测试
	myArray array2 = array;

	for (int i = 0; i < array2.getLen(); i++)
	{
		cout << array2.getData(i) << " ";
	}
	cout << endl;

}
int  main()
{
	
	test();
	system("pause");
	return 0;
}