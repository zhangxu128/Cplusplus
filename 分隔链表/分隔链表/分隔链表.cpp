//����һ�������һ���ض�ֵ x����������зָ���ʹ������С�� x �Ľڵ㶼�ڴ��ڻ���� x �Ľڵ�֮ǰ��
//��Ӧ����������������ÿ���ڵ�ĳ�ʼ���λ�á�
//ʾ�� :
//����: head = 1->4->3->2->5->2, x = 3
//	��� : 1->2->2->4->3->5

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



//˼·������Ԫ���������������ֱ�洢���ں�С��Ŀ������ֵ��Ȼ������������
//      ������������


class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL) return NULL;
		ListNode* p = head, *ret;
		vector<ListNode*> min;
		vector<ListNode*> max;
		while (p != NULL) {
			if (p->val < x) {
				min.push_back(p);
			}
			else {
				max.push_back(p);
			}
			p = p->next;
		}
		if (!min.empty()) {
			ret = min[0];
			for (int i = 1; i < min.size(); i++) {
				ret->next = min[i];
				ret = ret->next;
			}
			for (int j = 0; j < max.size(); j++) {
				ret->next = max[j];
				ret = ret->next;
			}
			ret->next = NULL;
			return min[0];
		}
		else {
			ret = max[0];
			for (int i = 1; i < max.size(); i++) {
				ret->next = max[i];
				ret = ret->next;
			}
			ret->next = NULL;
			return max[0];
		}
		return NULL;
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
	ListNode* ret = s.partition(node1, n);
	Print(ret);
	system("pause");
	return 0;
}

