#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{ 1,2,3,2,2,2,5,4,2 }����������2�������г�����5�Σ�
//�������鳤�ȵ�һ�룬������2����������������0��

int MoreThanHalfNum_Solution(vector<int> numbers) {
	int count = 1;
	if (numbers.size() == 1) {
		return numbers[0];
	}
	sort(numbers.begin(), numbers.end());
	int i = 0;
	for (; i < numbers.size() - 1; i++) {
		if (numbers[i] == numbers[i + 1]) {
			count++;
			if (count > numbers.size() / 2) {
				break;
			}
			continue;
		}
		else {
			count = 1;
		}
	}
	if (count > numbers.size() / 2) {
		return numbers[i];
	}
	return 0;
}

int main() {
	int array[] = { 1,2,3,2,2,2,5,4,2 };
	int size = sizeof(array) / sizeof(array[0]);
	vector<int> num(array, array + size);
	cout << MoreThanHalfNum_Solution(num) << endl;
	system("pause");
	return 0;
}