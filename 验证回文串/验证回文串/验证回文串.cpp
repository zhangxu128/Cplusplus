#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��
//˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���
//  ʾ�� 1:
//  ����: "A man, a plan, a canal: Panama"
//	��� : true
//	ʾ�� 2 :
//	���� : "race a car"
//	��� : false

//��֤���Ĵ�
bool isPalindrome(string s) {
	string str = s;
	int x = 0;
	int y = str.length() - 1;
	int flag = 0;
	while (x < y) {
		if (!((str[x] >= 'a'&&str[x] <= 'z') || (str[x] >= 'A'&&str[x] <= 'Z') || (str[x] >= '0'&&str[x] <= '9'))) {//�������ֻ���
			x++;
			continue;
		}
		if (!((str[y] >= 'a'&&str[y] <= 'z') || (str[y] >= 'A'&&str[y] <= 'Z') || (str[y] >= '0'&&str[y] <= '9'))) {//�������ֻ���
			y--;
			continue;
		}
		if (str[x] >= 'a'&&str[x] <= 'z') {
			str[x] -= 32;
		}
		if (str[y] >= 'a'&&str[y] <= 'z') {
			str[y] -= 32;
		}
		if (str[x] != str[y]) {
			return false;
		}
		x++;
		y--;
	}
	return true;
}


int main()
{
	string str;
	cin >> str;
	cout << isPalindrome(str) << endl;
	system("pause");
	return 0;
}