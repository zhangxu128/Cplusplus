//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢һ�����֡�
//
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��
//
//ʾ�� 1:
//
//����: [1, 2, 3]
//	��� : [1, 2, 4]
//	���� : ���������ʾ���� 123��
//	ʾ�� 2 :
//
//	���� : [4, 3, 2, 1]
//	��� : [4, 3, 2, 2]
//	���� : ���������ʾ���� 4321��

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	//�����������û��9ֱ�Ӽ�һ
	//��9��0��ѭ��������ֱ����Ϊ9

	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] < 9) {
			digits[i] += 1;
			return digits;
		}
		else {
			digits[i] = 0;
		}
	}
	vector<int> v;
	v.push_back(1);
	for (int i = 0; i < digits.size(); i++) {

		v.push_back(digits[i]);
	}
	return v;
}

int main(void) {
	
	cout << "����������Ԫ��:";
	int n;
	cin >> n;
	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	vector<int> ret = plusOne(v);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}