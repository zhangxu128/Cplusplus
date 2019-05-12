#include <iostream>

using namespace std;

/*给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。

注意 :

给定的整数保证在32位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
示例 1 :

	输入 : 5
	输出 : 2
	解释 : 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
	示例 2 :

	输入 : 1
	输出 : 0
	解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
*/


//没有前导0，这个就比较简单了，按照%2的方式取余
//只要余数为0，则要取反求值，当然还得一个计数器
//记录当前位置

int findComplement(int num) {
	int sum = 0;
	int cnt = 0;
	while (num != 0) {
		int tmp = num % 2;
		if (tmp != 1) {
			sum += pow(2, cnt);
		}
		num /= 2;
		cnt++;
	}
	return sum;
}

int main(void) {

	cout << "请输入一个数字" << endl;
	int num;
	cin >> num;
	cout << "这个数字的补数是：" << findComplement(num) << endl;
	system("pause");
	return 0;
}