#include<iostream>
#include<vector>
using namespace std;

//����һ���ַ��� S ��һ���ַ� C������һ�������ַ��� S ��ÿ���ַ����ַ��� S �е��ַ� C ����̾�������顣
//ʾ�� 1:
//  ����: S = "loveleetcode", C = 'e'
//	��� : [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
//	˵�� :
//	�ַ��� S �ĳ��ȷ�ΧΪ[1, 10000]��
//	C ��һ�����ַ����ұ�֤���ַ��� S ����ַ���
//	S �� C �е�������ĸ��ΪСд��ĸ��

class Solution {
public:
	int min(int i, int j) {
		return i < j ? i : j;
	}
	vector<int> shortestToChar(string S, char C) {
		int *array = new int[S.size()]{ 0 };
		int preC = -1;
		//���ҵ� C ��λ��, �ٶ� C ǰ���λ�ø�ֵ
		for (int i = 0; i < S.size(); i++) {
			if (C == S[i]) {
				int j = i - 1;
				for (; j > preC; j--) {
					array[j] = preC == -1 ? i - j : min(j - preC, i - j);
				}
				preC = i;
			}
		}
		//���һ�� C �����λ�ø�ֵ
		for (int i = preC + 1; i < S.size(); i++) {
			array[i] = i - preC;
		}
		vector<int>v(array, array + S.size());
		return v;
	}
};

int main() {

	string str = "abdfajf";
	char c = 'f';
	Solution s;
	vector<int> v = s.shortestToChar(str, c);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}