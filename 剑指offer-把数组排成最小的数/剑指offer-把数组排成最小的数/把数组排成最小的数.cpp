//��Ŀ����
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{ 3��32��321 }��
//���ӡ���������������ųɵ���С����Ϊ321323��

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool MyCompare(const string &str1, const string &str2) {
	return str1 + str2 < str2 + str1;
}

string PrintMinNumber(vector<int> numbers) {
	string ret;   //���ܷ���ֵ
	vector<string> numbers_str;
	for (int i = 0; i < numbers.size(); ++i) {
		//�������е�����ת���ַ���������������
		numbers_str.push_back(to_string(numbers[i]));
	}
	//�����Զ�������
	sort(numbers_str.begin(), numbers_str.end(), MyCompare);
	for (int i = 0; i < numbers_str.size(); ++i) {
		//ֱ����Ӿ�����С���ַ�������
		ret += numbers_str[i];
	}
	return ret;
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << PrintMinNumber(v) << endl;
	system("pause");
	return 0;
}