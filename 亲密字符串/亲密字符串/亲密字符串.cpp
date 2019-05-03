//����������Сд��ĸ���ɵ��ַ��� A �� B ��
//ֻҪ���ǿ���ͨ������ A �е�������ĸ�õ��� B ��ȵĽ�����ͷ��� true �����򷵻� false ��
//ʾ�� 1��
//���룺 A = "ab", B = "ba"
//����� true
//ʾ�� 2��
//���룺 A = "ab", B = "ab"
//����� false
//ʾ�� 3:
//���룺 A = "aa", B = "aa"
//����� true
//ʾ�� 4��
//���룺 A = "aaaaaaabc", B = "aaaaaaacb"
//����� true
//ʾ�� 5��
//���룺 A = "", B = "aa"
//����� false
//��ʾ��
//0 <= A.length <= 20000
//0 <= B.length <= 20000
//A �� B ����Сд��ĸ���ɡ�

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

bool buddyStrings(string A, string B) {
	if ((A.empty() && B.empty()) || (A.length() != B.length())) {
		return false;
	}
	vector<int> vec;
	for (int i = 0; i < A.length(); i++) {
		if (A[i] != B[i]) {
			vec.push_back(i);
		}
		if (vec.size() > 2) {
			return false;
		}
	}
	if (A != B) {
		char c;
		c = A[vec[0]];
		A[vec[0]] = A[vec[1]];
		A[vec[1]] = c;
		// swap(A[vec[0]],A[vec[1]]);
		return A == B;
	}
	else {
		map<char, int> m;
		for (int j = 0; j < A.size(); j++) {
			m[A[j]]++;
			if (m[A[j]] >= 2) {
				return true;
			}
		}
		return false;
	}
	return false;
}

int main(void) {
		
	string s1;
	string s2;
	cin >> s1 >> s2;
	if (buddyStrings(s1, s2)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}