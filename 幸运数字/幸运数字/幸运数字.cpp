//��Ŀ����
//��������n��ȡ���ɸ�1��n����������͵�������m��������������ϵĸ�����
//���統n = 6��m = 8ʱ����������ϣ�[2, 6], [3, 5], [1, 2, 5], [1, 3, 4]���޶�n��mС��120

#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b || a < 1 || b < 1 || a>1000000000 || b> 1000000000)
			cout << -1 << endl;
		string a1, b1;
		a1 = to_string(a);
		b1 = to_string(b);
		int lena, lenb;
		lena = a1.size();
		lenb = b1.size();
		int i, sums = 0;
		for (i = lena; i < lenb; i++)
			sums = sums + pow(2, i);
		cout << sums << endl;
	}
	return 0;
}