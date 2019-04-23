#include<iostream>
using namespace std;

//��������
//ԭ�������������������Ԫ�أ���δ����Ԫ�ز��뵽���������еĹ̶�λ�ã�Ĭ������������Ϊarray[0]
//ʱ�临�Ӷȣ�O(n^2)   
//�ռ临�Ӷȣ�O(1)
//�ȶ��ԣ��ȶ�
//���������������С�����������������Ч�ʽϸ�

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


//�������� 
void InsertSort(int array[], int size) {
	for (int i = 1; i < size; i++) {
		if (array[i] < array[i - 1]) {
			int tmp = array[i];
			int j;
			for (j = i - 1; j >= 0 && tmp < array[j]; j--) {
				array[j + 1] = array[j];
			}
			array[j + 1] = tmp;
		}
	}
}


int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "�����";
	InsertSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}