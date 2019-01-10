//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң�

#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int size, int key) {
	if (arr == NULL) {
		return 0;
	}
	/*���ֲ���*/
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		/*���mid���±�*/
		int mid = left + (right - left) / 2;
		if (arr[mid] > key) {
			right = mid - 1;
		}
		else if (arr[mid] < key) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	//������������ʾû���ҵ�
	return -1;
}

int main() {
	int arr[] = {5,12,23,34,45,56,67,78,89,90 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 67;
	int ret = search(arr, size, key);
	printf("�����±��� :%d\n", ret);
	system("pause");
	return 0;
}
