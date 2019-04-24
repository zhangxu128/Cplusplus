#include<iostream>
using namespace std;


/*
�鲢����:��������������кϲ����õ���ȫ��������У�����ʹÿ����������
         ����ʹ�����жμ������������������ϲ���һ���������Ϊ��·�鲢��
ʱ�临�Ӷ�	O(n * log(n))
�ռ临�Ӷ�	O(n)
�ȶ��ԣ�    �ȶ�
�ⲿ����(�������������ڴ�Ų���)
*/


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

//�ϲ���������
void merge(int array[], int start, int mid, int end, int* tmp) {
	int start1 = start;  //������1��ʼ
	int end1 = mid;      //������1����
	int start2 = mid + 1;//������2��ʼ
	int end2 = end;      //������2����

	int len = 0;         //�����ռ����Ч����

	//������������ϲ�
	while (start1 <= end1 && start2 <= end2) {
		if (array[start1] < array[start2]) {
			tmp[len++] = array[start1++];
		}
		else {
			tmp[len++] = array[start2++];
		}
	}
	//���������鲻һ����ʱ������������ʣ���Ԫ�ز�ȫ�������ռ����
	while (start1 <= end1) {
		tmp[len++] = array[start1++];
	}
	while(start2 <= end2) {
		tmp[len++] = array[start2++];
	}

	//�������ռ�����ݿ�����ԭ�����е�ԭλ��
	for (int i = 0; i < len; i++) {
		array[start + i] = tmp[i];
	}

}

//�鲢�����ڲ�ʵ��
void MergeSortInner(int array[], int start, int end, int* tmp) {
	
	//�ݹ��������
	if (start >= end) {
		return;
	}

	//�ֳ�������
	int mid = (start + end) / 2;
	//�ݹ��󲿷�
	MergeSortInner(array, start, mid, tmp);
	//�ݹ��Ҳ���
	MergeSortInner(array, mid+1, end, tmp);
	//�ϲ���������
	merge(array, start, mid, end, tmp);
}

//�鲢���������
void MergeSort(int array[], int size) {
	//��Ϊ�鲢������Ҫ�ϲ������������У��ʴ�Ҫ����һ������ĸ����ռ䣬��װ�ϲ������������
	int* tmp = new int [size];
	MergeSortInner(array, 0, size - 1, tmp);
	delete[] tmp;
}


int main(void) {

	int array[] = { 12,2,34,10,8,2,54,70,100,86,34,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "�����";
	MergeSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}