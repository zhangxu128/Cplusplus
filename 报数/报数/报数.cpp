#include <iostream>
#include <string>

using namespace std;


//����������һ���������У��������е�������˳����б������õ���һ��������ǰ�������£�
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//6.     312211
//  1 ������  "one 1"  ("һ��һ"), �� 11��
//  11 ������ "two 1s" ("����һ"��, �� 21��
//	21 ������ "one 2", "one 1" ��"һ����", "һ��һ"), �� 1211��
//	����һ�������� n��1 �� n �� 30��������������еĵ� n �
//	ע�⣺����˳�򽫱�ʾΪһ���ַ�����
//	ʾ�� 1:
//����: 1
//	��� : "1"
//	ʾ�� 2 :
//	���� : 4
//	��� : "1211"


string countAndSay(int n) {

	if (n == 1) {
		return "1";
	}
	if (n == 2) {
		return "11";
	}
	string begin = "11";
	while (n-2) {
		string end = "";
		int flag = 0;
		//cout << begin << endl;
		for (int i = 0; i < begin.length()-1; i++) {
			int num = 1;
			while (begin[i] == begin[i + 1]&&i<begin.length()) {
				if (i + 1 == begin.length() - 1) {
					flag = 1;
				}
				num++;
				i++;
			}
			//���ڲ���ȣ��������Ӳ���
			end = end +to_string(num) + begin[i];
		}
		if (flag == 0) {
			//�����һ�����ϼ���
			char c = begin[begin.length() - 1];
			end = end + "1" + c;
		}
		begin = end;
		n--;
	}
	return begin;
}
int main(void) {
	
	int n;
	cin >> n;
	cout<<countAndSay(n)<<endl;
	system("pause");
	return 0;
}