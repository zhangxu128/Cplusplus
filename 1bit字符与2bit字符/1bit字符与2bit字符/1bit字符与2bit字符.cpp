#include<iostream>
#include<vector>

using namespace std;

//����:
//Ψһ�ı��뷽ʽ��һ���������ַ���һ��һ�����ַ����������һ���ַ���һ�����ַ���
//ʾ�� 2 :
//	���� :
//	bits = [1, 1, 1, 0]
//	��� : False
//	���� :
//Ψһ�ı��뷽ʽ���������ַ����������ַ����������һ���ַ�����һ�����ַ���
//ע�� :
//1 <= len(bits) <= 1000.
//bits[i] ����0 �� 1.

bool isOneBitCharacter(vector<int>& bits) {
	int n = bits.size();
	int i = 0;
	while (i < n) {
		if (i == n - 1)
			return true;
		if (bits[i] == 1)
			i += 2;
		else
			i++;
	}
	return false;
}

int main(void) {

	int n;
	cin >> n;
	vector<int>v;
	int tmp = 0;
	while (n--) {
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	cout << isOneBitCharacter(v) << endl;
	system("pause");
	return 0;
}