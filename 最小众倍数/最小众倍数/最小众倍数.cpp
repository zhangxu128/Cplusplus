#include<iostream>
#include<vector>
using namespace std;

//��Ŀ����
//����5��������, ���ǵ���С���ڱ�����ָ���ܹ�������������������������С��������
//����5����ͬ��������, �����������ǵ���С�ڱ�����
//���� 1 2 3 4 5
//��� 4




//��ʱû������ð취��ֻ�ܴ�1��ʼ���ϼӣ�����С�ڱ���
int main() {
	int num;
	vector<int> v;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		//����������������������У��Ա�������
		v.push_back(num);
	}
	int k = 1;
	int r = 0;
	while (1) {
		if (k%v[0] == 0) {
			r++;
		}
		if (k%v[1] == 0) {
			r++;
		}
		if (k%v[2] == 0) {
			r++;
		}
		if (k%v[3] == 0) {
			r++;
		}
		if (k%v[4] == 0) {
			r++;
		}
		if (r >= 3) {
			cout << k << endl;
			break;
		}
		k++;
		r = 0;
	}
	system("pause");
	return 0;
}