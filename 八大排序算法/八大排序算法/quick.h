#pragma once



void QuickSortInner(int array[], int left,int right) {
	int i = left;
	int j = right;
	int privot = array[left];

	if (i < j) {
		while (i < j) {
			//�Ӻ���ǰ��һ��С�ڻ�׼ֵ����
			while (i < j && array[j] > privot) {
				j--;
			}
			// �ҵ����
			if (i < j) {
				array[i] = array[j];
				i++;
			}
			//��ǰ������һ�����ڻ�׼ֵ����
			while (i < j && array[i] < privot) {
				i++;
			}
			if (i < j) {
				array[j] = array[i];
				j--;
			}
			//������׼ֵ
			array[i] = privot;
			//�ݹ���
			QuickSortInner(array, left,i - 1);
			//�ݹ���
			QuickSortInner(array, i + 1, right);

		}
	}
}

void QuickSort(int array[], int size) {
	QuickSortInner(array, 0, size - 1);
}