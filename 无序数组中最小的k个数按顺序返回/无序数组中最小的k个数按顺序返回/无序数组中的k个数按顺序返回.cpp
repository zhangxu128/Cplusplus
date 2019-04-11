#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//对于一个无序数组，数组中元素为互不相同的整数，请返回其中最小的k个数，顺序与原数组中元素顺序一致。
//给定一个整数数组A及它的大小n，同时给定k，请返回其中最小的k个数。
//测试样例：
//[1, 2, 4, 3], 4, 2
//返回：[1, 2]

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