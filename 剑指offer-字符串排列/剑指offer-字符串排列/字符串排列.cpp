//题目描述
//编写一个方法，确定某字符串的所有排列组合。
//给定一个string A和一个int n, 代表字符串和其长度，请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，排列中的字符串按字典序从大到小排序。(不合并重复字符串)
//测试样例：
//"ABC"
//返回：["CBA", "CAB", "BCA", "BAC", "ACB", "ABC"]


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//注意参数res为引用类型
void dfs(string A, vector<string> &res, int cur) {
	int len = A.size();
	if (cur == len - 1) { //到最后一个字符，就插入结果
		res.push_back(A);
		return;
	}
	for (int i = cur; i < len; ++i) {
		swap(A[i], A[cur]); //交换元素
		dfs(A, res, cur + 1); //递归调用
		swap(A[i], A[cur]); //恢复
	}
}

//常规套路
vector<string> getPermutation(string A) {
	vector<string> res;
	/*if (A.empty())
		return res;*/
	dfs(A, res, 0);
	sort(res.begin(), res.end(), greater<string>()); //降序排列
	return res;
}

int main(void) {

	string str;
	cin >> str;
	vector<string> ret = getPermutation(str);

	for (auto e : ret) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}