//NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼������
//���ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
//���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
//���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���
//�������� :
//�������ݰ������顣
//ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to�졣
//������� :
//��Ӧÿһ�����룬�����from��to��Щ�������from��to���죩����Ҫ�����ٷ���͡�

#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int>v;
	v.resize(81);
	v[1] = 1;
	v[2] = 1;
	for (int i = 3; i <= 80; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	int to;
	int from;
	while (cin >> from >> to) {
		int sum = 0;
		while (from <= to) {
			sum += v[from];
			from++;
		}
		cout << sum << endl;
	}
	system("pause");
	return 0;
}

