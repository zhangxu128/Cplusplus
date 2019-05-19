//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//示例 1:
//输入: [2, 2, 3, 2]
//	输出 : 3
//	示例 2 :
//	输入 : [0, 1, 0, 1, 0, 1, 99]
//	输出 : 99

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//常规思路一 ， 排序后，判断相邻两个元素是否不同
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

//利用异或实现  
//0 ^ x = x,
//x ^ x = 0；
//x & ~x = 0,
//x & ~0 = x;
//-那么就是很好解释上面的代码了。一开始a = 0, b = 0;
//x第一次出现后，a = (a ^ x) & ~b的结果为 a = x, b = (b ^ x) & ~a的结果为0， 此时因为a = x了，所以b = 0。
//x第二次出现：a = (a ^ x) & ~b, a = (x ^ x) & ~0, a = 0; b = (b ^ x) & ~a 化简， b = (0 ^ x) & ~0, b = x;
//x第三次出现：a = (a ^ x) & ~b， a = (0 ^ x) & ~x, a = 0; b = (b ^ x) & ~a 化简， b = (x ^ x) & ~0, b = 0; 
//所以出现三次同一个数，a和b最终都变回了0.
//只出现一次的数，按照上面x第一次出现的规律可知a = x, b = 0; 因此最后返回a.

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

	cout << "请输入数组元素" << endl;
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