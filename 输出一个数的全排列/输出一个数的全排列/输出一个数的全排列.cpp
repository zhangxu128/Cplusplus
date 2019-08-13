//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//void Perm(int array[], int low, int high) {
//	if (low == high) {
//		for (int i = 0; i <= low; i++) {
//			cout << array[i] << " ";
//		}
//		cout << endl;
//	}
//	for (int i = low; i <= high; i++) {
//		swap(array[i], array[low]);
//		Perm(array, low + 1, high);
//		swap(array[i], array[low]);
//	}
//}
//
//int  main(void) {
//
//	int array[] = { 1,2,3};
//	int size = sizeof(array) / sizeof(array[0]);
//	Perm(array, 0, size - 1);
//	cout << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Perm(string s, int low, int high) {
	if (low == high) {
		cout << s << endl;
	}
	for (int i = low; i <= high; i++) {
		swap(s[i], s[low]);
		Perm(s, low + 1, high);
		swap(s[i], s[low]);
	}
}

int main(void) {
	string  s;
	while (cin >> s) {
		sort(s.begin(), s.end());
		Perm(s, 0, s.size() - 1);
		cout << endl;
	}
	system("pause");
	return 0;
}