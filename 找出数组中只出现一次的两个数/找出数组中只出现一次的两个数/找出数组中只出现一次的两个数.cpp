#include<iostream>
#include<vector>
using namespace std;


//��Ŀ����
//һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int num = 0;
		int count = 0;
		for (int i = 0; i < data.size(); i++) {
			num ^= data[i];  //���ֻ����һ�ε��������������
		}
		//cout << num << endl;
		for (int i = 0; i < 32; i++) {        
			if (((num >> i) & 1) != 1) {
				count++;      //�ҵ���һ��Ϊ1��λ
			}
			else {
				break;
			}
		}
		for (int i = 0; i < data.size(); i++) {
			if (((data[i] >> count) & 1) == 1) {
				*num1 ^= data[i];
			}
			else {
				*num2 ^= data[i];
			}
		}
	}
};

int main()
{
	vector<int> v;
	v.push_back(12);
	v.push_back(90);
	v.push_back(8);
	v.push_back(6);
	v.push_back(12);
	v.push_back(90);
	v.push_back(10);
	v.push_back(6);
	int num1 = 0;
	int num2 = 0;
	Solution s;
	s.FindNumsAppearOnce(v,&num1,&num2);
	cout << num1 << " " << num2 << endl;
	system("pause");
	return 0;
}