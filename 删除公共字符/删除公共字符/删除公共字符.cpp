#include<iostream>
#include <string>
#include<algorithm>


using namespace std;
//��Ŀ����
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
//�������� :
//ÿ�������������2���ַ���
//������� :
//���ɾ������ַ���


string delstr(string s1, string s2) {

	for (int i = 0; i < s2.size(); i++)
	{
		int index;
		while ((index = s1.find(s2[i])) != -1)
		{
			s1.erase(index, 1);
		}
	}
	return s1;
}
int main(void) {


	string s1;
	getline(cin, s1);
	string s2;
	getline(cin, s2);
	string s = delstr(s1, s2);
	cout << s << endl;
	system("pause");
	return 0;
}