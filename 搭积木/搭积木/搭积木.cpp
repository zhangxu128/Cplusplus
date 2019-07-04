//��Ŀ����
//С����һ���ӳ����εĻ�ľ�����һ����ľA�ĳ��Ϳ�����������һ����ľB�ĳ��Ϳ����ľA���Դ��ڻ�ľB�����档�����С���ر���֪����һ���ӻ�ľ�����Դ���ٲ㣬���ܰ�������취��
//����ÿһ�������εĳ�L�Ϳ�W��Ϊ������������1 <= W <= L <= INT_MAX, �������泤���εĸ���ΪN, ���� 1 <= N <= 1000000.
//��������ﹲ��5����ľ�ֱ�Ϊ(2, 2), (2, 4), (3, 3), (2, 5), (4, 5), �����ж���Щ��ľ�����Դ��4��, ��Ϊ(2, 2) < (2, 4) < (2, 5) < (4, 5)��
//	�������� :
//��һ��Ϊ��ľ���ܸ��� N
//
//֮��һ����N�У��ֱ��Ӧ��ÿһ����ľ�Ŀ�W�ͳ�L
//������� :
//����ܹ����Դ�Ĳ���
//ʾ��1
//����
//5
//2 2
//2 4
//3 3
//2 5
//4 5
//���
//4

/*
�Գ����εĿ�w���򣬱��⻯��Ϊ�Գ�l������������С�
����ֻ���� ����������� �ĳ��ȣ����Ż���O(nlogn)
���Ȿ���ʱ����Ʒǳ��ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > vp(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &vp[i].first, &vp[i].second);
	}
	sort(vp.begin(), vp.end());
	vector<int> res(n);
	int start = 0;
	for (int i = 0; i < n; i++) {
		if (start == 0 || vp[i].second >= res[start - 1]) {
			res[start] = vp[i].second;
			start++;
		}
		else {
			auto it = lower_bound(res.begin(), res.begin() + start, vp[i].second);
			*it = vp[i].second;
		}
	}
	cout << start << endl;
	system("pause");
	return 0;
}