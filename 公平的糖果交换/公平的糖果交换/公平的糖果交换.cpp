//����˿�ͱ����в�ͬ��С���ǹ�����A[i] �ǰ���˿ӵ�еĵ� i ���ǵĴ�С��B[j] �Ǳ���ӵ�еĵ� j ���ǵĴ�С��
//��Ϊ���������ѣ����������뽻��һ���ǹ������������������Ƕ�����ͬ���ǹ�������
//��һ����ӵ�е��ǹ�����������ӵ�е��ǹ�����С���ܺ͡���
//����һ���������� ans������ ans[0] �ǰ���˿���뽻�����ǹ����Ĵ�С��ans[1] �� Bob ���뽻�����ǹ����Ĵ�С��
//����ж���𰸣�����Է��������κ�һ������֤�𰸴��ڡ�
//ʾ�� 1
//���룺A = [1, 1], B = [2, 2]
//�����[1, 2]
//ʾ�� 2��
//���룺A = [1, 2], B = [2, 3]
//�����[1, 2]
//ʾ�� 3��
//���룺A = [2], B = [1, 3]
//�����[2, 3]
//ʾ�� 4��
//���룺A = [1, 2, 5], B = [2, 4]
//�����[5, 4]
//��ʾ��
//1 <= A.length <= 10000
//1 <= B.length <= 10000
//1 <= A[i] <= 100000
//1 <= B[i] <= 100000
//��֤����˿�뱫�����ǹ�������ͬ��
//�𰸿϶����ڡ�

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
	int sumA = accumulate(A.begin(), A.end(), 0);
	int	sumB = accumulate(B.begin(), B.end(), 0);
	int diff = (sumA - sumB) / 2;
	for (int i = 0; i < A.size(); i++)
		if (find(B.begin(), B.end(), A[i] - diff) != B.end())
			return { A[i],A[i] - diff };
	return {};
}


int main(void) {

	cout << "������A���ǹ���" << endl;
	int a;
	cin >> a;
	cout << "����ÿ���ǹ��Ĵ�Сֵ" << endl;
	int numa;
	vector<int> va;
	for (int i = 0; i < a; i++) {
		cin >> numa;
		va.push_back(numa);
	}

	cout << "������B���ǹ���" << endl;
	int b;
	cin >> b;
	cout << "����ÿ���ǹ��Ĵ�Сֵ" << endl;
	int numb;
	vector<int> vb;
	for (int i = 0; i < b; i++) {
		cin >> numb;
		vb.push_back(numb);
	}
	vector<int>v = fairCandySwap(va, vb);
	cout << v[0] << " " << v[1] << endl;
	system("pause");
	return 0;
}
