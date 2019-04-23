#include<iostream>
using namespace std;

//插入排序
//原理简述：挨个遍历数组元素，将未排序元素插入到已排序序列的固定位置，默认已排序序列为array[0]
//时间复杂度：O(n^2)   
//空间复杂度：O(1)
//稳定性：稳定
//插入排序对数据量小基本有序的序列排序效率较高

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


//插入排序 
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		if (array[i] < array[i - 1]) {
			int tmp = array[i];
			int j;
			for (j = i - 1; j >= 0 && tmp < array[j]; j--) {
				array[j + 1] = array[j];
			}
			array[j + 1] = tmp;
		}
	}
}


int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "排序后：";
	InsertSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}