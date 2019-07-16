// write your code here cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {

	string A, B;
	while (cin >> A >> B) {
		int *arrA = new int[26];
		int *arrB = new int[26];

		for (int i = 0; i < A.size(); i++) {
			arrA[A[i] - 'A']++;
		}

		for (int i = 0; i < B.length(); i++) {
			arrB[B[i] - 'A']++;
		}

		bool flag = true;
		for (int i = 0; i < 26; i++) {
			if (arrA[i] < arrB[i]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}

	return 0;
}