#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//��Ŀ����
//ţţ��һ��������x, ţţ��Ҫ������x�е���λ�������ŵõ�һ������(��ͬ��x����),
//ţţ��֪����������Ƿ������ԭx�ı������������������������⡣
//�������� :
//�������t + 1��, ��һ�а���һ������t(1 �� t �� 10),
//������t��, ÿ��һ������x(1 �� x �� 10 ^ 6)
//������� :
//	����ÿ��x, �����������֮���Ϊ�Լ��ı������"Possible", �������"Impossible".
//	ʾ��1
//	����
//	2
//	14
//	1035
//	���
//	Impossible
//	Possible


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int ori = stoi(s), flag = 0;
		sort(s.begin(), s.end());

		do {
			int num = stoi(s);
			if (num != ori && num%ori == 0) {
				flag = 1;
				break;
			}
		} while (next_permutation(s.begin(), s.end()));
		if (flag)cout << "Possible" << endl;
		else cout << "Impossible" << endl;
	}
	system("pause");
	return 0;
}
