#include<iostream>
using namespace std;

//题目描述
//有一个数组a[N]顺序存放0~N - 1，要求每隔两个数删掉一个数，
//到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。
//以8个数(N = 7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),
//如此循环直到最后一个数被删除。
//输入描述 :
//每组数据为一行一个整数n(小于等于1000)，为数组成员数, 如果大于1000，则对a[999]进行计算。

#define null 0
struct node
{
	int data;
	node* next;
};

int delnum(int size) {
	node* head = new node;
	head->data = 0;
	head->next = null;
	node* p = head;
	for (int i = 1; i < size; i++)
	{
		node* tmp = new node;
		tmp->data = i;
		tmp->next = null;
		head->next = tmp;
		head = head->next;
	}
	head->next = p;
	while (p != p->next)
	{
		p->next->next = p->next->next->next;
		p = p->next->next;
	}
	return p->data;
}

int main(void) {

	int n = 0;
	cin >> n;
	if (n >= 1000) {
		n = 999;
	}
	int ret = delnum(n);
	cout << ret << endl;
	system("pause");
	return 0;
}