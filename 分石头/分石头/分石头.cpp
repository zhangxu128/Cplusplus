//��Ŀ����
//��֪ʯͷ�������顣��ʯͷ��Ϊ������ӽ�������
//�������� :
//���飬ֵΪÿ��ʯͷ������
//������� :
//�������������������
//ʾ��1
//����
//5, 1, 1, 1, 1, 1
//���
//5, 5

#include <iostream>
#include <vector>

using namespace std;


int part(vector<int> a, int b, int c, int i, int len);

int main(){
	vector<int> a;
	int x;
	int num = 0;
	while (cin >> x)  //����
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
