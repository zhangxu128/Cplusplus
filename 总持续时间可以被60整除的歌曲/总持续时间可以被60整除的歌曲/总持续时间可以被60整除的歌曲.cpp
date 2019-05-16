//�ڸ����б��У��� i �׸����ĳ���ʱ��Ϊ time[i] �롣
//�������ܳ���ʱ�䣨����Ϊ��λ���ɱ� 60 �����ĸ����Ե���������ʽ�ϣ�����ϣ������������  i < j ����(time[i] + time[j]) % 60 == 0��
//	ʾ�� 1��
//	���룺[30, 20, 150, 100, 40]
//	�����3
//	���ͣ������Ե��ܳ���ʱ��ɱ� 60 ������
//	(time[0] = 30, time[2] = 150) : �ܳ���ʱ�� 180
//	(time[1] = 20, time[3] = 100) : �ܳ���ʱ�� 120
//	(time[1] = 20, time[4] = 40) : �ܳ���ʱ�� 60
//	ʾ�� 2��
//
//	���룺[60, 60, 60]
//	�����3
//	���ͣ��������Ե��ܳ���ʱ�䶼�� 120�����Ա� 60 ������

#include <iostream>
#include <vector>
using namespace std;


//��ʵ��һ�����Ľ��Ͱѣ����һ������60������Ϊ20����������Ե�����60��������ȻΪ40����ֻ��鿴����Ϊ40�����ĸ�����
//��Ϊ�����Ŀ��ͬʱ��¼����Ϊ20��������Ŀ�����ͳ�������Ŀ�ܺͼ���

int numPairsDivisibleBy60(vector<int>& time) {
	int map[60] = { 0 };
	int sum = 0;
	int i = 0;
	for (i = 0; i < time.size(); i++) {
		sum += map[(60 - time[i] % 60) % 60];
		map[time[i] % 60]++;
	}
	return sum;
}

int main(void) {
	
	cout << "�����������Ŀ" << endl;
	int n;
	cin >> n;

	vector<int> v;
	int num = 0;
	for (int i = 0; i < n; i++) {
		cout << "���������" << i + 1 << "��ʱ��" << endl;
		cin >> num;
		v.push_back(num);
	}

	cout << numPairsDivisibleBy60(v) << endl;

	system("pause");
	return 0;
}