//题目描述
//请设计一个高效算法，找出数组中两数之和为指定值的所有整数对。
//给定一个int数组A和数组大小n以及需查找的和sum，请返回和为sum的整数对的个数。保证数组大小小于等于3000。
//测试样例：
//[1, 2, 3, 4, 5], 5, 6
//返回：2

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int countPairs(vector<int> A, int n, int sum) {
	// write code here
	int c = 0;
	for (int i = 0, j; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (A[i] + A[j] == sum)
				c++;
		}
	}
	return c;
}



//int countPairs(vector<int> A, int n, int sum) {
//	map<int, int> M;
//	for (int i = 0; i < n; i++)
//		M[A[i]]++;
//	int cnt = 0;
//	for (int i = 0; i < n; i++) {
//		int t = sum - A[i];
//		if (M[A[i]] != 0) { 
//			if (A[i] == t)      
//				cnt += M[t] * (M[t] - 1) / 2;                
//			else if (M.find(t) != M.end() && M[t] != 0)              
//				cnt += M[A[i]] * M[t];               
//			M[A[i]] = M[t] = 0; 
//		}
//	}   
//	return cnt;
//}

int main(void) {
	int n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> n;
	}
	int k;
	cin >> k;
	cout << countPairs(A, n, k) << endl;

	system("pause");
	return 0;
}