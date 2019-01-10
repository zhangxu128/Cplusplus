//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）

#include<stdio.h>
#include<stdlib.h>

int search(int arr[], int size, int key) {
	if (arr == NULL) {
		return 0;
	}
	/*二分查找*/
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		/*求出mid的下标*/
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
	//如果到了这里表示没有找到
	return -1;
}

int main() {
	int arr[] = {5,12,23,34,45,56,67,78,89,90 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int key = 67;
	int ret = search(arr, size, key);
	printf("数组下标是 :%d\n", ret);
	system("pause");
	return 0;
}
