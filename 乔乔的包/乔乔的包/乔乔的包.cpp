//题目描述
//玥玥带乔乔一起逃亡，现在有许多的东西要放到乔乔的包里面，但是包的大小有限，所以我们只能够在里面放入非常重要的物品。现在给出该种物品的数量、体积、价值的数值，希望你能够算出怎样能使背包的价值最大的组合方式，并且输出这个数值，乔乔会非常感谢你。
//输入描述 :
//第1行有2个整数，物品种数n和背包装载体积v；
//第2行到i + 1行每行3个整数，为第i种物品的数量m、体积w、价值s。
//输出描述 :
//仅包含一个整数，即为能拿到的最大的物品价值总和。
//示例1
//输入
//2 10
//3 4 3
//2 2 5
//输出
//13


#include<iostream>
#include<cmath>
using namespace std;
int dp[2005], m[2005], w[2005], s[2005];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, v;
	cin >> n >> v;
	for (int i = 1; i <= n; i++) {
		cin >> m[i] >> w[i] >> s[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = v; j >= w[i]; j--)
			for (int k = 1; k <= m[i] && k*w[i] <= j; k++) {
				dp[j] = max(dp[j], dp[j - k * w[i]] + k * s[i]);
			}
	cout << dp[v] << endl;
	return 0;
}