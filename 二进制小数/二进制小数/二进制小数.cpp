//��Ŀ����
//��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ������������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ء�Error����
//����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
//����������
//0.625
//���أ�0.101


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string printBin(double num) {
	stringstream res;
	res << "0.";
	for (int i = 0; i < 32; ++i) {
		if (num == 0.0) break;
		num *= 2;
		res << (int)num;
		num -= (int)num;
	}
	if (num == 0.0) {
		return res.str();
	}
	else {
		return "Error";
	}
}

int main(void) {

	double e;
	cin >> e;

	cout << printBin(e) << endl;
	system("pause");
	return 0;
}