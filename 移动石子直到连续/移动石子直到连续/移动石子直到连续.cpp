    //��öʯ�ӷ����������ϣ�λ�÷ֱ�Ϊ a��b��c��
    //ÿһ�غϣ����Ǽ�������öʯ�ӵ�ǰ�ֱ�λ��λ�� x, y, z �� x < y < z����λ�� x ������λ�� z ����һöʯ�ӣ�
	//������ʯ���ƶ���ĳһ����λ�� k �������� x < k < z �� k != y��
	//�����޷������κ��ƶ�ʱ��������Щʯ�ӵ�λ������ʱ����Ϸ������
	//Ҫʹ��Ϸ�����������ִ�е���С������ƶ������ֱ��Ƕ��٣� �Գ���Ϊ 2 ��������ʽ���ش𰸣�
	//answer = [minimum_moves, maximum_moves]
	//ʾ�� 1��
	//���룺a = 1, b = 2, c = 5
	//�����[1, 2]
	//���ͣ���ʯ�Ӵ� 5 �ƶ��� 4 ���ƶ��� 3���������ǿ���ֱ�ӽ�ʯ���ƶ��� 3��
	//ʾ�� 2��
	//���룺a = 4, b = 3, c = 2
	//�����[0, 0]
	//���ͣ������޷������κ��ƶ���


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> numMovesStones(int a, int b, int c) {
	vector<int> vec{ a, b, c };
	sort(vec.begin(), vec.end());
	int mini = 0, maxi = 0;
	int dist1 = vec[1] - vec[0] - 1;
	int dist2 = vec[2] - vec[1] - 1;
	if (dist1 == 0 || dist2 == 0)
		mini = (dist1 == dist2) ? 0 : 1;
	else if (dist1 == 1 || dist2 == 1)
		mini = 1;
	else
		mini = 2;
	maxi = dist1 + dist2;
	return { mini, maxi };
}

int main(void) {

	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	vector<int> v = numMovesStones(a, b, c);
	cout << v[0] << " " << v[1] << endl;
	system("pause");
	return 0;
}