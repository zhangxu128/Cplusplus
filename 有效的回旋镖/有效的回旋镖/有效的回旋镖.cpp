//�����ڶ���Ϊһ�������㣬��Щ�������ͬ�Ҳ���һ��ֱ���ϡ�
//����ƽ������������ɵ��б��ж���Щ���Ƿ���Թ��ɻ����ڡ�
//ʾ�� 1��
//���룺[[1, 1], [2, 3], [3, 2]]
//�����true
//ʾ�� 2��
//���룺[[1, 1], [2, 2], [3, 3]]
//�����false
//��ʾ��
//points.length == 3
//points[i].length == 2
//0 <= points[i][j] <= 100

#include <iostream>
#include <vector>


using namespace std;

//���������ķ����ж�����һ���Ƿ����
bool isBoomerang(vector<vector<int>>& points) {
	int x1 = points[0][0];
	int y1 = points[0][1];
	int x2 = points[1][0];
	int y2 = points[1][1];
	int x3 = points[2][0];
	int y3 = points[2][1];

	return (y2 - y1)*(x3 - x2) != (y3 - y2)*(x2 - x1);
}
int main(void) {
	vector<int> tmp(2);
	vector<vector<int>> v(3,tmp);
	int num;
	for (int i = 0; i < v.size(); i++) {
	
		for (int j = 0; j < v[i].size(); j++) {
			cin >> num;
			v[i][j] = num;
		}
	}

	if (isBoomerang(v)) {
		cout << "����һ��,���ܹ��ɻ�����" << endl;
	}
	else {
		cout << "���㲻��һ�ߣ����Թ��ɻ�����" << endl;
	}
	system("pause");
	return 0;
}