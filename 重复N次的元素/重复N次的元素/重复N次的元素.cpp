//在大小为 2N 的数组 A 中有 N + 1 个不同的元素，其中有一个元素重复了 N 次。
//返回重复了 N 次的那个元素。
//示例 1：
//输入：[1, 2, 3, 3]
//输出：3
//示例 2：
//输入：[2, 1, 2, 5, 3, 2]
//输出：2
//示例 3：
//输入：[5, 1, 5, 2, 5, 3, 5, 4]
//输出：5
//提示：
//4 <= A.length <= 10000
//0 <= A[i] < 10000
//	A.length 为偶数


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


//unordered_map 简单使用
int repeatedNTimes(vector<int>& A) {
	int size = A.size();

	unordered_map<int, int> mmap;
	for (auto& e : A) {
		mmap[e]++;
	}
	for (auto e : mmap) {
		if (e.second == size / 2) {
			return e.first;
		}
	}
	return 0;
}

int main(void) {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << repeatedNTimes(v);
	system("pause");
	return 0;
}