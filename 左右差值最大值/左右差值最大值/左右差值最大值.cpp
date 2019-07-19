//给定一个长度为N(N > 1)的整型数组A，可以将A划分成左右两个部分，左部分A[0..K]，
//右部分A[K + 1..N - 1]，K可以取值的范围是[0, N - 2]。求这么多划分方案中，
//左部分中的最大值减去右部分最大值的绝对值，最大是多少？

//给定整数数组A和数组的大小n，请返回题目所求的答案。
//
//测试样例：
//[2, 7, 3, 1, 1], 5
//返回：6


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