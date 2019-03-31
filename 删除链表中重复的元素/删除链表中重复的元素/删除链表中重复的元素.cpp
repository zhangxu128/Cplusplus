#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
//�ظ��Ľ�㲻��������������ͷָ�롣
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
ListNode* deleteDuplication(ListNode* pHead){
	if (pHead == NULL || pHead->next == NULL) return pHead;
	else
	{
		//�½�һ���ڵ㣬��ֹͷ���Ҫ��ɾ��
		ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
		newHead->next = pHead;
		ListNode* pre = newHead;
		ListNode* p = pHead;
		ListNode* next = NULL;
		while (p != NULL && p->next != NULL)
		{
			next = p->next;
			if (p->val == next->val)//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ���
			{
				while (next != NULL && next->val == p->val)//����ظ�����
					next = next->next;
				pre->next = next;//ָ�븳ֵ�����൱��ɾ��
				p = next;
			}
			else//�����ǰ�ڵ����һ���ڵ�ֵ���ȣ�������ƶ�һλ
			{
				pre = p;
				p = p->next;
			}
		}
		return newHead->next;//����ͷ������һ���ڵ�
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