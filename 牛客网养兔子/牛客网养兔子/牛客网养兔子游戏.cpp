// write your code here cpp

//��Ŀ����
//
//һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 
//ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�
//�������� :
//�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
//������� :
//��Ӧ�����n���м�ֻ����(����û��������������)��


#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	while (cin >> n) {
		vector<long long>v(91);
		v[1] = 1;
		v[2] = 2;
		for (int i = 3; i < n + 1; i++) {
			v[i] = v[i - 1] + v[i - 2];
		}
		cout << v[n] << endl;
	}
	system("pause");
	return 0;
}