#include<iostream>

using namespace std;

//��1 + 2 + 3 + ... + n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case
//�ȹؼ��ּ������ж���䣨A ? B : C����
int getSum(int n)
{
	int sum = n;
	bool flag = (sum > 0) && ((sum += getSum(--n)) > 0);
	return sum;
}

int main()
{
	int n;
	cin >> n;
	cout<<getSum(n)<<endl;
	system("pause");
	return 0;
}