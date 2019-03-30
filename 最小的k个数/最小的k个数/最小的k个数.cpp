#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//题目描述
//输入n个整数，找出其中最小的K个数。例如输入4, 5, 1, 6, 2, 7, 3, 8这8个数字
//，则最小的4个数字是1, 2, 3, 4, 。

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	sort(input.begin(), input.end());
	vector<int>v;
	if (input.size() < k) {
		input.resize(0);
		return input;
	}
	for (int i = 0; i < k; i++) {
		v.push_back(input[i]);
	}
	return v;
}

void print(vector<int> v) {
	for (int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	int array[] = { 4,5,1,6,2,7,3,8};
	int size = sizeof(array) / sizeof(array[0]);
	vector<int> num(array, array + size);
	int k;
	cin >> k;
	vector<int> v = GetLeastNumbers_Solution(num,k);
	print(v);
	system("pause");
	return 0;
}