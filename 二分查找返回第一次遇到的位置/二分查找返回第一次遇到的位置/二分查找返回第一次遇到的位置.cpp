#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//����һ���������飬����ͨ�����ö��ֲ��ҵķ�ʽ����λĳһԪ�أ����д���ֲ��ҵ��㷨���������в���ָ��Ԫ�ء�
//����һ����������A�����Ĵ�Сn��ͬʱ����Ҫ���ҵ�Ԫ��val���뷵�����������е�λ��(��0��ʼ)���������ڸ�Ԫ�أ�
//���� - 1������Ԫ�س��ֶ�Σ��뷵�ص�һ�γ��ֵ�λ�á�
//����������
//[1, 3, 5, 7, 9], 5, 3
//���أ�1
int getPos(vector<int> A, int n, int val) {
	// write code here
	int left = 0;
	int right = A.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (A[mid] == val) {
			if (mid > 0) {
				while (A[mid] == val) {
					if (mid == 0) {
						return mid;
					}
					mid--;
				}
				return mid + 1;
			}
			return mid;
		}
		else if (A[mid] > val) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}
int main() {
	int a[] = { 1,2,2,3,5,7,9 };
	vector<int>v(a,a+7);
	cout << getPos(v,7,2) << endl;
	system("pause");
	return 0;
}