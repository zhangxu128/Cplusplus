#include<iostream>

using namespace std;
//
//����һ�� ��������������ͳ������������������������֮����ȣ����ǳ���Ϊ������������
//����һ�� ������ n�� ������������������� True�����򷵻� False
//ʾ����
//  ���� : 28
//	��� : True
//	���� : 28 = 1 + 2 + 4 + 7 + 14

bool checkPerfectNumber(int num) 
{
	int tmp = num;
	int sum = 0;
	if (num == 1)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (tmp%i == 0)
		{
			sum += i;
			sum += (tmp / i);
		}
	}
	if ((sum+1) == num)
	{
		return true;
	}

	return false;
}

int main()
{
	int n;
	cin >> n;
	cout << checkPerfectNumber(n) << endl;
	system("pause");
	return 0;
}