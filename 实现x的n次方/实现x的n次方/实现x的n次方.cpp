#include<iostream>


using namespace std;

//实现x的n次方

double Pow(double x, int n)
{
	double sum = 1;
	if (n == 0)
	{
		return 1;
	}
	for (int i = 0; i < abs(n); i++)
	{
		sum = sum * x;
	}
	if (n < 0)
	{
		return 1.0 / sum;
	}
	return sum;
}

int main()
{
	double x = 0;
	int n = 0;
	cin >> x >> n;
	double r = Pow(x, n);
	cout  << r << endl;
	system("pause");
	return 0;
}