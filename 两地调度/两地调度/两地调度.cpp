//��˾�ƻ����� 2N �ˡ��� i �˷��� A �еķ���Ϊ costs[i][0]������ B �еķ���Ϊ costs[i][1]��
//���ؽ�ÿ���˶��ɵ�ĳ�����е���ͷ��ã�Ҫ��ÿ�����ж��� N �˵ִ
//ʾ����
//���룺[[10, 20], [30, 200], [400, 50], [30, 20]]
//�����110
//���ͣ�
//��һ����ȥ A �У�����Ϊ 10��
//�ڶ�����ȥ A �У�����Ϊ 30��
//��������ȥ B �У�����Ϊ 50��
//���ĸ���ȥ B �У�����Ϊ 20��
//����ܷ���Ϊ 10 + 30 + 50 + 20 = 110��ÿ�����ж���һ����������ԡ�



#include <iostream>
#include <vector>


int twoCitySchedCost(vector<vector<int>>& costs) {
	int res = 0;
	vector<int> dp;
	for (int i = 0; i < costs.size(); i++)
	{
		res += costs[i][0];
		dp.push_back(costs[i][1] - costs[i][0]);
	}
	sort(dp.begin(), dp.end());
	for (int i = 0; i < dp.size() / 2; i++)
	{
		res += dp[i];
	}
	return res;
}

int main(void) {




	system("pause");
	return 0;
}