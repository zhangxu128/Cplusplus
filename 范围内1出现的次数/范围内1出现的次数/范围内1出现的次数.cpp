//��Ŀ����
//���1~13��������1���ֵĴ���, �����100~1300��������1���ֵĴ�����
//Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��, 
//���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����, ������������ձ黯, 
//���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������

#include <iostream>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	if (n < 1) return 0;
	for (int i = 1; i <= n; ++i)
	{
		int temp = i;
		while (temp)
		{
			if (temp % 10 == 1)
				++count;
			temp /= 10;
		}
	}
	return count;
}

int main(void) {

	int n;
	cin >> n;
	cout << NumberOf1Between1AndN_Solution(n) << endl;
	system("pause");
	return 0;
}