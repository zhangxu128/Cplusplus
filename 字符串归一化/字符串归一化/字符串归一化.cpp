//��Ŀ����
//ͨ����������һ��Сд��ĸ(a~z)��ɵ��ַ�����
//���дһ���ַ�����һ������ͳ���ַ�������ͬ�ַ����ֵĴ����������ֵ�������ַ�������ִ�����
//�����ַ���"babcc"��һ����Ϊ"a1b2c2"
//��������:
//ÿ����������ÿ��Ϊһ���ַ�������'\n'��β������cccddecca
//������� :
//���ѹ������ַ���ac5d2e
//ʾ��1
//����
//dabcab
//���
//a2b2c1d1

#include <iostream>
#include<stdio.h>
#define SIZE 128
using namespace std;
int main() {
	int cnt[26] = { 0 }, i = 0;
	char a[SIZE];
	fgets(a, SIZE, stdin);
	while (a[i] != '\n')
	{
		cnt[a[i] - 'a']++;
		i++;
		if (i == SIZE) {
			i = 0;
			fgets(a, SIZE, stdin);
		}
	}
	for (int i = 0; i < 26; i++)
		if (cnt[i] != 0)
			cout << (char)(i + 'a') << cnt[i];
	system("pause");
	return 0;
}
