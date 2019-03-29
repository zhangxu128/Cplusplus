#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{ 1,2,3,2,2,2,5,4,2 }。由于数字2在数组中出现了5次，
//超过数组长度的一半，因此输出2。如果不存在则输出0。

int MoreThanHalfNum_Solution(vector<int> numbers) {
	int count = 1;
	if (numbers.size() == 1) {
		return numbers[0];
	}
	sort(numbers.begin(), numbers.end());
	int i = 0;
	for (; i < numbers.size() - 1; i++) {
		if (numbers[i] == numbers[i + 1]) {
			count++;
			if (count > numbers.size() / 2) {
				break;
			}
			continue;
		}
		else {
			count = 1;
		}
	}
	if (count > numbers.size() / 2) {
		return numbers[i];
	}
	return 0;
}

int main() {
	int array[] = { 1,2,3,2,2,2,5,4,2 };
	int size = sizeof(array) / sizeof(array[0]);
	vector<int> num(array, array + size);
	cout << MoreThanHalfNum_Solution(num) << endl;
	system("pause");
	return 0;
}