    //三枚石子放置在数轴上，位置分别为 a，b，c。
    //每一回合，我们假设这三枚石子当前分别位于位置 x, y, z 且 x < y < z。从位置 x 或者是位置 z 拿起一枚石子，
	//并将该石子移动到某一整数位置 k 处，其中 x < k < z 且 k != y。
	//当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。
	//要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：
	//answer = [minimum_moves, maximum_moves]
	//示例 1：
	//输入：a = 1, b = 2, c = 5
	//输出：[1, 2]
	//解释：将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
	//示例 2：
	//输入：a = 4, b = 3, c = 2
	//输出：[0, 0]
	//解释：我们无法进行任何移动。


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> numMovesStones(int a, int b, int c) {
	vector<int> vec{ a, b, c };
	sort(vec.begin(), vec.end());
	int mini = 0, maxi = 0;
	int dist1 = vec[1] - vec[0] - 1;
	int dist2 = vec[2] - vec[1] - 1;
	if (dist1 == 0 || dist2 == 0)
		mini = (dist1 == dist2) ? 0 : 1;
	else if (dist1 == 1 || dist2 == 1)
		mini = 1;
	else
		mini = 2;
	maxi = dist1 + dist2;
	return { mini, maxi };
}

int main(void) {

	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	vector<int> v = numMovesStones(a, b, c);
	cout << v[0] << " " << v[1] << endl;
	system("pause");
	return 0;
}