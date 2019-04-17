#include <iostream>
using namespace std;


//题目描述
//游戏里面有很多各式各样的任务，其中有一种任务玩家只能做一次，
//这类任务一共有1024个，任务ID范围[1, 1024]。请用32个unsigned int类型来记录着1024个任务是否已经完成。
//初始状态都是未完成。 输入两个参数，都是任务ID，需要设置第一个ID的任务为已经完成；
//并检查第二个ID的任务是否已经完成。 输出一个参数，
//如果第二个ID的任务已经完成输出1，如果未完成输出0。如果第一或第二个ID不在[1, 1024]范围，则输出 - 1。

int main() {
	//位图   用来做标记
	unsigned int task_flag[32] = { 0 };

	int id1, id2;
	while (cin >> id1 >> id2) {  //输入的合法性检验
		if (id1 > 1024 || id1 < 1 || id2 > 1024 || id2 < 1) {
			cout << -1 << endl;
			break;
		}

		int index = (id1 - 1) / 32;
		int bit = (id1 - 1) % 32;
		task_flag[index] |= 1 << bit;         // 设置任务

		index = (id2 - 1) / 32;
		bit = (id2 - 1) % 32;
		//cout << (1 << bit & task_flag[index]) << endl;  简洁写法
		if (1 << bit & task_flag[index]) {    // 检查任务
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}