//输入N，求N！末尾的第一个非零数字。如6 != 720，因此6的阶乘末尾的非零位是2。



//求阶乘最后非零位,复杂度O(nlogn)  
//返回该位,n以字符串方式传入  5!=120 返回值为2  
#include <iostream>  

using namespace std;

#define MAXN 10000  
char c[MAXN];
int lastdigit(char* buf) {

	const int mod[20] = { 1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2 };
	int len = strlen(buf), a[MAXN], i, c, ret = 1;

	if (len == 1)
		return mod[buf[0] - '0'];
	for (i = 0; i < len; i++)
		a[i] = buf[len - 1 - i] - '0';
	for (; len; len -= !a[len - 1]) {
		ret = ret * mod[a[1] % 2 * 10 + a[0]] % 5;
		for (c = 0, i = len - 1; i >= 0; i--)
			c = c * 10 + a[i], a[i] = c / 5, c %= 5;
	}
	return ret + ret % 2 * 5;


}

int main() {

	while (cin >> c) {
		int result = lastdigit(c);

		cout << result << endl;


	}


	return 0;

}