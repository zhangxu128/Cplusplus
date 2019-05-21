//��������Ϊ n ���������� nums������ n > 1������������� output ������ output[i] 
//���� nums �г� nums[i] ֮�������Ԫ�صĳ˻���
//ʾ�� :
//����: [1, 2, 3, 4]
//	��� : [24, 12, 8, 6]
//	˵�� : �벻Ҫʹ�ó��������� O(n) ʱ�临�Ӷ�����ɴ��⡣
//	���ף�
//	������ڳ����ռ临�Ӷ�����������Ŀ�𣿣� ���ڶԿռ临�Ӷȷ�����Ŀ�ģ�������鲻����Ϊ����ռ䡣��


#include <iostream>
#include <vector>

using namespace std;


//�ֱ����ұ����ۻ�����
vector<int> productExceptSelf(vector<int>& nums) {
	int left = 1;
	int right = 1;
	vector<int> output;
	output.resize(nums.size());
	int len = nums.size();
	for (int i = 0; i < len; i++) {
		output[i] = left;
		left *= nums[i];
	}
	for (int j = len - 1; j >= 0; j--) {
		output[j] *= right;
		right *= nums[j];
	}
	return output;
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
	vector<int> ret = productExceptSelf(v);
	for (int i : ret) {
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}