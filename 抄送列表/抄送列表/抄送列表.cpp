//NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
//���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�
//�������� :
//�����ж������ݣ�ÿ�����������С�
//��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���
//�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���
//������� :
//����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!������ʾ����ʼ���Ҫ�����ȴ���
//ʾ��1
//����
//Joe, Kewell, Leon
//Joe
//"Letendre, Bruce", Joe, "Quan, William"
//William
//���
//Ignore
//Important!


#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s, res;
	while (getline(cin, s))
	{
		getline(cin, res);
		bool sta = false;
		for (int i = 0; i < s.length(); i++)
		{
			string t;
			if (s[i] == '"')
			{
				i++;
				while (i < s.length() && s[i] != '"')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
			else if (s[i] != ',')
			{
				while (i < s.length() && s[i] != ',')
				{
					t += s[i];
					i++;
				}
				if (t == res)
				{
					sta = true;
					break;
				}
			}
		}
		if (sta == true)
			cout << "Ignore" << endl;
		else
			cout << "Important!" << endl;
	}
	system("pause");
	return 0;
}