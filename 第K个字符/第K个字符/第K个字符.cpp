//��Ŀ����
//��һЩ����������ֻ��3��5��7�������һ���㷨���ҳ����еĵ�k������
//����һ����int k���뷵�ص�k��������֤kС�ڵ���100��
//����������
//3
//���أ�7


#include <iostream>
#include <algorithm>
using namespace std;


int findKth(int k) {
	int* array = new int[k];
	int num3 = 0;
	int num5 = 0;
	int num7 = 0;
	array[0] = 3;
	array[1] = 5;
	array[2] = 7;
	for (int i = 3; i < k; i++) {
		array[i] = min(min(array[num3] * 3, array[num5] * 5), array[num7] * 7);
		if (array[i] == array[num3] * 3) num3++;
		if (array[i] == array[num5] * 5) num5++;
		if (array[i] == array[num7] * 7) num7++;
	}
	return array[k - 1];
}

int main(void) {

	int k;
	cin >> k;


	system("pause");
	return 0;
}