#include<iostream>
#include<string>
#include<map>
using namespace std;

//�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��
//	�ַ�          ��ֵ
//	I             1
//	V             5
//	X             10
//	L             50
//	C             100
//	D             500
//	M             1000
//	���磬 �������� 2 д�� II ����Ϊ�������е� 1��12 д�� XII ����Ϊ X + II �� 
//	27 д��  XXVII, ��Ϊ XX + V + II ��
//	ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ��������
//    ���� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�
//	����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX��
//	�������Ĺ���ֻ�������������������
//	I ���Է��� V(5) �� X(10) ����ߣ�����ʾ 4 �� 9��
//	X ���Է��� L(50) �� C(100) ����ߣ�����ʾ 40 �� 90��
//	C ���Է��� D(500) �� M(1000) ����ߣ�����ʾ 400 �� 900��
//	����һ���������֣�����ת��������������ȷ���� 1 �� 3999 �ķ�Χ�ڡ�

class Solution {
public:
	int romanToInt(string s) {

		map<char, int> dict;
		dict['I'] = 1;
		dict['V'] = 5;
		dict['X'] = 10;
		dict['L'] = 50;
		dict['C'] = 100;
		dict['D'] = 500;
		dict['M'] = 1000;
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (dict[s[i]] < dict[s[i + 1]]) res -= dict[s[i]];
			else res += dict[s[i]];
		}
		return res;
	}
};

int main()
{
	string s;
	cin >> s;
	Solution ans;
	cout << ans.romanToInt(s) << endl;
	system("pause");
	return 0;
}