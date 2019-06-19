//��Ŀ����
//���������������У������е�K�����������{ 45��67��33��21 }����2����Ϊ45
//�������� :
//�����һ��Ϊ�������У������ÿո�ָ����磺45 67 33 21
//����ڶ���һ������K��K�����鳤�ȷ�Χ�ڣ��磺2
//������� :
//�����K�����������Ϊ��2������45


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//topK���⣬�������ȼ����м���
int getTopK(vector<int>& v, int k) {
	priority_queue<int> p(v.begin(), v.end());

	for(int i = 0; i < k; i++) {
		p.pop();
	}
	return p.top();
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int K;
	cin >> K;
	cout << getTopK(v, K) << endl;

	system("pause");
	return 0;
}