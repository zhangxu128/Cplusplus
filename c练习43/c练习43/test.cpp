#include<iostream>
#include<iomanip>
using namespace std;

double get_pow(double x, int n)
{
	double sum = 1;
	if (x == 1 || n == 0)
	{
		return sum;
	}
	else if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			sum *= x;
		}
	}
	else 
	{
		n = n * (-1);
		for (int i = 0; i < n; i++)
		{
			sum *= x;
		}
		sum = 1.0 / sum;
	}

	return sum;
}

int main()
{
	//计算x的n次方
	double x;
	int n;
	cin >> x >> n;
	double ret = get_pow(x, n);
	cout << setprecision(5) << ret << endl;
	system("pause");
	return 0;
}