#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����һ���������飬������Ԫ��Ϊ������ͬ���������뷵��������С��k������˳����ԭ������Ԫ��˳��һ�¡�
//����һ����������A�����Ĵ�Сn��ͬʱ����k���뷵��������С��k������
//����������
//[1, 2, 4, 3], 4, 2
//���أ�[1, 2]

class KthNumbers {
public:
	vector<int> findKthNumbers(vector<int> A, int n, int k) {
		vector<int> v = A;
		vector<int> r;
		sort(v.begin(), v.end());
		for (int i = 0; i < A.size(); i++) {
			if (A[i] <= v[k - 1]) {
				r.push_back(A[i]);
			}
		}
		return r;
	}
};

int main(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(3);
	int n = v.size();
	int kk = 2;
	KthNumbers k;
	vector<int> ret = k.findKthNumbers(v, n, kk);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}