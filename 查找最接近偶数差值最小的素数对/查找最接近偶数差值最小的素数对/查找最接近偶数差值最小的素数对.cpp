#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {

	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {

	int n;
	while (cin >> n) {
		int i = n / 2;
		int j = n / 2;
		while (true) {
			if (isprime(i) && isprime(j) && i + j == n) {
				break;
			}
			else {
				i--;
				j++;
			}
		}
		cout << i << endl;
		cout << j << endl;
	}
	system("pause");
	return 0;
}