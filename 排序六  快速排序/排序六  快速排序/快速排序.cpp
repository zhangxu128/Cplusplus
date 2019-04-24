#include<iostream>
#include<stack>
using namespace std;

/*
��������:ѡ��һ����׼ֵ���û�׼ֵ��ߵ�����С�ڻ�׼ֵ���ұߵ��������ڻ�׼ֵ
ÿһ��� Partition
	ʱ�临�Ӷ��� O(n)
	�ռ临�Ӷ��� O(1)
�����ٸ� O(n)���������߶ȸ� O(n)
�ռ��������ڵݹ���õ�ջ֡���ģ��������ĵ�����Ƕ������ĸ߶�
	�������ĸ߶��� log(n) - n �ڱ仯
					���						ƽ��					�
ʱ�临�Ӷ�		O(n * log(n))				O(n * log(n))			O(n^2)
�ռ临�Ӷ�		O(log(n))					O(log(n))				O(n)

�ȶ���: ���ȶ�
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


//������ӷ���������
void QuickSort1(int array[], int left,int right) {
	int i = left;
	int j = right;
	//���û�׼ֵ
	int temp = array[left];
	if (i < j) {
		while (i < j) {
			//�Ӻ���ǰ��С�ڻ�׼ֵ����
			while (i < j && array[j] >= temp) {
				j--;
			}
			//���

			if (i < j) {
				array[i] = array[j];
				i++;
			}
			//��ǰ�����Ҵ��ڻ�׼ֵ����
			while (i < j && array[i] < temp) {
				i++;
			}
			//���
			if (i < j) {
				array[j] = array[i];
				j--;
			}
		}
		//ѭ������ i == j,����׼ֵ������ȷλ��
		array[i] = temp;
		//�ݹ�����
		QuickSort1(array, left, i - 1);
		QuickSort1(array, i + 1, right);
	}
}

//����hover����������
void QuickSort2(int array[], int left, int right) {
	int i = left;
	int j = right;
	//���û�׼ֵ
	int temp = array[left];
	if (i < j) {
		while (i < j) {
			//�Ӻ���ǰ��һ��С�ڻ�׼ֵ����
			while (i < j && array[j] >= temp) {
				j--;
			}
			//��ǰ������һ�����ڻ�׼ֵ����
			while (i < j && array[i] < temp) {
				i++;
			}
			//�����������н���
			if (i < j) {
				swap(array, i, j);
				j--;
				i++;
			}
		}
		//i == j ����ѭ����������׼ֵ
		swap(array, temp, array[i]);
		QuickSort2(array, left, i - 1);
		QuickSort2(array, i + 1, right);
	}
}




int main(void) {
	int array[] = { 12,23,7,3,54,0,7,2,4,54,9,1,3 };
	int size = sizeof(array) / sizeof(int);
	cout << "����ǰ��";
	print(array, size);
	cout << "�����";
	QuickSort1(array,0,size - 1);
	print(array, size);
	cout << "�����";
	QuickSort2(array, 0, size - 1);
	print(array, size);
	system("pause");
	return 0;
}