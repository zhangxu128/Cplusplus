//����һ��������������������������1�ĸ�����
//�������� 3  ������ 11
//����    2


#include <iostream>
#include <vector>

using namespace std;

//˼·���Ƚ������ת��Ϊ�����Ʒ��������У�Ȼ���ж��������1�ĸ������ɡ�

int main(void) {

	int n;
	while (cin >> n) {
		if (n == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<int> v;
		while (n != 0) {
			v.push_back(n % 2);
			n /= 2;
		}
		int maxlen = 0;
		int cnt = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			if (v[i] == v[i + 1] && v[i] == 1) {
				cnt++;
				if (maxlen < cnt) {
					maxlen = cnt;
				}
				continue;
			}
			if (v[i] != v[i + 1] || v[i] == 0) {
				cnt = 0;
			}
		}
		cout << maxlen + 1 << endl;
	}
	system("pause");
	return 0;
}