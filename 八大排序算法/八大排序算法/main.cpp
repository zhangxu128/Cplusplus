
#include <iostream>
#include "bubble.h"
#include "select.h"
#include "insert.h"
#include "shell.h"
#include "quick.h"
#include "merge.h"
using namespace std;


#define SIZE(array) (sizeof((array)) / sizeof((array[0])))


void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main(void) {

	int array[] = { 9,5,2,7,3,8,6,4,1,10};
	BubbleSort(array, SIZE(array));
	print(array, SIZE(array));
	SelectSort(array, SIZE(array));
	print(array, SIZE(array));
	InsertSort(array, SIZE(array));
	print(array, SIZE(array));
	ShellSort(array, SIZE(array));
	print(array, SIZE(array));
	QuickSort(array, SIZE(array));
	print(array, SIZE(array));
	MergeSort(array, SIZE(array));
	print(array, SIZE(array));
	system("pause");
	return 0;
}