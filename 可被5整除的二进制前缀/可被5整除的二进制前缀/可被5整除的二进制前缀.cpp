//���������� 0 �� 1 ��ɵ����� A�����Ƕ��� N_i��
//�� A[0] �� A[i] �ĵ� i �������鱻����Ϊһ�������������������Чλ�������Чλ����
//���ز���ֵ�б� answer��ֻ�е� N_i ���Ա� 5 ����ʱ���� answer[i] Ϊ true������Ϊ false��
//ʾ�� 1��
//���룺[0, 1, 1]
//�����[true, false, false]
//���ͣ�
//��������Ϊ 0, 01, 011��Ҳ����ʮ�����е� 0, 1, 3 ��ֻ�е�һ�������Ա� 5 ��������� answer[0] Ϊ�档
//ʾ�� 2��
//���룺[1, 1, 1]
//�����[false, false, false]
//ʾ�� 3��
//���룺[0, 1, 1, 1, 1, 1]
//�����[true, false, false, false, true, false]
//ʾ�� 4��
//���룺[1, 1, 1, 0, 1]
//�����[false, false, false, false, false]

#include <iostream>
#include <vector>
using namespace std;


vector<bool> prefixesDivBy5(vector<int>& A) {
	vector<bool> res;
	int a = 0;
	for (int i = 0; i < A.size(); ++i) {
		a = (a << 1) + A[i];   // 40ms: a*2+A[i]                 24ms: (a<<1)+A[i]
		a = a % 5;
		res.push_back(0 == a);
	}
	return res;
}

void print(vector<bool> v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {

	vector<int> v;
	int num;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<bool> b = prefixesDivBy5(v);
	print(b);
	system("pause");
	return 0;
}