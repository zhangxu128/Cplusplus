#include<iostream>
#include<map>

using namespace std;

//����һ���ַ����������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//
//  ʾ�� 1:
//
//  ����: "abcabcbb"
//	��� : 3
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
//	ʾ�� 2 :
//
//	���� : "bbbbb"
//	��� : 1
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
//	ʾ�� 3 :
//
//	���� : "pwwkew"
//	��� : 3
//	���� : ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
//	��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���

int max(int a, int b)
{
	return a > b ? a : b;
}

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> m;//map<character,index>
		int maxLen = 0;
		int start = 0;
		for (unsigned int i = 0; i < s.size(); i++) {
			if (m.count(s[i]) > 0) {
				start = max(start, m[s[i]] + 1); //��max��ԭ��startֻ����ǰ�ߣ����������ˡ�
			}
			maxLen = max(maxLen, i - start + 1);//��������󣬹ʼ�max��
			m[s[i]] = i; //�����Ƿ��ظ����������ַ���Ӧ���±�Ϊ����ǰ�ַ������³��ָ��ַ����±ꡣ
		}
		return maxLen;
	}
};

int main()
{
	Solution s;
	cout << s.lengthOfLongestSubstring("pwwkew") <<endl;
	system("pause");
	return 0;
}