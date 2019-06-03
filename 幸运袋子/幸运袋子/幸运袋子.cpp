//���ǹ涨�����˴�����������ֵ�������������Ļ�
// ���� �� 1 1 2 3 
//    ��   7
//    ��   6
//  ���ǳ����ִ���Ϊ���˴��ӣ�����Ҫ�����ǿ��ԴӴ����Ƴ�С��
//  ���������˴��ӣ�������0��   ���ж������Ʒ�

//����  ��һ��  ������С�������
//      �ڶ���  С���ֵ

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Lucky(vector<int>v, int index, int sum, int mul) {
	int cnt = 0;
	for (int i = index; i < v.size(); i++) {
		sum += v[i];
		mul *= v[i];
		if (sum > mul) {
			cnt += 1 + Lucky(v, i + 1, sum, mul);
		}
		else if (v[i] == 1) {
			cnt += Lucky(v, i + 1, sum, mul);
		}
		else {  //������
			break;
		}
		sum -= v[i];
		mul /= v[i];
		for (; i < v.size() - 1 && v[i] == v[i + 1]; i++);//��ͬ��������

	}
	return cnt;
}

int main() {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int method = Lucky(v, 0, 0, 1);

	cout << method << endl;
	system("pause");
	return 0;
}