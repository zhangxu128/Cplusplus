#include<iostream>

using namespace std;

//求1 + 2 + 3 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case
//等关键字及条件判断语句（A ? B : C）。
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