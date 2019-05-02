//����һ���������� A������ֻ�������·����޸ĸ����飺����ѡ��ĳ�������� i
//���� A[i] �滻Ϊ - A[i]��Ȼ���ܹ��ظ�������� K �Ρ������ǿ��Զ��ѡ��ͬһ������ i����
//�����ַ�ʽ�޸�����󣬷���������ܵ�����
//ʾ�� 1��
//���룺A = [4, 2, 3], K = 1
//�����5
//���ͣ�ѡ������(1, ) ��Ȼ�� A ��Ϊ[4, -2, 3]��
//ʾ�� 2��
//���룺A = [3, -1, 0, 2], K = 3
//�����6
//���ͣ�ѡ������(1, 2, 2) ��Ȼ�� A ��Ϊ[3, 1, 0, 2]��
//ʾ�� 3��
//���룺A = [2, -3, -1, 5, -4], K = 2
//�����13
//���ͣ�ѡ������(1, 4) ��Ȼ�� A ��Ϊ[2, 3, -1, 5, 4]��
//��ʾ��
//1 <= A.length <= 10000
//1 <= K <= 10000
//- 100 <= A[i] <= 100

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
using namespace std;

int largestSumAfterKNegations(vector<int>& A, int K) {
	multiset<int> setA(A.begin(), A.end());
	while (K--)
	{
		int temp = *setA.begin();
		setA.erase(setA.begin());
		setA.insert(-temp);
	}
	return accumulate(setA.begin(), setA.end(), 0);

}

int main(void) {

	int n;
	cin >> n;

	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	int k;
	cin >> k;

	int ret = largestSumAfterKNegations(v,k);
	cout << ret << endl;
	system("pause");
	return 0;
}