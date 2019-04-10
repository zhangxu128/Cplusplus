#include<iostream>
using namespace std;

//在一个长度为n的数组里的所有数字都在0到n - 1的范围内。
//数组中某些数字是重复的，但不知道有几个数字是重复的。
//也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
//例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，
//那么对应的输出是第一个重复的数字2。

//思路：利用桶排序将数组排序，只要桶里的个数大于1，则改数字重复


bool duplicate(int numbers[], int length, int* duplication) {
	//桶排序
	int* tong = new int[length];
	memset(tong, 0, length * 4);
	for (int i = 0; i < length; i++) {
		cout << tong[i] << " ";
	}
	cout << endl;
	int tmp;  //保存数值
	for (int i = 0; i < length; i++) {
		tmp = numbers[i];
		tong[tmp]++;
	}//已经完成桶排序
	//找重复元素
	for (int i = 0; i < length; i++) {
		cout << tong[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < length; i++) {
		if (tong[i] > 1) {
			*duplication = i;
			return true;
		}
	}
	return false;
}

int main(void) {
	
	int num[] = {2,3,7,4,1,8,9,0,6,7};
	int size = sizeof(num) / sizeof(num[0]);
	int p = 0;
	duplicate(num, size, &p);
	cout << "数组中重复数字为：" << p << endl;
	system("pause");
	return 0;
}