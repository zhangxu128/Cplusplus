//�������������� x �� y�����ĳһ�������� x^i + y ^ j���������� i >= 0 �� j >= 0��
//��ô������Ϊ��������һ��ǿ������
//����ֵС�ڻ���� bound ������ǿ������ɵ��б�
//����԰��κ�˳�򷵻ش𰸡�����Ļش��У�ÿ��ֵ������һ�Ρ�
//ʾ�� 1��
//���룺x = 2, y = 3, bound = 10
//�����[2, 3, 4, 5, 7, 9, 10]
//���ͣ�
//2 = 2 ^ 0 + 3 ^ 0
//3 = 2 ^ 1 + 3 ^ 0
//4 = 2 ^ 0 + 3 ^ 1
//5 = 2 ^ 1 + 3 ^ 1
//7 = 2 ^ 2 + 3 ^ 1
//9 = 2 ^ 3 + 3 ^ 0
//10 = 2 ^ 0 + 3 ^ 2
//ʾ�� 2��
//���룺x = 3, y = 5, bound = 15
//�����[2, 4, 6, 8, 10, 14]

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound) {
	if (x == 1 && y == 1) {
		if (bound >= 2) return vector<int>{2};
		else return vector<int>(0);
	}

	if (x == 1) swap(x, y);
	unordered_set<int> intS;
	for (int i = 0; pow(x, i) < bound; i++) {
		intS.insert(pow(x, i) + 1);
		if (y > 1) {
			for (int j = 1; pow(x, i) + pow(y, j) <= bound; j++) {
				intS.insert(pow(x, i) + pow(y, j));
			}
		}
	}
	return vector<int>(intS.begin(), intS.end());

}

int main(void) {

	int x, y, bound;
	cin >> x >> y >> bound;
	vector<int> v = powerfulIntegers(x, y, bound);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}