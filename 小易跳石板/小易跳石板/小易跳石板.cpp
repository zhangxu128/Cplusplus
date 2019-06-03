//С����ʯ��
//ʯ����Ϊ1~n
//С�����ڱ��ΪK��ʯ�壬��ֻ����ǰ��K��һ��Լ����������1�ͱ���
//�����������ΪM��ʯ�壬������Ҫ�����Ρ�
// N = 4�� M = 24
// 4 6 8  12 18 24

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getys(vector<int>& ys,int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ys.push_back(i);
			if (n / i != i) {
				ys.push_back(n / i);
			}
		}
	}
}

int main(void) {

	int n,m;
	cin >> n >> m;
	vector<int> v(m + 1, 0);
	for (int i = n; i < m; i++) {
		vector<int> ys;
		v[n] = 1;
		if (v[i] == 0) {
			continue;
		}
		getys(ys, i);
		for (int j = 0; j < ys.size(); j++) {
			if ((ys[j] + i) <= m && v[ys[j] + i] != 0) {
				v[ys[j] + i] = min(v[ys[j]+i], v[i] + 1);
			}
			else if(ys[j] + i<=m){
				v[ys[j] + i] = v[i] + 1;
			}
		}
	}
	if (v[m] == 0) {
		cout << -1 << endl;
	}
	else {
		cout << v[m] - 1 << endl;
	}
	system("pause");
	return 0;
}