//二货小易有一个W*H的网格盒子，网格的行编号为0~H - 1，网格的列编号为0~W - 1。
//每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
//对于两个格子坐标(x1, y1), (x2, y2)的欧几里得距离为:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) 的算术平方根
//小易想知道最多可以放多少块蛋糕在网格盒子里。

//其实就是一个数学问题，分整除4，整除2，奇数等几种情况讨论即可。
//蛋糕位置就是间隔每个2 * 2的正方形的区域。

#include<iostream>
using namespace std;


int main() {

	int W, H, counts = 0;

	cin >> W >> H;

	if (W % 4 == 0 || H % 4 == 0) {

		counts = W * H / 2;

	}
	else if (W % 2 == 0 && H % 2 == 0) {

		counts = (W*H / 4 + 1) * 2;

	}
	else {

		counts = W * H / 2 + 1;

	}

	cout << counts << endl;
	
	system("pause");
	return 0;

}
