//����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����
//ʾ�� 1:
//����: 1->2->3->4->5->NULL, k = 2
//	��� : 4->5->1->2->3->NULL
//	���� :
//	������ת 1 �� : 5->1->2->3->4->NULL
//		������ת 2 �� : 4->5->1->2->3->NULL
//		ʾ�� 2 :
//
//		���� : 0->1->2->NULL, k = 4
//		��� : 2->0->1->NULL
//		���� :
//	������ת 1 �� : 2->0->1->NULL
//		������ת 2 �� : 1->2->0->NULL
//		������ת 3 �� : 0->1->2->NULL
//		������ת 4 �� : 2->0->1->NULL

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



//˼·������Ԫ������������װ������Ȼ����ݹ��ɣ�����������Ӽ���
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || k == 0 || head->next == NULL) return head;
		// 1 2       1
		vector<ListNode*> v;
		while (head != NULL) {
			v.push_back(head);
			head = head->next;
		}
		if (k % v.size() == 0) return v[0];
		if (k > v.size()) {
			k = k % v.size();
		}
		ListNode* ret = v[v.size() - k];
		for (int i = v.size() - k + 1; i < v.size(); i++) {
			ret->next = v[i];
			ret = ret->next;
		}
		ret->next = v[0];
		v[v.size() - k - 1]->next = NULL;
		return v[v.size() - k];
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
	ListNode* node3 = CreateListNode(3);
	ListNode* node4 = CreateListNode(4);
	ListNode* node5 = CreateListNode(5);
	ListNode* node6 = CreateListNode(6);
	node1->next = node2; node2->next = node3;
	node3->next = node4; node4->next = node5;
	node5->next = node6;
	Print(node1);
	Solution s;
	cout << "��������ת������";
	int n;
	cin >> n;
	ListNode* ret = s.rotateRight(node1,n);
	Print(ret);
	system("pause");
	return 0;
}

