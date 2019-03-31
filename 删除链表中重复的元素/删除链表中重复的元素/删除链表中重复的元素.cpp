#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
//重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
ListNode* deleteDuplication(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL) return pHead;
	else
	{
		//新建一个节点，防止头结点要被删除
		ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
		newHead->next = pHead;
		ListNode* pre = newHead;
		ListNode* p = pHead;
		ListNode* next = NULL;
		while (p != NULL && p->next != NULL)
		{
			next = p->next;
			if (p->val == next->val)//如果当前节点的值和下一个节点的值相等
			{
				while (next != NULL && next->val == p->val)//向后重复查找
					next = next->next;
				pre->next = next;//指针赋值，就相当于删除
				p = next;
			}
			else//如果当前节点和下一个节点值不等，则向后移动一位
			{
				pre = p;
				p = p->next;
			}
		}
		return newHead->next;//返回头结点的下一个节点
	}
}


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
	printf("%p(%d) --> NULL",cur, cur->val);
	printf("\n");
}

int main(){
	ListNode* node1 = CreateListNode(1);
	ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(3);
	ListNode* node4 = CreateListNode(3); 
	ListNode* node5 = CreateListNode(4);
	ListNode* node6 = CreateListNode(4);
	ListNode* node7 = CreateListNode(5);
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = node5;
	node5->next = node6; node6->next = node7;
	Print(node1);
	deleteDuplication(node1);
	Print(node1);
	system("pause");
	return 0;
}