#include<iostream>
using namespace std;

//ð������
//ԭ��������������������бȽϣ����ǰ�߱Ⱥ��ߴ󣬽��н�������������ŵ����棬�ظ�����
//ʱ�临�Ӷȣ�O(n^2)   
//�ռ临�Ӷȣ�O(1)
//�ȶ��ԣ��ȶ�

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


//ð������һ��ֱ�ӽ�������û���Ż�
void BubbleSort1(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				swap(array, j - 1, j);
			}
		}
	}
}


//ð��������������Ż����������򼸴κ������Ѿ�������ô����һ����־λ����
void BubbleSort2(int array[], int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = 1; j < size - i; j++) {
			if (array[j - 1] > array[j]) {
				swap(array, j - 1, j);
				flag = 1;
			}
		}
		if (flag == 1) {
			break;
		}
	}
}



int main(void) {
	
	int array[] = { 9,5,2,7,3,8,6 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array,size);
	cout << "���Ż������";
	BubbleSort1(array, size);
	print(array, size);
	cout << "�Ż������";
	BubbleSort2(array, size);
	print(array, size);
	system("pause");
	return 0;
}