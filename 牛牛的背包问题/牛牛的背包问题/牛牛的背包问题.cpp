//题目描述
//牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
//牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
//牛牛想知道在总体积不超过背包容量的情况下, 他一共有多少种零食放法(总体积为0也算一种放法)。
//输入描述 :
//输入包括两行
//第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10 ^ 9), 表示零食的数量和背包的容量。
//第二行n个正整数v[i](0 <= v[i] <= 10 ^ 9), 表示每袋零食的体积。
//输出描述 :
//输出一个正整数, 表示牛牛一共有多少种零食放法。
//示例1
//输入
//
//复制
//3 10
//1 2 4
//输出
//
//复制
//8
//说明
//
//三种零食总体积小于10, 于是每种零食有放入和不放入两种情况，一共有2 * 2 * 2 = 8种情况。



//背包问题1

//F[i][j] 当重量为j的时候，可以放入前i个商品的最大价值
// F[i][j] :  w[i] > j  F[i-1][j]
//                           //不放入  //腾出空间，放入商品     
//            w[i] <= j, max(F[i-1][j],F[i-1][j-w[i]+v[i]])

//初始状态  F[0][j] = 0  F[i][0] = 0;  求F[n][m]


//背包问题2
//其中，表示第i个放入还是不放入，设state(i, w)表示i个零食放入背包小于等于W的个数，把state(i, w)分解，可以分解为两个情况：
//1、是第i个不放入时，前i - 1个零食放入背包小于等于W的个数即state(i - 1, w)；
//2、是在第i个放入的情况下，前i - 1个零食放入背包体积小于等于W - v[i]的个数即state(i - 1, w - v[i]);
//即               state(i, w) = state(i - 1, w) + state(i - 1, w - v[i])
//边界条件：i = 1时，state(1, w1) 此时如果w1 > 0 且v[1] <= w1, state(1, w1) = 2, 即有可放入和不放入两种；
//i = 1 时，swate(1, w1)此时如果w1 > 0且v[1] > w1, state(1, w1) = 1, 即只有不放入一种；
//如果state(i, w)中出现w <= 0, 则state(i, w) = 0;

#include<iostream>
#include <vector>


using namespace std;
long long sum = 0;
void bag(int count, long long weight, int arr[], int pos, const int w, const int n)
{
	if (weight > w) return;
	if (pos > n || pos < 0) return;
	if (pos == n)
	{
		sum++;
	}
	bag(++count, weight + arr[pos], arr, pos + 1, w, n);
	bag(count, weight, arr, pos + 1, w, n);
}

int main()
{
	int n;
	long long w;
	cin >> n >> w;
	int* arr = new int[n];
	long long count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		count += arr[i];
	}
	if (count <= w)
	{
		sum = (pow(2, n));
		cout << sum;
		return 0;
	}
	bag(0, 0, arr, 0, w, n);
	cout << sum;
	system("pause");
	return 0;
}