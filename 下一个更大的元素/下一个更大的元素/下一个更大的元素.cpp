//��������û���ظ�Ԫ�ص����� nums1 �� nums2 ������nums1 �� nums2 ���Ӽ���
//�ҵ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
//nums1 ������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء�
//��������ڣ���Ӧλ����� - 1��
//    ʾ�� 1:
//	����: nums1 = [4, 1, 2], nums2 = [1, 3, 4, 2].
//	��� : [-1, 3, -1]
//	���� :
//	����num1�е�����4�����޷��ڵڶ����������ҵ���һ����������֣������� - 1��
//	����num1�е�����1���ڶ�������������1�ұߵ���һ���ϴ������� 3��
//	����num1�е�����2���ڶ���������û����һ����������֣������� - 1��
//	ʾ�� 2 :
//	���� : nums1 = [2, 4], nums2 = [1, 2, 3, 4].
//	��� : [3, -1]
//	���� :
//	����num1�е�����2���ڶ��������е���һ���ϴ�������3��
//	����num1�е�����4���ڶ���������û����һ����������֣������� - 1��
//	ע�� :
//	nums1��nums2������Ԫ����Ψһ�ġ�
//		nums1��nums2 �������С��������1000��


#include <iostream>
#include <vector>


using namespace std;

//˼·����������
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
	vector<int> v;
	// 2 4      4    1    2
	//1 2 3 4   1    3    4    2
	for (int i = 0; i < nums1.size(); i++) {
		int j;
		for (j = 0; j < nums2.size();j++) {
			if (nums1[i] == nums2[j]) {
				while (j < nums2.size()) {
					if (nums2[j] > nums1[i]) {
						v.push_back(nums2[j]);
						break;
					}
					j++;
				}
				if (j == nums2.size()) {
					v.push_back(-1);
					break;
				}
			}
		}
	}
	return v;
}

int main(void){

	cout << "����������1Ԫ�ظ���" << endl;
	int n;
	cin >> n;
	vector<int> v1, v2;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v1.push_back(num);
	}
	cout << "����������2Ԫ�ظ���" << endl;
	int n1;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> num;
		v2.push_back(num);
	}
	vector<int> ret = nextGreaterElement(v1, v2);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0; 
}

