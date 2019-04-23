#include<iostream>
using namespace std;

//希尔排序
//原理简述：希尔排序就是一种升级版的插入排序，它将待排序的区间划分组，
//          然后对每个组的数据进行插入排序，然后缩小区间增量，重复，直到增量为1，排序之后，数据有序
//时间复杂度：最好O(n^1.3)  最坏 O(n^2) 平均   O(N^1.3—N^2）  
//空间复杂度：O(1)
//稳定性：稳定
//分组依据：经过许多大佬的实验  分组依据满足  gap = gap / 3 + 1


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



void ShellSort(int array[], int size) {
	int gap = size;
	//分组循环 ,注意当gap == 1 时还要再排序一次，故使用do while 循环
	do {
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++) {
			int j;
			for (j = i + gap; j < size; j += gap) {
				if (array[j] < array[j - gap]) {
					int tmp = array[j];
					int k;
					for (k = j - gap;k >= 0 && tmp < array[k]; k -= gap) {
						array[k + gap] = array[k];
					}
					array[k + gap] = tmp;
				}
			}
		}

	} while (gap > 1);
}

int main(void) {
	int array[] = {12,23,7,3,54,0,7,2,4,54,9,1,3};
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "排序后：";
	ShellSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}