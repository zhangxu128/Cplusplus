#include<iostream>
using namespace std;

//选择排序
//原理简述：遍历数组，每次从未排序区间找到一个最小值放到已排序区间，直到数组有序
//时间复杂度：O(n^2)   
//空间复杂度：O(1)
//稳定性：不稳定

//打印数组内容
void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
//交换函数
void swap(int array[], int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


//直接选择排序  选择最小值放到前边
void SelectSort1(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(array, min, i);
		}
	}
}

//直接选择排序  选择最大值放到后边
void SelectSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (array[max] < array[j]) {
				max = j;
			}
		}
		if (max != i) {
			swap(array, max, i);
		}
	}
}


int main(void) {

	int array[] = { 9,5,2,7,3,8,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "升序排序后：";
	SelectSort1(array, size);
	print(array, size);
	cout << "降序排序后：";
	SelectSort2(array, size);
	print(array, size);
	system("pause");
	return 0;
}