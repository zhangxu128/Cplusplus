#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL) return NULL;
		vector<ListNode*> vec;
		ListNode* list = NULL;
		int flag = 0;
		while (pHead != NULL)
		{
			vec.push_back(pHead);
			pHead = pHead->next;
			for (int i = 0; i < vec.size(); ++i)
			{
				//  if (pHead->next == vec[i])//如果pHead->next在之前的数组中，说明存在环
				if (pHead == vec[i])//如果pHead->next在之前的数组中，说明存在环
				{
					list = vec[i];
					flag = 1;
					break;
				}
			}
			if (flag == 1)break;//找到入口节点，结束
		}
		return list;

	}
};
int main()
{

	//vector<int> vec = { 49,38,65,97,76,13,27,49};
	Solution so;
	ListNode node1(1);
	ListNode* node01 = &node1;
	node01->next = node01;
	ListNode node2(2);
	ListNode* node02 = &node2;
	node01->next = node02;
	ListNode node3(3);
	ListNode* node03 = &node3;
	node02->next = node03;
	node03->next = node02;
	so.EntryNodeOfLoop(node01);
	cout << "入口节点是：" << so.EntryNodeOfLoop(node01)->val << endl;
	system("pause");
	return 0;
}