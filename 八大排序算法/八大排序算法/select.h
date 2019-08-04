#pragma once

// —°‘Ò≈≈–Ú
// 
// O(n^2)

#include "swap.h"
void SelectSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] < array[min])
				min = j;
		}
		if (min != i) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}
}