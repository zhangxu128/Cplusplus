#include<iostream>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};


void Print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		printf("%p(%d)-->  ", cur, cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//复制随机链表
Node* CopyRandomList(Node* head)
{
	if (head == NULL) {
		return NULL;
	}
	//创建新节点，插入到旧节点后面
	Node* cur = head;
	while (cur != NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		node->random = NULL;
		cur = node->next;
	}
	// 插入成功，复制random指针
	cur = head;
	while (cur != NULL)	{
		if (cur->random != NULL) {
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	//拆分链表
	cur = head;
	Node* newHead = cur->next;
	while (cur != NULL) {
		Node* nn = cur->next;
		cur->next = nn->next;
		if (nn->next != NULL) {
			nn->next = cur->next->next;
		}
		cur = cur->next;
	}
	return newHead;
}

Node* CreateNode(int val) {
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->val = val;
	return node1;
}


int main()
{
	Node* node1 = CreateNode(1);
	Node* node2 = CreateNode(2);
	Node* node3 = CreateNode(3);
	Node* node4 = CreateNode(4);
	node1->next = node2; node1->random = node3;
	node2->next = node3; node2->random = node1;
	node3->next = node4; node3->random = node3;
	node4->next = NULL; node4->random = NULL;
	Print(node1);
	Node* newHead = CopyRandomList(node1);
	Print(newHead);
	system("pause");
	return 0;
}