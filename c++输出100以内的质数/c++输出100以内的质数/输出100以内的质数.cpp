#include<iostream>
#include<cmath>
using namespace std;

/*
实验一 简单程序设计
内容提要
设计程序找出1 - 100间的质数，显示出来。
基本要求
用for或while或do - while循环语句实现。
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

//输出质数
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