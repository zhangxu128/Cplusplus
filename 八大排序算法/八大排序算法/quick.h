#pragma once



void QuickSortInner(int array[], int left,int right) {
	int i = left;
	int j = right;
	int privot = array[left];

	if (i < j) {
		while (i < j) {
			//从后往前找一个小于基准值的数
			while (i < j && array[j] > privot) {
				j--;
			}
			// 找到填坑
			if (i < j) {
				array[i] = array[j];
				i++;
			}
			//从前往后找一个大于基准值的数
			while (i < j && array[i] < privot) {
				i++;
			}
			if (i < j) {
				array[j] = array[i];
				j--;
			}
			//交换基准值
			array[i] = privot;
			//递归左
			QuickSortInner(array, left,i - 1);
			//递归右
			QuickSortInner(array, i + 1, right);

		}
	}
}

void QuickSort(int array[], int size) {
	QuickSortInner(array, 0, size - 1);
}