//����һ������ΪN(N > 1)����������A�����Խ�A���ֳ������������֣��󲿷�A[0..K]��
//�Ҳ���A[K + 1..N - 1]��K����ȡֵ�ķ�Χ��[0, N - 2]������ô�໮�ַ����У�
//�󲿷��е����ֵ��ȥ�Ҳ������ֵ�ľ���ֵ������Ƕ��٣�

//������������A������Ĵ�Сn���뷵����Ŀ����Ĵ𰸡�
//
//����������
//[2, 7, 3, 1, 1], 5
//���أ�6


#include <iostream>
#include <vector>

using namespace std;

int findMaxGap(vector<int> A, int n) {
	// write code here

	int max = A[0];
	int min;
	for (int i = 1; i < n; i++) {
		if (max < A[i]) {
			max = A[i];
		}
	}
	min = A[0] > A[n - 1] ? A[n - 1] : A[0];
	return max - min;
}


int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << findMaxGap(v,n) << endl;

	system("pause");
	return 0;
}