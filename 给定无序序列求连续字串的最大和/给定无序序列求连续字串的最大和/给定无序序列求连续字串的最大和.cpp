//��Ŀ����
//���������������У��������Ӵ����ͣ�����{ -23 17 - 7 11 - 2 1 - 34 }���Ӵ�Ϊ{ 17,-7,11 }������Ϊ21
//�������� :
//����Ϊ�������У������ÿո�ָ����磺 - 23 17 - 7 11 - 2 1 - 34
//������� :
//	���Ϊ�����е����ͣ�21
//	ʾ��1
//	����
//	- 23 17 - 7 11 - 2 1 - 34
//	���
//	21


//������Ŀ����Ϊ�������Ӵ���������Ǹ��ݵ�ǰλ���Ǵ�ͷ��������֮ǰ�������ּ���
#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
	int tmp;
	vector<int> num;
	while (cin >> tmp)
	{
		num.push_back(tmp);
	}
	int begin = 0, end = 1;
	int max = num[0], sum = num[0];
	while (end < num.size())
	{
		sum += num[end];
		if (sum < 0)
		{
			begin = end + 1;
			sum = 0;
		}
		else if (sum > max)
		{
			max = sum;
		}
		end++;
	}
	cout << max << endl;
	system("pause");
	return 0;
}
