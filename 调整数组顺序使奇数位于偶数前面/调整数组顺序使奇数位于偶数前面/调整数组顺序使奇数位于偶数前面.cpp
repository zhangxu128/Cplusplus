#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//�������е����������ŵ������ǰ�棬�����е�ż���ŵ�����ĺ���
//������������������ż��ԭ�е����λ�ò������仯

void reOrderArray(vector<int> &array) {
	vector<int>v;
	for (size_t i = 0; i < array.size(); i++) {
		if (array[i] % 2 != 0) {
			v.push_back(array[i]);
		}
	}
	for (size_t i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0) {
			v.push_back(array[i]);
		}
	}
	array = v;
}

int main() {
	int array[] = { 1,2,3,2,2,2,5,4,2 };
	int size = sizeof(array) / sizeof(array[0]);
	vector<int> num(array, array + size);
	cout << "��ʼ��" << endl;
	for (size_t i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	reOrderArray(num);
	cout << "����仯֮��" << endl;
	for (size_t i = 0; i < num.size(); i++) {
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}