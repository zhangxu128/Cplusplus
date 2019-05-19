//����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//˵����
//����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
//ʾ�� 1:
//����: [2, 2, 3, 2]
//	��� : 3
//	ʾ�� 2 :
//	���� : [0, 1, 0, 1, 0, 1, 99]
//	��� : 99

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����˼·һ �� ������ж���������Ԫ���Ƿ�ͬ
int singleNumber1(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int i = 0; int j = 1;
	// 0 0 0 1 1 1 2 3 3 3
	while (j < nums.size()) {
		if (nums[i] == nums[j]) {
			j += 2;
			if (j != nums.size() - 1) {
				j++;
				i += 3;
			}
			else {
				return nums[j];
			}
		}
		else {
			return nums[i];
		}
	}
	return nums[0];
}

//�������ʵ��  
//0 ^ x = x,
//x ^ x = 0��
//x & ~x = 0,
//x & ~0 = x;
//-��ô���Ǻܺý�������Ĵ����ˡ�һ��ʼa = 0, b = 0;
//x��һ�γ��ֺ�a = (a ^ x) & ~b�Ľ��Ϊ a = x, b = (b ^ x) & ~a�Ľ��Ϊ0�� ��ʱ��Ϊa = x�ˣ�����b = 0��
//x�ڶ��γ��֣�a = (a ^ x) & ~b, a = (x ^ x) & ~0, a = 0; b = (b ^ x) & ~a ���� b = (0 ^ x) & ~0, b = x;
//x�����γ��֣�a = (a ^ x) & ~b�� a = (0 ^ x) & ~x, a = 0; b = (b ^ x) & ~a ���� b = (x ^ x) & ~0, b = 0; 
//���Գ�������ͬһ������a��b���ն������0.
//ֻ����һ�ε�������������x��һ�γ��ֵĹ��ɿ�֪a = x, b = 0; �����󷵻�a.

int singleNumber2(vector<int>& nums) {
	int a = 0, b = 0;
	for (auto num : nums)
	{
		a = (a ^ num) & ~b;
		b = (b ^ num) & ~a;
	}
	return a;
}

int main(void) {

	cout << "����������Ԫ��" << endl;
	int n;
	cin >> n;
	int num;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	cout << singleNumber1(v) << endl;
	cout << singleNumber2(v) << endl;
	system("pause");
	return 0;
}