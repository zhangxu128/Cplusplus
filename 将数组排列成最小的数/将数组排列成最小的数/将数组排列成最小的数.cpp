#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//��Ŀ����
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{ 3��32��321 }�����ӡ���������������ųɵ���С����Ϊ321323��


class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		string ret;   //���ܷ���ֵ
		vector<string> numbers_str;
		for (int i = 0; i < numbers.size(); ++i) { 
			//�������е�����ת���ַ���������������
			numbers_str.push_back(to_string(numbers[i]));
		}
		//�����Զ�������
		sort(numbers_str.begin(), numbers_str.end(), MyCompare);
		for (int i = 0; i < numbers_str.size(); ++i){
			//ֱ����Ӿ�����С���ַ�������
			ret += numbers_str[i];
		}
		return ret;
	}
private:    //�Զ�������
	//�ص�   ����С��
	static bool MyCompare(const string &str1, const string &str2) {
		return str1 + str2 < str2 + str1;
	}
};

int main() {

	vector<int>v;
	v.push_back(12);
	v.push_back(93);
	v.push_back(4);

	Solution s;

	string str = s.PrintMinNumber(v);
	cout << str << endl;

	system("pause");
	return 0;
}