#include<iostream>
using namespace std;

//������
//ԭ��������ѿ��Ժܷ��������ֵ���ʴˣ����ǿ��Խ���ѣ������򣬽�С���Ž���
//ʱ�临�Ӷȣ�O(nlog(n))   
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


//���µ���
void Heapify(int array[], int size, int index) {
	//�ж��ǲ���Ҷ�ӽڵ�
	//�ں������ҵ����ֵ
	//���ĺ��Ӹ����Ƚϣ��������˳�
	//���򣬽������ظ�����
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size) {
		return;
	}
	int max = left;
	if (right<size && array[right]>array[left]) {
		max = right;
	}
	if (array[max] <= array[index]) {
		return;
	}
	swap(array, max, index);
	Heapify(array, size, max);
}
//�����
void CreateHeapify(int array[], int size) {
	//�����һ����Ҷ�ӽڵ㲻�ϵ����µ���
	for (int i = size / 2 - 1; i >= 0; i--) {
		Heapify(array, size, i);
	}
}

//������
void HeapifySort(int array[], int size) {
	CreateHeapify(array, size);
	for (int i = 0; i < size; i++) {
		// ������������������������һ����
		swap(array, 0, size - 1 - i);
		// �ѵ����ʱ��ƻ���
		// ֻ�и��ĵط�
		// Ҫ��������ʣ�����򲿷ֵĳ��� size - 1 - i
		Heapify(array, size - 1 - i, 0);
	}
}

int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "�����";
	HeapifySort(array, size);
	print(array, size);
	system("pause");
	return 0;
}