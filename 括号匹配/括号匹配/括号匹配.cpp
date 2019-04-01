#include<iostream>
#include<string>
#include<stack>
using namespace std;

//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
//
//��Ч�ַ��������㣺
//
//�����ű�������ͬ���͵������űպϡ�
//�����ű�������ȷ��˳��պϡ�
//ע����ַ����ɱ���Ϊ����Ч�ַ�����

bool isValid(string s) {
	if (s.empty())
	{
		return true;
	}
	if (s.size() % 2 != 0)
	{
		return false;
	}
	stack<char> c;
	if (s[0] == ')' || s[0] == ']' || s[0] == '}')return false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			c.push(s[i]);
		}
		else if((s[i]==')'&&c.top()=='(') || (s[i] == ']'&&c.top() == '[') || (s[i] == '}'&&c.top() == '{'))
		{
			c.pop();
		}
		else
		{
			return false;
		}
	}
	if (c.empty()) {
		return true;
	}
	return false;
}

int main()
{
	string s;
	cin >> s;
	cout << isValid(s) << endl;
	system("pause");
	return 0;
}