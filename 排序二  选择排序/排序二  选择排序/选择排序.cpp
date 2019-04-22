#include<iostream>
using namespace std;

//ѡ������
//ԭ��������������飬ÿ�δ�δ���������ҵ�һ����Сֵ�ŵ����������䣬ֱ����������
//ʱ�临�Ӷȣ�O(n^2)   
//�ռ临�Ӷȣ�O(1)
//�ȶ��ԣ����ȶ�

//��ӡ��������
void print(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
//��������
void swap(int array[], int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


//ֱ��ѡ������  ѡ����Сֵ�ŵ�ǰ��
void SelectSort1(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(array, min, i);
		}
	}
}

//ֱ��ѡ������  ѡ�����ֵ�ŵ����
void SelectSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int max = i;
		for (int j = i + 1; j < size; j++) {
			if (array[max] < array[j]) {
				max = j;
			}
		}
		if (max != i) {
			swap(array, max, i);
		}
	}
}


int main(void) {

	int array[] = { 9,5,2,7,3,8,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "���������";
	SelectSort1(array, size);
	print(array, size);
	cout << "���������";
	SelectSort2(array, size);
	print(array, size);
	system("pause");
	return 0;
}