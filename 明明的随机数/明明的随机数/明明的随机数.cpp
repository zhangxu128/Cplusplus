//��Ŀ����
//��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ�
//�����ü����������N��1��1000֮������������N��1000�������������ظ������֣�
//ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�
//Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣
//����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ���(ͬһ��������������ܻ��ж������ݣ�
//	ϣ���������ȷ����)��


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	set<int>s;
	for (int i = 0; i < n; i++) {
		int num = 0;
		cin >> num;
		s.insert(num);
	}
	//sort(s.begin(), s.end());
	//set�Դ�ȥ�ؼ�����
	for (auto e : s) {
		cout << e << endl;
	}

	system("pause");
	return 0;
}