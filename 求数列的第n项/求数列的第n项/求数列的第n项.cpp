//��Ŀ����
//���ô����������˽⵽��һ�����޳����������� 1, 2��3��3��4��4��4, 5��5��5��5��5 ..., 
//(��֪��������һ�����ɣ��ֽ���Щ���ְ���ͬ��ֵ�ѵ�����ֵͬ��������ͬһ��)��
//������֪������������еĵ�n�������ڵ���һ��֮ǰ�����в��ﹲ�ж��ٸ�����
//�������� :
//n(n <= 1e18)
//������� :
//	��n�������ڵ���һ��֮ǰ�����в��ﹲ�ж��ٸ���
//	ʾ��1
//	����
//	6
//	���
//	4

#include <iostream>
using namespace std;

int main() {
	long long input;
	cin >> input;
	long long formal = 0;
	long long now = 1;
	long long count = 0;

	while (1) {
		if (count + now >= input) {
			cout << count << endl;
			break;
		}
		count += now;
		long long tmp = now;
		now = formal + now;
		formal = tmp;
	}
	return 0;
}