#include<iostream>
using namespace std;


//��Ŀ����
//С��ͬѧѧϰ�˲�ͬ�Ľ���֮��������һЩ������������Ϸ��
//С��ͬѧ֪�������ճ�������������õ���ʮ�����������ڼ�����У�
//��������Ҳ�ܳ��á����ڶ���һ������x��С��ͬѧ���������������f(x)��g(x)��
//f(x)��ʾ��x�������ʮ����д���������λ�ϵ�����֮�͡�
//��f(123) = 1 + 2 + 3 = 6�� g(x)��ʾ��x������ö�����д���������λ�ϵ�����֮�͡�
//��123�Ķ����Ʊ�ʾΪ1111011����ô��g(123) = 1 + 1 + 1 + 1 + 0 + 1 + 1 = 6��
//С��ͬѧ���ֶ���һЩ������x����f(x) = g(x)��������������Ϊ����������������֪����
//����0��С�ڵ���n���������ж��ٸ���


bool LuckNum(int n) {
	int k = n;
	int sum1 = 0;   //����ĳ�ʮ�������ܺ�
	while (k != 0) {
		int tmp = k % 10;
		//cout << tmp << " ";
		sum1 += tmp;
		k /= 10;
	}
	int kk = n;
	int sum2 = 0;
	while (kk != 0) {
		int tmp = kk % 2;
		sum2 += tmp;
		kk = kk / 2;
	}
	if (sum2 == sum1) {
		return true;
	}
	return false;
}

int main(void) {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (LuckNum(i)) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}