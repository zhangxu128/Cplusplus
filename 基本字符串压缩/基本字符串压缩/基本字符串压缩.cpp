//��Ŀ����
//�����ַ��ظ����ֵĴ�������дһ��������ʵ�ֻ������ַ���ѹ�����ܡ�
//���磬�ַ�����aabcccccaaa����ѹ�����ɡ�a2b1c5a3������ѹ������ַ���û�б�̣��򷵻�ԭ�ȵ��ַ�����
//����һ��string iniStringΪ��ѹ���Ĵ�(����С�ڵ���10000)��
//��֤�����ַ����ɴ�СдӢ����ĸ��ɣ�����һ��string��Ϊ�����ѹ�����δ�仯�Ĵ���
//��������
//"aabcccccaaa"
//���أ�"a2b1c5a3"
//"welcometonowcoderrrrr"
//���أ�"welcometonowcoderrrrr"


#include <iostream>
#include <string >

using namespace std;

string zipString(string iniString) {
	// write code here
	string str;
	int i = 0, j = 0;
	while (i < iniString.length()) {
		while (iniString[i] == iniString[j]) i++;
		str += iniString[j];
		str += to_string(i - j);
		j = i;
	}
	if (iniString.length() < str.length()) 
		return iniString;
	else 
		return str;
}

int main(void) {

	string s;
	cin >> s;
	cout << zipString(s) << endl;

	system("pause");
	return 0;
}