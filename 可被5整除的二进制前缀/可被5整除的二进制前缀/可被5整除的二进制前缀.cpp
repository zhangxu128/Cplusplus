//给定由若干 0 和 1 组成的数组 A。我们定义 N_i：
//从 A[0] 到 A[i] 的第 i 个子数组被解释为一个二进制数（从最高有效位到最低有效位）。
//返回布尔值列表 answer，只有当 N_i 可以被 5 整除时，答案 answer[i] 为 true，否则为 false。
//示例 1：
//输入：[0, 1, 1]
//输出：[true, false, false]
//解释：
//输入数字为 0, 01, 011；也就是十进制中的 0, 1, 3 。只有第一个数可以被 5 整除，因此 answer[0] 为真。
//示例 2：
//输入：[1, 1, 1]
//输出：[false, false, false]
//示例 3：
//输入：[0, 1, 1, 1, 1, 1]
//输出：[true, false, false, false, true, false]
//示例 4：
//输入：[1, 1, 1, 0, 1]
//输出：[false, false, false, false, false]

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