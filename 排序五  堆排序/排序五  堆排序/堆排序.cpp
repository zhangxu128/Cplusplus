#include<iostream>
using namespace std;

//堆排序
//原理简述：堆可以很方便的求最值，故此，我们可以建大堆，排升序，建小堆排降序
//时间复杂度：O(nlog(n))   
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


//向下调整
void Heapify(int array[], int size, int index) {
	//判断是不是叶子节点
	//在孩子里找到最大值
	//最大的孩子跟根比较，若根大，退出
	//否则，交换，重复进行
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size) {
		return;
	}
	int max = left;
	if (right<size && array[right]>array[left]) {
		max = right;
	}
	if (array[max] <= array[index]) {
		return;
	}
	swap(array, max, index);
	Heapify(array, size, max);
}
//建大堆
void CreateHeapify(int array[], int size) {
	//从最后一个非叶子节点不断地向下调整
	for (int i = size / 2 - 1; i >= 0; i--) {
		Heapify(array, size, i);
	}
}

//堆排序
void HeapifySort(int array[], int size) {
	CreateHeapify(array, size);
	for (int i = 0; i < size; i++) {
		// 交换最大的数和无序区间的最后一个数
		swap(array, 0, size - 1 - i);
		// 堆的性质被破坏了
		// 只有根的地方
		// 要调整的是剩余无序部分的长度 size - 1 - i
		Heapify(array, size - 1 - i, 0);
	}
}

int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "排序后：";
	HeapifySort(array, size);
	print(array, size);
	system("pause");
	return 0;
}