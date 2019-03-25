#include<iostream>

using namespace std;

typedef struct ListNode
{
	int value;
	struct ListNode* next;
}ListNode;

bool isPalindrome(ListNode* head) 
{
	// ��������
	int len = 0;
	for (ListNode *cur = head; cur != NULL; cur = cur->next) {
		len++;
	}

	// �ҵ�������м���
	ListNode *middle = head;
	for (int i = 0; i < len / 2; i++) {
		middle = middle->next;
	}

	// ��������ĺ�벿��
	ListNode *node = middle;
	ListNode *rhead = NULL;
	while (node != NULL) {
		ListNode *next = node->next;

		node->next = rhead;
		rhead = node;

		node = next;
	}

	// �ж��Ƿ��ǻ���
	ListNode *p1 = head;
	ListNode *p2 = rhead;
	while (p1 != NULL && p2 != NULL) {
		if (p1->value != p2->value) {
			return false;
		}

		p1 = p1->next;
		p2 = p2->next;
	}

	return true;
}

void PushBack(ListNode* head, int v)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->value = v;
	if (head == NULL)
	{
		head = node;
		node->next = NULL;
	}
	else
	{
		ListNode* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
		node->next = NULL;
	}
}

int main()
{
	ListNode* p = NULL;
	PushBack(p, 1);
	PushBack(p, 2);
	PushBack(p, 3);
	PushBack(p, 2);
	PushBack(p, 1);
	cout << isPalindrome(p) << endl;
	system("pause");
	return 0;
}