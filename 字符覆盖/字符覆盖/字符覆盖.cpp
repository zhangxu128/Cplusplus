//��Ŀ����
//С����һ��Сд��ĸ��ɵ��ַ���s.�ַ���s�Ѿ���д��ǽ����.
//С�Ȼ��кܶ࿨Ƭ, ÿ����Ƭ����һ��Сд��ĸ, ���һ���ַ���t��С�ȿ���ѡ���ַ���t������һ���ַ�, Ȼ�󸲸����ַ���s��һ���ַ�֮�ϡ�С����֪����ѡȡһЩ��Ƭ����s��һЩ�ַ�֮��, ���Եõ����ֵ��������ַ�����ʲô��
//�������� :
//�����������, ��һ��һ���ַ���s, �ַ���s����length(1 �� length �� 50), s��ÿ���ַ�����Сд��ĸ
//�ڶ���һ���ַ���t, �ַ���t����length(1 �� length �� 50), t��ÿ���ַ�����Сд��ĸ
//������� :
//���һ���ַ���, �����Եõ����ֵ�������ַ���
//ʾ��1
//����
//fedcba
//ee
//���
//feeeba



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end(), greater<char>());
	int pos = 0;
	for (int i = 0; i < s.size(); i++)
	{
		//string�ĵײ����һ���ַ���'\0'
		if (s[i] < t[pos])
		{
			s[i] = t[pos++];
		}
	}
	cout << s << endl;
	

	system("pause");
	return 0;
}
