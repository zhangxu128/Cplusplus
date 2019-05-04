//����ֻ�� "I"�����󣩻� "D"����С�����ַ��� S ���� N = S.length��
//����[0, 1, ..., N] ���������� A ʹ�ö������� i = 0, ..., N - 1�����У�
//��� S[i] == "I"����ô A[i] < A[i + 1]
//	��� S[i] == "D"����ô A[i] > A[i + 1]
//	ʾ�� 1��
//	�����"IDID"
//	�����[0, 4, 1, 3, 2]
//	ʾ�� 2��
//	�����"III"
//	�����[0, 1, 2, 3]
//	ʾ�� 3��
//	�����"DDI"
//	�����[3, 2, 0, 1]
//	��ʾ��
//	1 <= S.length <= 1000
//	S ֻ�����ַ� "I" �� "D"��

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string S)
	{
		int N = S.size();        //�ַ����ĳ���
		vector<int> a(N + 1);    //����һ���������0-N�����Ԫ��
		vector<int> b(N + 1);    //����һ����������ڹ����������0-N��Ԫ��
		int couts1 = 0;          //������aǰ�濪ʼȡԪ��
		int couts2 = N;          //������a���濪ʼȡԪ��
		for (int j = 0; j < N + 1; j++) //��a�д�0-N
		{
			a[j] = j;
		}
		for (int i = 0; i < N; i++)    //����S�е��ַ�
		{
			if (S[i] == 'I')       //���ڡ�I�������a��ǰ��ȡֵ����b
			{
				b[i] = a[couts1];
				couts1++;
			}
			else                //���ڡ�D�������a�ĺ���ȡֵ����b
			{
				b[i] = a[couts2];
				couts2--;
			}
		}
		b[N] = a[couts2];   //b�����һ��Ԫ��û�����ݣ���ʱa[couts1]��a[couts2]
						  //��ָ��a��û��ʹ�õ����һ��Ԫ��,���丳ֵ��b���һ��Ԫ��
		return b;
	}
};

int main(void) {

	string s;
	cin >> s;
	Solution sol;
	vector<int> v = sol.diStringMatch(s);
	for (int i = 0; i < v.size(); i++) {

		cout << v[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}