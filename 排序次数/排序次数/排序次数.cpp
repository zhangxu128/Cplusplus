#include <iostream>
#include <vector>
using namespace std;

//��Ŀ����
//СĦ��һ��N���������飬���뽫�����С���� �ź��򣬵������ȵ�СĦֻ���������������
//��ȡ�����е�һ����Ȼ������������������һ��λ�á�
//�����ٲ������ٴο���ʹ�������С��������
//�������� :
//��������һ��������N����������һ������N��������(N <= 50, ÿ�����ľ���ֵС�ڵ���1000)
//������� :
//	���һ�в�����
//	ʾ��1
//	����
//	4
//	19 7 8 25
//	���
//	2


int main(void) {

	int N;
	cin >> N;
	//����
	int count = 0;
	vector <int> v;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
	}
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] > v[i + 1]) {
			count++;
			v.push_back(v[i]);
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}
