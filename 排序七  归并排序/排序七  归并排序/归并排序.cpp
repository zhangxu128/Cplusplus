#include<iostream>
using namespace std;


/*
归并排序:将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有
         序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
时间复杂度	O(n * log(n))
空间复杂度	O(n)
稳定性：    稳定
外部排序(海量数据排序，内存放不下)
*/


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

//合并有序序列
void merge(int array[], int start, int mid, int end, int* tmp) {
	int start1 = start;  //子数组1开始
	int end1 = mid;      //子数组1结束
	int start2 = mid + 1;//子数组2开始
	int end2 = end;      //子数组2结束

	int len = 0;         //辅助空间的有效长度

	//进行数据排序合并
	while (start1 <= end1 && start2 <= end2) {
		if (array[start1] < array[start2]) {
			tmp[len++] = array[start1++];
		}
		else {
			tmp[len++] = array[start2++];
		}
	}
	//当两个数组不一样长时，将长的数组剩余的元素补全到辅助空间后面
	while (start1 <= end1) {
		tmp[len++] = array[start1++];
	}
	while(start2 <= end2) {
		tmp[len++] = array[start2++];
	}

	//将辅助空间的数据拷贝到原数组中的原位置
	for (int i = 0; i < len; i++) {
		array[start + i] = tmp[i];
	}

}

//归并排序内部实现
void MergeSortInner(int array[], int start, int end, int* tmp) {
	
	//递归结束条件
	if (start >= end) {
		return;
	}

	//分成子序列
	int mid = (start + end) / 2;
	//递归左部分
	MergeSortInner(array, start, mid, tmp);
	//递归右部分
	MergeSortInner(array, mid+1, end, tmp);
	//合并有序序列
	merge(array, start, mid, end, tmp);
}

//归并排序主框架
void MergeSort(int array[], int size) {
	//因为归并排序是要合并两个有序序列，故此要申请一个额外的辅助空间，来装合并后的有序序列
	int* tmp = new int [size];
	MergeSortInner(array, 0, size - 1, tmp);
	delete[] tmp;
}


int main(void) {

	int array[] = { 12,2,34,10,8,2,54,70,100,86,34,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "排序后：";
	MergeSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}