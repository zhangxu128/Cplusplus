//��Ŀ����
//��дһ��������ȷ��ĳ�ַ���������������ϡ�
//����һ��string A��һ��int n, �����ַ������䳤�ȣ��뷵�����и��ַ����ַ������У���֤�ַ�������С�ڵ���11���ַ������ַ���Ϊ��дӢ���ַ��������е��ַ������ֵ���Ӵ�С����(���ϲ��ظ��ַ���)
//����������
//"ABC"
//���أ�["CBA", "CAB", "BCA", "BAC", "ACB", "ABC"]


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//ע�����resΪ��������
void dfs(string A, vector<string> &res, int cur) {
	int len = A.size();
	if (cur == len - 1) { //�����һ���ַ����Ͳ�����
		res.push_back(A);
		return;
	}
	for (int i = cur; i < len; ++i) {
		swap(A[i], A[cur]); //����Ԫ��
		dfs(A, res, cur + 1); //�ݹ����
		swap(A[i], A[cur]); //�ָ�
	}
}

//������·
vector<string> getPermutation(string A) {
	vector<string> res;
	/*if (A.empty())
		return res;*/
	dfs(A, res, 0);
	sort(res.begin(), res.end(), greater<string>()); //��������
	return res;
}

int main(void) {

	string str;
	cin >> str;
	vector<string> ret = getPermutation(str);

	for (auto e : ret) {
		cout << e << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}