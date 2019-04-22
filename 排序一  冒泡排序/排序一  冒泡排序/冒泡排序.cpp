#include<iostream>
using namespace std;

//冒泡排序
//原理简述：相邻两个数进行比较，如果前者比后者大，进行交换，将大的数放到后面，重复即可
//时间复杂度：O(n^2)   
//空间复杂度：O(1)
//稳定性：稳定

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


//冒泡排序一，直接进行排序，没有优化
void BubbleSort1(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				swap(array, j - 1, j);
			}
		}
	}
}


//冒泡排序二，进行优化，假如排序几次后，数组已经有序，那么设置一个标志位即可
void BubbleSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				swap(array, j - 1, j);
				flag = 1;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}



int main(void) {
	
	int array[] = { 9,5,2,7,3,8,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array,size);
	cout << "无优化排序后：";
	BubbleSort1(array, size);
	print(array, size);
	cout << "优化排序后：";
	BubbleSort2(array, size);
	print(array, size);
	system("pause");
	return 0;
}