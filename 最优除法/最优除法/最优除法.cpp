//����һ�������������ڵ�����֮�佫����и���������������磬[2, 3, 4] -> 2 / 3 / 4 ��
//���ǣ������������λ�����������Ŀ�����ţ����ı����������ȼ�������Ҫ�ҳ���ô������ţ����ܵõ����Ľ����
//���ҷ�����Ӧ���ַ�����ʽ�ı��ʽ����ı��ʽ��Ӧ�ú�����������š�
//ʾ����
//���� : [1000, 100, 10, 2]
//	��� : "1000/(100/10/2)"
//	���� :
//	1000 / (100 / 10 / 2) = 1000 / ((100 / 10) / 2) = 200
//	���ǣ����¼Ӵֵ����� "1000/((100/10)/2)" ������ģ�
//	��Ϊ���ǲ���Ӱ����������ȼ�����������Ҫ���� "1000/(100/10/2)"��
//	�������� :
//1000 / (100 / 10) / 2 = 50
//1000 / (100 / (10 / 2)) = 50
//1000 / 100 / 10 / 2 = 0.5
//1000 / 100 / (10 / 2) = 2
//˵�� :
//	��������ĳ�����[1, 10] ֮�䡣
//	������ÿ��Ԫ�صĴ�С����[2, 1000] ֮�䡣
//	ÿ����������ֻ��һ�����ų����⡣

#include <iostream>
#include <vector>
#include <string>
using namespace  std;

string optimalDivision(vector<int>& nums) {
	string res = to_string(nums[0]);
	if (nums.size() == 1) return res;

	string tmp = "";
	for (int i = 1; i < nums.size(); i++) {
		tmp = tmp + to_string(nums[i]);
		if (i < nums.size() - 1) tmp = tmp + "/";
	}

	if (nums.size() == 2) return res + "/" + tmp;
	else return res + "/(" + tmp + ")";
	return res;
}

int main(void) {

	cout << "��������Ԫ�ظ���" << endl;
	int n;
	cin >> n;
	cout << "��������Ԫ��" << endl;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << optimalDivision(v) << endl;
	system("pause");
	return 0;
}
