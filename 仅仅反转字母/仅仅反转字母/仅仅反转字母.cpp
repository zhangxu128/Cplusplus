#include<iostream>
#include <string>

using namespace std;
//����һ���ַ��� S������ ����ת��ġ� �ַ��������в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת��
//ʾ�� 1��
//���룺"ab-cd"
//�����"dc-ba"
//ʾ�� 2��
//���룺"a-bC-dEf-ghIj"
//�����"j-Ih-gfE-dCba"

class Solution {
public:
	string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right) {
			if (S[left] >= 'A'&&S[left] <= 'Z' || S[left] >= 'a'&&S[left] <= 'z') {
				if (S[right] >= 'A'&&S[right] <= 'Z' || S[right] >= 'a'&&S[right] <= 'z') {
					char tmp = S[left];
					S[left] = S[right];
					S[right] = tmp;
					left++;
					right--;
				}
				else {
					right--;
					continue;
				}
			}
			else {
				left++;
			}
		}
		return S;
	}
};
int main() {

	string str = "afa-Fff--das";
	Solution s;
	string s1 = s.reverseOnlyLetters(str);
	cout << s1 << endl;
	system("pause");
	return 0;
}