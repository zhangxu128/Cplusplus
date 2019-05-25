//���������� �������� ָ�������������ֵĶ���������Ӧλ��ͬ��������
//����һ�������У�����������֮�人��������ܺ͡�
//ʾ�� :
//����: 4, 14, 2
//	��� : 6
//	���� : �ڶ����Ʊ�ʾ�У�4��ʾΪ0100��14��ʾΪ1110��2��ʾΪ0010����������ʾ��Ϊ�����ֺ���λ֮���ϵ��
//	���Դ�Ϊ��
//	HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

#include <iostream>
#include <vector>

using namespace std;


//˼·һ��˫��ѭ��  ����  ��¼��ͬλ����ʹ�ó�ʱ
//        ȡ��ÿ������ÿλ�Ƚϼ�¼     
int totalHammingDistance(vector<int>& nums) {
	int dist = 0;
	for (int i = 0; i < 8 * sizeof(int); i++) {
		int b1 = 0;
		for (int n : nums) {
			b1 += n >> i & 1;
		}
		dist += b1 * (nums.size() - b1);
	}
	return dist;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << totalHammingDistance(v) << endl;
	system("pause");
	return 0;
}