//��Ŀ����
//�����ϿΣ���ʦ����С����ô����ӷ��ͳ˷����˷������ȼ����ڼӷ����������һ������������ţ���ô�������ȼ�����ߵġ����磺
//1 + 2 * 3 = 7
//1 * (2 + 3) = 5
//1 * 2 * 3 = 6
//(1 + 2) * 3 = 9
//����С��ϣ��������������3����a��b��c���������м����"+"�� "*"�� "("�� ")"���ţ��ܹ���õ����ֵ��
//�������� :
//һ��������a��b��c(1 <= a, b, c <= 10)
//������� :
//	�ܹ���õ����ֵ
//	ʾ��1
//	����
//	1 2 3
//	���
//	9

#include<iostream>
#include<vector>
using namespace std;
int max(int a, int b, int c) {
	vector<int> count;
	int max_n = 0;
	int max_1 = a + b + c;
	int max_2 = a * b + c;
	int max_3 = a * b*c;
	int max_4 = (a + b)*c;
	count.push_back(max_1);
	count.push_back(max_2);
	count.push_back(max_3);
	count.push_back(max_4);
	for (int i = 0; i < count.size(); i++) {
		if (count[i] > max_n) {
			max_n = count[i];
		}
	}
	return max_n;
}
int main() {
	int x, y, z;
	int max_num;
	while (cin >> x >> y >> z) {
		max_num = 0;
		int max_1 = max(x, y, z);
		int max_2 = max(y, z, x);
		max_num = max_1 > max_2 ? max_1 : max_2;
		cout << max_num << endl;
	}
	return 0;
}