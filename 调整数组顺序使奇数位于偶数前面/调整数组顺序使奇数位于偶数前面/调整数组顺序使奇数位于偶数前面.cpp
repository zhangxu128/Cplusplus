#include<iostream>
#include<vector>
using namespace std;

//题目描述
//将数组中的所有奇数放到数组的前面，数组中的偶数放到数组的后面
//并且数组中奇数或者偶数原有的相对位置不发生变化

void reOrderArray(vector<int> &array) {
	vector<int>v;
	for (size_t i = 0; i < array.size(); i++) {
		if (array[i] % 2 != 0) {
			v.push_back(array[i]);
		}
	}
	for (size_t i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0) {
			v.push_back(array[i]);
		}
	}
	array = v;
}

int main() {
	int array[] = { 1,2,3,2,2,2,5,4,2 };
	int size = sizeof(array) / sizeof(array[0]);
	vector<int> num(array, array + size);
	cout << "初始化" << endl;
	for (size_t i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	reOrderArray(num);
	cout << "数组变化之后" << endl;
	for (size_t i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}