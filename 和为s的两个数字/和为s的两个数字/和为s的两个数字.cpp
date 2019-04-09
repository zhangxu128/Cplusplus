#include<iostream>
#include<vector>
using namespace std;

//����һ����������������һ������S���������в�����������
//ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�
//������� :
//��Ӧÿ�����԰����������������С���������

//˼·��������һ�����Ƿ����������Ϊ�Ѿ������������ҵ������϶��ǳ˻��Ƚ�С��

class Solution {
public:
	bool binary_search(vector<int> array, int k) {
		int left = 0;
		int right = array.size() - 1;
		while (left <= right) {
			int mid = left + right;
			if (array[mid] == k) {
				return true;
			}
			else if (array[mid] > k) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> v;
		for (int i = 0; i < array.size(); i++) {
			if (binary_search(array, sum - array[i])) {
				v.push_back(array[i]);
				v.push_back(sum - array[i]);
				break;
			}
		}
		return v;
	}
};
int main(void) {
	
	int num[] = { 1,2,5,6,7,8,9 };
	vector<int> v(num, num + 7);
	int k = 0;
	cin >> k;
	Solution s;
	vector<int> ret = s.FindNumbersWithSum(v,k);
	cout << ret[0] << " " << ret[1] << endl;
	system("pause");
	return 0;
}