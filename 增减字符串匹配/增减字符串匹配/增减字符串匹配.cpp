//给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
//返回[0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N - 1，都有：
//如果 S[i] == "I"，那么 A[i] < A[i + 1]
//	如果 S[i] == "D"，那么 A[i] > A[i + 1]
//	示例 1：
//	输出："IDID"
//	输出：[0, 4, 1, 3, 2]
//	示例 2：
//	输出："III"
//	输出：[0, 1, 2, 3]
//	示例 3：
//	输出："DDI"
//	输出：[3, 2, 0, 1]
//	提示：
//	1 <= S.length <= 1000
//	S 只包含字符 "I" 或 "D"。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string S)
	{
		int N = S.size();        //字符串的长度
		vector<int> a(N + 1);    //定义一个向量存放0-N排序的元素
		vector<int> b(N + 1);    //定义一个向量存放在规则下排序的0-N的元素
		int couts1 = 0;          //从向量a前面开始取元素
		int couts2 = N;          //从向量a后面开始取元素
		for (int j = 0; j < N + 1; j++) //往a中存0-N
		{
			a[j] = j;
		}
		for (int i = 0; i < N; i++)    //遍历S中的字符
		{
			if (S[i] == 'I')       //等于‘I’，则从a的前面取值赋给b
			{
				b[i] = a[couts1];
				couts1++;
			}
			else                //等于‘D’，则从a的后面取值赋给b
			{
				b[i] = a[couts2];
				couts2--;
			}
		}
		b[N] = a[couts2];   //b的最后一个元素没有数据，此时a[couts1]和a[couts2]
						  //都指向a中没有使用的最后一个元素,将其赋值给b最后一个元素
		return b;
	}
};

int main(void) {

	string s;
	cin >> s;
	Solution sol;
	vector<int> v = sol.diStringMatch(s);
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}