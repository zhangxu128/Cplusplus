#pragma once

// Ï£¶ûÅÅÐò

void ShellSort(int array[], int size) {
	int gap = size;
	do {
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++) {
			for (int j = gap + 1; j < size; j += gap) {
				if (array[j - gap] < array[j]) {
					int tmp = array[j];
					int k;
					for (k = j - gap; k >= 0 && tmp < array[k]; k -= gap) {
						array[k + gap] = array[k];
					}
					array[k + gap] = tmp;
				}
			}
		}

	} while (gap > 1);
}
