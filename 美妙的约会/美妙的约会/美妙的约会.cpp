//题目描述
//牛牛和妞妞在一天晚上决定一起去看一场情人节演唱会，可是由于这场演唱会实在太出名了，有很多情侣都来观看，牛牛和妞妞不小心被人流冲散了！
//维持秩序的人决定，让大家排成一列，相邻两个进去的人（2k - 1和2k，k为正整数）坐在相邻座位。但是现在的队伍乱糟糟的，有很多情侣都不在相邻位置。维持秩序的人同意让情侣们跟相邻的人交换位置，直到所有情侣都在2k - 1和2k位置上为止。
//但是维持秩序的人很没有耐心，所以需要最少的交换次数，你能帮情侣们算出这个次数吗？
//输入描述 :
//第一行一个整数n，表示一共有n对情侣，编号从1到n。同一对情侣编号相同。1 <= n <= 100
//第二行2n个整数ai，表示编号为ai的情侣在第i个位置。1 <= ai <= n
//输出描述 :
//一个整数，代表最少交换次数。
//示例1
//输入
//3
//3 3 2 2 1 1
//输出
//0
//说明
//示例2
//输入
//4
//1 2 3 4 1 2 3 4
//输出
//6


#include<iostream>
using namespace std;
int main()
{
	int n_;
	cin >> n_;
	int n = 2 * n_;
	int * pos = new int[n];
	int * mark = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
		mark[i] = 1;
	}
	//3 3 2 2 1 1
 //    for(int i=0; i<n; i++)
	 //    cout<<pos[i]<<"  ";
   // cout<<endl;
	int left = 0, right, count = 0;
	while (left < n) {
		if (mark[left]) {
			mark[left] = 0;
			right = left + 1;
			while (right < n && pos[right] != pos[left])
			{
				count += mark[right];
				++right;
			}
			mark[right] = 0;
		}
		left++;
	}
	cout << count << endl;
	system("pause");
	return 0;
}