#include<iostream>
#include<string>
using namespace std;

//ʵ�� strStr() ������
//����һ�� haystack �ַ�����һ�� needle �ַ�����
//�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ��(��0��ʼ)
//��������ڣ��򷵻� - 1��
//ʾ�� 1:
//  ����: haystack = "hello", needle = "ll"
//	��� : 2
//	ʾ�� 2 :
//	���� : haystack = "aaaaa", needle = "bba"
//	��� : -1

class Solution {
public:
	int strStr(string haystack, string needle) {
		//�����ĺϷ��Լ���
		if (needle.size() == 0) {
			return 0;
		}
		if (haystack.size() < needle.size()) {
			return -1;
		}
		int j = 0;// ����needle�ַ���
		int i = 0;//����haystack���ַ���
		//�������ַ�����������û����ͬ��һ��Ԫ��
		for (i = 0; i < haystack.size(); i++) {
			//�������ַ�����������û����ͬ��һ��Ԫ��
			if (j == needle.size()) {
				return i - needle.size();
			}
			if (haystack[i] == needle[j]) {
				j++;
			}
			else {
				i -= j;
				j = 0;
			}
		}
		if (j == needle.size()) {
			return i - needle.size();
		}
		return -1;
	}
};

int main(){
	string s1 = "hello";
	string s2 = "ll";
	Solution s;
	cout << s.strStr(s1, s2) << endl;
	system("pause");
	return 0;
}