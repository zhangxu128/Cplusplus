//��Ŀ����
//����һ������N��512 <= N <= 1024��������2��N�η�������Ļ��ʾʮ���ƽ����
//�������� :
//����һ������N��512 <= N <= 1024��
//������� :
//2��N�η���ʮ���ƽ��
//ʾ��1
//����
//512
//���
//1340780792994259709957402499820584612747936582059239337
//7723561443721764030073546976801874298166903427690031858
//186486050853753882811946569946433649006084096


#include <string>
#include <iostream>
using namespace std;

string NPowerOf2(int n) {
	string res("1");

	for (int i = 0; i < n; ++i) {
		int carry = 0, multi = 0;
		for (int j = res.size() - 1; j >= 0; --j) {
			int tmpNum = res[j] - '0';
			multi = (tmpNum << 1) + carry;
			carry = multi / 10;
			res[j] = (multi % 10) + '0';
		}
		if (carry > 0)
			res.insert(res.begin(), carry + '0');
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	cout << NPowerOf2(n) << endl;
	system("pause");
	return 0;
}