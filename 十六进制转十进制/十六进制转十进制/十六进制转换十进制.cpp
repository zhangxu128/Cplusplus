//��Ŀ����
//д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����������ͬʱ���� ��
//�������� :
//����һ��ʮ�����Ƶ���ֵ�ַ�����
//������� :
//�������ֵ��ʮ�����ַ�����
//ʾ��1
//����
//0xA
//���
//10

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;

	while (getline(cin, str)) {
		long num = 0; int index = 16;
		for (int i = 2; i < str.size(); ++i) {
			if (str[i] >= '0' && str[i] <= '9')
				num = num * 16 + (str[i] - '0');
			else
				num = num * 16 + (str[i] - 'A' + 10);
		}
		cout << num << endl;
	}
	system("pause");
	return 0;
}