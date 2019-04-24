#include<iostream>
#include<stack>
using namespace std;

/*
快速排序:选择一个基准值，让基准值左边的数都小于基准值，右边的数都大于基准值
每一层的 Partition
	时间复杂度是 O(n)
	空间复杂度是 O(1)
数多少个 O(n)，二叉树高度个 O(n)
空间消耗在于递归调用的栈帧消耗，最终消耗的情况是二叉树的高度
	二叉树的高度是 log(n) - n 在变化
					最好						平均					最坏
时间复杂度		O(n * log(n))				O(n * log(n))			O(n^2)
空间复杂度		O(log(n))					O(log(n))				O(n)

稳定性: 不稳定
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


//利用填坑法快速排序
void QuickSort1(int array[], int left,int right) {
	int i = left;
	int j = right;
	//设置基准值
	int temp = array[left];
	if (i < j) {
		while (i < j) {
			//从后往前找小于基准值的数
			while (i < j && array[j] >= temp) {
				j--;
			}
			//填坑

			if (i < j) {
				array[i] = array[j];
				i++;
			}
			//从前往后找大于基准值的数
			while (i < j && array[i] < temp) {
				i++;
			}
			//填坑
			if (i < j) {
				array[j] = array[i];
				j--;
			}
		}
		//循环结束 i == j,将基准值放入正确位置
		array[i] = temp;
		//递归左半边
		QuickSort1(array, left, i - 1);
		QuickSort1(array, i + 1, right);
	}
}

//利用hover法快速排序
void QuickSort2(int array[], int left, int right) {
	int i = left;
	int j = right;
	//设置基准值
	int temp = array[left];
	if (i < j) {
		while (i < j) {
			//从后往前找一个小于基准值的数
			while (i < j && array[j] >= temp) {
				j--;
			}
			//从前往后找一个大于基准值的数
			while (i < j && array[i] < temp) {
				i++;
			}
			//将两个数进行交换
			if (i < j) {
				swap(array, i, j);
				j--;
				i++;
			}
		}
		//i == j 结束循环，交换基准值
		swap(array, temp, array[i]);
		QuickSort2(array, left, i - 1);
		QuickSort2(array, i + 1, right);
	}
}




int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "排序前：";
	print(array, size);
	cout << "排序后：";
	QuickSort1(array,0,size - 1);
	print(array, size);
	cout << "排序后：";
	QuickSort2(array, 0, size - 1);
	print(array, size);
	system("pause");
	return 0;
}