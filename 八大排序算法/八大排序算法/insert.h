#pragma once

// 直接插入排序
// 不稳定 
// O(n^2)

void  InsertSort(int array[], int size) {
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
