//��Ŀ����
//СMͻȻ�Թ�����������Ȥ������һ����n�����[n / 1] + [n / 2] + ... + [n / k]
//(kΪ�������������������)Ϊһ��ż������ô�������һ�����������ڸ���һ������[a, b]����[a, b]֮���ж��ٹ�����
//[x]��ʾ������x�����������
//�������� :
//����ֻ����һ�У��������Ǹ�����a, b(0 <= a, b <= 2 ^ 31, a <= b)��
//������� :
//�������[a, b]�еĹ����ĸ�����
//ʾ��1
//����
//0 10
//���
//6

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	long isStrange(long num) {
		return (long(floor(sqrt(num))) & 1) == 0 ? 1 : 0;
	}

	// strange number from 0 to n
	long StrangeNumber(long &n) {
		long res = 0;
		long last = long(floor(sqrt(n)));
		if (last & 1) {
			res = last * (last + 1) >> 1;
		}
		else {
			res = last * (last - 1) >> 1;
			res += (n - last * last + 1);
		}
		return res;
	}
};

int main() {
	long a, b;
	cin >> a >> b;
	Solution s;
	long ret = s.StrangeNumber(b) - s.StrangeNumber(a) + s.isStrange(a);
	printf("%d", ret);
	system("pause");
	return 0;
}