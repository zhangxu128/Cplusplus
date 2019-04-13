#include<iostream>
#include<vector>
using namespace std;

//�Գ��� ��ָ���Ա���������ÿһλ������������
//���磬128 ��һ���Գ�������Ϊ 128 % 1 == 0��128 % 2 == 0��128 % 8 == 0��
//���У��Գ������������ 0 ��
//�����ϱ߽���±߽����֣����һ���б��б��Ԫ���Ǳ߽磨���߽磩�����е��Գ�����
//ʾ�� 1��
//���룺
//�ϱ߽�left = 1, �±߽�right = 22
//�����[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
//ע�⣺
//ÿ����������ı߽����� 1 <= left <= right <= 10000��

class Solution {
public:
	bool isitdiv(int n) {    //�ж�������ǲ����Գ���
		if (n > 0 && n < 10) {
			return true;
		}
		int k = n;
		while (k != 0) {
			int t = k % 10;    //22   2
			if (t == 0) {
				return false;
			}
			if (n % t == 0) {
				k /= 10; //   2
			}
			else {
				return false;
			}
		}
		return true;
	}
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> v;
		for (int i = left; i <= right; i++) {   //�����Գ��������������
			if (isitdiv(i)) {
				v.push_back(i);
			}
		}
		return v;
	}
};
int main(void) {
	vector<int>v;
	int left = 1;
	int right = 22;
	Solution s;
	v = s.selfDividingNumbers(left, right);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}