#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "myArray.h"

using namespace std;

void test() {

	myArray array(10); //�����вι��캯��

	//������Ԫ�ؽ��и�ֵ

	for (int i = 0; i < array.getLen(); i++)
	{
		array.setData(i, 10);
	}

	cout << "-------------------------" << endl;

	//��������Ԫ��
	for (int i = 0; i < array.getLen(); i++)
	{
		cout << array.getData(i) << " ";
	}
	cout << endl;


	//�������캯������
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