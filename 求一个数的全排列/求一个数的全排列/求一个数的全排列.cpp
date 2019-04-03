#include<iostream>
#include<vector>
using namespace std;


//交换两个数
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

//求数的全排列
void Perm(vector<int> v,int low,int high){
	if (v.size() == 0) {
		return;
	}
	if (low == high) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	else {
		for (int i = low; i <= high; i++) {
			swap(v[i], v[low]);
			Perm(v, low + 1, high);
			swap(v[i], v[low]);
		}
	}

};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Perm(v, 0, v.size() - 1);
	system("pause");
	return 0;
}