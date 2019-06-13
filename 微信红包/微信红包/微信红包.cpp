//�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�
//ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�
//Ҫ���㷨�����ܸ�Ч��
//����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
//��û�н���������һ�룬����0��
//����������
//[1, 2, 3, 2, 2], 5
//���أ�2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getValue(vector<int> gifts, int n) {
	// write code here
	/*sort(gifts.begin(), gifts.end());
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (gifts[i] == gifts[i - 1]) {
			cnt++;
			if (cnt > n / 2) {
				return gifts[i];
			}
		}
		else {
			cnt = 1;
		}
	}
	return 0;*/
	int cnt = 1;
	int tmp = gifts[0];
	for (int i = 0; i < n; i++) {
		if (tmp == gifts[i]) {
			cnt++;
		}
		else {
			cnt--;
			if (cnt == 0) {
				cnt = 1;
				tmp = gifts[i];
			}
		}
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		if (gifts[i] == tmp) {
			cnt++;
			if (cnt > n / 2) {
				return tmp;
			}
		}
	}
	return 0;
}

int main(void) {

	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << getValue(v,n) << endl;
	}
	
	system("pause");
	return 0;
}