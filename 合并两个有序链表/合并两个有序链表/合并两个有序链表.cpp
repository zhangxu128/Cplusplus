#include<iostream>
using namespace std;

//将两个有序链表合并为一个新的有序链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
		{
			return l2;
		}
		if (l2 == NULL)
		{
			return l1;
		}
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		ListNode* last = NULL;
		ListNode* ret = NULL;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val <= l2->val) {
				ListNode* next = l1->next;
				l1->next = NULL;
				if (ret == NULL)
				{
					ret = l1;
					last = l1;
				}
				else {
					last->next = l1;
					last = l1;
				}
				l1 = next;
			}
			else {
				ListNode* next = l2->next;
				l2->next = NULL;
				if (ret == NULL)
				{
					ret = l2;
					last = l2;
				}
				else {
					last->next = l2;
					last = l2;
				}
				l2 = next;
			}
		}
		if (l1 == NULL)
		{
			last->next = l2;
		}
		if (l2 == NULL)
		{
			last->next = l1;
		}
		return ret;
	}
};




ListNode* CreateListNode(int val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = val;
	node->next = NULL;
	return node;
}

void Print(ListNode* head) {
	ListNode* cur = head;
	while (cur->next != NULL) {
		printf("%p(%d) --> ", cur, cur->val);
		cur = cur->next;
	}
	printf("%p(%d) --> NULL", cur, cur->val);
	printf("\n");
}

int main() {
	ListNode* node1 = CreateListNode(1);
	ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(4);
	ListNode* node4 = CreateListNode(1);
	ListNode* node5 = CreateListNode(3);
	ListNode* node6 = CreateListNode(4);
	node1->next = node2; node2->next = node3;
	node3->next = NULL; node4->next = node5;
	node5->next = node6; node6->next = NULL;
	Print(node1);
	Print(node4);
	cout << "合并两个有序链表之后，新链表如下：" << endl;
	Solution s;
	ListNode* ret = s.mergeTwoLists(node1, node4);
	Print(ret);
	system("pause");
	return 0;
}