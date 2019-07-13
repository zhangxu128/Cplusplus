//题目描述
//给定一个非空的整数数组，从数组第一个元素(下标为0的元素)开始遍历进行移动，下一次向后或向前移动 该元素的值 的位数（值为正数向后移动，值为负数向前移动，值为零不移动），依次类推进行移动，若某次移动数组出现越界，则说明数组可以跳出，返回true；不能跳出则返回false；（加分项：也可考虑不增加使用其他集合数组辅助完成算法）
//例1：
//输入数组a[5] = [1, 2, 3, 2, 5]; 从第一个元素开始a[0] = 1, 下次向后移动1位到第二个元素a[1] = 2, 再次向后移动2位到第四个元素a[3], 因为下次向后移动2位(a[3] = 2)后, 向后数组越界, 即跳出数组, 输出true;
//例2：
//输入数组a[2] = [1, -3]; 从第一个元素开始a[0] = 1, 下次移动1位到第二个元素a[1] = -3, 再次向前移动3位后, 向前数组越界, 即跳出数组, 输出true;
//输入描述:
//一个非空的整数数组(至少有一个元素, 可正可负)
//输出描述 :
//按规则移动后是否能跳出数组
//示例1
//输入
//[1]
//输出
//true
//说明
//示例2
//输入
//[2, 1, 3, 5]
//输出
//true
//说明
//示例3
//输入
//[2, 1, -3]
//输出
//true


#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> m_array;
	int s;
	getchar();
	while (1) {
		cin >> s;
		m_array.push_back(s);
		if (getchar() == ']')
			break;
	}
	int index = 0;
	int length = m_array.size() + 1;
	while (length--) {
		if (index < 0 || index >= m_array.size()) {
			cout << "true";
			return 0;
		}
		if (m_array[index] == 0) {
			cout << "false";
			return 0;
		}
		index = index + m_array[index];
	}
	cout << "false" << endl;
	system("pause");
	return 0;
}