#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//��Ŀ����
//��ֻ����������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ������������7��
//ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������


int Min(int a, int b, int c)
{
	int temp = (a < b ? a : b);
	return (temp < c ? temp : c);
}
int FindUgly(int n) //
{
	int* ugly = new int[n];
	ugly[0] = 1;
	int index2 = 0;
	int index3 = 0;
	int index5 = 0;
	int index = 1;
	while (index < n)
	{
		int val = Min(ugly[index2] * 2, ugly[index3] * 3, ugly[index5] * 5); //����������һ������   
		if (val == ugly[index2] * 2) //���������������index*���Ųһλ��  
			++index2;
		if (val == ugly[index3] * 3)   //���ﲻ����elseif����Ϊ������������Сֵ����ʱ��ҪŲ����
			++index3;
		if (val == ugly[index5] * 5)
			++index5;
		ugly[index++] = val;
	}
	/*
		for (int i = 0; i < n; ++i)
			cout << ugly[i] << endl;
	//*/
	int result = ugly[n - 1];
	delete[] ugly;
	return result;
}

int main()
{
	int n;//��n����
	cin >> n;
	cout << FindUgly(n) << endl;
	system("pause");
	return 0;
}