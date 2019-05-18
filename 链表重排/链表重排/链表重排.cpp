//给定一个单链表 L：L0→L1→…→Ln - 1→Ln ，
//将其重新排列后变为： L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
//
//示例 1:
//
//给定链表 1->2->3->4, 重新排列为 1->4->2->3.
//示例 2 :
//
//给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



//思路：遍历元链表，用容器封装起来，然后进行重排，最后重新连接


class Solution {
public:
	ListNode* reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL)return NULL;
		vector<ListNode*> v, vv;
		while (head != NULL) {
			v.push_back(head);
			head = head->next;
		}
		ListNode* ret;
		for (int i = 0; i < v.size() / 2; i++) {
			vv.push_back(v[i]);
			vv.push_back(v[v.size() - i - 1]);
		}
		if (v.size() % 2 != 0) {
			vv.push_back(v[v.size() / 2]);
		}
		ret = vv[0];
		for (int i = 0; i < vv.size(); i++) {
			ret->next = vv[i];
			ret = ret->next;
		}
		ret->next = NULL;
		return vv[0];
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
	ListNode* node2 = CreateListNode(1);
	ListNode* node3 = CreateListNode(3);
	ListNode* node4 = CreateListNode(2);
	ListNode* node5 = CreateListNode(5);
	ListNode* node6 = CreateListNode(2);
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = node5;
	node5->next = node6;
	Solution s;
	int n = 3;
	ListNode* ret = s.reorderList(node1);
	Print(ret);
	system("pause");
	return 0;
}

