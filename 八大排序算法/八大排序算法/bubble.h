// √∞≈›≈≈–Ú
// Œ»∂®
// O(n^2)
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		bool flag = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				flag = true;
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
		if (!flag) {
			return;
		}
	}
}