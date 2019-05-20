//������Χ[m, n]������ 0 <= m <= n <= 2147483647�����ش˷�Χ���������ֵİ�λ�루���� m, n ���˵㣩��
//ʾ�� 1:
//����: [5, 7]
//	��� : 4
//	ʾ�� 2 :
//	���� : [0, 1]
//	��� : 0

#include <iostream>

using namespace std;


//˼·��
//n�Ķ�����λ��m����������ߵ�1��ʱ��&�Ľ����ȻΪ0�� �����˼�����������������λ��ͬʱ��
//���1�ᱣ�棬Ȼ��Ƚ���һλ����ͬҲ����... 
//����ֻ��Ҫm n ͬʱ���Ƶ����ʱ m n��ֵ����&���ܱ�����λ����
//Ȼ�����ƻ�����������ֵ��
int rangeBitwiseAnd1(int m, int n) {
	if (m == 0 || n / 2 >= m)    return 0;//��2�����
	if (m == n)    return m;
	for (int i = n; i >= m; i--)//����ȡ�������
		n = n & i;
	return n;
}

int rangeBitwiseAnd2(int m, int n) {
	int  count = 0;   // 101  10 100
					// 111  11 1
	while (m != n) {
		m >>= 1;
		n >>= 1;
		count++;
	}
	return m << count;
}

int main(void) {

	int m, n;
	cin >> m >> n;
	cout << rangeBitwiseAnd1(m, n) << endl;
	cout << rangeBitwiseAnd2(m, n) << endl;
	system("pause");
	return 0;
}