#include<iostream>

using namespace std;

//����һ����������дһ���������ж����Ƿ��� 2 ���ݴη���
bool isPowerOfTwo(int n) 
{
	if (n <= 0 || n % 2 != 0)
	{
		return false;
	}
	while (n != 2)
	{
		if ((n /= 2) % 2 != 0)
		{

			return false;
		}
	}
	return true;
}

int main()
{
	int num = 0;
	cin >> num;
	cout << isPowerOfTwo(num) << endl;
	system("pause");
	return 0;
}
