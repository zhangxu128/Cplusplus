#include<iostream>
#include<string>
using namespace std;
//����һ���ַ���������һ��ѧ���ĳ��ڼ�¼�������¼���������������ַ���
//'A' : Absent��ȱ��
//'L' : Late���ٵ�
//'P' : Present������
//���һ��ѧ���ĳ��ڼ�¼�в�����һ��'A'(ȱ��)���Ҳ���������������'L'(�ٵ�), ��ô���ѧ���ᱻ���͡�
//����Ҫ�������ѧ���ĳ��ڼ�¼�ж����Ƿ�ᱻ���͡�
//  ʾ�� 1 :
//	���� : "PPALLP"
//	��� : True
//	ʾ�� 2 :
//	���� : "PPALLL"
//	��� : False

class Solution {
public:
	
	bool checkRecord(string s) {
		int a = 0, c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'A')a++;
			if (a > 1)return false;
			if (s[i] == 'L')c++;
			if (c > 2)return false;
			if (s[i] != 'L')c = 0;
		}
		return true;
	}
};

int main()
{
	string str;
	cin >> str;
	Solution s;
	cout<< s.checkRecord(str) << endl;
	system("pause");
	return 0;
}