//������ N ��Сд��ĸ�ַ�����ɵ����� A������ÿ���ַ���������ȡ�
//
//ѡȡһ��ɾ���������У����� A �е�ÿ���ַ�����ɾ����Ӧÿ�����������ַ��� �����µ��ַ����д������¶��γ��С�
//
//���磬�� A = ["abcdef", "uvwxyz"]��ɾ����������{ 0, 2, 3 }��ɾ���� A Ϊ["bef", "vyz"]��
//A ���зֱ�Ϊ["b", "v"], ["e", "y"], ["f", "z"]������ʽ�ϣ��� n ��Ϊ[A[0][n], A[1][n], ..., A[A.length - 1][n]]����
//���裬����ѡ����һ��ɾ������ D����ô��ִ��ɾ������֮��A ����ʣ���ÿһ�ж������� 
//�ǽ��� ���еģ�Ȼ�����㷵�� D.length ����С����ֵ��
//ʾ�� 1��
//���룺["cba", "daf", "ghi"]
//�����1
//���ͣ�
//��ѡ�� D = { 1 }��ɾ���� A ����Ϊ��["c", "d", "g"] ��["a", "f", "i"]����Ϊ�ǽ������С�
//��ѡ�� D = {}����ô A ����["b", "a", "h"] �Ͳ��Ƿǽ��������ˡ�
//ʾ�� 2��
//���룺["a", "b"]
//�����0
//���ͣ�D = {}
//ʾ�� 3��
//���룺["zyx", "wvu", "tsr"]
//�����3
//���ͣ�D = { 0, 1, 2 }
//��ʾ��
//1 <= A.length <= 100
//1 <= A[i].length <= 1000

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDeletionSize(vector<string>& A) {

	if (A.size() == 0 || A.size() == 1)
		return 0;

	int res = 0;
	for (int j = 0; j < A[0].size(); j++)
	{
		for (int i = 0; i < A.size() - 1; i++)
		{
			if (A[i][j] > A[i + 1][j])
			{
				res++;
				break;
			}
		}
	}
	return res;
}

int main(void) {

	string s;
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	int ret = minDeletionSize(v);
	cout << ret << endl;
	system("pause");
	return 0;
}