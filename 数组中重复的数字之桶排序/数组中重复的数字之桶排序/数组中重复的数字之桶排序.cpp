#include<iostream>
using namespace std;

//��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ�
//������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
//Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡� 
//���磬������볤��Ϊ7������{ 2,3,1,0,2,5,3 }��
//��ô��Ӧ������ǵ�һ���ظ�������2��

//˼·������Ͱ������������ֻҪͰ��ĸ�������1����������ظ�


bool duplicate(int numbers[], int length, int* duplication) {
	//Ͱ����
	int* tong = new int[length];
	memset(tong, 0, length * 4);
	for (int i = 0; i < length; i++) {
		cout << tong[i] << " ";
	}
	cout << endl;
	int tmp;  //������ֵ
	for (int i = 0; i < length; i++) {
		tmp = numbers[i];
		tong[tmp]++;
	}//�Ѿ����Ͱ����
	//���ظ�Ԫ��
	for (int i = 0; i < length; i++) {
		cout << tong[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < length; i++) {
		if (tong[i] > 1) {
			*duplication = i;
			return true;
		}
	}
	return false;
}

int main(void) {
	
	int num[] = {2,3,7,4,1,8,9,0,6,7};
	int size = sizeof(num) / sizeof(num[0]);
	int p = 0;
	duplicate(num, size, &p);
	cout << "�������ظ�����Ϊ��" << p << endl;
	system("pause");
	return 0;
}