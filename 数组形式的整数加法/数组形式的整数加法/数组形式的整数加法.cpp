#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为[1, 2, 3, 1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234
//输入：A = [9, 9, 9, 9, 9, 9, 9, 9, 9, 9], K = 1
//输出：[1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
//解释：9999999999 + 1 = 10000000000
//提示：
//1 <= A.length <= 10000
//0 <= A[i] <= 9
//0 <= K <= 10000
//如果 A.length > 1，那么 A[0] != 0

vector<int> addToArrayForm(vector<int>& A, int K) {
	string L = to_string(K);                
	reverse(L.begin(), L.end());            
	reverse(A.begin(), A.end());            
	int sum = 0, carr = 0;         
	vector<int> res;
	for (int i = 0; i < L.size() || i < A.size(); i++) {
		int a = (i < A.size()) ? A[i] : 0;       
		int b = (i < L.size()) ? (L[i] - '0') : 0;  
		sum = a + b + carr;   
		carr = sum / 10;    
		//tmp +=tmp+sum%10;
		res.push_back(sum % 10);  
	}
	if (carr == 1)
		res.push_back(1);
	reverse(res.begin(), res.end());
	return res;
}


int main() {

	int n;
	cin >> n;
	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	int k;
	cin >> k;
	vector<int> ret = addToArrayForm(v, k);
	//打印结果
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}