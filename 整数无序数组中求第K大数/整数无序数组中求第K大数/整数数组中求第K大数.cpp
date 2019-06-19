//题目描述
//给定无序整数序列，求其中第K大的数，例如{ 45，67，33，21 }，第2大数为45
//输入描述 :
//输入第一行为整数序列，数字用空格分隔，如：45 67 33 21
//输入第二行一个整数K，K在数组长度范围内，如：2
//输出描述 :
//输出第K大的数，本例为第2大数：45


#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//topK问题，采用优先级队列即可
int getTopK(vector<int>& v, int k) {
	priority_queue<int> p(v.begin(), v.end());

	for(int i = 0; i < k; i++) {
		p.pop();
	}
	return p.top();
}

int main(void) {

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int K;
	cin >> K;
	cout << getTopK(v, K) << endl;

	system("pause");
	return 0;
}