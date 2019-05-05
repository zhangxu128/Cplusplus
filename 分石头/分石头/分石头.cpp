//题目描述
//已知石头重量数组。将石头分为质量最接近的两组
//输入描述 :
//数组，值为每个石头的质量
//输出描述 :
//两组的质量（降序排序）
//示例1
//输入
//5, 1, 1, 1, 1, 1
//输出
//5, 5

#include <iostream>
#include <vector>

using namespace std;


int part(vector<int> a, int b, int c, int i, int len);

int main(){
	vector<int> a;
	int x;
	int num = 0;
	while (cin >> x)  //输入
	{
		a.push_back(x);
		num += x;
		if (cin.get() == '\n')
			break;
	}
	int len = a.size();
	x = part(a, 0, 0, 0, len);
	cout << (num + x) / 2 << "," << (num - x) / 2;
	
	system("pause");
	return 0;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int part(vector<int> a, int b, int c, int i, int len)
{
	if (i == len)
	{
		if (b > c)
			return b - c;
		else
			return c - b;
	}
	int x1 = part(a, b + a[i], c, i + 1, len);
	int x2 = part(a, b, c + a[i], i + 1, len);
	return min(x1, x2);
}
