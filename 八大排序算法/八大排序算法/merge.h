#pragma once

// 归并排序
// O(nlog(n))    空间O(n)

void Merge(int array[], int left, int mid, int right, int* tmp) {
	int start1 = left;
	int end1 = mid;
	int start2 = mid + 1;
	int end2 = right;

	int len = 0; 

	while (start1 <= end1 && start2 <= end2) {
		if (start1 < start2) {
			tmp[len++] = array[start1++];
		}
		else {
			tmp[len++] = array[start2++];
		}
	}

	while (start1 <= end1) {
		tmp[len++] = array[start1++];
	}

	while (start2 <= end2) {
		tmp[len++] = array[start2++];
	}

	for (int i = 0; i < len; i++) {
		array[left + i] = tmp[i];
	}
}

void MergeSortInner(int array[], int left, int right, int* tmp) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;

	MergeSortInner(array, left, mid, tmp);
	MergeSortInner(array, mid + 1, right, tmp);
	Merge(array, left, mid, right, tmp);
}

void MergeSort(int array[], int size) {
	//需要辅助空间
	int* tmp = new int[size];
	MergeSortInner(array, 0, size - 1,tmp);
	delete[] tmp;
}
