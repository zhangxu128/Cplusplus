//��Ŀ����
//����һ������Сд��ĸ��ɵ��ַ������������ҳ�һ��λ�ã�ɾ���Ǹ���ĸ֮���ַ�����ɻ��ġ�������ܻ���һ���Ϸ��Ľ⡣����������ַ����Ѿ���һ�����Ĵ�����ô��� - 1��
//�������� :
//��һ�а���T���������ݵ��������������T�У�ÿ�а���һ���ַ�����
//������� :
//�������ɾȥһ����ĸʹ����ɻ��Ĵ������������һ������������ɾȥ��ĸ��λ�ã��±��0��ʼ�������磺
//bcc
//���ǿ���ɾ��λ��0��b�ַ���
//ʾ��1
//����
//3
//aaab
//baa
//aaa
//���
//3
//0
//- 1

#include<iostream>
#include <algorithm>
#include<string>
using namespace std;
int main() {
	string str, str1, str2;
	int n;
	cin >> n;
	while (n--)
	{
		cin >> str;
		str1 = str;
		str2 = str;
		reverse(str1.begin(), str1.end());
		int i = 0;
		if (str1 != str2) {

			do {
				str1 = str;
				str2 = str;
				str2.erase(i++, 1);
				str1 = str2;
				reverse(str1.begin(), str1.end());
			} while (str1 != str2);
			cout << i - 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}

