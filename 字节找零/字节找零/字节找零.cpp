//题目描述
//Z国的货币系统包含面值1元、4元、16元、64元共计4种硬币，以及面值1024元的纸币。现在小Y使用1024元的纸币购买了一件价值为
//N
//(
//	0
//	<
//	N
//	≤
//	1024
//)
//N(0 < N≤1024)的商品，请问最少他会收到多少硬币？
//	输入描述 :
//一行，包含一个数N。
//输出描述 :
//一行，包含一个数，表示最少收到的硬币数。
//示例1
//输入
//
//复制
//200
//输出
//
//复制
//17
//说明
//
//花200，需要找零824块，找12个64元硬币，3个16元硬币，2个4元硬币即可。


#include <iostream>

using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		int cnt = 0;
		int ret = 1024 - n;
		if (ret >= 64) {
			cnt += ret / 64;
			ret = ret % 64;
		}
		if (ret >= 16) {
			cnt += ret / 16;
			ret = ret % 16;
		}
		if (ret >= 4) {
			cnt += ret / 4;
			ret = ret % 4;
		}
		if(ret < 4){
			cnt += ret;
		}
		
		cout << cnt << endl;
	}

	system("pause");
	return 0;
}