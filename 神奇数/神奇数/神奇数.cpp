
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsNum(int &in) {
	vector<int> arry;
	int num = in;
	int half = 0;
	while (num) {//�����ִ�ɢ����arry����
		arry.push_back(num % 10);
		half += num % 10;
		num /= 10;
	}
	if (half % 2 != 0) return false;
	half /= 2;
	vector<int> dp(half + 1); //֮����һС���õ���01�������ж���װ����������һ���Ƿ���ȡ�
	for (int i = 0; i < arry.size(); i++) {
		for (int j = half; j >= arry[i]; j--) {
			dp[j] = max(dp[j], dp[j - arry[i]] + arry[i]);
		}
	}
	return dp[half] == half;
}



int main()
{
	int l, r;
	cin >> l >> r;
	int count = 0;
	for (int i = l; i <= r; i++) {
		if (IsNum(i))
			count++;//�����������������+1
	}
	cout << count << endl;
	system("pause");
	return 0;
}