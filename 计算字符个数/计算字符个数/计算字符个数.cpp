//��Ŀ����
//д��һ�����򣬽���һ������ĸ��������ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��
//�������� :
//����һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���
//������� :
//��������ַ����к��и��ַ��ĸ�����
//ʾ��1
//����
//ABCDEF A
//���
//1

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main(void) {

	string s;  //�����ַ���
	char c;    // �����ַ�

	cin >> s >> c;

	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (((s[i]>='a'&& s[i] <= 'z')|| (s[i] >= 'A'&& s[i] <= 'Z')) && ((s[i] == c) || (s[i]==c+32) || (s[i] == c-32))) {
			cnt++;
		}
	}
	cout << cnt << endl;
	system("pause");
	return 0;
}