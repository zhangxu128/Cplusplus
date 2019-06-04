#include <iostream>
#include <vector>

using namespace std;

int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int ret1 = 0;
	int ret2 = 0;
	int leftsum = 27;
	int rightsum = 27;
	for (int i = 0; i < n; i++) {
		if (left[i] == 0) {
			ret1 = ret1 + right[i];
		}
		else {
			ret1 = ret1 + left[i];
		}
		if (right[i] == 0) {
			ret2 = ret2 + left[i];
		}
		else {
			ret2 = ret2 + right[i];
		}
		if (left[i] != 0 && right[i] != 0 && left[i] < leftsum) {
			leftsum = left[i];
		}
		if (right[i] != 0 && left[i] != 0 && right[i] < rightsum) {
			rightsum = right[i];
		}
	}
	ret1 = ret1 - (leftsum - 1) + 1;
	ret2 = ret2 - (rightsum - 1) + 1;
	return (ret1 < ret2) ? ret1 : ret2;
}

int main(void) {
	int n;
	cin >> n;
	vector<int>left(n);
	for (int i = 0; i < n; i++) {
		cin >> left[i];
	}
	vector<int>right(n);
	for (int i = 0; i < n; i++) {
		cin >> right[i];
	}
	cout << findMinimum(n, left, right) << endl;
	system("pause");
	return 0;
}