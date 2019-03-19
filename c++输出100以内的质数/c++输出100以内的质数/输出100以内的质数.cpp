#include<iostream>
#include<cmath>
using namespace std;

/*
ʵ��һ �򵥳������
������Ҫ
��Ƴ����ҳ�1 - 100�����������ʾ������
����Ҫ��
��for��while��do - whileѭ�����ʵ�֡�
*/


bool isPrime(int num)
{
	bool flag = true;
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

//�������
void printPrime()
{
	int count = 0;
	for (int i = 2; i <= 100; i++)
	{

		if (isPrime(i))
		{
			cout << i << " ";
			count++;
		}
		if (count % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}


int main()
{
	printPrime();
	system("pause");
	return 0;
}