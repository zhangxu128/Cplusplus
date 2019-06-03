//我们规定：幸运袋子里面的球的值加起来大于它的积
// 例如 ： 1 1 2 3 
//    和   7
//    积   6
//  我们称这种袋子为幸运袋子，现在要求我们可以从袋中移除小球
//  让其变成幸运袋子，可以移0个   问有多少种移法

//输入  第一行  袋子里小球的数量
//      第二行  小球的值

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Lucky(vector<int>v, int index, int sum, int mul) {
	int cnt = 0;
	for (int i = index; i < v.size(); i++) {
		sum += v[i];
		mul *= v[i];
		if (sum > mul) {
			cnt += 1 + Lucky(v, i + 1, sum, mul);
		}
		else if (v[i] == 1) {
			cnt += Lucky(v, i + 1, sum, mul);
		}
		else {  //不幸运
			break;
		}
		sum -= v[i];
		mul /= v[i];
		for (; i < v.size() - 1 && v[i] == v[i + 1]; i++);//相同号码跳过

	}
	return cnt;
}

int main() {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int method = Lucky(v, 0, 0, 1);

	cout << method << endl;
	system("pause");
	return 0;
}