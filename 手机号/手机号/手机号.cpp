//��Ŀ����    ������ĿΪͼƬ��ʽ���޷�ճ������Ϊţ����2018����֮�ֻ���
//�������� :
//�������:
//ʾ��1
//����
//5
//13312345678
//18687654324
//18277748494
//15898494958
//45364
//���
//China Telecom
//China Unicom
//China Mobile Communications
//- 1
//- 1

#include <iostream>
#include <string>
using namespace std;

bool isTrue(string a[], string s)   //�ж�s��������a
{
	if (s.length() != 11)
	{
		return false;
	}
	string temp = s.substr(0, 3);
	for (int i = 0; i < 5; i++)
	{
		if (a[i] == temp)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string CT[] = { "133","153","180","181","189" };   //�й�����
	string CU[] = { "130","131","155","185","186" };   //�й���ͨ
	string CMC[] = { "135","136","150","182","188" };  //�й��ƶ�
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string temp;
		cin >> temp;
		if (isTrue(CT, temp))
		{
			cout << "China Telecom" << endl;
		}
		else if (isTrue(CU, temp))
		{
			cout << "China Unicom" << endl;
		}
		else if (isTrue(CMC, temp))
		{
			cout << "China Mobile Communications" << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	system("pause");
	return 0;
}