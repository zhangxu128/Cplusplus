#include<iostream>
using namespace std;

//ϣ������
//ԭ�������ϣ���������һ��������Ĳ���������������������仮���飬
//          Ȼ���ÿ��������ݽ��в�������Ȼ����С�����������ظ���ֱ������Ϊ1������֮����������
//ʱ�临�Ӷȣ����O(n^1.3)  � O(n^2) ƽ��   O(N^1.3��N^2��  
//�ռ临�Ӷȣ�O(1)
//�ȶ��ԣ��ȶ�
//�������ݣ����������е�ʵ��  ������������  gap = gap / 3 + 1


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



void ShellSort(int array[], int size) {
	int gap = size;
	//����ѭ�� ,ע�⵱gap == 1 ʱ��Ҫ������һ�Σ���ʹ��do while ѭ��
	do {
		gap = gap / 3 + 1;
		for (int i = 0; i < gap; i++) {
			int j;
			for (j = i + gap; j < size; j += gap) {
				if (array[j] < array[j - gap]) {
					int tmp = array[j];
					int k;
					for (k = j - gap;k >= 0 && tmp < array[k]; k -= gap) {
						array[k + gap] = array[k];
					}
					array[k + gap] = tmp;
				}
			}
		}

	} while (gap > 1);
}

int main(void) {
	int array[] = {12,23,7,3,54,0,7,2,4,54,9,1,3};
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "�����";
	ShellSort(array, size);
	print(array, size);
	system("pause");
	return 0;
}