//�����ں���������� �����֣�Bulls and Cows����Ϸ����д��һ��������������Ѳ¡�
//ÿ�����²�������һ����ʾ���������ж���λ���ֺ�ȷ��λ�ö��¶��ˣ���Ϊ��Bulls��, ��ţ����
//�ж���λ���ֲ¶��˵���λ�ò��ԣ���Ϊ��Cows��, ��ţ����������ѽ��������ʾ�����£�ֱ���³��������֡�
//��д��һ�������������ֺ����ѵĲ²���������ʾ�ĺ������� A ��ʾ��ţ���� B ��ʾ��ţ��
//��ע���������ֺ����ѵĲ²��������ܺ����ظ�����
//ʾ�� 1
//����: secret = "1807", guess = "7810"
//	��� : "1A3B"
//	���� : 1 ��ţ�� 3 ��ţ����ţ�� 8����ţ�� 0, 1 �� 7��
//	ʾ�� 2 :
//	���� : secret = "1123", guess = "0111"
//	��� : "1A1B"
//	���� : ���Ѳ²����еĵ�һ�� 1 �ǹ�ţ���ڶ���������� 1 �ɱ���Ϊ��ţ��
//	˵�� : ����Լ����������ֺ����ѵĲ²�����ֻ�������֣��������ǵĳ�����Զ��ȡ�


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//�ȱ���һ���ҹ�ţ������ͬΪ����������
//Ȼ�������ֱ�ӱȽ���ĸţ
string getHint(string secret, string guess) {
	int cntA = 0;
	int cntB = 0;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < secret.size(); i++) {
		if (secret[i] == guess[i]) {
			cntA++;
		}
		else {
			v1.push_back(secret[i]);
			v2.push_back(guess[i]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	while (!v1.empty() && !v2.empty())
	{
		if (v1[v1.size() - 1] == v2[v2.size() - 1])
		{
			cntB++;
			v1.pop_back();
			v2.pop_back();
		}
		else if (v1[v1.size() - 1] > v2[v2.size() - 1])
		{
			v1.pop_back();
		}
		else
		{
			v2.pop_back();
		}
	}
	return to_string(cntA) + "A" + to_string(cntB) + "B";
}

int main(void) {

	string s1, s2;
	cin >> s1 >> s2;
	cout << getHint(s1, s2) << endl;
	system("pause");
	return 0;
}