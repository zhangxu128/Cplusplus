//��Ŀ
//NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
//���ڸ���һ���ռ����������������������Ӧ���ռ����б�
//�������� :
//��������������ݡ�
//ÿ�����ݵĵ�һ����һ������n(1��n��128)����ʾ������n��������
//������n�У�ÿһ�а���һ���ռ��˵��������������Ȳ�����16���ַ���
//������� :
//��Ӧÿһ�����룬���һ���ռ����б�
//ʾ��1
//����
//3
//Joe
//Quan, William
//Letendre, Bruce
//2
//Leon
//Kewell
//���
//Joe, "Quan, William", "Letendre,Bruce"
//Leon, Kewell

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cin.get();
		string name;
		for (int i = 0; i < n; i++)
		{
			getline(cin, name);
			if (i != n - 1)
			{
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << ',' << ' ';
				else
					cout << name << ',' << ' ';
			}
			else
			{
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << endl;
				else
					cout << name << endl;
			}
		}
	}
	return 0;
}