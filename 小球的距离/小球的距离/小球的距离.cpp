#include<iostream>
#include<cmath>
using namespace std;
//��Ŀ����
//С������������һ����¥����С������վ��¥���Ĳ�ͬ�㣬
//����С��վ��¥��������N�ף�����������������£�ÿ����غ������ϴ�����߶ȵ�һ�룬
//���Դ�����ֱ��ȫ���䵽���治������4��С��һ�������˶����ף�(���ֶ�Ϊ����)
//�����ĸ�����A, B, C, D���뷵����������
//����������
//100, 90, 80, 70
//���أ�1020
class Balls {
public:
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		
		int sum = 3 * (A + B + C + D);
		return sum;
	}
};
int main(void) {

	Balls b;
	int sum = b.calcDistance(100, 90, 80, 70);
	cout << sum << endl;
	system("pause");
	return 0;
}